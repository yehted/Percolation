#include "stdafx.h"
#include "Percolation.h"
#include <vector>

class PercolationStats {
public:
	PercolationStats();							// default constructor
	PercolationStats(int N, int T);				// perform T independent computational experiments on a N-by-N grid
	double mean();								// sample mean of percolation threshold
	double stddev();							// sample standard deviation of percolation threshold
	double confidenceLo();						// returns lower bound of the 95% confidence interval
	double confidenceHi();						// returns upper bound of the 95% confidence interval
	static int main(int argc, char *argv[]);	// test client, described below

private:
	vector<double> results;
	double trials;
};