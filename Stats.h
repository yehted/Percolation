/*
Stats class
Requires vector<double>
Returns, sum, mean, standard deviation, and double
*/
#include <vector>

class Stats {
public:
	static double sum(const std::vector<double> &x);
	static double mean(const std::vector<double> &x);
	static double stddev(const std::vector<double> &x);
	static double var(const std::vector<double> &x);

private:
	Stats();
};