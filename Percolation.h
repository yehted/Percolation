#include "WeightedQuickUnionUF.h"

class Percolation {
public:
	Percolation();						// default constructor
	~Percolation();						// destructor
	Percolation(const Percolation &that);				// copy constructor
	Percolation &operator=(const Percolation &that);	// copy assignment operator
	Percolation(int N);					// create N-by-N grid, with all sites blocked
	void open(int i, int j);			// open site (row i, column j) if it is not already
	bool isOpen(int i, int j);			// is site (row i, column j) open?
	bool isFull(int i, int j);			// is site (row i, column j) full?
	bool percolates();					// does the system percolate?

private:
	int gridSize;
	WeightedQuickUnionUF grid;
	WeightedQuickUnionUF grid2;			// for visualizer to prevent backwash
	bool *site;
	int bottom;
	int xyTo1D(int i, int j);			// converts (i, j) coordinates to 1D vector index
	bool isValidIndex(int i, int j);	// checks if (i, j) is valid coordinate
	bool connected(int i, int j);		// checks if i and j are connected
};