#include "DirectoryHasher.h"
#include "Directory.h"

#ifdef WITH_MEM_LEAK_TESTING
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif


// Benutzung: Verzeichnis
int main( int argc, const char* argv[] )
{
	if( argc != 2 ) return -1;

#ifdef WITH_MEM_LEAK_TESTING
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	int ret = 0;

	try
	{
		Directory* d = new Directory( argv[1] );
		delete d;
	}
	catch( exception )
	{
		ret = -2;
	};

//#ifdef WITH_MEM_LEAK_TESTING
//	bool leak = _CrtDumpMemoryLeaks();
//#endif

	return ret;
}
