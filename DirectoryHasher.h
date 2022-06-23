#pragma once

#include <iostream>


using namespace std;

// Debugging und Memory-Leaks-Erkennung
const bool VERBOSE = false;
#define WITH_MEM_LEAK_TESTING

// Externe Funktionen
string systemCall( const char* cmd );
