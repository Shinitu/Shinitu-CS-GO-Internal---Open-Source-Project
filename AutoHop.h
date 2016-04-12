//=============================
// Auto Hop
#pragma once


//=============================
#include "ValveSDK.h"
#include "Windows.h"
//=============================


//=============================
//Auto Hop
class cAutoHop {
public:

	void AutoHop( ValveSDK::BaseEntity * Local, UserCmd * Cmd ) {

	    static bool bLastJumped = false;
	    static bool bShouldFake = false;
		if( !bLastJumped && bShouldFake ) {
			bShouldFake = false;
			Cmd->Buttons |= IN_JUMP;
		}
		else if( Cmd->Buttons & IN_JUMP ) {
			if( Local->GetFlags() & FL_ONGROUND ) {
				bLastJumped = true;
				bShouldFake = true;
			}
			else {
				Cmd->Buttons &= ~IN_JUMP;
				bLastJumped = false;
			}
	    }
		else {
		    bLastJumped = false;
			bShouldFake = false;
		}  

	}

};
//=============================