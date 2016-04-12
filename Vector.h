//=============================
// Vector
#pragma once

//=============================
//Vector Class
typedef float vec_t;
class Vector {
public:

    //=============================
	float x, y, z;
    //=============================

    //=============================
	Vector( float x = 0, float y = 0, float z = 0 ) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
    //=============================

    //=============================
	FORCEINLINE vec_t LengthSqr(void) const {
		return (x * x + y * y + z * z);
	}
    //=============================

    //=============================
	Vector operator + ( const Vector & In ) {
		return Vector(x + In.x, y + In.y, z + In.z);
	}
    //=============================

    //=============================
	Vector operator - ( const Vector & In ) {
		return Vector(x - In.x, y - In.y, z - In.z);
	}
    //=============================

    //=============================
	Vector operator * ( const Vector & In ) {
		return Vector(x * In.x, y * In.y, z * In.z);
	}
    //=============================

    //=============================
	Vector operator / ( const Vector & In ) {
		return Vector(x / In.x, y / In.y, z / In.z);
	}
    //=============================

    //=============================
	Vector operator -= (const Vector & In) {
		this->x -= In.x;
		this->y -= In.y;
		this->z -= In.z;
		return *this;
	}
    //=============================

    //=============================
	Vector operator += (const Vector & In) {
		this->x += In.x;
		this->y += In.y;
		this->z += In.z;
		return *this;
	}
    //=============================
};
//=============================


//=============================
//Vector Class
class QAngleByValue;
class QAngle {
public:
	// Members
	float x, y, z;

	// Construction/destruction
	QAngle( void );
	QAngle( float X, float Y, float Z );
	//      QAngle(RadianEuler const &angles);      // evil auto type promotion!!!

	// Allow pass-by-value
	operator QAngleByValue & ( )              { return *( ( QAngleByValue * )( this ) ); }
	operator const QAngleByValue & ( ) const  { return *( ( const QAngleByValue * )( this ) ); }

	// Initialization
	void Init( float ix = 0.0f, float iy = 0.0f, float iz = 0.0f );
	void Random( float minVal, float maxVal );

	// Got any nasty NAN's?
	bool IsValid( ) const;
	void Invalidate( );

	// array access...
	float operator[ ]( int i ) const;
	float& operator[ ]( int i );

	// Base address...
	float* Base( );
	float const* Base( ) const;

	// equality
	bool operator==( const QAngle & v ) const;
	bool operator!=( const QAngle & v ) const;

	// arithmetic operations
	QAngle & operator+=( const QAngle & v );
	QAngle & operator-=( const QAngle & v );
	QAngle & operator*=( float s );
	QAngle & operator/=( float s );

	// Get the vector's magnitude.
	float   Length( ) const;
	float   LengthSqr( ) const;

	// negate the QAngle components
	//void  Negate( );

	// No assignment operators either...
	QAngle & operator=( const QAngle & src );

#ifndef VECTOR_NO_SLOW_OPERATIONS
	// copy constructors

	// arithmetic operations
	QAngle  operator-( void ) const;

	QAngle  operator+( const QAngle & v ) const;
	QAngle  operator-( const QAngle & v ) const;
	QAngle  operator*( float fl ) const;
	QAngle  operator/( float fl ) const;
#else

private:
	// No copy constructors allowed if we're in optimal mode
	QAngle( const QAngle & vOther );

#endif
};
//=============================