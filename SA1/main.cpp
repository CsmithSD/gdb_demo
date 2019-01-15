#include <iostream>
#include <fstream>
#include "functions.h"
#include "io.h"

using namespace std;

int main ( int argc, char* argv[] )
{
	ifstream fin;
	linkedList* ll;

	if ( !checkArgs ( argc, argv ) )
		return -1;

	if ( !openFile ( fin, argv[1] ) )
		return -2;

	ll = fillList ( fin );

	ll->printList();

	return 0;
}
