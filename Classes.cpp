#include "StdAfx.h"
#include "Classes.h"


//Classes::Classes(void)
//{
//}


//Classes::~Classes(void)
//{
//}

void AbstractCategoryTable::outputToFile(std::string tableName, std::ofstream &file )
{
	file << tableName << std::endl;
	for (int i = 0; i < EndOfRecords - FirstRecord; i++)
	{
		EnumRecord record = FirstRecord[i];
		file<<"\t" <<std::hex << record.Id <<" " << std::string(record.name)<<std::endl;
	}
}

void GameData::outputToFile( std::ofstream &file )
{
	attackClassTable->outputToFile("LAttackClassTable", file);;//0x0C
	attackSourceTable->outputToFile("LAttackSourceTable", file);;//0x10
	attackReachTable->outputToFile("SubRaceCategoryTable", file);;//0x14
	unitBranchTable->outputToFile("LUnitBranchTable", file);;//0x18
	unitCategoryTable->outputToFile("LUnitCategoryTable", file);;//0x1C
	buildingCategoryTable->outputToFile("LBuildingCategoryTable", file);;//0x20
	groundCategoryTable->outputToFile("LGroundCategoryTable", file);;//0x24
	difficultyLevelTable->outputToFile("LDifficultyLevelTable", file);;//0x28
	itemCategoryTable->outputToFile("LItemCategoryTable", file);;//0x2C
	lordCategoryTable->outputToFile("LLordCategoryTable", file);;//0x30
	modifierElementTable->outputToFile("LModifierElementTable", file);;//0x34
	orderCategoryTable->outputToFile("LOrderCategoryTable", file);;//0X38
	raceCategoryTable->outputToFile("LRaceCategoryTable", file);;//0X3c
	subRaceCategoryTable->outputToFile("LSubRaceCategoryTable", file);;//0X40
	resourceTypeTable->outputToFile("SubRaceCategoryTable", file);;//0X44
	siteCategoryTable->outputToFile("LSiteCategoryTable", file);;//0x48
	spellCategoryTable->outputToFile("LSpellCategoryTable", file);;//0x4C
	terrainCategoryTable->outputToFile("LTerrainCategoryTable", file);;//0x50
	leaderAbilityTable->outputToFile("LLeaderAbilityTable", file);;//0x54
	leaderCategoryTable->outputToFile("LLeaderCategoryTable", file);;//0x58
	aiSpellCategoryTable->outputToFile("LAiSpellCategoryTable", file);;//0x5C
	modifGroupTable->outputToFile("LModifGroupTable", file);;//0x60
	attitudesCategoryTable->outputToFile("LAttitudesCategoryTable", file);;//0x64
	aiMsgCategoryTable->outputToFile("LAiMsgCategoryTable", file);;//0x68
	nobleActionCatTable->outputToFile("LNobleActionCatTable", file);;//0x6C
	immuneCatTable->outputToFile("LImmuneCatTable", file);;//0x70
	fortCategoryTable->outputToFile("LFortCategoryTable", file);;//0x74
	eventCondCategoryTable->outputToFile("LEventCondCategoryTable", file);;//0x78
 	eventEffectCategoryTable->outputToFile("LEventEffectCategoryTable", file);;//0x7C
	landmarkCategoryTable->outputToFile("LLandmarkCategoryTable", file);;//0x80
	deathAnimCategoryTable->outputToFile("LDeathAnimCategoryTable", file);;//0x84
	objects[0]->outputToFile(file);
	objects1[0]->outputToFile(file);
	objects2[0]->outputToFile(file);
	objects3[0]->outputToFile(file);
	objects4[0]->outputToFile(file);
	objects5[0]->outputToFile(file);
	objects6[0]->outputToFile(file);
}

void IdObjectVector::outputToFile( std::ofstream &file )
{	
	file << "====-----========-------========--------" << std::endl;
	for (int i = 0; i < pVectorEnd - pVectorBegin; i++)
	{
		ObjectRecord record = pVectorBegin[i];
		file<<"\t" <<std::hex << record.id <<" " << std::hex <<record.object->vftable<<std::endl;
	}
}
