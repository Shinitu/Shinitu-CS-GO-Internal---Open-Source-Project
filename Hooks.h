//=============================
// Tools
#pragma once

//=============================
#include "UserCmd.h"
//=============================

//=============================
//Hooks
namespace Hooks {

	//===================
	// Interface [for create interface]
	typedef void*( *Interface )( char* _Name, int Return );

	//===================
	// hkCreateMove
    typedef bool( __fastcall *CreateMove )( void*, float, UserCmd* );

	//===================
	// hkPaintTraverse
    typedef void( __thiscall *PaintTraverse )( void*, unsigned int, bool, bool );

    //=============================
    // Interface Utils
    struct Tools {

	    virtual void* GrabInterface( char* _Module, char* _Interface ) {

		    Hooks::Interface TempInterface = ( Hooks::Interface ) GetProcAddress( GetModuleHandle( _Module ), "CreateInterface" );


		    return ( void* ) TempInterface( _Interface, 0 );

	    }

    }tools;

};
//=============================

