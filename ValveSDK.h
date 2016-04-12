//=============================
// Valve SDK
#pragma once


//=============================
#include "Vector.h"
#include "UserCmd.h"
#include "PlayerInfo.h"
#include "Matrix.h"
#include "color.h"
//=============================

//=============================
// getvfunc
template<typename Fn>
inline Fn getvfunc(const void *v, int i) {
	return (Fn) *(*(const void ***) v + i);
}
//=============================

//=============================
//EmulateVirtual
template<typename Function>Function EmulateVirtual(void* _VMT, int Index) {

	void*** _TVMT = (void***) _VMT;

	void** VMT = *_TVMT;

	void* _Address = VMT[Index];

	return (Function)(_Address);

}
//=============================


//=============================
template<typename T> //nanocats
inline T *makeptr(void *base, int o)
{
	return (T *) ((char *) base + o);
}
//=============================


//=============================
//Valve SDK
namespace ValveSDK {

	//===================
	// Base Client
    class BaseClientDll {

    };

	//===================
	// Client Mode
    class ClientMode {

    };

	//===================
	// Client Entity List
    class ClientEntityList {
	public:

        //=============================
	    virtual void PAD0( );
	    virtual void PAD1( );
	    virtual void PAD2( );
	    virtual void* GetClientEntity( int Index );
	    virtual void* GetClientEntityFromHandle( void* _Handle );
	    virtual int NumberOfEntities( bool NonNetworkable );
	    virtual int GetHighestEntityIndex( );
	    virtual void SetMaxEntities( int Max );
	    virtual void GetMaxEntities( );
        //=============================

   };

	//===================
	// Engine Client
    class EngineClient {
    public:

        //=============================
	    void GetPlayerInfo( int Index, PlayerInfo* _Info ) {
		    typedef void( __thiscall* _GetPlayerInfo )( void*, int, PlayerInfo* );
		    return EmulateVirtual<_GetPlayerInfo>( this, 8 )( this, Index, _Info );
	    }
        //=============================

        //=============================
	    void GetScreenSize( int& Width, int& Height ) {
		    typedef void( __thiscall* _GetScreenSize )( void*, int&, int& );
		    return EmulateVirtual< _GetScreenSize >( this, 5 )( this, Width, Height );
	    }
        //=============================

        //=============================
 	    int GetLocalPlayer( ) {
		    typedef int( __thiscall*_GetLocalPlayer )( void* );
		    return EmulateVirtual< _GetLocalPlayer >( this, 12 )(this );
	    }
        //=============================


        //=============================
	    int GetMaxClients( ) {
		    typedef int( __thiscall*_GetMaxClients )( void* );
		    return EmulateVirtual< _GetMaxClients >( this, 20 )(this );
	    }
        //=============================

        //=============================
	    const Matrix3x4 & GetMatrix( ) {
		    typedef const Matrix3x4 & ( __thiscall*_GetMatrix )( void* );
		    return EmulateVirtual< _GetMatrix >( this, 37 )( this );
	    }
        //=============================

        //=============================
	    bool IsInGame( ) {
		    typedef bool( __thiscall* _IsInGame )( void* );
		    return EmulateVirtual<_IsInGame>( this, 26 )( this );
	    }
        //=============================

        //=============================
	    bool IsConnected( ) {
		    typedef bool( __thiscall* _IsConnected )( void* );
		    return EmulateVirtual<_IsConnected>( this, 27 )( this );
	    }
        //=============================

    };

	//===================
	// Engine Client
    class BaseEntity {
    public:

        //=============================
	    int GetFlags( ) {
		    return *( int* )( this + 0x100 );
	    }
        //=============================

        //=============================
		int GetCrosshairIndex( ) {
			return *( int* )( this + 0xA954 );
		}
        //=============================

        //=============================
		int GetTeam( ) {
			return *( int* )( this + 0xF0 );
		}
        //=============================

        //=============================
	    bool GetDormant( ) {   
		    return *( bool* ) ( this + 0xE9 );
	    }
        //=============================

        //=============================
		int GetHealth( ) {
			return *( int* )( this + 0xFC );
		}
        //=============================

        //=============================
	    Vector GetOrigin( ) {
		    return *( Vector* ) ( this + 0x134 );
	    }
        //=============================

        //=============================
	    Vector *GetPunch( )  {
		    return ( Vector *) ( this + 0x3018 );
	    }
        //=============================

        //=============================
	    Vector GetEyePosition( ) {
		    return *( Vector* ) ( this + 0x104 ) + GetOrigin( );
	    }
        //=============================


        //=============================
	    bool SetupBones( Matrix3x4 * pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime ) {
		    PVOID pRenderable = ( PVOID )( this + 0x4 );
		    typedef bool( __thiscall * oSetupBones )( PVOID, Matrix3x4*, int, int, float );
		    return getvfunc< oSetupBones >( pRenderable, 13 )( pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime );
	    }
        //=============================

        //=============================
	    bool IsImmune( ) {
		    return *( bool* ) ( this + 0x38A0);
	    }
        //=============================

    };

	//===================
	// surface
    class Surface
    {
    public:

        //=============================
	    void DrawSetColor( CColor Color ) {
		    typedef void( __thiscall* _DrawSetColor )( void*, CColor );
		    return EmulateVirtual<_DrawSetColor>( this, 14 )( this, Color );
	    }
        //=============================

        //=============================
	    void DrawOutlinedRect( int X, int Y, int W, int H ) {
		    typedef void( __thiscall* _DrawOutlinedRect )( void*, int, int, int, int );
		    return EmulateVirtual<_DrawOutlinedRect>( this, 18 )( this, X, Y, W, H );
	    }
        //=============================

        //=============================
		void DrawLine( int X1, int Y1, int X2, int Y2 ) {
		    typedef void( __thiscall* _DrawOutlinedRect )( void*, int, int, int, int );
		    return EmulateVirtual<_DrawOutlinedRect>( this, 19 )( this, X1, Y1, X2, Y2 );
		}
        //=============================

        //=============================
	    void DrawSetTextFont( int Font ) {
		    typedef void( __thiscall* _DrawSetTextFont )( void*, int );
		    return EmulateVirtual<_DrawSetTextFont>( this, 23 )( this, Font );
	    }
        //=============================

        //=============================
	    void DrawSetTextColor( CColor Color ) {
		    typedef void( __thiscall* _DrawSetTextColor )( void*, CColor );
		    return EmulateVirtual<_DrawSetTextColor>( this, 24 )( this, Color );
	    } 
        //=============================

        //=============================
	    void DrawSetTextPos( int X, int Y ) {
		    typedef void( __thiscall* _DrawSetTextPos )( void*, int, int );
		    return EmulateVirtual<_DrawSetTextPos>( this, 26 )( this, X, Y );
	    }
        //=============================

        //=============================
	    void DrawPrintText( wchar_t* _Input, int Length, int Type ) {
		    typedef void( __thiscall* _DrawPrintText )( void*, wchar_t*, int, int );
		    return EmulateVirtual<_DrawPrintText>( this, 28 )( this, _Input, Length, Type );
	    }
        //=============================

        //=============================
	    bool GetTextSize( int Font, const wchar_t* _Input, int& Wide, int& Tall ){
		    typedef bool( __thiscall* _GetTextSize )( void*, int, const wchar_t*, int&, int& );
		    return EmulateVirtual< _GetTextSize >( this, 79 )( this, Font, _Input, Wide, Tall );
	    }
        //=============================

    };


    //=============================
	// Panel
    class Panel {
    public:

        //=============================
	    const char* GetName( int Panel )
	    {
		    typedef const char*( __thiscall* _GetName )( void*, int );
		    return EmulateVirtual< _GetName >( this, 36 )( this, Panel );
	    }
        //=============================

    }; 

}
//=============================