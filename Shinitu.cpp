//=============================
// Shinitu Source
#include "Shinitu.h"


// in memory of ndboy @iKaros Framework @Staff [the fuccboi] - "He's not" "He's using free cheats" "even n0xious knows you're a copy paster"
// [ continues on to shoot at me 10 times with an auto before killing me literally standing right infront of me ] "ez win"

 
//=============================
// Create Move Function
bool __stdcall hkCreateMove( float sample_time, UserCmd * Cmd ) {

    typedef bool( __stdcall * oCreateMove )( float sample_time , UserCmd* );
    ValveSDK::BaseEntity * Local = ( ValveSDK::BaseEntity * ) Client_Entity->GetClientEntity( Engine_Client->GetLocalPlayer( ) );
	int Crosshair = Local->GetCrosshairIndex( );
	ValveSDK::BaseEntity* Player = ( ValveSDK::BaseEntity * )Client_Entity->GetClientEntity( Crosshair );
	///////////////////////////////////////////////////////////////////////

	if ( Cmd->CommandNumber == 0 )
		return 0;

	if ( !Local ) 
		return 0;

    //=============================
	if ( Engine_Client->IsConnected( ) && Engine_Client->IsInGame( ) ) {

        pAutoHop->AutoHop( Local, Cmd );
		pTrigger->Trigger( Local, Player, Cmd );
		pAutoStrafe->AutoStrafe( Local, Cmd );

		ClampAngles( Cmd->ViewAngles );
		normalize( Cmd->ViewAngles );

	}
    //=============================

	return 0;

}
//=============================


//=============================
// Paint Traverse Function
void __stdcall hkPaintTraverse( int VGUIPanel, bool ForceRepaint, bool AllowForce ) {

	oPaintTraverse( Panel_, VGUIPanel, ForceRepaint, AllowForce );
	///////////////////////////////////////////////////////////////////////

	if ( !strcmp( "FocusOverlayPanel", Panel_->GetName( VGUIPanel ) ) ) {
		//render here
	}

}
//=============================


//=============================
// Shinitu Function
void Shinitu( ) {

	//===================
	// Base Client
	Base_Client = ( ValveSDK::BaseClientDll* )Hooks::tools.GrabInterface( "client.dll", "VClient017" );

	//===================
	// Client Entity List
	Client_Entity = ( ValveSDK::ClientEntityList* )Hooks::tools.GrabInterface( "client.dll", "VClientEntityList003" );		

	//===================
	// Engine Client
	Engine_Client = ( ValveSDK::EngineClient* )Hooks::tools.GrabInterface( "engine.dll", "VEngineClient013" );

	//===================
	// Panel
	Panel_ = ( ValveSDK::Panel* )Hooks::tools.GrabInterface( "vgui2.dll", "VGUI_Panel009" );

	//===================
	// Surface
	Surface_	= ( ValveSDK::Surface* )Hooks::tools.GrabInterface( "vguimatsurface.dll", "VGUI_Surface031" );

	//===================
	// Client Dll Vmt
	void** ClientDllVMT = *( void*** )Base_Client;

	//===================
	// Client Mode
	Client_Mode = *( ValveSDK::ClientMode*** )( ( DWORD )ClientDllVMT[ 10 ] + 5 );

	//===================
	// Create Move [ Current Index is 24 ]
	hookedCreateMove = new VMTManager( * ( DWORD*** ) Client_Mode );
	//======
	oCreateMove = ( Hooks::CreateMove )hookedCreateMove->HookMethod( ( DWORD ) hkCreateMove, 24 );

	//===================
	// Paint Traverse [ Current Index is 41 ]
	hookedPanel = new VMTManager( ( DWORD** ) Panel_ );
	//======
	oPaintTraverse = ( Hooks::PaintTraverse ) hookedPanel->HookMethod( ( DWORD ) hkPaintTraverse, 41 );

}
//=============================


//=============================
int __stdcall DllMain( HMODULE Instacen, DWORD Reason, LPVOID _Reserved ) {

	if ( Reason == 1 ) {

		CreateThread( 0, 0, ( LPTHREAD_START_ROUTINE ) Shinitu, 0, 0, 0 );

	}

	return 1;

}
//=============================

