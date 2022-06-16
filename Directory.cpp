#include "Directory.h"
#include "DirectoryHasher.h"


// Konstruktor
Directory::Directory( path p )
{
	wstring sp = p;
	string s = string( sp.begin(), sp.end() );
	cout << "Zu untersuchendes Verzeichnis: " + s << endl;

	int count = crawler( p );

	cout << endl << "Anzahl Dateien: " << count << endl;
}

int Directory::crawler( path p )
{
	int count = 0;

	for( directory_iterator next( p ), end; next != end; ++next )
	{
		directory_entry d = *next;

		if( d.is_directory() )
		{
			count += crawler( d );
		}
		else
		{
			count += 1;

			// provide argument for calling certutil
			wstring wp = d.path();
			string p = string( wp.begin(), wp.end() );
			string cmd = string( "certutil -hashfile" );
			string method = string( "SHA512" );
			string arg = string( cmd + " " + p + " " + method );

			// call certutil
			string res = systemCall( arg.c_str() );

			// process output of certutil
			string delimiter = string( "CertUtil: -hashfile-Befehl wurde erfolgreich ausgeführt." );

			int ndx = res.find( delimiter );
			if( ndx != string::npos )
			{
				string token = res.substr( 0, res.find( delimiter ) );
				cout << token << endl;
			}
			else cout << "certutil scheitert bei: " + p << endl;
		}
	}

	return count;
}
