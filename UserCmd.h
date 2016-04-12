//=============================
// User Cmd
#pragma once


//=============================
#include "Vector.h"
//=============================


//=============================
#define IN_JUMP (1 << 1)
#define FL_ONGROUND (1 << 0)
#define IN_ATTACK (1 << 0)
//=============================


//=============================
//User Cmd
class UserCmd {
public:

    //=============================
	virtual ~UserCmd( ){};
    //=============================

    //=============================
	int CommandNumber;
	int TickCount;
    //=============================

    //=============================
	Vector ViewAngles;
	Vector AimDirection;
    //=============================

    //=============================
	float ForwardMove;
	float SideMove;
	float UpMove;
    //=============================

    //=============================
	int Buttons;
	unsigned char Impulse;
	int WeaponSelect;
	int WeaponSubtype;
	int RandomSeed;
    //=============================

    //=============================
	short MousedX;
	short MousedY;
	bool HasBeenPredicted;
	char PAD1[0x18];
    //=============================
};
//=============================