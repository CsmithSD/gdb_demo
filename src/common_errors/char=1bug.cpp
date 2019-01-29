#include<string>
#include<iostream>
using namespace std;

int main()
{
	string s = "010100001111";
	cout << "String: " << s << endl;

	for ( int i = 0; i < s.length(); i++ ) {
		cout << s[i] << " :";

		if ( s[i] == 0 )
			cout << "It's a ZERO" << endl;

		else
			cout << "It's a ONE" << endl;
	}

	return 0;
}
