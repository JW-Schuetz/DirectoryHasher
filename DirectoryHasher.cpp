#include "DirectoryHasher.h"

#ifdef WITH_MEM_LEAK_TESTING
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include "Directory.h"


// Benutzung: BitCoinTransfer FTP-Passwort Zielverzeichnis
int main( int argc, const char* argv[] )
{
	if( argc != 2 ) return -1;

	int ret = 0;

	try
	{
		Directory* d = new Directory( argv[1] );
		delete d;
	}
	catch( exception )
	{
	};

#ifdef WITH_MEM_LEAK_TESTING
	bool leak = _CrtDumpMemoryLeaks();
#endif

	return ret;
}
