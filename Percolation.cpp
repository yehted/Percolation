#include "Percolation.h"
#include <stdexcept>
#include <iostream>

Percolation::Percolation(): gridSize(0) {}

Percolation::Percolation(int N) : gridSize(N), grid(N*N + 2), 
	grid2(N*N + 1), bottom(N*N + 1), site(new bool[N*N + 1]())
{}

Percolation::~Percolation() {
	delete[] site;
}

Percolation::Percolation(const Percolation &that) : gridSize(that.gridSize), 
	grid(that.grid), grid2(that.grid2), bottom(that.bottom), 
	site(new bool[that.gridSize * that.gridSize + 1]())
{	
	int N = that.gridSize * that.gridSize + 1;
	for (int i = 0; i < N; i++)
		site[i] = that.site[i];
}

Percolation &Percolation::operator=(const Percolation &that) {
	// Check for self assignment
	if (this == &that) return *this;
	
	// Deallocate old memory
	delete[] site;
	
	// Allocate new memory and copy elements
	int N = that.gridSize * that.gridSize + 1;
	bool *new_site = new bool[N];
	for (int i = 0; i < N; i++)
		new_site[i] = that.site[i];
	
	// Assignm new memory
	site = new_site;
	gridSize = that.gridSize;
	grid = that.grid;
	grid2 = that.grid2;
	bottom = that.bottom;
	
	return *this;
}

int Percolation::xyTo1D(int i, int j) {
	return (gridSize * (i - 1) + j);
}

bool Percolation::isValidIndex(int i, int j) {
	return ((i > 0 && i <= gridSize) && (j > 0 && j <= gridSize));
}

void Percolation::open(int i, int j) {
	if (!isValidIndex(i, j)) {
		throw std::out_of_range("Index out of bounds");
	}
	int id = xyTo1D(i, j);
	site[id] = true;

	if (isValidIndex(i-1, j) && isOpen(i-1, j)) {
		grid.unite(id, xyTo1D(i-1,j));
		grid2.unite(id, xyTo1D(i-1,j));
	}
	if (isValidIndex(i+1, j) && isOpen(i+1, j)) {
		grid.unite(id, xyTo1D(i+1,j));
		grid2.unite(id, xyTo1D(i+1,j));
	}
	if (isValidIndex(i, j-1) && isOpen(i, j-1)) {
		grid.unite(id, xyTo1D(i,j-1));
		grid2.unite(id, xyTo1D(i,j-1));
	}
	if (isValidIndex(i, j+1) && isOpen(i, j+1)) {
		grid.unite(id, xyTo1D(i,j+1));
		grid2.unite(id, xyTo1D(i,j+1));
	}

	if (i == 1) {
		grid.unite(0, id);
		grid2.unite(0, id);
	}

	if (i == gridSize) grid.unite(id, bottom);
}

bool Percolation::isOpen(int i, int j) {
	if (!isValidIndex(i, j)) {
		throw std::out_of_range("Index out of bounds");
	}
	int id = xyTo1D(i, j);
	return (site[id]);
}

bool Percolation::isFull(int i, int j) {
	if (!isOpen(i, j)) return false;
	int id = xyTo1D(i, j);
	return (grid2.connected(id, 0));
}

bool Percolation::percolates() {
	return (grid.connected(bottom, 0));
}

bool Percolation::connected(int i, int j) {
	return (grid.connected(i, j));
}