#include "functions.h"

bool checkArgs ( int n, char* argv[] )
{
	if ( n < 2 ) {
		cout << "Usage: " << argv[0] << " infile\n";
		cout << "\ninfile - input file containing data\n";
		return false;
	}

	return true;
}

bool openFile ( ifstream &fin, char* filename )
{
	fin.open ( filename );

	if ( !fin.is_open() ) {
		cout << "Cannot open file " << filename << " for reading\n";
		return false;
	}

	return true;
}
