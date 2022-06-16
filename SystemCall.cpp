#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


using namespace std;

std::string systemCall( const char* cmd )
{
    string result;
    array<char, 128> buffer {};
    unique_ptr<FILE, decltype( &_pclose )> pipe( _popen( cmd, "r" ), _pclose );

    if( !pipe )
    {
        throw runtime_error( "popen() failed!" );
    }

    while( fgets( buffer.data(), buffer.size(), pipe.get() ) != nullptr )
    {
        result += buffer.data();
    }

    return result;
}
