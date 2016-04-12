//=============================
// Render
#pragma once


//=============================
#include <iostream>
#include "Windows.h"
#include "Shinitu.h"
#include "ValveSDK.h"
//=============================


//=============================
ValveSDK::Surface * Surface_;
ValveSDK::Panel * Panel_;
//=============================


//=============================
extern ValveSDK::Surface * Surface_;
extern ValveSDK::Panel * Panel_;
//=============================


//=============================
// Render Class
class CRender {
public:

    //=============================
	void Draw( int X, int Y, CColor Color, int Font, bool Center, char* _Input, ... ) {

		char Buffer[ 1024 ] = { '\0' };

		va_list Args;

		va_start( Args, _Input );
		vsprintf_s( Buffer, _Input, Args );
		va_end( Args );

		size_t Size = strlen( Buffer ) + 1;

		wchar_t* WideBuffer = new wchar_t[ Size ];

		mbstowcs_s( 0, WideBuffer, Size, Buffer, Size - 1 );

		int Width = 0, Height = 0;

		if ( Center ) {
			Surface_->GetTextSize( Font, WideBuffer, Width, Height );
		}

		Surface_->DrawSetTextColor( Color );
		Surface_->DrawSetTextFont( Font );
		Surface_->DrawSetTextPos( X - ( Width * .5 ), Y );
		Surface_->DrawPrintText( WideBuffer, wcslen( WideBuffer ), 0 );
	}
    //=============================

};
//=============================