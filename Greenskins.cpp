// Greenskins.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Classes.h"
#include "GUI.h"


#define DATA( name, type, address ) static type& name = (*((type*)address));
#define FUNC( name, address, ret_type, call_convention, args ) ret_type(call_convention * const name)args = (ret_type(call_convention *)args) address;
#define PFNC( name, address, ret_type, call_convention, args ) static ret_type (call_convention *& name)args = *( (ret_type(call_convention **)args)address);
//#define DATA1( name, type, address ) static type& name = (*((type*)address));


//================================= Game functions and data definitions ============================

namespace Game
{

	//my_0057EB99 definitions
	DATA( undeadCategory,  LRaceCategory, 0x00837290 );
	DATA( elfCategory,     LRaceCategory, 0x008372A0 );
	DATA( neutralCategory, LRaceCategory, 0x008372B0 );
	DATA( humanCategory,   LRaceCategory, 0x008372C0 );
	DATA( hereticCategory, LRaceCategory, 0x008372D0 );
	DATA( dwarfCategory,   LRaceCategory, 0x008372E0 );
	LRaceCategory greenskinsCategory; //New race

	DATA( globalData, GameData*, 0x00837304 );

	// DATA( ptrundead,  *SomeOtherClass, 0x00837290 );
	// DATA( ptrelf,     *SomeOtherClass, 0x008372A0 );
	//  DATA( ptrneutral, *SomeOtherClass, 0x008372B0 );
	//  DATA( ptrhuman,   *SomeOtherClass, 0x008372C0 );
	// DATA( ptrheretic, *SomeOtherClass, 0x008372D0 );
	// DATA( ptrdwarf,   *SomeOtherClass, 0x008372E0 );
	//  DATA(ptrgreenskins, *SomeOtherClass, 0x00837280);



	FUNC( InitRaceCategoryTableFromFile, 0x0057ED2E, DWORD, __stdcall, ( LRaceCategoryTable*, void*, char*, char* ) );
	FUNC( SetRaceId, 0x0057EDA6, DWORD, __stdcall, ( LRaceCategory*, LRaceCategoryTable*, char*, char* ) );
	FUNC (sub_0057ECE9, 0x0057ECE9, DWORD, __thiscall, ( LRaceCategoryTable*));

	FUNC(sub_4EE08F, 0x004EE08F, DWORD, __stdcall, (CDialogInterf* dialogInterface, LRaceCategory *race));
	FUNC(GetTextBoxFromDlg, 0x0050B013, CTextBoxInterf*, __stdcall, (CDialogInterf*, char*));
	FUNC(GetValueFromTable, 0x0057EF4F, DWORD*, __thiscall, (CDialogInterf**, char*));
	FUNC(GetStringByIndex, 0x005C7F06, char*, __stdcall, (DWORD*));
	FUNC(AllocateString, 0x00403C8B, char*, __thiscall, (InternalString*, const char*, DWORD));
	FUNC(ReplaceSubstr, 0x0051EB96, char*, __stdcall, (InternalString*, const char*, char*));
	FUNC(SetTextBoxText, 0x005337B0, void, __thiscall, (CTextBoxInterf*, char *));
	FUNC(FreeString, 0x0040106A, void, __thiscall, (InternalString*));



	//my_0058CCB9 definitions

	// DATA definition for the LSubRace addresses
	DATA( sr_custom,                  LSubRaceCategory, 0x00837AE8 );
	DATA( sr_human,                   LSubRaceCategory, 0x00837AC8 );
	DATA( sr_undead,                  LSubRaceCategory, 0x00837AA8 );
	DATA( sr_heretic,                 LSubRaceCategory, 0x00837B70 );
	DATA( sr_dwarf,                   LSubRaceCategory, 0x00837B18 );
	DATA( sr_neutral,                 LSubRaceCategory, 0x00837AF8 );
	DATA( sr_neutral_human,           LSubRaceCategory, 0x00837B80 );
	DATA( sr_neutal_elf,				 LSubRaceCategory, 0x00837B08 );
	DATA( sr_neutral_green,           LSubRaceCategory, 0x00837AB8 );
	DATA( sr_neutral_dragon,			 LSubRaceCategory, 0x00837AD8 );
	DATA( sr_neutral_marsh,           LSubRaceCategory, 0x00837B58 );
	DATA( sr_neutral_water,           LSubRaceCategory, 0x00837B28 );
	DATA( sr_neutral_barbarian,		 LSubRaceCategory, 0x00837A98 );
	DATA( sr_neutral_wolf,            LSubRaceCategory, 0x00837B38 );
	DATA( sr_elf,                     LSubRaceCategory, 0x00837B48 );
	LSubRaceCategory sr_greenskins;

	//     DATA(greenskins, SomeOtherClass, 0x00837280); //New race data memory slot

	// Data definitions for my_0040BBB6
	DATA(offset_006CC64C, char, 0x006CC64C);

	DATA(byte_839137, char, 0x00839137);
	DATA(word_83918C, char*, 0x0083918C);

	//Function definitions for LSubRace
	FUNC( InitSubRaceCategoryTableFromFile, 0x0058CF1D, DWORD, __stdcall, ( LSubRaceCategoryTable*, void*, char*, char* ) );
	FUNC( SetSubRaceId, 0x0058CF95, DWORD, __stdcall, ( LSubRaceCategory*, LSubRaceCategoryTable*, char*, char* ) );
	FUNC (sub_0058CED8, 0x0058CED8, DWORD, __thiscall, ( LSubRaceCategoryTable*));

	//Function definitions for my_0040BBB6

	FUNC( sub_004018D6, 0x004018D6, DWORD, __thiscall, (Struct_0040BBB6*, char*) );
	FUNC( sub_00561299, 0x00561299, Struct1_0040BBB6*, __stdcall, ( int* ) );
	FUNC( sub_005613E1, 0x005613E1, DWORD, __thiscall, (int) );
	FUNC( sub_00401943, 0x00401943, DWORD, __thiscall, (int*, DWORD) );
	FUNC( sub_00608AB7, 0x00608AB7, int, __fastcall, (LRaceCategory**, DWORD) );
	FUNC( sub_0040CE75, 0x0040CE75, int, __stdcall, (LRaceCategory**) );
	FUNC( sub_0040CEA3, 0x0040CEA3, int, __stdcall, (int) );

	FUNC( sub_0056A675, 0x0056A675, DWORD, __stdcall, ( int, LRaceCategory* ) );
	FUNC( sub_0056AB03, 0x0056AB03, int, __stdcall, ( int ) );

	FUNC( sub_005984F9, 0x005984F9, int, __thiscall, ( struct_00582121*,DWORD*) );
	FUNC( sub_00598507, 0x00598507, int, __thiscall, ( struct_00582121*, DWORD* ) );
	FUNC( GetRaceTypeByRaceCategory, 0x005821C5, DWORD, __stdcall, ( struct_00582121*, LRaceCategory*, char* ) );

    FUNC(GetValueIndexFromTable, 0x0057EF4F, int, __fastcall, (CMenuCategories*, DWORD, char*));

	//std::ofstream log("log.txt");
    DWORD GreenSkinsCampaignId;

	void Init()
	{
		greenskinsCategory.vfTable = (void *)0x006CCA84;
		sr_greenskins.vftable = (void *)0x006D15D4;
        GetValueIndexFromTable((CMenuCategories*)&GreenSkinsCampaignId, 0, "C000CC0007");
		//DWORD thID;
		//globalData->outputToFile(log);
	}

}

//================================= END OF Game functions and data definitions ============================

//================================= my_0057EB99 =============================================
//Function to define LRace.dbf data




LRaceCategoryTable* __fastcall LoadLRaceCategoryTable( LRaceCategoryTable* thisptr, DWORD unused, char* szDir, CProxyCodeBaseEnv* proxyCodeBaseEnv )
{
	char szLRacedbf[] = { "LRace.dbf" };
	thisptr->vfTable = 0x006E7234; //LRaceCategoryTable
	thisptr->FirstRecord = 0;
	thisptr->EndOfRecords = 0;
	thisptr->UnknownC = 0;
	thisptr->UnknownD = 0;
	Game::InitRaceCategoryTableFromFile( thisptr, proxyCodeBaseEnv, szDir, szLRacedbf );
	Game::SetRaceId( &Game::undeadCategory,      thisptr, "L_UNDEAD", szLRacedbf );
	Game::SetRaceId( &Game::elfCategory,         thisptr, "L_ELF",        szLRacedbf );
	Game::SetRaceId( &Game::neutralCategory,     thisptr, "L_NEUTRAL",    szLRacedbf );
	Game::SetRaceId( &Game::humanCategory,       thisptr, "L_HUMAN",      szLRacedbf );
	Game::SetRaceId( &Game::hereticCategory,     thisptr, "L_HERETIC",    szLRacedbf );
	Game::SetRaceId( &Game::dwarfCategory,       thisptr, "L_DWARF",      szLRacedbf );
 	Game::SetRaceId( &Game::greenskinsCategory,  thisptr, "L_GREEN_SKIN", szLRacedbf ); //new race identification
	Game::sub_0057ECE9( thisptr);  
	return  thisptr;
}

//================================= END OF my_0057EB99 =============================================

//================================= my_0058CCB9 ====================================================

//Function to define LSubRace.dbf data


LSubRaceCategoryTable* __fastcall LoadLSubRaceCategoryTable( LSubRaceCategoryTable* thisptr, DWORD unused, char* szDir, void* some_pointer )
{
	char szLSubRacedbf[] = { "LSubRace.dbf" };
	thisptr->vfTable = 0x006E8A4C;
	thisptr->FirstRecord = 0;
	thisptr->EndOfRecords = 0;
	thisptr->UnknownC = 0;
	thisptr->UnknownD = 0;
	Game::InitSubRaceCategoryTableFromFile( thisptr, some_pointer, szDir, szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_custom,                         thisptr, "L_CUSTOM",              szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_human,                          thisptr, "L_HUMAN",                      szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_undead,                         thisptr, "L_UNDEAD",              szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_heretic,                        thisptr, "L_HERETIC",                    szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_dwarf,                          thisptr, "L_DWARF",                      szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral,                        thisptr, "L_NEUTRAL",                    szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_human,           thisptr, "L_NEUTRAL_HUMAN",        szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutal_elf,                     thisptr, "L_NEUTRAL_ELF",         szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_green,           thisptr, "L_NEUTRAL_GREEN_SKIN",szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_dragon,          thisptr, "L_NEUTRAL_DRAGON",       szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_marsh,           thisptr, "L_NEUTRAL_MARSH",        szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_water,           thisptr, "L_NEUTRAL_WATER",        szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_barbarian,       thisptr, "L_NEUTRAL_BARBARIAN",       szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_neutral_wolf,                   thisptr, "L_NEUTRAL_WOLF",        szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_elf,                            thisptr, "L_ELF",                        szLSubRacedbf );
	Game::SetSubRaceId( &Game::sr_greenskins,                     thisptr, "L_GREEN_SKIN",          szLSubRacedbf );
	Game::sub_0058CED8( thisptr);
	return  thisptr;
}

//================================= END OF my_0058CCB9 =============================================

//================================= my_0040BBB6 ===================================================

extern "C" __declspec(dllexport) int __stdcall my_0040BBB6(int a1, char a2, int a3, int a4, int a5, char *Source, int* a7, int a8)
{

	Struct_0040BBB6 *sc;
	int vptr8;
	//int rid;
	//SomeOtherClass* vptrRace;
	Struct1_0040BBB6 *sc1;
	Struct2_0040BBB6 *sc2;

	sc->p=&(sc->UnknownH);
	sc->UnknownA=0;
	sc->UnknownH=0;
	Game::sub_004018D6(sc, &Game::offset_006CC64C);

	sc->p=&(sc->UnknownH);
	sc->UnknownA=1;
	Game::sub_004018D6(sc, Source);

	sc1->p1=&(sc->UnknownE);
	vptr8 = Game::sub_00561299(&(sc->UnknownE))->UnknownA1;

	sc->UnknownA=2;
	Game::sub_005613E1(vptr8);

	sc->UnknownA=1;
	Game::sub_00401943(&(sc->UnknownE), 0);


	if ( sc2->p2=a7 )
	{

		if ( sc2->UnknownB2 == Game::dwarfCategory.id )
		{
			sc->pRace = &Game::dwarfCategory;
		}
		else
		{
			if (  sc2->UnknownB2 == Game::undeadCategory.id )
			{
				sc->pRace = &Game::undeadCategory;
			}
			else
			{
				if (  sc2->UnknownB2 == Game::hereticCategory.id )
				{
					sc->pRace = &Game::hereticCategory;
				}
				else
				{
					if (  sc2->UnknownB2 == Game::humanCategory.id)
					{
						sc->pRace = &Game::humanCategory;
					}
					else
					{
						if (  sc2->UnknownB2 == Game::elfCategory.id )
							sc->pRace = &Game::elfCategory;
					}
				}
			}
		}
	}
	else
	{
		sc->pRace = 0;
	}



	if ( !a8 )
	{
		sc2->UnknownA2 = a1;
		Game::sub_0040CE75(&sc->pRace);
		(&sc2->UnknownB2 - &sc2->UnknownA2) % 12;

		if ( ((unsigned int)(&sc2->UnknownB2 - &sc2->UnknownA2) / 12) > 0x32 )
			Game::sub_0040CEA3(sc2->UnknownA2);
	}

	//v12 = 0;
	//v20 = a3;
	//v13 = *(_DWORD *)a3;
	// while ( 1 )
	//{
	// v14 = v12 ? 0 : v13 == v20;
	// if ( v14 )
	//   break;
	// v15 = v12;
	// if ( !v12 )
	//    v15 = v13 + 8;
	//  (*(void (__fastcall **)(_DWORD, int, int, char *, int))(**(_DWORD **)v15 + 4))(*(_DWORD *)v15, v9, v17, Source, a8);
	//  if ( v12 )
	//   v12 += 4;
	//  else
	//     v13 = *(_DWORD *)v13;
	// }

	Game::sub_00608AB7(&(sc->pRace), 0);

	return 0;

}

__declspec(dllexport) int __stdcall sub_56A5EC(Struct_56A5EC *thisptr)
{
	//  void *v1; // esi@1
	int result; // eax@1

	//  v1 = thisptr;

	Game::sub_0056A675(thisptr->UnknownA[19], &Game::hereticCategory);
	Game::sub_0056A675(thisptr->UnknownA[19], &Game::dwarfCategory);
	Game::sub_0056A675(thisptr->UnknownA[19], &Game::humanCategory);
	Game::sub_0056A675(thisptr->UnknownA[19], &Game::undeadCategory);
	Game::sub_0056A675(thisptr->UnknownA[19], &Game::elfCategory);

	result = thisptr->p;
	if ( thisptr )
	{
		thisptr = 0;
		result = Game::sub_0056AB03(result);
	}

	return result;
}

__declspec(dllexport) void __fastcall sub_00582121(struct_00582121 *thisptr, DWORD unused, DWORD a2)
{
	//	__asm{
	//	int 3
	//	} 
	void *v2; // esi@1
	struct_00582121_2* v3; // eax@1
	struct_00582121_2 v5; // [sp+4h] [bp-8h]@1
	struct_00582121_2 v6; // [sp+8h] [bp-4h]@1
	struct_00582121_2* v7;

	char szGRacedbf[] = { "GRace.dbf" };

	//v6 = new struct_00582121_2;
	Game::sub_005984F9(thisptr, &v6.p);
	Game::sub_00598507(thisptr, &v5.UnknownA); //v5

	v3 =(struct_00582121_2*)v6.p;
	v7 = v3;
	while ( v3!=(struct_00582121_2*)v5.UnknownA )
	{
		(*(void (__thiscall **)(DWORD, DWORD))(*(DWORD *)(v7->UnknownA) + 4))(v3->UnknownA, a2);
		v3 = (struct_00582121_2*)((char *)v3 + 8);

	}


	Game::GetRaceTypeByRaceCategory(thisptr, &Game::dwarfCategory, szGRacedbf);
	Game::GetRaceTypeByRaceCategory(thisptr, &Game::humanCategory, szGRacedbf);
	Game::GetRaceTypeByRaceCategory(thisptr, &Game::hereticCategory, szGRacedbf);
	Game::GetRaceTypeByRaceCategory(thisptr, &Game::undeadCategory, szGRacedbf);
	Game::GetRaceTypeByRaceCategory(thisptr, &Game::elfCategory, szGRacedbf);
	Game::GetRaceTypeByRaceCategory(thisptr, &Game::greenskinsCategory, szGRacedbf);
}

void __stdcall sub_4EE08F(CDialogInterf* dialogInterface, LRaceCategory *race)
{
	DWORD* v2; // eax@1
	const char *v3; // eax@1
	void *str; // esi@1
	size_t len; // eax@1
	DWORD* v6; // eax@2
	int v7; // eax@3
	char *v8; // eax@13
	char *v9; // eax@14
	InternalString formatString; // [sp+Ch] [bp-1Ch]@1
	int v12; // [sp+10h] [bp-18h]@1
	char *raceString; // [sp+14h] [bp-14h]@1
	int v14; // [sp+18h] [bp-10h]@1
	char *pRace = "TXT_RACE_DESC";
	CTextBoxInterf *raceNameTextBox;
	raceNameTextBox = Game::GetTextBoxFromDlg(dialogInterface, pRace);
	v14 = 0;
	raceString = 0;
	ZeroMemory(&formatString, sizeof(InternalString));
	v12 = 0;
	v2 = Game::GetValueFromTable(&dialogInterface, "X005TA0484");
	v3 = (const char *)Game::GetStringByIndex(v2);
	len = strlen(v3);
	Game::AllocateString(&formatString, v3, len);
	if ( race != NULL )
	{
		if ( race->id == Game::humanCategory.id)
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0480");
		} else if ( race->id == Game::undeadCategory.id )
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0481");
		}
		else if ( race->id == Game::dwarfCategory.id )
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0482");
		}
		else if ( race->id == Game::hereticCategory.id )
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0483");
		} else if (race->id == Game::elfCategory.id)
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X160TA0003");
		} else if (race->id == Game::greenskinsCategory.id)
		{
			v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0895");
		}
	}
	else
	{
		v6 = Game::GetValueFromTable(&dialogInterface, "X005TA0479");
	}
	v8 = (char *)Game::GetStringByIndex(v6);
	Game::ReplaceSubstr(&formatString, "%RACE%", v8);
LABEL_14:
	/*v9 = formatString;
	if ( !raceString )
	{
		if ( !(Game::byte_839137 & 1) )
		{
			Game::byte_839137 |= 1u;
			Game::word_83918C = 0;
		}
		v9 = Game::word_83918C;
	}*/
	Game::SetTextBoxText(raceNameTextBox, formatString.strPtr);
	Game::FreeString(&formatString);
}

FUNC(AddControlsToRaceDialog, 0x004ED9EC, void, __stdcall, (CMenuRace*));
//FUNC(CreateRaceCategoryFromIndex, 0x004EDD34, void, __stdcall, (LRaceCategory*, int));
FUNC(GetMenuPhase, 0x00402DB0, CMenuPhase*, __fastcall, (CMenuRace*));
FUNC(GetPictureFromDialog, 0x0050AFE3, CPictureInterf*, __stdcall, (CMenuPhase*, char *));
FUNC(SetImage, 0x00530DB8, CMenuPhase*, __fastcall, (CPictureInterf*, DWORD, int , SomeStruct*));
FUNC(GetRaceDlgMenuPhase, 0x004F129B, CMenuPhase*, __fastcall, (CMenuRace*));
FUNC(StartMenuAnimation, 0x004EA917, CMenuPhase*, __stdcall, (SomeStruct*, char*));
FUNC(sub_5E357A, 0x005E357A, int, __fastcall, (DWORD*, DWORD, CMenuPhase*));
FUNC(sub_55B7BC, 0x0055B7BC, DWORD, __fastcall, (SomeStruct*, DWORD, DWORD));

const int cMaxMenuPictures = 6;
const int cForward = 1;
const int cBackward = -1;


LRaceCategory* __stdcall CreateRaceCategoryFromIndex(LRaceCategory* outRace, int raceIndex)
{
	//vftable is the same for all races
	outRace->vfTable = Game::humanCategory.vfTable;
	switch (raceIndex)
	{
		case 0:
			outRace->categoryTable = Game::humanCategory.categoryTable;
			outRace->id = Game::humanCategory.id;
			break;
		case 1:
			outRace->categoryTable = Game::greenskinsCategory.categoryTable;
			outRace->id  = Game::greenskinsCategory.id;
			break;
		case 2:
			outRace->categoryTable = Game::hereticCategory.categoryTable;
			outRace->id = Game::hereticCategory.id;
			break;
		case 3:
			outRace->categoryTable = Game::dwarfCategory.categoryTable;
			outRace->id  = Game::dwarfCategory.id;
			break;
		case 4:
			outRace->categoryTable = Game::elfCategory.categoryTable;
			outRace->id  = Game::elfCategory.id;
			break;
		case 5:
			outRace->categoryTable = Game::undeadCategory.categoryTable;
			outRace->id  = Game::undeadCategory.id;
			break;
		default:
			break;
	}
	return outRace;
}


DATA( difficultyLevel, LDifficultyLevel,0x008379B8 );
DATA( lordCategory, LLordCategory,  0x00837748 );
DATA( difficultyTable, CategoryTablesContainer, 0x008379BC );
DATA( lordTable, CategoryTablesContainer, 0x0083774C );
DATA( dword_6EE5F8, DWORD, 0x6EE5F8 );
static DWORD CMenuLord___vftable_ = 0x6DC8CC;

DWORD LordContinueButtonHandler = 0x4E6CDE;
DWORD LordBackButtonHandler = 0x4E66AB;
DWORD LordImportButtonHandler = 0x4E670A;
DWORD LordFaceButtonHandler = 0x4E6945;
DWORD sub_4E68EE = 0x4E68EE;
DWORD sub_4E6918 = 0x4E6918;
DWORD sub_4E71C7 = 0x4E71C7;
DWORD sub_4E73E8 = 0x4E73E8;
DWORD sub_4E74E5 = 0x4E74E5;
DWORD sub_4E75B4 = 0x4E75B4;

FUNC(CMenuBase__CMenuBase, 0x004DAC4F, CMenuLord*,  __fastcall, (CMenuLord*, DWORD , int));
FUNC(InitCategories, 0x004E6180, CMenuCategories*, __fastcall, (CMenuCategories*));
FUNC(GetRaceCategoryFromMenuPhase, 0x005A5BA5, LRaceCategory*, __fastcall, (CMenuPhase *));
FUNC(getResourceByName, 0x005C8CEE, int, __stdcall, (char* dialogInterface));
FUNC(LoadDiscResource, 0x0041B1AD, int, __fastcall, (SomeLordStruct*, DWORD, DWORD));
FUNC(InitDialogFromResourceString, 0x004DADCF, void, __fastcall, (CMenuLord*, DWORD, char*));
FUNC(CreateMenuLordButtonFunctor, 0x004E77ED, int, __stdcall, (int*, DWORD, CMenuLord*, DWORD*));
FUNC(AssignFunctorToButton, 0x005C83A4, int, __stdcall, (CMenuPhase*, char*, char*, int, int));
FUNC(sub_495146, 0x00495146, int, __fastcall, (int*, DWORD, int));
FUNC(sub_4C7CBC, 0x004C7CBC, int, __fastcall, (int*));
FUNC(sub_409C67, 0x00409C67, int, __stdcall, (int*));
FUNC(sub_66936D, 0x0066936D, int, __stdcall, (int*));
FUNC(GetCampaignIdFromMenuPhase, 0x004EB065, int, __fastcall, (CMenuPhase*));
FUNC(sub_669464, 0x00669464, int, __fastcall, (int, int, int));
FUNC(sub_4051F3, 0x004051F3, int, __fastcall, (int*, int, int));
FUNC(sub_668DFC, 0x00668DFC, int, __fastcall, (int));
FUNC(CreateMenuLordRadionFunctor, 0x004E7839, int, __stdcall, (int*, DWORD, CMenuLord*, DWORD*));
FUNC(AssignFunctorToRadio, 0x005C84EA, int, __stdcall, (CMenuPhase*, char*, char*, int));
FUNC(sub_4E5E22, 0x004E5E22, int, __stdcall, (char*));
FUNC(sub_5368AF, 0x005368AF, void, __fastcall, (int*, int, int));
FUNC(sub_4E5DDC, 0x004E5DDC, int, __stdcall, (CMenuCategories*));
FUNC(getTextBoxByName, 0x005C8C54, int, __stdcall, (CMenuPhase*, char*, char*, int, int));
FUNC(sub_4E63BF, 0x004E63BF, int, __fastcall, (int));
FUNC(sub_4E6530, 0x004E6530, int, __fastcall, (int));
FUNC(sub_4E646B, 0x004E646B, int, __fastcall, (int));
FUNC(sub_4E6B6C, 0x004E6B6C, int, __fastcall, (int));
FUNC(sub_4E7885, 0x004E7885, int, __stdcall, (int*, DWORD, CMenuLord*, DWORD*));
FUNC(sub_561299, 0x00561299, int, __stdcall, (int));
FUNC(sub_5614AA, 0x005614AA, int, __fastcall, (int, int, int, int));
FUNC(sub_56181E, 0x0056181E, int, __fastcall, (int, int, int));
FUNC(sub_5617ED, 0x005617ED, int, __fastcall, (int));
FUNC(sub_401943, 0x00401943, int, __fastcall, (int, int, int));
FUNC(sub_4EA157, 0x004EA157, int, __fastcall, (int, int, int*));
FUNC(sub_40F75B, 0x0040F75B, int, __stdcall, (int));
FUNC(sub_4E78D1, 0x004E78D1, int, __stdcall, (CMenuLord*, int));
FUNC(sub_55B1B8, 0x0055B1B8, int, __fastcall, (int,int, char*));
FUNC(sub_4E78F8, 0x004E78F8, int, __stdcall, (CMenuLord*, int));
FUNC(sub_4E791F, 0x004E791F, int, __stdcall, (CMenuLord*, int));
FUNC(sub_4C7DFF, 0x004C7DFF, int, __fastcall, (int));
FUNC(sub_5215FC, 0x005215FC, int, __fastcall, (int, int, int));
FUNC(AllocMemory, 0x00508820, void *, __cdecl, (int));
FUNC(GetStringByIndex, 0x005C7F06, char*, __stdcall, (int));
FUNC(GetTextBoxFromDlg, 0x0050B013, int, __stdcall, (CMenuPhase*, char*));
FUNC(SetTextBoxText, 0x005337B0, int, __fastcall, (int, int, char*));
FUNC(getButton, 0x0050AFB3, int, __stdcall, (CMenuPhase*, char*));


struct someInternalStruct
{
	DWORD v62;
	SomeStruct v63;
	DWORD v64;
	LRaceCategory* raceCategory;
	DWORD v66;
	DWORD v67;
};

struct someInternalStruct2
{
	DWORD val1;
	DWORD val2;
	DWORD val3;
	DWORD val4;
	DWORD val5;
	DWORD val6;
};


char* __stdcall GetRaceToLordAnimationByIndex(int index)
{
    switch (index)
    {
        case 0:
            return "TRANS_GOD2LORD_HU";
        break;
        case 2:
            return "TRANS_GOD2LORD_HE";
        break;
        case 1:
            return "TRANS_GOD2LORD_GR";
        break;
        case 3:
            return "TRANS_GOD2LORD_DW";
        break;
        case 4:
            return "TRANS_GOD2LORD_EL";
        break;
        case 5:
            return "TRANS_GOD2LORD_UN";
        break;
        default:
            return NULL;
        break;
    }
}


FUNC(sub_4E5EFF, 0x004E5EFF, int, __stdcall, (char**, int, int));
FUNC(sub_4EAA42, 0x004EAA42, CMenuPhase*, __stdcall, (SomeStruct*, char*));

char* humanFaces[4] = {"FACE_HU_0", "FACE_HU_1", "FACE_HU_2", "FACE_HU_3"};
char* hereticFaces[4] = {"FACE_HE_0", "FACE_HE_1", "FACE_HE_2", "FACE_HE_3"};
char* dwarfFaces[4] = {"FACE_DW_0", "FACE_DW_1", "FACE_DW_2", "FACE_DW_3"};
char* undeadFaces[4] = {"FACE_UN_0", "FACE_UN_1", "FACE_UN_2", "FACE_UN_3"};
char* elvesFaces[4] = {"FACE_EL_0", "FACE_EL_1", "FACE_EL_2", "FACE_EL_3"};
char*  greenskinsFaces[4] = {"FACE_GR_0", "FACE_GR_1", "FACE_GR_2", "FACE_GR_3"};

int __stdcall sub_4E5E7B(LRaceCategory *raceCategory, int a2)
{
    char **v3 = NULL;
    if (raceCategory->id == Game::humanCategory.id )
    {
        v3 = (char**)humanFaces;
    } else if (raceCategory->id == Game::hereticCategory.id ) 
    {
        v3 = (char**)hereticFaces;
    } else if (raceCategory->id == Game::dwarfCategory.id)
    {
        v3 = (char**)dwarfFaces;
    } else if (raceCategory->id == Game::undeadCategory.id )
    {
        v3 = (char**)undeadFaces;
    } else if (raceCategory->id == Game::elfCategory.id )
    {
        v3 = (char**)elvesFaces;
    }
    else if (raceCategory->id == Game::greenskinsCategory.id )
    {
        v3 = (char**)greenskinsFaces;
    }
    return sub_4E5EFF(v3, 4, a2);
}

int __fastcall LoadNextLeaderFace(CMenuLord *menuLord, DWORD dummy, CMenuPhase *menuPhase, int leaderId, int a4)
{
    char **v3 = NULL;
    SomeStruct someStruct;
    LRaceCategory *raceCategory = GetRaceCategoryFromMenuPhase(menuPhase);
    if (raceCategory->id == Game::humanCategory.id )
    {
        v3 = (char**)humanFaces;
    } else if (raceCategory->id == Game::hereticCategory.id ) 
    {
        v3 = (char**)hereticFaces;
    } else if (raceCategory->id == Game::dwarfCategory.id)
    {
        v3 = (char**)dwarfFaces;
    } else if (raceCategory->id == Game::undeadCategory.id )
    {
        v3 = (char**)undeadFaces;
    } else if (raceCategory->id == Game::elfCategory.id )
    {
        v3 = (char**)elvesFaces;
    }
    else if (raceCategory->id == Game::greenskinsCategory.id )
    {
        v3 = (char**)greenskinsFaces;
    }
    CMenuPhase* v6 = sub_4EAA42(&someStruct, v3[leaderId]);
    sub_5E357A((DWORD*)a4, 0, (CMenuPhase*)v6);
    sub_55B7BC(&someStruct, 0, 0);  
    return sub_5E357A((DWORD*)(a4 + 8), 0, (CMenuPhase *)a4);
}


//C000CC0001 => 40130001
DATA(HumanCampaignId3, DWORD, 0x838B30);
//C000CC0005 => 40130005
DATA(UndeadCampaignId, DWORD, 0x00838B10);
//C000CC0002 => 40130002
DATA(HumanCampaignId, DWORD, 0x00838B20);
//C000CC0003 => 40130003
DATA(DwarfCampaignId, DWORD, 0x00838B28);
//C000CC0004 => 40130004
DATA(HereticCampaignId, DWORD, 0x00838B18);
//C000CC0006 => 40130006
DATA(ElfCampaignId, DWORD, 0x00838B44);
// => 0x3f0000
DATA(NullCampaignId, DWORD, 0x6E7618);

bool __stdcall IsValidCampaignInPhase(CMenuPhase *menuPhase)
{
  int campaignId;
  DWORD *pCampaignId = (DWORD*)GetCampaignIdFromMenuPhase(menuPhase);
  campaignId = pCampaignId[0];
  return campaignId != HumanCampaignId3
      && campaignId != HumanCampaignId
      && campaignId != DwarfCampaignId
      && campaignId != HereticCampaignId
      && campaignId != UndeadCampaignId
      && campaignId != ElfCampaignId
      && campaignId != Game::GreenSkinsCampaignId;
}


void *__fastcall CMenuLord__CMenuLord(CMenuLord *menuLord, DWORD dummy, int a2)
{
	someInternalStruct2 intStr;
	CMenuCategories *v2; // ecx@1
	CMenuLord *v3; // esi@1
	LLordCategory* v4; // eax@2
	LDifficultyLevel v5; // eax@4
	int someDword;
	int v6; // eax@6
	int v7; // eax@8
	char *backgroundPictureName; // edi@8
	CMenuPhase *v9; // eax@8
	int v10; // eax@8
	int v11; // edi@18
	int v12; // eax@18
	int v13; // eax@18
	char *v14; // ST10_4@18
	char *v15; // ST0C_4@18
	int v16; // eax@18
	int v17; // eax@18
	int v18; // ST0C_4@18
	int v19; // ST08_4@18
	char *v20; // ST04_4@18
	int v21; // eax@18
	int v22; // ST0C_4@18
	int v23; // ST08_4@18
	char *v24; // ST04_4@18
	int v25; // eax@18
	CMenuPhase *v26; // eax@18
	int v27; // eax@18
	int v28; // ST0C_4@20
	int v29; // ST08_4@20
	char *v30; // ST04_4@20
	int v31; // eax@20
	char *v32; // ST10_4@21
	int v33; // eax@21
	int v34; // eax@21
	int v35; // eax@22
	int v36; // ST10_4@22
	int v37; // ST0C_4@22
	char *v38; // ST08_4@22
	int v39; // eax@22
	int v40; // eax@22
	int v41; // ST10_4@22
	int v42; // ST0C_4@22
	char *v43; // ST08_4@22
	int v44; // eax@22
	int v45; // eax@22
	int v46; // ST0C_4@22
	int v47; // ST08_4@22
	char *v48; // ST04_4@22
	int v49; // eax@22
	int v50; // ST10_4@22
	int v51; // ST08_4@22
	char *v52; // ST04_4@22
	int v53; // eax@22
	int v54; // edi@22
	int v55; // eax@22
	int v56; // ST10_4@23
	char *v57; // eax@24
	char *v58; // eax@24
	char *v59; // eax@24
	CMenuPhase* v60; // eax@24
	someInternalStruct v62; // [sp+Ch] [bp-58h]@22
	SomeStruct v63; // [sp+24h] [bp-40h]@18
	int v64; // [sp+28h] [bp-3Ch]@26
	LRaceCategory *raceCategory; // [sp+34h] [bp-30h]@8
	int v66; // [sp+38h] [bp-2Ch]@8
	int v67; // [sp+3Ch] [bp-28h]@8
	someInternalStruct2 v68; // [sp+40h] [bp-24h]@22
	SomeStruct v69; // [sp+48h] [bp-1Ch]@18
	int v71; // [sp+54h] [bp-10h]@22

	v3 = menuLord;
	CMenuBase__CMenuBase(menuLord, 0, a2);
	v2 = (CMenuCategories*)AllocMemory(144);
	menuLord->categories = InitCategories(v2);

	menuLord->vftable = CMenuLord___vftable_;
	if ((DWORD)&menuLord->categories->levelCategory != (DWORD)&difficultyLevel )
	{
		menuLord->categories->levelCategory.table = (LDifficultyLevelTable *)difficultyTable.table;
		menuLord->categories->levelCategory.count = difficultyTable.count;
	}
	if ((DWORD)&menuLord->categories->lordCategory != (DWORD)&lordCategory )
	{
		menuLord->categories->lordCategory.table = (LLordCategoryTable*)lordTable.table;
		menuLord->categories->lordCategory.count = lordTable.count;
	}
	v9 = GetRaceDlgMenuPhase((CMenuRace*)menuLord);
	raceCategory = GetRaceCategoryFromMenuPhase(v9);
	if (raceCategory->id == Game::humanCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_HUMAN_BG";
	}
	else if ( raceCategory->id == Game::hereticCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_HERETIC_BG";
	}
	else if ( raceCategory->id == Game::undeadCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_UNDEAD_BG";
	} 
	else if ( raceCategory->id == Game::dwarfCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_DWARF_BG";
	}
	else if ( raceCategory->id == Game::elfCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_ELF_BG";
	}
    else if (raceCategory->id == Game::greenskinsCategory.id)
	{
		backgroundPictureName = "DLG_CHOOSE_LORD_ELF_BG";
	}

	v12 = getResourceByName(backgroundPictureName);
	LoadDiscResource(&menuLord->categories->lordStruct, 0, v12);
	InitDialogFromResourceString(menuLord, 0, "DLG_CHOOSE_LORD");
	sub_4E5E7B(raceCategory, (DWORD)&menuLord->categories->someDword6);
    v13 = Game::GetValueIndexFromTable((CMenuCategories*)&someDword, 0, "X005TA0830");
	v14 = GetStringByIndex(v13);
	CMenuPhase *menuPhase = GetMenuPhase((CMenuRace*)menuLord);
	v17 = GetTextBoxFromDlg(menuPhase, "TXT_TITLE");
	SetTextBoxText(v17, 0, v14);
	v18 = CreateMenuLordButtonFunctor((int*)&v69, 05, menuLord, &LordContinueButtonHandler);
	AssignFunctorToButton(menuPhase, "BTN_CONTINUE", "DLG_CHOOSE_LORD", v18, 0);
	sub_495146((int*)&v69, 0, 0);
	v22 = CreateMenuLordButtonFunctor((int*)&v69, 0, menuLord, &LordBackButtonHandler);
	AssignFunctorToButton(menuPhase, "BTN_BACK", "DLG_CHOOSE_LORD", v22, 0);
	sub_495146((int*)&v69, 0, 0);
	sub_4C7CBC((int*)&intStr);
	sub_409C67((int*)&intStr);
	sub_66936D((int*)&v69);
	v26 = GetRaceDlgMenuPhase((CMenuRace*) menuLord);
	v27 = GetCampaignIdFromMenuPhase(v26);
	v11 = sub_669464((int)v69.val2, 0, v27);
	sub_4051F3((int*)&v69, 0, 0);
	if ( intStr.val1 != 0 && (unsigned __int8)sub_668DFC(v11) )
	{
		v28 = CreateMenuLordButtonFunctor((int*)&v69, 0, menuLord, &LordImportButtonHandler);
		AssignFunctorToButton(menuPhase, "BTN_IMPORT_LEADER", "DLG_CHOOSE_LORD", v28, 0);
		sub_495146((int*)&v69, 0, 0);
	}
	else
	{
		v34 = getButton(menuPhase, "BTN_IMPORT_LEADER");
//		(*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v34 + 160))(v34, 0);
	}
	
	v36 = CreateMenuLordRadionFunctor((int*)&v69, 0, menuLord, &sub_4E6918);
	int radioFunctor = AssignFunctorToRadio(menuPhase, "RAD_DIFF", "DLG_CHOOSE_LORD", v36);
	sub_495146((int*)&v69, 0, 0);
	v40 = sub_4E5E22((char*)&menuLord->categories->levelCategory);
	sub_5368AF((int*)radioFunctor, 0, v40);
	v41 = CreateMenuLordRadionFunctor((int*)&v69, 0, menuLord, &sub_4E68EE);
	radioFunctor = AssignFunctorToRadio(menuPhase, "RAD_LORD", "DLG_CHOOSE_LORD", v41);
	sub_495146((int*)&v69, 0, 0);
	v45 = sub_4E5DDC(menuLord->categories);
	sub_5368AF((int*)radioFunctor, 0, v45);
	v46 = CreateMenuLordButtonFunctor((int*)&v69, 0, menuLord, &LordFaceButtonHandler);
	AssignFunctorToButton(menuPhase, "BTN_FACE", "DLG_CHOOSE_LORD", v46, 0);
	sub_495146((int*)&v69, 0, 0);
	getTextBoxByName(menuPhase, "EDIT_LORD_NAME", "DLG_CHOOSE_LORD", 1, dword_6EE5F8);
	sub_4E63BF((int)menuLord);
	sub_4E6530((int)menuLord);
	sub_4E646B((int)menuLord);
	sub_4E6B6C((int)menuLord);
	v54 = sub_4E7885((int*)&v68, 0, menuLord, &sub_4E71C7);
	DWORD* v80 = (DWORD*)sub_561299((int)&v69);
	v55 = sub_5614AA(v80[1], 0, (int)&v62, v54);
	sub_56181E((int)&menuLord->categories->dummy1, 0, v55);
	sub_5617ED((int)&v62);
	sub_401943((int)&v69, 0, 0);
	sub_495146((int*)&v68, 0, 0);
	v71 = 0;
	GetRaceDlgMenuPhase((CMenuRace*)menuLord);
	sub_4EA157((int)v26, 0, &v71);
	v36 = menuLord->categories->someDword5;
	if ( v71 != menuLord->categories->someDword5 )
	{
		menuLord->categories->someDword5 = v71;
		sub_40F75B(v36);
	}
	v57 = (char *)sub_4E78D1(menuLord, sub_4E73E8);
	sub_55B1B8((int)menuLord->categories->someDword5, 0, v57);
	v58 = (char *)sub_4E78F8(menuLord, sub_4E74E5);
	sub_55B1B8((int)menuLord->categories->someDword5, 0, v58);
	v59 = (char *)sub_4E791F(menuLord, sub_4E75B4);
	sub_55B1B8((int)menuLord->categories->someDword5, 0, v59);
	v60 = GetRaceDlgMenuPhase((CMenuRace*)menuLord);
	if (IsValidCampaignInPhase(v60))
    {
		menuLord->categories->someDword7 = 1;
    }
	sub_4C7DFF((int)&intStr);
	sub_5215FC((int)&intStr, 0, (int)intStr.val2);
	return menuLord;
}

FUNC(sub_4EAEAE, 0x004EAEAE, void, __fastcall, (CMenuPhase*, DWORD, int));
FUNC(sub_4EAEBB, 0x004EAEBB, void, __fastcall, (CMenuPhase*, DWORD, LRaceCategory*));
FUNC(sub_4EAF55, 0x004EAF55, void, __fastcall, (CMenuPhase*, DWORD, int));
FUNC(sub_4EE7A0, 0x004EE7A0, int, __fastcall, (CMenuRace*, DWORD, int));




int __fastcall sub_4EE685(CMenuRace *menuRaceCampain, DWORD dummy, LRaceCategory *raceCategory)
{
    int v2; // eax@1
    int v3; // ecx@1
    void *v4; // edi@1
    int v5; // esi@1
    int v7; // [sp-Ch] [bp-1Ch]@1
    void *v8; // [sp+0h] [bp-10h]@1
    DWORD someDword;
    CMenuPhase *phase;

    phase = GetRaceDlgMenuPhase(menuRaceCampain);
    sub_4EAEAE(phase, 0, 1);
    phase = GetRaceDlgMenuPhase(menuRaceCampain);
    sub_4EAEBB(phase, 0, raceCategory);
    phase = GetRaceDlgMenuPhase(menuRaceCampain);
    sub_4EAF55(phase, 0, 1);
    v3 = NullCampaignId;
    if (raceCategory->id == Game::undeadCategory.id)
    {
        v3 = UndeadCampaignId;
    }
    else if (raceCategory->id == Game::humanCategory.id)
    {
        v3 = HumanCampaignId;
    }
    else if (raceCategory->id == Game::dwarfCategory.id)
    {
        v3 = DwarfCampaignId;
    } else if (raceCategory->id == Game::hereticCategory.id)
    {
        v3 = HereticCampaignId;
    } else if (raceCategory->id == Game::elfCategory.id)
    {
        v3 = ElfCampaignId;
    } else if (raceCategory->id == Game::greenskinsCategory.id)    
    {
        v3 = Game::GreenSkinsCampaignId;
    }
    return sub_4EE7A0(menuRaceCampain, 0, v3);
}



char* GetAnimationNameByIndex(LRaceCategory *race, char direction)
{
	if (direction == cBackward)
	{
		if (race->id == Game::elfCategory.id)
			return "GOD_DW2EL";
		if (race->id == Game::dwarfCategory.id)
			return "GOD_HE2DW";
		if (race->id == Game::humanCategory.id)
			return "GOD_UN2HU";
		if (race->id == Game::undeadCategory.id)
			return "GOD_EL2UN";
		if (race->id == Game::hereticCategory.id)
			return "GOD_GR2HE";
		if (race->id == Game::greenskinsCategory.id)
			return "GOD_HU2GR";
	}
	else
	{
		if (race->id == Game::elfCategory.id)
			return "GOD_UN2EL";
		if (race->id == Game::dwarfCategory.id)
			return "GOD_EL2DW";
		if (race->id == Game::humanCategory.id)
			return "GOD_GR2HU";
		if (race->id == Game::undeadCategory.id)
			return "GOD_HU2UN";
		if (race->id == Game::hereticCategory.id)
			return "GOD_DW2HE";
		if (race->id == Game::greenskinsCategory.id)
			return "GOD_HE2GR";
		return 0;
	}
	return 0;
}

char *__stdcall GetCampaignPictureByIndex(LRaceCategory *category)
{
	char *result;
	if(category->id == Game::undeadCategory.id)	{
		result = "DLG_CHOOSE_RACE_GODUN_BG";
	} else if(category->id == Game::humanCategory.id) {
		result = "DLG_CHOOSE_RACE_GODHU_BG";
	} else if (category->id == Game::hereticCategory.id) {
		result = "DLG_CHOOSE_RACE_GODHE_BG";
	} else if (category->id == Game::dwarfCategory.id) {
		result = "DLG_CHOOSE_RACE_GODDW_BG";
	} else if (category->id == Game::elfCategory.id) {
		result = "DLG_CHOOSE_RACE_GODEL_BG";
	} else if (category->id == Game::greenskinsCategory.id) {
		result = "DLG_CHOOSE_RACE_GODGS_BG";
	} else {
		result = "";
	}
	return result;
}


int ChangePicture(CMenuRace *v1, int increment, int direction)
{
	DWORD dummyDWORD = 0;
	int v2; // eax@1
	int v4; // eax@3
	char *v5; // ST04_4@3
	CMenuPhase *v6; // eax@3
	char *v7; // ST04_4@3
	CMenuPhase *v8; // eax@3
	char *v9; // ST0C_4@3
	CMenuPhase *v10; // eax@3
	LRaceCategory v11; // [sp+8h] [bp-20h]@3
	SomeStruct v12; // [sp+14h] [bp-14h]@3
	char* fireFlyImg = "IMG_FIREFLY";
	char* waterImg = "IMG_WATER";
	CPictureInterf *picture;
	AddControlsToRaceDialog(v1);
	v1->race->someByte1 = 1;
	v1->race->raceIndex += increment;
	v1->race->raceIndex %= cMaxMenuPictures;
	if (v1->race->raceIndex < 0)
	{
		v1->race->raceIndex = cMaxMenuPictures - 1;
	}
	CreateRaceCategoryFromIndex(&v11, v1->race->raceIndex);
	v1->race->slideDirection = direction;
	ZeroMemory(&v12, 8);
	v6 = GetMenuPhase(v1);
	picture = GetPictureFromDialog(v6, waterImg);
	SetImage(picture, dummyDWORD, 0, &v12);
	ZeroMemory(&v12, 8);
	v8 = GetMenuPhase(v1);
	GetPictureFromDialog(v8, fireFlyImg);
	SetImage(picture, dummyDWORD, 0, &v12);
	v9 = GetAnimationNameByIndex(&v11, v1->race->slideDirection);
	GetRaceDlgMenuPhase(v1);
	v10 = StartMenuAnimation(&v12, v9);
	sub_5E357A(&v1->race->dummy1, dummyDWORD, v10);
	return sub_55B7BC(&v12, dummyDWORD, 0);
}

int __fastcall sub_4EE217(CMenuRace *v1)
{
	return ChangePicture(v1, cBackward, 1);
}

int __fastcall sub_4EE3F4(CMenuRace *v1)
{
	return ChangePicture(v1, cForward, -1);
}



/*
//----- (004ED819) --------------------------------------------------------
__declspec(dllexport) int __stdcall sub_004ED819(DWORD a1, DWORD a2)
{
	int v2; // eax@1
	int v3; // ecx@1
	bool v4; // zf@2
	int v5; // eax@6
	int v6; // ecx@6
	bool v7; // zf@7
	int v8; // edi@11
	int v9; // eax@11
	bool v10; // cl@11
	int v11; // edi@15
	int v12; // eax@15
	bool v13; // cl@15
	int v14; // edi@19
	int result; // eax@19
	bool v16; // cl@19
	DWORD v17; // [sp-1Ch] [bp-44h]@1
	int v18; // [sp-18h] [bp-40h]@1
	int v19; // [sp-14h] [bp-3Ch]@1
	int v20; // [sp-10h] [bp-38h]@1
	int v21; // [sp-Ch] [bp-34h]@1
	int v22; // [sp-8h] [bp-30h]@1 sc.UnknownB
	int v23; // [sp-4h] [bp-2Ch]@1 sc.UnknownA
	char v24; // [sp+Ch] [bp-1Ch]@5
	DWORD v25; // [sp+10h] [bp-18h]@1
	char v26; // [sp+1Ch] [bp-Ch]@1
	int v27; // [sp+20h] [bp-8h]@3
	int v28; // [sp+24h] [bp-4h]@2


	struct1_004ED819* sc;

	Game::sub_0042434A(a1);

	LRaceCategory * RaceRef[]= {&Game::humanCategory};


	for ( int i=0;i<1;i++ ) {
		//v23 = (DWORD)&Game::human;
		Game::sub_00567F02((DWORD)&v26, *( DWORD *)(a2 + 4));
		Game::sub_0040B43F(a2, (DWORD)&v20);
		Game::sub_004C7E28(a2, &a1);
		result = Game::sub_004EE899(v25, &v17, v18, v19, v20, v21, v22, RaceRef[i]);
		v3 = *( DWORD *)(result + 8);

		if  ( v3 )
			v4 = v3 == v28;
		else
			v4 = *(DWORD *)(result + 4) == v27;
		if ( v4 )
			result = Game::sub_004241E7(a1, &v24, RaceRef[i]);

	}
	//sub_42434A(a1);
	//  sub_567F02((int)&ch8_struct2.field6, *(_DWORD *)(a2 + 4));
	//  v23 = (int)&unk_8372C0;
	//  sub_40B43F(a2, (int)&v20);
	//  sub_4C7E28(a2, (int)&v17);
	//  v2 = sub_4EE899(&ch8_struct2.field18, v17, v18, v19, v20, v21, v22, v23);
	//  v3 = *(_DWORD *)(v2 + 8);
	//  if ( v3 )
	//    v4 = v3 == ch8_struct2.field1;
	//  else
	//    v4 = *(_DWORD *)(v2 + 4) == ch8_struct2.field2;
	//  if ( v4 )
	//    sub_4241E7(a1, (int)&ch8_struct2.field22, (int)&unk_8372C0);
	//  v23 = *(_DWORD *)(a2 + 4);
	//  sub_567F02((int)&ch8_struct2.field6, v23);
	//  v23 = (int)&unk_837290;
	//  sub_40B43F(a2, (int)&v20);
	//  sub_4C7E28(a2, (int)&v17);
	//  v5 = sub_4EE899(&ch8_struct2.field18, v17, v18, v19, v20, v21, v22, v23);
	//  v6 = *(_DWORD *)(v5 + 8);
	//  if ( v6 )
	//    v7 = v6 == ch8_struct2.field1;
	//  else
	//    v7 = *(_DWORD *)(v5 + 4) == ch8_struct2.field2;
	//  if ( v7 )
	//    sub_4241E7(a1, (int)&ch8_struct2.field22, (int)&unk_837290);
	//  v8 = *(_DWORD *)(a2 + 4);
	//  v23 = (int)&unk_8372D0;
	//  sub_40B43F(a2, (int)&v20);
	//  sub_4C7E28(a2, (int)&v17);
	//  v9 = sub_4EE899(&ch8_struct2.field18, v17, v18, v19, v20, v21, v22, v23);
	//  v10 = 0;
	//  if ( !*(_DWORD *)(v9 + 8) )
	//    v10 = *(_DWORD *)(v9 + 4) == v8;
	//  if ( v10 )
	//    sub_4241E7(a1, (int)&ch8_struct2.field22, (int)&unk_8372D0);
	//  v11 = *(_DWORD *)(a2 + 4);
	//  v23 = (int)&unk_8372E0;
	//  sub_40B43F(a2, (int)&v20);
	//  sub_4C7E28(a2, (int)&v17);
	//  v12 = sub_4EE899(&ch8_struct2.field18, v17, v18, v19, v20, v21, v22, v23);
	//  v13 = 0;
	//  if ( !*(_DWORD *)(v12 + 8) )
	//    v13 = *(_DWORD *)(v12 + 4) == v11;
	//  if ( v13 )
	//    sub_4241E7(a1, (int)&ch8_struct2.field22, (int)&unk_8372E0);
	//  v14 = *(_DWORD *)(a2 + 4);
	//  v23 = (int)&unk_8372A0;
	//  sub_40B43F(a2, (int)&v20);
	//  sub_4C7E28(a2, (int)&v17);
	//  result = sub_4EE899(&ch8_struct2.field18, v17, v18, v19, v20, v21, v22, v23);
	//  v16 = 0;
	//  if ( !*(_DWORD *)(result + 8) )
	//    v16 = *(_DWORD *)(result + 4) == v14;
	//  if ( v16 )
	//    result = sub_4241E7(a1, (int)&ch8_struct2.field22, (int)&unk_8372A0);
	return result;
}

*/




//Function for 4ED819 - Looks as if this is a race selection function
FUNC(sub_42434A, 0x0042434A, DWORD, __fastcall, ( DWORD ) );
FUNC(sub_567F02, 0x00567F02, DWORD, __fastcall, ( RacesStruct*, DWORD, RacesList*));
FUNC(sub_40B43F, 0x0040B43F, DWORD, __fastcall, ( RacesStruct*, DWORD, RacesStruct*) );
FUNC(sub_4C7E28, 0x004C7E28, DWORD, __fastcall, ( RacesStruct*, DWORD, RacesStruct*) );
FUNC(sub_4EE899, 0x004EE899, RacesStruct*, __stdcall, ( RacesStruct*, RacesStruct, RacesStruct, LRaceCategory*) );
FUNC(sub_4241E7, 0x004241E7, DWORD, __fastcall, (DWORD, DWORD, Some16Struct*,  LRaceCategory* ) );

FUNC(sub_42413B, 0x0042413B, void, __fastcall, (Some16Struct*, DWORD));
FUNC(sub_42BF66, 0x0042BF66, void, __fastcall, (Some16Struct*, DWORD, LRaceCategory*));
FUNC(sub_42BEA5, 0x0042BEA5, void, __fastcall, (RacesStruct*, DWORD, Some16Struct*));
FUNC(sub_40A22B, 0x0040A22B, void, __fastcall, (Some16Struct*));



RacesStruct* __stdcall sub_4EB764(RacesStruct *a1)
{
  Some16Struct v2; // [sp+4h] [bp-20h]@1
  __asm
  {
      push esi
      lea ecx, v2
      call sub_42413B
      pop esi
  }
  //sub_42413B(&v2);
  sub_42BF66(&v2, 0, &Game::humanCategory);
  sub_42BF66(&v2, 0, &Game::humanCategory);
  sub_42BF66(&v2, 0, &Game::dwarfCategory);
  sub_42BF66(&v2, 0, &Game::undeadCategory);
  sub_42BF66(&v2, 0, &Game::elfCategory);
  sub_42BF66(&v2, 0, &Game::greenskinsCategory);
  sub_42BEA5(a1, 0, &v2);
  sub_40A22B(&v2);
  sub_5215FC((int)&v2, 0, v2.m4);
  return a1;
}
/*

int __stdcall sub_5C636C(int a1)
{
  int v1; // eax@1
  int result; // eax@2
  char v3; // zf@14

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 == dword_8382C0 )
    return (int)"HUMAN";
  if ( v1 == dword_8382E8 )
    return (int)"HERETIC";
  if ( v1 == dword_8382B0 )
    return (int)"DWARF";
  if ( v1 == dword_8382D0 )
    return (int)"UNDEAD";
  if ( v1 == dword_838290 )
    goto LABEL_18;
  if ( v1 == dword_8382A0 )
    return (int)"DRAGON";
  if ( v1 == dword_838280 )
    return (int)"GHOST";
  v3 = v1 == dword_838270;
  result = (int)"ELF";
  if ( !v3 )
LABEL_18:
    result = (int)"NEUTRAL";
  return result;
}

*/
void _stdcall ProcessRaceList(int a1, RacesStruct *a2, LRaceCategory* race, Some16Struct *result)
{
  RacesStruct races25;
  RacesStruct races2628;
  RacesStruct races1719;
  RacesStruct races2022;
  RacesStruct *v2; // eax@1
  char v4; // zf@2

  sub_567F02(&races2628, 0, a2->races);
  sub_40B43F(a2, 0, &races2022);
  sub_4C7E28(a2, 0, &races1719);
  v2 = sub_4EE899(&races25, races1719, races2022, race);
  if (v2->someDword != 0)
      v4 = (v2->someDword == races2628.someDword);
  else
      v4 = (v2->races == races2628.races);
  if (v4 != 0)
    sub_4241E7(a1, 0, result, race);
}


FUNC(sub_5F0D08, 0x005F0D08, int, __stdcall, (int, int, LRaceCategory*, char*));


int __stdcall sub_5F0DA9(int a1, int a2)
{
  Some16Struct someStruct; // [sp+8h] [bp-10h]@3
  typedef bool(__fastcall *pt2Func)(DWORD, DWORD, char *);
  pt2Func getSomeFlag = (pt2Func)(((DWORD***)a1)[0][0][8]);
  if (getSomeFlag(a1, 0, "VERHUMAN"))
  {
    sub_5F0D08(a1, a2, &Game::humanCategory, "VERHUMAN");
    sub_5F0D08(a1, a2, &Game::dwarfCategory, "VERDWARF");
    sub_5F0D08(a1, a2, &Game::undeadCategory, "VERUNDEAD");
    sub_5F0D08(a1, a2, &Game::hereticCategory, "VERHERETIC");
    sub_5F0D08(a1, a2, &Game::neutralCategory, "VERNEUTRAL");
    sub_5F0D08(a1, a2, &Game::greenskinsCategory, "VERGREENS");
    return sub_5F0D08(a1, a2, &Game::elfCategory, "VERELF");
  }
 /* else
  {
      sub_4241E7(a2, 0, &someStruct, &Game::humanCategory);
      sub_4241E7(a2, 0, &someStruct, &Game::dwarfCategory);
      sub_4241E7(a2, 0, &someStruct, &Game::undeadCategory);
      sub_4241E7(a2, 0, &someStruct, &Game::hereticCategory);
      sub_4241E7(a2, 0, &someStruct, &Game::neutralCategory);
      return sub_4241E7(a2, 0, &someStruct, &Game::elfCategory);
  }*/
}


int __stdcall sub_5F0C93(int a1, int a2)
{
  sub_5F0D08(a1, a2, &Game::humanCategory, "HUMAN");
  sub_5F0D08(a1, a2, &Game::dwarfCategory, "DWARF");
  sub_5F0D08(a1, a2, &Game::greenskinsCategory, "GREEN_SKIN");
  sub_5F0D08(a1, a2, &Game::hereticCategory, "HERETIC");
  sub_5F0D08(a1, a2, &Game::neutralCategory, "NEUTRAL");
  return sub_5F0D08(a1, a2, &Game::elfCategory, "ELF");
}


Some16Struct* __stdcall sub_4ED819(int a1, RacesStruct *a2)
{
  Some16Struct v24; // [sp+Ch] [bp-1Ch]@5
  sub_42434A(a1);
  ProcessRaceList(a1, a2, &Game::humanCategory, &v24);
  ProcessRaceList(a1, a2, &Game::undeadCategory, &v24);
  ProcessRaceList(a1, a2, &Game::hereticCategory, &v24);
  ProcessRaceList(a1, a2, &Game::dwarfCategory, &v24);
  ProcessRaceList(a1, a2, &Game::elfCategory, &v24);
  ProcessRaceList(a1, a2, &Game::greenskinsCategory, &v24);
  return &v24;
}


/*

DWORD dword_6E7250[4] = {1, 3, 2, 4};
DWORD dword_6E7240[4] = {0, 1, 4, 6};
DWORD dword_6E7618 = 0x3F0000;
DWORD unk_6E7440 = 0x00000000;
unsigned char byte_6E7260[4] = {0x47, 0x43, 0x53, 0x58};

char __stdcall getSubStr(char *Dest, char* a2, signed int a3)
{
  if ( a3 < 0 || a3 > 3 )
  {
    return 0;
  }
  else
  {
    Dest[0] = 0;
    int size = dword_6E7250[a3];
    int offset = dword_6E7240[a3];
    Dest[size] = 0;
    strncpy(Dest, &a2[offset], size);
    return 1;
  }
}

char __stdcall sub_57F699(int a1, char* a2)
{
  int v2; // eax@1
  char v3; // sf@2
  char v4; // of@2

  v2 = *(_DWORD *)(a1 + 4);
  if ( *(_BYTE *)v2 == *(_BYTE *)a2 )
  {
    v4 = 0;
    v3 = *(_BYTE *)(v2 + 1) - (signed int)*(_BYTE *)(a2 + 1) < 0;
  }
  else
  {
    v4 = 0;
    v3 = *(_BYTE *)v2 - (signed int)*(_BYTE *)a2 < 0;
  }
  return v3 ^ v4;
}



int __stdcall sub_57F646(int a1, int a2, char* a3, char np, int np1, int np2)
{
  int v6; // edi@1

  v6 = (a2 - a1) >> 3;
  while ( v6 > 0 )
  {
    if ( (unsigned __int8)sub_57F699(a1 + 8 * v6 / 2, a3) )
    {
      a1 += 8 * v6 / 2 + 8;
      v6 += -1 - v6 / 2;
    }
    else
    {
      v6 /= 2;
    }
  }
  return a1;
}


char __stdcall sub_57F161(const char *Str2, char* a2)
{
  int v3; // eax@1
  int v4; // edi@1
  char result; // al@3

  v3 = sub_57F646((int)&unk_6E7440, (int)&dword_6E7618, (int)&Str2, (char)Str2, 0, 0);
  v4 = v3;
  if (v3 == dword_6E7618 || strcmp(*(const char **)(v3 + 4), Str2) )
  {
    result = 0;
  }
  else
  {
    *(_DWORD *)a2 = *(_DWORD *)v4;
    result = 1;
  }
  return result;
}


//TA
signed int __stdcall sub_57F11F(char *a1)
{
  signed int result; // eax@5
  char Str2[3]; // [sp+0h] [bp-Ch]@1

  getSubStr(Str2, a1, 2);
  if (Str2[0] && Str2[1] && !Str2[2] && (unsigned __int8)sub_57F161(Str2, a1))
    return (int)a1;
  else
    return 0x3B;
}

//005
int __stdcall sub_57F0D8(char *a1)
{
  int result; // eax@2
  char Dest; // [sp+4h] [bp-Ch]@1

  getSubStr(&Dest, a1, 1);
  result = atoi(&Dest);
  if ( strlen(&Dest) != 4 || (result < 0) || (result > 255) )
    result = 0x100;
  return result;
}

//X
signed int __stdcall sub_57F044(char *a1)
{
  signed int result; // eax@1
  signed int v2; // ecx@2
  char Dest; // [sp+4h] [bp-Ch]@1

  getSubStr(&Dest, a1, 0);
  result = 4;
  if ( strlen(&Dest) == 2 )
  {
    v2 = 0;
    while ( Dest != byte_6E7260[v2] )
    {
      ++v2;
      if ( v2 >= 4 )
        return result;
    }
    result = v2;
  }
  return result;
} 

//X005TA0000

void *__fastcall GetValueIndexFromTable(DWORD *result, DWORD dummy, char* keyString)
{
  char *v2; // eax@1
  signed int v3; // ecx@1
  int v5; // esi@1
  int i; // ecx@5
  char *v7; // edi@5
  unsigned int v8; // ecx@5
  int v9; // eax@8
  signed int v10; // edi@8
  signed int v11; // esi@8
  void *v12; // eax@16
  char EndPtr[4]; // [sp+Ch] [bp-Ch]@1
  char v15; // [sp+10h] [bp-8h]@8
  char v16; // [sp+11h] [bp-7h]@8
  char v17; // [sp+16h] [bp-2h]@8

  char keyCopy[0xB];

  v5 = 0;
  *result = 0x3F0000;

  strcpy(keyCopy, keyString);
  v5 = strlen(keyString);

  if ( v5 != 10 )
  {
    v8 = (unsigned int)(10 - v5);
    memset(&EndPtr[v5], 0x20202020, v8);
    v7 = &EndPtr[v8] + v5;
    for ( i = (10 - (byte)v5) & 3; i; --i )
      *v7++ = 32;
  }

  v17 = 0;
  keyCopy[0] = toupper(keyCopy[0]);
  keyCopy[4] = toupper(keyCopy[4]);
  keyCopy[5] = toupper(keyCopy[5]);
  v11 = sub_57F044(EndPtr);
  v10 = sub_57F0D8(EndPtr);
  a2 = sub_57F11F(EndPtr);
  v9 = sub_57F1A7(EndPtr);
  if ( v11 < 0 || v11 >= 4 || a2 < 0 || a2 >= 59 || v10 < 0 || v10 > 255 || v9 < 0 || v9 > 65535 )
  {
    *result = 0x3F0000;
  }
  else
  {
    v12 = (void *)sub_57F2B2(&a2, v11, v10, a2, v9);
    if ( v4 != v12 )
      *result = *(_DWORD *)v12;
  }
  return result;
}*/
/*
struct TreeLeaf
{
    TreeLeaf *m1;
    DWORD m2;
    LRaceCategory *race;
};

struct TreeStruct
{
    DWORD m1;
    TreeLeaf *category;
    LRaceCategory *m3;
};

TreeStruct* __fastcall getNextListElement(TreeStruct *tree)
{
  if (tree->m3 != NULL){}      //tree->m3 = tree->m3->ta;
  else
    tree->category = tree->category->m1;
  return tree;
}


TreeStruct *__stdcall sub_4EE899(TreeStruct *a1, TreeStruct tree, int a5, TreeLeaf *a6, LRaceCategory *a7, LRaceCategory* targetRace)
{
  int v8; // ecx@1
  int v9; // esi@1
  char v10; // zf@2
  LRaceCategory* v11; // eax@5
  TreeStruct * result; // eax@9

  while ( 1 )
  {
    v10 = tree.m3 ? tree.m3 == a7 : tree.category == a6;
    if ( v10 )
      break;
    v11 = tree.m3;
    if (!tree.m3)
        v11 = tree.category->race;
    if (v11->id == targetRace->id)
      break;
    getNextListElement(&tree);
  }
  result = a1;
  a1->m1 = 0;
  a1->category = tree.category;
  a1->m3 = tree.m3;
  return result;
}
*/

