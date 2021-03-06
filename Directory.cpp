#include "DirectoryHasher.h"
#include "Directory.h"


// Konstruktor
Directory::Directory( path p )
{
	wstring sp = p;
	string s = string( sp.begin(), sp.end() );
	cout << "Zu untersuchendes Verzeichnis: " + s << endl;

	current_path( p ); //set path for our process

	int count = crawler( "." );

	cout << endl << "Anzahl Dateien: " << count << endl;
}

int Directory::crawler( path pstartPath )
{
	int count = 0;

	for( directory_iterator next( pstartPath ), end; next != end; ++next )
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

			// call certutil if file size not zero
			string res = "";
			if( file_size( p ) )
			{
				string cmd = string( "certutil -hashfile " );
				string lim = string( "\"" );
				string arg = string( cmd + lim + p + lim + " SHA512" );

				res = systemCall( arg.c_str() );

				// process output of certutil
				string delimiter = string( "CertUtil: -hashfile-Befehl wurde erfolgreich ausgeführt." );

				int ndx = res.find( delimiter );
				if( ndx != string::npos )
				{
					// am Ende: delimiter entfernen
					string token = res.substr( 0, ndx );

					// am Anfang: SHA512-Hash entfernen
					ndx = token.find( p );
					token = token.substr( ndx, token.length() );

					// in der Mitte: NL durch " " ersetzen (und am Ende durch "")
					token = token.replace( token.find( "\n" ), 1, " " );
					token = token.replace( token.find( "\n" ), 1, "" );

					cout << token << endl;
				}
				else cout << "certutil scheitert bei: " + p << endl;
			}
			else cout << p + ": leere Datei" << endl;
		}
	}

	return count;
}
