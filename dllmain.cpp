// dllmain.cpp : Defines the entry point for the DLL application.

#include "stdafx.h"
#include "Classes.h"
#include "GUI.h"
#include "Greenskins.h"

#include "detours.h"

typedef void (WINAPI *pFunc)(DWORD);

#pragma comment(lib, "detours.lib")

// Function prototypes
LRaceCategoryTable* __fastcall LoadLRaceCategoryTable( LRaceCategoryTable* thisptr, DWORD unused, char* szDir, CProxyCodeBaseEnv* proxyCodeBaseEnv );
LSubRaceCategoryTable* __fastcall LoadLSubRaceCategoryTable( LSubRaceCategoryTable* thisptr, DWORD unused, char* szDir, void* some_pointer );
__declspec(dllexport) void __fastcall sub_00582121(struct_00582121 *thisptr, DWORD unused, DWORD a2);
__declspec(dllexport) void __stdcall sub_4EE08F(CDialogInterf* dialogInterface, LRaceCategory *race);
__declspec(dllexport) int __fastcall sub_4EE3F4(CMenuRace *v1);
__declspec(dllexport) int __fastcall sub_4EE217(CMenuRace *v1);
__declspec(dllexport) RacesStruct* __stdcall sub_4EB764(RacesStruct *a1);
__declspec(dllexport) LRaceCategory* __stdcall CreateRaceCategoryFromIndex(LRaceCategory* outRace, int raceIndex);
__declspec(dllexport) char* __stdcall GetCampaignPictureByIndex(LRaceCategory* category);
__declspec(dllexport) void* __fastcall CMenuLord__CMenuLord(CMenuLord *menuLord, DWORD dummy, int a2);
__declspec(dllexport) char* __stdcall GetRaceToLordAnimationByIndex(int index);
__declspec(dllexport) int __fastcall sub_4EE685(CMenuRace *menuRaceCampain, DWORD dummy, LRaceCategory *raceCategory);
__declspec(dllexport) int __fastcall LoadNextLeaderFace(CMenuLord *menuLord, DWORD dummy, CMenuPhase *menuPhase, int leaderId, int a4);
__declspec(dllexport) bool __stdcall IsValidCampaignInPhase(CMenuPhase *menuPhase);
__declspec(dllexport) Some16Struct*__stdcall sub_4ED819(int a1, RacesStruct *a2);
__declspec(dllexport) int __stdcall sub_5F0C93 (int, int);
__declspec(dllexport) int __stdcall sub_5F0DA9(int a1, int a2);

//================================= Functions to Detour ============================================

pFunc LoadLRaceCategoryTableAddress = (pFunc)(0x0057EB99); //Lrace initialisation (Lrace.dbf)
pFunc LoadLSubRaceCategoryTableDetour = (pFunc)(0x0058CCB9);
pFunc sub_40BBB6_Detour = (pFunc)(0x0040BBB6);
pFunc sub_56A5EC_Detour = (pFunc)(0x0056A5EC);
pFunc sub_00582121_Detour = (pFunc)(0x00582121);
pFunc sub_004EE08F_Detour = (pFunc)(0x004EE08F);
pFunc sub_004EE3F4_Detour = (pFunc)(0x004EE3F4);
pFunc sub_004EE217_Detour = (pFunc)(0x004EE217);
pFunc sub_004EDDBE_Detour = (pFunc)(0x004EDDBE);
pFunc sub_004E5899_Detour = (pFunc)(0x004E5899);
pFunc sub_004EE685_Detour = (pFunc)(0x004EE685);
pFunc sub_004ED819_Detour = (pFunc)(0x004ED819);
pFunc sub_004EB764_Detour = (pFunc)(0x004EB764);
pFunc sub_005F0C93_Detour = (pFunc)(0x005F0C93);
pFunc sub_005F0DA9_Detour = (pFunc)(0x005F0DA9);

pFunc LoadNextLeaderFace_Detour = (pFunc)(0x004E6A67);
pFunc GetRaceToLordAnimationByIndex_Detour = (pFunc)(0x4EB63C);
pFunc CreateRaceCategoryFromIndex_Detour = (pFunc)(0x004EDD34);
pFunc IsValidCampaignInPhase_Detour = (pFunc)(0x004E6112);



INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved)
{

	switch(Reason)
	{
	case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hDLL);
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourAttach(&(PVOID&)LoadLRaceCategoryTableAddress, LoadLRaceCategoryTable);
			DetourAttach(&(PVOID&)LoadLSubRaceCategoryTableDetour, LoadLSubRaceCategoryTable);
			//			DetourAttach(&(PVOID&)sub_56A5EC_Detour, sub_56A5EC);
			//			DetourAttach(&(PVOID&)sub_40BBB6_Detour, sub_40BBB6);
			DetourAttach(&(PVOID&)sub_00582121_Detour, sub_00582121);
			DetourAttach(&(PVOID&)sub_004EE08F_Detour, sub_4EE08F);
			DetourAttach(&(PVOID&)sub_004EE3F4_Detour, sub_4EE3F4);
			DetourAttach(&(PVOID&)sub_004EE217_Detour, sub_4EE217);
			DetourAttach(&(PVOID&)sub_004EE685_Detour, sub_4EE685);
            DetourAttach(&(PVOID&)sub_005F0C93_Detour, sub_5F0C93);
            DetourAttach(&(PVOID&)sub_005F0DA9_Detour, sub_5F0DA9);
			//DetourAttach(&(PVOID&)sub_004ED819_Detour, sub_4ED819);
			//DetourAttach(&(PVOID&)sub_004EB764_Detour, sub_4EB764);
			DetourAttach(&(PVOID&)sub_004EDDBE_Detour, GetCampaignPictureByIndex);
			DetourAttach(&(PVOID&)LoadNextLeaderFace_Detour, LoadNextLeaderFace);
			DetourAttach(&(PVOID&)CreateRaceCategoryFromIndex_Detour, CreateRaceCategoryFromIndex);
			DetourAttach(&(PVOID&)sub_004E5899_Detour, CMenuLord__CMenuLord);
			DetourAttach(&(PVOID&)GetRaceToLordAnimationByIndex_Detour, GetRaceToLordAnimationByIndex);
			DetourAttach(&(PVOID&)IsValidCampaignInPhase_Detour, IsValidCampaignInPhase);
			DetourTransactionCommit();
			Game::Init();
		}
		break;
	case DLL_PROCESS_DETACH:
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)LoadLRaceCategoryTableAddress,  LoadLRaceCategoryTable);
		DetourDetach(&(PVOID&)LoadLSubRaceCategoryTableDetour,  LoadLSubRaceCategoryTable);
		DetourDetach(&(PVOID&)sub_00582121_Detour, sub_00582121);
		DetourDetach(&(PVOID&)sub_004EE08F_Detour, sub_4EE08F);
		DetourDetach(&(PVOID&)sub_004EE3F4_Detour, sub_4EE3F4);
		DetourDetach(&(PVOID&)sub_004EE217_Detour, sub_4EE217);
		DetourDetach(&(PVOID&)sub_004EE685_Detour, sub_4EE685);
        DetourDetach(&(PVOID&)sub_005F0C93_Detour, sub_5F0C93);
		DetourDetach(&(PVOID&)sub_004ED819_Detour, sub_4ED819);
		DetourDetach(&(PVOID&)sub_005F0DA9_Detour, sub_5F0DA9);
		DetourDetach(&(PVOID&)LoadNextLeaderFace_Detour, LoadNextLeaderFace);
		DetourDetach(&(PVOID&)CreateRaceCategoryFromIndex_Detour, CreateRaceCategoryFromIndex);
        DetourDetach(&(PVOID&)GetRaceToLordAnimationByIndex_Detour, GetRaceToLordAnimationByIndex);
		DetourDetach(&(PVOID&)IsValidCampaignInPhase_Detour, IsValidCampaignInPhase);
		DetourTransactionCommit();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

//================================= END OF Functions to Detour ============================================


