#pragma once

#include <fstream>
#include <string>

//LRace Class definitions========================================

enum race_id
{
	HUMAN = 0,
	UNDEAD,
	HERETIC,
	DWARF,
	NEUTRAL,
	ELF,
	GREENSKINS, // New race variable
	UNDEFINED = -1
};

struct EnumRecord
{
	int Id;
	char *name;
};

class CProxyCodeBaseEnv
{

};

struct InternalString
{
	int strLen;
	int strWithTerminatorLen;
	char *strPtr;
	DWORD somePtr;
};

struct AbstractCategoryTable
{
	DWORD vfTable;                   // 0x00
	EnumRecord *FirstRecord;            // 0x04
	EnumRecord *EndOfRecords;            // 0x08
	DWORD UnknownC;            // 0x0C
	DWORD UnknownD;            // 0x10
	void outputToFile(std::string tableName, std::ofstream &file);
};

struct LRaceCategoryTable : public AbstractCategoryTable
{
	LRaceCategoryTable() {
		vfTable = 0x006E7234;
	}
};


struct LSubRaceCategoryTable : public AbstractCategoryTable
{
	LSubRaceCategoryTable() {
		vfTable = 0x006E8A4C;
	}
};


struct LAttackClassTable : public AbstractCategoryTable
{
	LAttackClassTable() {
		vfTable = 0x006E7E54;
	}
};

struct LAttackSourceTable : public AbstractCategoryTable{
	LAttackSourceTable()
	{
		vfTable = 0x006E7CFC;
	}
};
	struct LAttackReachTable: public AbstractCategoryTable{
		LAttackReachTable()
		{
			vfTable = 0x006E938C;
		}
	};
	struct LUnitBranchTable: public AbstractCategoryTable{
		LUnitBranchTable(){
			vfTable = 0x006E915C;
		}
	};
	struct LUnitCategoryTable: public AbstractCategoryTable{
		LUnitCategoryTable(){
			vfTable = 0x006E94AC;
		}
	};
	struct LBuildingCategoryTable: public AbstractCategoryTable{
		LBuildingCategoryTable(){
			vfTable = 0x006E86BC;
		}
	};
	struct LGroundCategoryTable: public AbstractCategoryTable{
		LGroundCategoryTable()
		{
			vfTable = 0x006E7C54;
		}
	};
	struct LDifficultyLevelTable: public AbstractCategoryTable{
		LDifficultyLevelTable(){
			vfTable = 0x006E8684;
		}
	};
	struct LItemCategoryTable: public AbstractCategoryTable{
		LItemCategoryTable(){
			vfTable = 0x006E7FF4;
		}
	};
	struct LLordCategoryTable: public AbstractCategoryTable{
		LLordCategoryTable(){
			vfTable = 0x006E8034;
		}
	};
	struct LModifierElementTable: public AbstractCategoryTable{
		LModifierElementTable(){
			vfTable = 0x006E9B14;
		}
	};
	struct LOrderCategoryTable: public AbstractCategoryTable{
		LOrderCategoryTable(){
			vfTable = 0x006E8534;
		}
	};

	struct LResourceTypeTable: public AbstractCategoryTable{
		LResourceTypeTable(){
			vfTable = 0x006E956C;
		}
	};
	struct LSiteCategoryTable: public AbstractCategoryTable{
		LSiteCategoryTable(){
			vfTable = 0x006E9674;
		}
	};
	struct LSpellCategoryTable: public AbstractCategoryTable{
		LSpellCategoryTable() 	{
			vfTable = 0x006E845C;
		}
	};
	struct LTerrainCategoryTable: public AbstractCategoryTable{
		LTerrainCategoryTable(){
			vfTable = 0x006E85DC;
		}
	};
	struct LLeaderAbilityTable: public AbstractCategoryTable{
		LLeaderAbilityTable(){
			vfTable = 0x006E7F24;
		}
	};
	struct LLeaderCategoryTable: public AbstractCategoryTable{
		LLeaderCategoryTable(){
			vfTable = 0x006E87C4;
		}
	};
	struct LAiSpellCategoryTable: public AbstractCategoryTable{
		LAiSpellCategoryTable(){
			vfTable = 0x006E9414;
		}
	};
	struct LModifGroupTable: public AbstractCategoryTable{
		LModifGroupTable(){
			vfTable = 0x006E99FC;
		}
	};
	struct LAttitudesCategoryTable: public AbstractCategoryTable{
		LAttitudesCategoryTable(){
			vfTable = 0x006E92C4;
		}
	};
	struct LAiMsgCategoryTable: public AbstractCategoryTable{
		LAiMsgCategoryTable(){
			vfTable = 0x006E9274;
		}
	};
	struct LNobleActionCatTable: public AbstractCategoryTable{
		LNobleActionCatTable(){
			vfTable = 0x006E8DD4;
		}
	};
	struct LImmuneCatTable: public AbstractCategoryTable{
		LImmuneCatTable(){
			vfTable = 0x006E7CA4;
		}
	};
	struct LFortCategoryTable: public AbstractCategoryTable{
		LFortCategoryTable() {
			vfTable = 0x006E898C;
		}
	};
	struct LEventCondCategoryTable: public AbstractCategoryTable{
		LEventCondCategoryTable(){
			vfTable = 0x006E8CF4;
		}
	};
	struct LEventEffectCategoryTable: public AbstractCategoryTable{
		LEventEffectCategoryTable()	{
			vfTable = 0x006E8BCC;
		}
	};
	struct LLandmarkCategoryTable: public AbstractCategoryTable{
		LLandmarkCategoryTable(){
			vfTable = 0x006E99D4;
		}
	};
	struct LDeathAnimCategoryTable: public AbstractCategoryTable{
		LDeathAnimCategoryTable(){
			vfTable = 0x006E997C;
		}
	};


struct __declspec( align( 16 ) ) LRaceCategory
{
	void* vfTable;           // 0x00
	LRaceCategoryTable* categoryTable;     // 0x04
	race_id id;        // 0x08
};


//Subrace class definitions=========================================

enum sub_race_id
{
	SR_CUSTOM = 0,
	SR_HUMAN,
	SR_UNDEAD,
	SR_HERETIC,
	SR_DWARF,
	SR_NEUTRAL,
	SR_NEUTRAL_HUMAN,
	SR_NEUTRAL_ELF,
	SR_NEUTRAL_GREEN_SKIN,
	SR_NEUTRAL_DRAGON,
	SR_NEUTRAL_MARSH,
	SR_NEUTRAL_WATER,
	SR_NEUTRAL_BARBARIAN,
	SR_NEUTRAL_WOLF,
	SR_ELF,
	SR_GREENSKINS, // New race variable
};
/*
struct LSubRaceCategoryTable
{
	void* vftable;                   // 0x00
	DWORD FirstRecord;            // 0x04
	DWORD EndOfRecords;            // 0x08
	DWORD UnknownC;            // 0x0C
	DWORD UnknownD;            // 0x10
};
*/
struct __declspec( align( 16 ) ) LSubRaceCategory
{
	void* vftable;                                 // 0x00
	LSubRaceCategoryTable* subRaceCategoryTable;             // 0x04
	sub_race_id id;                          // 0x08
};


// 0040BBB6 structures

struct Struct_0040BBB6
{
	int *p;			//0x00
	int UnknownA;	//0x04	
	int UnknownB;	//0x08
	int UnknownC;	//0x0C
	int UnknownD;	//0x10
	int UnknownE;	//0x14
	int UnknownF;
	int UnknownG;
	int UnknownH;	//0x20
	LRaceCategory* pRace; //0x24
	//	DWORD sub_004018D6 (char* );

};

struct Struct1_0040BBB6
{
	int *p1;
	int UnknownA1;
	int *UnknownB1;
	int UnknownC1;
	int UnknownD1;
	int UnknownE1;
	int UnknownF1;
	int UnknownG1;
	int UnknownH1;
	//	DWORD sub_00561299 (int* );

};

struct Struct2_0040BBB6
{
	int *p2;
	int UnknownA2;
	int UnknownB2;

};

struct Struct_56A5EC
{
	int p;                   // 0x00
	int UnknownA[19];            // 0x04
	DWORD UnknownB;            // 0x08
	DWORD UnknownC;            // 0x0C
	DWORD UnknownD;            // 0x10
};


struct struct_00582121_2_vtable 
{

	DWORD UnknownA;
	DWORD UnknownB;
	DWORD UnknownC;

};

struct struct_00582121 {

	int* p;
	DWORD UnknownA;
	DWORD UnknownB;
	DWORD UnknownC;

};

struct struct_00582121_2 {

	DWORD p;
	DWORD UnknownA; //0x04
	DWORD UnknownB;
	DWORD UnknownC;

};

struct struct1_004ED819 {

	DWORD p;
	DWORD UnknownA; //0x04
	DWORD UnknownB; //0x08
	DWORD UnknownC; //0x0C
	DWORD UnknownD; //0x10
	DWORD UnknownE; //0x14
	DWORD UnknownF;
	DWORD UnknownH;
};

struct struct2_004ED819 {

	DWORD p;
	DWORD field1; //0x04
	DWORD field2; //0x08
	DWORD field3; //0x0C
	DWORD field4; //0x10
	DWORD field5; //0x14
	char field6;
	DWORD filed7;
};


struct TItemTypeList {

};

struct CMidObject
{
	void *vftable;
};

struct ObjectRecord
{
	DWORD id;
	CMidObject *object;
};

struct IdObjectVector
{
	DWORD vftable;
	ObjectRecord *pVectorBegin;
	ObjectRecord *pVectorEnd;
	void outputToFile(std::ofstream &file);
};

struct KeyValueVector
{
	DWORD vftable;
	EnumRecord *pVectorBegin;
	EnumRecord *pVectorEnd;	
};

class GameData
{
	DWORD *dataptr;				//0x00
	DWORD *pairsCount;			//0x04
	KeyValueVector *pairData;	//0x08
	LAttackClassTable	*attackClassTable;//0x0C
	LAttackSourceTable	*attackSourceTable;//0x10
	LAttackReachTable	*attackReachTable;//0x14
	LUnitBranchTable	*unitBranchTable;//0x18
	LUnitCategoryTable	*unitCategoryTable;//0x1C
	LBuildingCategoryTable	*buildingCategoryTable;//0x20
	LGroundCategoryTable	*groundCategoryTable;//0x24
	LDifficultyLevelTable	*difficultyLevelTable;//0x28
	LItemCategoryTable	*itemCategoryTable;//0x2C
	LLordCategoryTable	*lordCategoryTable;//0x30
	LModifierElementTable	*modifierElementTable;//0x34
	LOrderCategoryTable	*orderCategoryTable;//0X38
	LRaceCategoryTable	*raceCategoryTable;//0X3c
	LSubRaceCategoryTable	*subRaceCategoryTable;//0X40
	LResourceTypeTable	*resourceTypeTable;//0X44
	LSiteCategoryTable	*siteCategoryTable;//0x48
	LSpellCategoryTable	*spellCategoryTable;//0x4C
	LTerrainCategoryTable	*terrainCategoryTable;//0x50
	LLeaderAbilityTable	*leaderAbilityTable;//0x54
	LLeaderCategoryTable	*leaderCategoryTable;//0x58
	LAiSpellCategoryTable	*aiSpellCategoryTable;//0x5C
	LModifGroupTable	*modifGroupTable;//0x60
	LAttitudesCategoryTable	*attitudesCategoryTable;//0x64
	LAiMsgCategoryTable	*aiMsgCategoryTable;//0x68
	LNobleActionCatTable	*nobleActionCatTable;//0x6C
	LImmuneCatTable	*immuneCatTable;//0x70
	LFortCategoryTable	*fortCategoryTable;//0x74
	LEventCondCategoryTable	*eventCondCategoryTable;//0x78
	LEventEffectCategoryTable 	*eventEffectCategoryTable;//0x7C
	LLandmarkCategoryTable	*landmarkCategoryTable;//0x80
	LDeathAnimCategoryTable	*deathAnimCategoryTable;//0x84
	IdObjectVector **objects;//(<id, CMidObject>) //0x88
	IdObjectVector **objects1;//(<id, CMidObject>)	//0x8C
	IdObjectVector **objects2;//(<id, CMidObject>)	//0x90
	IdObjectVector **objects3;//(<id, CMidObject>)	//0x94
	IdObjectVector **objects4;//(<id, CMidObject>)	//0x98
	IdObjectVector **objects5;//(<id, CMidObject>)	//0x9C
	IdObjectVector **objects6;//(<id, CMidObject>)	//0xA0
	TItemTypeList itemTypes;	//0xA4
public:
	void outputToFile(std::ofstream &file);
};

struct CPictureInterf
{

};

struct SomeStruct
{
	DWORD val1;
	DWORD val2;
};

struct LDifficultyLevel
{
	DWORD vftable;
	LDifficultyLevelTable *table;
	DWORD count;
};


struct LLordCategory
{
	DWORD vftable;
	LLordCategoryTable* table;
	DWORD count;
};

struct CategoryTablesContainer
{
	AbstractCategoryTable *table;
	unsigned int count;
};

struct SomeLordStruct
{
	DWORD dummy1;
	DWORD dummy2;
	DWORD dummy3;
	DWORD dummy4;
	DWORD dummy5;
	DWORD dummy6;
};

struct CMenuCategories
{
	LLordCategory lordCategory;			//00
	LDifficultyLevel levelCategory;		//0C
	DWORD someDword1;					//18
	char dummy1[0x18];					//1C
	DWORD someDword6;					//34  52
	DWORD someDword2;					//38  56
	char dummy2[0x20];					//3C  60
	DWORD someDword3;					//5C  92
	DWORD someDword8;					//60  96
	DWORD someDword4;					//64  100
	DWORD someDword5;					//68  104
	DWORD someDword9;					//6C  104
	SomeLordStruct lordStruct;			//70
	DWORD someDword7;					//8C  104
};
//	char dummy3[0x20];					//6C  60

struct CMenuLord
{
	DWORD vftable;
	DWORD dummy1;
	DWORD dummy2;
	CMenuCategories *categories;
};

struct RaceElement
{
    RaceElement *prev;
    RaceElement *next;
    LRaceCategory race;
};

struct RacesList
{
    RaceElement *head;
    RaceElement *tail;
};

struct RacesStruct
{
    DWORD someByte;
    RacesList *races;
    DWORD someDword;
};

struct Some16Struct
{
    DWORD m0;
    DWORD m4;
    DWORD m8;
    DWORD mC;
};

struct CMidStreamEnvDB
{
    DWORD vftable;
    char dummy1[0x10];
    char *directory;
    DWORD dummy2;
    CProxyCodeBaseEnv *proxyCodeBaseEnv;
};

struct CDBcodeBaseEnv
{
    DWORD vftable;
};

struct CDBcodeBaseTable
{
    DWORD vftable;
};

struct CMidStreamDb 
{
    DWORD vftable;
    DWORD CDBTable;
    CDBcodeBaseEnv *codeBaseEnv;
    CDBcodeBaseTable *codeBaseTable;
    CMidStreamEnvDB *envDB;
};
