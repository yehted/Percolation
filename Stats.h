#include "stdafx.h"
#include <math.h>
#include <vector>

class Stats {
public:
	static double sum(std::vector<double> x);
	static double mean(std::vector<double> x);
	static double stddev(std::vector<double> x);
	static double var(std::vector<double> x);

private:
	Stats();
};