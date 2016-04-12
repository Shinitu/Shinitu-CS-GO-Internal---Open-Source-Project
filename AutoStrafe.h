//=============================
// Auto Strafe
#pragma once


//=============================
#include "ValveSDK.h"
#include "Windows.h"
#include "Math.h"

//=============================
//Auto Strafe
class cAutoStrafe {
public:

    //=============================
	void AutoStrafe( ValveSDK::BaseEntity * Local, UserCmd * Cmd ) {

		static bool bDirection;

		if ( !( Local->GetFlags( ) & FL_ONGROUND ) ) {

            //============================= // doing the strafing
		    if( Cmd->MousedX < 0 )
			    Cmd->SideMove = -450.0f;

		    if( Cmd->MousedX > 0 )
			    Cmd->SideMove = 450.0f;
            //============================= 

            //============================= 			
			if ( bDirection ) {
                Cmd->ViewAngles = ClampAngles( Vector ( Cmd->ViewAngles.x, Cmd->ViewAngles.y -= 1.f, 0.0f ) );
			    Cmd->SideMove = -450.f;
			    bDirection = false;
			}
			else {
                Cmd->ViewAngles = ClampAngles( Vector ( Cmd->ViewAngles.x, Cmd->ViewAngles.y += 1.f, 0.0f ) );
			    Cmd->SideMove = 450.f;
			    bDirection = true;;
			}
            //============================= 

		}

	}
    //=============================

};

//=============================
