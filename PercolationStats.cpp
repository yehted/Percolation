#include "PercolationStats.h"
#include "Stats.h"
#include <time.h>
#include <iostream>
#include <vld.h>

PercolationStats::PercolationStats(): trials(0) {}

PercolationStats::PercolationStats(int N, int T): results(T), trials(T) {
	srand((unsigned int) time(NULL));
	if (N < 1 || T < 1) {
		throw std::invalid_argument("Invalid argument");
	}

	double threshold;
	int x, y;
	for (int i = 0; i < T; i++) {
		Percolation perc(N);		
		threshold = 0;
		while (!perc.percolates()) {
			do {
				x = rand() % N + 1;
				y = rand() % N + 1;
			} while (perc.isOpen(x, y));
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
	using namespace std;
	int N, T;
	if (argc == 3) {
		N = atoi(argv[1]);
		T = atoi(argv[2]);
	}
	else {
		cout << "Size of grid (N): ";
		cin >> N;
		cout << "Number of trials (T): ";
		cin >> T;		
	}		
	
	PercolationStats test(N, T);
	cout << "mean = " << test.mean() << endl;
	cout << "stddev = " << test.stddev() << endl;
	cout << "95% confidence interval = " << test.confidenceLo() << ", " << test.confidenceHi() << endl;
	return 0;
}