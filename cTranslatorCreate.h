﻿#pragma once
#include <algorithm>
#include <array>
#include <vector>
#include "cColumn.h"



class cTranslatorCreate
{
public:

	unsigned int position;
	unsigned int iteration;
	string  tableName;
	std::vector<cColumn*>*columns;

	cSpaceDescriptor * SD;
	cSpaceDescriptor * keySD;
	cDataType *keyType;
	bool homogenous = true;






public:
	cTranslatorCreate();
	//void SetType(string input);
	void TranlateCreate(string input);
	int GetPosition();
	vector<cColumn*>GetColumns();
	//const char * GetTableName();
	cSpaceDescriptor* CreateFixSpaceDescriptor();
	cSpaceDescriptor* CreateKeySpaceDescriptor();
	cSpaceDescriptor* GetSpaceDescriptor();


};

cTranslatorCreate::cTranslatorCreate() :position(13), iteration(0), columns(NULL),SD(NULL)
{

}

/*
inline void cTranslatorCreate::SetType(string input)
{
	if (std::size_t foundDDL = input.find("create table", 0) == 0)
	{
		type = CREATE;
		position = 13;
	}
	else if (std::size_t foundDDL = input.find("create index", 0) == 0)
	{
		type = INDEX;
		position = 13;
	}
}
*/
inline void cTranslatorCreate::TranlateCreate(string input)
{
	int positionInTable=0;
	string TEMPTable;
	while (input.find("(", position) != position)//vyparsování názvu tabulky, dokud nenajde (
	{
		TEMPTable.insert(0, 1, input.at(position));
		position++;
	}
	std::reverse(TEMPTable.begin(), TEMPTable.end());//preklopení názvu tabulky
	tableName = TEMPTable;
	//tableName = TEMPTable.c_str();

	position++;

	columns = new vector<cColumn*>();
	cDataType *CheckType;
	//dataTypes = new vector<cDataType>();
	do
	{
		if (iteration > 0)
		{
			position++;
		}

		cColumn* column = new cColumn();
		string TEMPType;
		string TMPSize;


		while (input.find(" ", position) != position)//vyhledání mezery po názvu sloupce
		{
			column->name.insert(0, 1, input.at(position));
			position++;
		}
		column->positionInTable = positionInTable;//priřazení pozice v tabulce
		positionInTable++;
		
		
		std::reverse(column->name.begin(), column->name.end());//preklopení názvu sloupce
		position++;
		

		bool withSize = false;

		while (input.find("(", position) != position && input.find(",", position) != position && input.find(" ", position) != position && input.find(")", position) != position)//vyhledání do ( po datovem typu nebo po ,
		{
			TEMPType.insert(0, 1, input.at(position));
			position++;


		}
		if (input.find("(", position) == position)
		{
			withSize = true;
		}

		std::reverse(TEMPType.begin(), TEMPType.end());//preklopení datového typu sloupce

		column->cType = cBasicType<cDataType*>::GetType(TEMPType);

		if (iteration > 0 && homogenous == true)//ověření jestli je tabulka homogení
		{
			if (column->cType->GetCode() != CheckType->GetCode())
				homogenous = false;
			else
				homogenous = true;
		}

		CheckType=column->cType;


		//position++;

		if (withSize == true)
		{
			position++;
			while (input.find(")", position) != position)//vyhledání do ( po datovem typu
			{
				TMPSize.insert(0, 1, input.at(position));
				position++;
			}

			std::reverse(TMPSize.begin(), TMPSize.end());//preklopení datového typu sloupce
			column->size = std::stoi(TMPSize);
			if (column->cType->GetCode() == 'n')//pokud je typ tuple(VARCHAR)
			{
				cDataType ** ptr;
				ptr = new cDataType*[column->size];

				for (int i = 0; i < column->size; i++)
				{
					ptr[i] = new cChar();
				}
				column->columnSD = new cSpaceDescriptor(column->size, new cNTuple(), ptr, false);//SD tuplu				
			}
			else
			{
				column->columnSD = NULL;
			}
			position++;
		}
		else
		{
			column->size = NULL;
			column->columnSD = NULL;
		}


		if (input.find("NOT NULL", position + 1) == position + 1)
		{
			column->notNull = true;
			position = position + 9;
		}
		else
		{
			column->notNull = false;

		}
		if (input.find("PRIMARY KEY", position + 1) == position + 1)
		{
			column->primaryKey = true;
			position = position + 12;
			column->notNull = true;
		}
		else
		{
			column->primaryKey = false;
		}
		columns->push_back(column);
		
		iteration++;


		
		

	} while (input.find(")", position) != position);
	
	CreateFixSpaceDescriptor();
	CreateKeySpaceDescriptor();
}



inline int cTranslatorCreate::GetPosition()
{
	return position;
}



inline vector<cColumn*> cTranslatorCreate::GetColumns()
{
	return *columns;
}
/*
inline const char* cTranslatorCreate::GetTableName()
{
	return tableName;
}
*/


inline cSpaceDescriptor* cTranslatorCreate::CreateFixSpaceDescriptor()
{
	if (!homogenous)
	{
		cDataType *typ = new cInt();
		cDataType ** ptr;
		ptr = new cDataType*[columns->size() ];
		int i;

		for (i = 0; i < columns->size(); i++)
		{
			ptr[i] = columns->at(i)->cType;
		}

		//ptr[i] = new cInt();// cBasicType<cDataType*>::GetType("INT");
		SD = new cSpaceDescriptor(columns->size() , new cTuple(), ptr, false);//SD tuplu
	}
	else
	{
		/*cDataType *typ = new cInt();
		cDataType ** ptr;
		ptr = new cDataType*[columns->size()+1];
		int i;

		for ( i = 0; i < columns->size(); i++)
		{
			ptr[i] = columns->at(i)->cType;
		}
		
		ptr[i] = new cInt();// cBasicType<cDataType*>::GetType("INT");
		SD = new cSpaceDescriptor(columns->size()+1, new cTuple(), ptr, false);//SD tuplu
		*/
		
		SD = new cSpaceDescriptor(columns->size(), new cTuple(), columns->at(0)->cType, false);//SD tuplu
	}
	return SD;
	
}

inline cSpaceDescriptor * cTranslatorCreate::CreateKeySpaceDescriptor()
{
	/*
	for (int i = 0; i < columns->size(); i++)
	{
		if (columns->at(i)->primaryKey)
		{
			keyType = columns->at(i)->cType;
		}
	}
	keySD= new cSpaceDescriptor(1, new cTuple(), keyType, false);
	*/
	//nebo

	cDataType *typ = new cInt();
	cDataType ** ptr;
	ptr = new cDataType*[2];


	for (int i = 0; i < columns->size(); i++)
	{
		if (columns->at(i)->primaryKey)
		{
			keyType = columns->at(i)->cType;
			ptr[0] = keyType;
		}
	}
	
	ptr[1] = new cInt();
	keySD = new cSpaceDescriptor(2, new cTuple(), ptr, false);

	
	return keySD;
}

inline cSpaceDescriptor* cTranslatorCreate::GetSpaceDescriptor()
{
	return SD;
}


