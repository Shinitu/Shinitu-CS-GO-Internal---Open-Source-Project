//=============================
// Triggerbot
#pragma once


//=============================
#include "ValveSDK.h"
#include "Windows.h"
//=============================


//=============================
// Trigger
class cTrigger {
public:

	void Trigger( ValveSDK::BaseEntity * Local, ValveSDK::BaseEntity * Player,  UserCmd * Cmd ) {
		
		if( GetAsyncKeyState( VK_MENU ) & 0x8000 ) {
			if ( !Player->IsImmune( ) ) {
			    if ( Player->GetHealth( ) > 0 ) {
				    if ( Player->GetTeam( )  != Local->GetTeam( ) ) {
					    Cmd->Buttons |= IN_ATTACK;
				    }
			    }
			}
		}

	}

};
//=============================
