#include "stdafx.h"
#include <math.h>
#include <vector>
using namespace std;

class Stats {
public:
	static double sum(vector<double> x);
	static double mean(vector<double> x);
	static double stddev(vector<double> x);
	static double var(vector<double> x);

private:
	Stats();
};