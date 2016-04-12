//=============================
// cloudyware Header
#pragma once


//=============================
#include <iostream>
#include "Windows.h"
#include "Vector.h"
#include "UserCmd.h"
#include "ValveSDK.h"
//=============================


//=============================
// Normalize
void normalize( Vector & angles ) {

	while ( angles.x > 180.0f )
		angles.x -= 360.0f;
 
	while ( angles.x < -180.0f )
		angles.x += 360.0f;
 
	while ( angles.y > 180.0f )
		angles.y -= 360.0f;
 
	while ( angles.y < -180.0f )
		angles.y += 360.0f;
 
	while ( angles.z > 180.0f )
		angles.z -= 360.0f;
 
	while ( angles.z < -180.0f )
		angles.z += 360.0f;

}
//=============================


//=============================
// Clamp
Vector ClampAngles(Vector angles){
	
    while( angles.y > 180 )
    angles.y -= 360;
 
    while( angles.y < -180 )
    angles.y += 360;
 
    if(angles.x > 89.0f)
        angles.x = 89.0f;
 
	if (angles.x < -89.0f)
        angles.x = -89.0f;
 
    angles.z = 0;
	return angles;
 
}
//=============================


//=============================
//Calc Angle
void CalcAngle( float *src, float *dst, float *angles ) {

    double delta[3] = { ( src[ 0 ]-dst[ 0 ] ), ( src[ 1 ]-dst[ 1 ] ), ( src[ 2 ]-dst[ 2 ] ) };
    double hyp = sqrt( delta[ 0 ]*delta[ 0 ] + delta[ 1 ]*delta[ 1 ] );
    angles[ 0 ] = ( float ) ( asinf( delta[ 2 ]/hyp ) * 57.295779513082f );
    angles[ 1 ] = ( float ) ( atanf( delta[ 1 ]/delta[ 0 ]  * 57.295779513082f ) );
    angles[ 2 ] = 0.0f;
    if( delta[ 0 ] >= 0.0 ) { angles[ 1 ] += 180.0f; }

}
//=============================


//=============================
//Clamp Value
int ClampVal(int val, int min, int max)
{
	if(val < min) return min;
	if(val > max) return max;
	
	return val;
}
//=============================


//=============================
// ClampAngles [Qangle]
bool ClampAnglesQ(QAngle angles){
	
    while( angles.y > 180 )
        angles.y -= 360;
 
    while( angles.y < -180 )
        angles.y += 360;
 
    if (angles.x > 89.0f)
        angles.x = 89.0f;
 
    if (angles.x < -89.0f)
        angles.x = -89.0f;
 
    angles.z = 0;
 
}
//=============================
