#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <uxhw.h>
#include <cassert>


auto qexp(double lambda, double p ){
	assert(lambda > 0);
	assert(p >= 0);
	assert(p <= 0);

	return - std::log(1-p) / lambda;
}

int main(int argc, char *  argv[])
{
	std::vector<double> vec {
		UxHwDoubleUniformDist(0.0, 1.0),
	};

	std::cout << "Initial distributions:" << std::endl;
	for (const auto& dist : vec)
	{
		std::cout << dist << std::endl;
	}

	double exponential_dist = qexp(1, vec[0]);

	std::cout << exponential_dist << std::endl;

#ifdef DEBUG
	std::cout << "debug message" << std::endl;
#endif

	return 0;
}

