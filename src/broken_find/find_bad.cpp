#include <bits/stdc++.h>

using namespace std;

// Finds A's parent in a disjoint set
int find ( vector<int> &d, int a )
{
	if ( d[a] == -1 ) return a;

	return d[a] = find ( d, d[a] );
}

// Joins A and B in a disjoint set
void join ( vector<int> &d, int a, int b )
{
	a = find ( d, a );
	b = find ( d, b );
	d[a] = b;
}

int main()
{
	// Read in initial input
	int n, m, q;
	cin >> n >> m >> q;

	// A disjoint set to keep track of all n friends,
	// initialize to -1
	vector<int> d ( n, -1 );

	// For all m pairs of friends, join them together
	for ( int i = 0; i < m; i++ ) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		join ( d, u, v );
	}

	// For all q queries, tell if the people are friends
	for ( int i = 0; i < q; i++ ) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		if ( find ( d, u ) == find ( d, v ) )
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
