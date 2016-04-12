//=============================
// Shinitu Hook [ not mine tho ]
#pragma once

//=============================
// Hook
class VMTManager {
public:

	//===================
	VMTManager( void ) {

		memset( this, 0, sizeof( VMTManager ) );

	}
	//===================

	//===================
	VMTManager( PDWORD* classbase ) {

		Initialize( classbase );

	}
	//===================

	//===================
	~VMTManager( void ) {

		UnHook( );

	}
	//===================

	//===================
	bool Initialize( PDWORD* classbase ) {

		ClassBase = classbase;

		OldVmt = *classbase;

		vmtsize = dwGetVMTCount( *classbase );

		NewVmt = new DWORD[ vmtsize ];

		memcpy( NewVmt, OldVmt, sizeof( DWORD )* vmtsize );

		*classbase = NewVmt;

		return true;

	}
	//===================

	//===================
	bool Initialize( PDWORD** pclassbase ) {

		return Initialize( *pclassbase );

	}
	//===================

	//===================
	void UnHook( void ) {

		if ( ClassBase ) {

			*ClassBase = OldVmt;

		}

	}
	//===================

	//===================
	void ReHook( void ) {

		if ( ClassBase ) {

			*ClassBase = NewVmt;

		}

	}
	//===================

	//===================
	int iGetFuncCount( void ) {

		return ( int )vmtsize;

	}
	//===================

	//===================
	DWORD GetMethodAddress( int Index ) {

		if ( Index >= 0 && Index <= ( int )vmtsize && OldVmt != NULL ) {

			return OldVmt[ Index ];

		}

		return NULL;

	}
	//===================

	//===================
	PDWORD pdwGetOldVMT( void ) {

		return OldVmt;

	}
	//===================

	//===================
	DWORD HookMethod( DWORD dwNewFunc, unsigned int iIndex ) {

		if ( NewVmt && OldVmt && iIndex <= vmtsize && iIndex >= 0 ) {

			NewVmt[ iIndex ] = dwNewFunc;

			return OldVmt[ iIndex ];

		}

		return NULL;

	}
	//===================

private:

	//===================
	DWORD dwGetVMTCount( PDWORD pdwVMT ) {

		DWORD dwIndex = 0;

		for ( dwIndex = 0; pdwVMT[dwIndex]; dwIndex++ ) {

			if ( IsBadCodePtr( ( FARPROC )pdwVMT[ dwIndex ] ) ) {

				break;

			}

		}

		return dwIndex;

	}
	//===================

	PDWORD*    ClassBase;

	PDWORD    NewVmt, OldVmt;

	DWORD    vmtsize;

};
//=============================