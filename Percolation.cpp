//#include "stdafx.h"
#include "Percolation.h"

Percolation::Percolation(): gridSize(0) {}

Percolation::Percolation(int N): gridSize(N), grid(N*N+2), grid2(N*N+1), site(N*N+1), bottom(N*N+1) {
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
	return (site[xyTo1D(i, j)]);
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