#pragma once;
#include "windows.h"
#include "Classes.h"





struct CInterfManagerImpl
{

};

struct CMenuFullScreenAnim
{

};

struct CMidgard
{

};

struct CMidAutoDlgLog
{

};

struct ControlsTree
{
	DWORD LeftLeaf;
	DWORD MiddleLeaf;
	DWORD RightLeaf;
	char ctrlName[16];
};

struct ChildControls
{
	DWORD dummy;
	DWORD dummy1;
	DWORD dummy2;
	ControlsTree *firstTreeLeaf;
	DWORD dummy4;
	ControlsTree *lastTreeLeaf;
};

struct DlgStruct
{
	char dlgName[0x10];			  //0x00
	CMidAutoDlgLog *MidAutoDlg;	  //0x34
	ChildControls childControls; //0x38
};

struct CDialogInterf 
{
	DWORD vfTable;
	DWORD dummy;
	DlgStruct *dlg;
};


//0x74
struct CMenuState
{
	CMidgard *midgard; //global pointer to 0x7B59C8	//0x00
	CMenuFullScreenAnim *animation;					//0x04
	DWORD *somePtr;									//0x08
	CInterfManagerImpl *interfaceManager;			//0x0C
	DWORD currentPhase;								//0x10
	DWORD *somePtr2;									//0x14
	LRaceCategory race;								//0x38
	LDifficultyLevel	difficul;					//0x44
};

struct CMenuPhase
{
	DWORD vftable;
	DWORD dummy;
	CMenuState *state;
};

struct CTable
{

};

struct DialogStruct2
{
	CDialogInterf *dialogInterface;
	CTable *table;
};

struct RaceStruct 
{
	unsigned char dummy[0x38];
	int raceIndex;
	DWORD dummy1;
	DWORD someDword;
	char someByte1;
	char slideDirection;
};

struct DialogStruct
{
	CMenuPhase *phase;
	CDialogInterf *dialogInterface;
};

struct CMenuRace
{
	DWORD vftable;
	DWORD dummy;
	DialogStruct *dialog;
	RaceStruct *race;
};




struct CTextBoxInterf
{

};
