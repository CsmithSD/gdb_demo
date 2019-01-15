#include <stdio.h>
#include <string.h>

void do_things()
{
	static int i = 0;

	if ( i == 10 )
		return;

	i++;
	printf ( "Recursing %d\n", i );
	do_things();
	printf ( "Coming Up\n" );
}

void do_some_more()
{
	char b[20] = { "abcdefghijk"};
	char c [8];
	memcpy ( c, b, sizeof c + 1 );    // here invalid read and invalid write
	do_things();
	printf ( "\nsize: %d\n", sizeof b );
	printf ( "\nc: %s\n", c );

}
int main ( void )
{
	do_things();
	do_some_more();
	do_things();
	return 0;
}
