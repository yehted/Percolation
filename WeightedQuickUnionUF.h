/*
* The WeightedQuickUnionUF class represents a union-find data structure.
* It supports the union and find operations, along with 
* methods for determining whether two objects are in the same compnent 
* and the total number of components.
*
* This implementation uses weighted quick union by size (without path compression). 
* Initializing a data structure with N objects takes linear time.
* Afterwards, unite, find, and connected take logarithmic time (in the worst case)
* and count takes constant time.
*/

class WeightedQuickUnionUF {
public:
	WeightedQuickUnionUF();			// Default constructor
	~WeightedQuickUnionUF();		// Deconstructor
	WeightedQuickUnionUF(const WeightedQuickUnionUF &that);		// Copy constructor
	WeightedQuickUnionUF& operator=(const WeightedQuickUnionUF &that);	// Copy assignment operator
	WeightedQuickUnionUF(int N);	// Initializes an empty union-find data structure with N isolated components 0 through N-1.
	int count();					// Returns the number of components
	int find(int p);				// Returns the component identifier for the component containing site p
	bool connected(int p, int q);	// Are the two sites p and q in the same component?
	void unite(int p, int q);		// Merges the component containing site p with the component containing site q

private:
	int* id;						// id[i] = parent of i
	int* sz;						// sz[i] = number of objects in subtree rooted at i
	int n_count;					// number of components
};