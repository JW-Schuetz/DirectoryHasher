#pragma once

#include <filesystem>


using namespace std::filesystem;

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
