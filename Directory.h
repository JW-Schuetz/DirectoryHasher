#pragma once

#include <filesystem>


using namespace filesystem;

class Directory
{
	private:
		int crawler( path );

	public:
		// Konstruktor
		Directory( path );

		// Destruktor
		~Directory() {};
};
