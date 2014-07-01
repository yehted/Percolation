//#include "stdafx.h"
#include "WeightedQuickUnionUF.h"
#include <iostream>

// Default constructor
WeightedQuickUnionUF::WeightedQuickUnionUF(): n_count(0) {}

// Initializes an empty union-find data structure with N isolated components 0 through N-1.
WeightedQuickUnionUF::WeightedQuickUnionUF(int N): n_count(N), id(N), sz(N) {	
	for (int i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = i;
	}
}

// Returns the number of components
int WeightedQuickUnionUF::count() {
	return n_count;
}

// Returns the component identifier for the component containing site p
int WeightedQuickUnionUF::find(int p) {
	while (p != id[p])
		p = id[p];
	return p;
}

// Are the two sites p and q in the same component?
bool WeightedQuickUnionUF::connected(int p, int q) {
	return (find(p) == find(q));
}

// Merges the component containing site p with the component containing site q
void WeightedQuickUnionUF::unite(int p, int q) {
	int rootP = find(p);
	int rootQ = find(q);
	if (rootP == rootQ) return;

	// make smaller root point to larger one
	if (sz[rootP] < sz[rootQ])	{ id[rootP] = rootQ; sz[rootQ] += sz[rootP]; }
	else						{ id[rootQ] = rootP; sz[rootP] += sz[rootQ]; }
	n_count--;
}