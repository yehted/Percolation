//#include "stdafx.h"
#include "Stats.h"
using namespace std;

double Stats::sum(const vector<double> &x) {
	size_t N = x.size();
	double sum = 0;
	for (size_t i = 0; i < N; i++) {
		sum += x[i];
	}
	return (sum);
}

double Stats::mean(const vector<double> &x) {
	size_t N = x.size();
	double n_sum = sum(x);
	return (n_sum / N);
}

double Stats::var(const vector<double> &x) {
	size_t N = x.size();
	double avg = mean(x);
	double n_var = 0;
	for (size_t i = 0; i < N; i++) {
		n_var += (x[i] - avg) * (x[i] - avg);
	}
	return (n_var / (N - 1));
}

double Stats::stddev(const vector<double> &x) {
	size_t N = x.size();
	return (sqrt(var(x)));
}