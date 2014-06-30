#include "stdafx.h"
#include "PercolationStats.h"
#include "Stats.h"
#include <iostream>
#include <time.h>
using namespace std;

PercolationStats::PercolationStats(): trials(0) {}

PercolationStats::PercolationStats(int N, int T) {
	srand(time(0));
	if (N < 1 || T < 1) {
		cerr << "N and T must be greater than 1" << endl;
		exit(1);
	}
	results = vector<double> (T);
	trials = T;
	double threshold;
	int x = 0, y = 1;
	for (int i = 0; i < T; i++) {
		Percolation perc = Percolation(N);		
		threshold = 0;
		while (!perc.percolates()) {
			do {
//				x++;
				x = rand() % N + 1;
				y = rand() % N + 1;
			} while (perc.isOpen(x, y));
//			cout << x << " " << y << endl;
			perc.open(x, y);
			threshold++;
		}
		results[i] = threshold / (N * N);
	}
}

double PercolationStats::mean() {
	return (Stats::mean(results));
}

double PercolationStats::stddev() {
	return (Stats::stddev(results));
}

double PercolationStats::confidenceLo() {
	return (mean() - 1.96 * stddev() / sqrt(trials));
}

double PercolationStats::confidenceHi() {
	return (mean() + 1.96 * stddev() / sqrt(trials));
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int T = atoi(argv[2]);
//	cout << N << " " << T << endl;
	PercolationStats test = PercolationStats(N, T);
	cout << "mean = " << test.mean() << endl;
	cout << "stddev = " << test.stddev() << endl;
	cout << "95% confidence interval = " << test.confidenceLo() << ", " << test.confidenceHi() << endl;
	return 0;
}