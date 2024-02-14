#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <uxhw.h>
#include <cassert>


auto qexp(double lambda, double p ){
	assert(lambda > 0);
	assert(p >= 0);
	assert(p <= 1);

	return - std::log(1-p) / lambda;
}

// see https://en.wikipedia.org/wiki/Logistic_function
auto logistic(double L, double k, double x, double x0){
	return L / (1 + std::exp(-k*(x - x0)));
}

int main(int argc, char *  argv[])
{
	std::vector<double> vec {
		UxHwDoubleUniformDist(0.0, 1.0),
		UxHwDoubleUniformDist(1.0, 3.0),
	};

	std::cout << "Initial distributions:" << std::endl;
	for (const auto& dist : vec)
	{
		std::cout << dist << std::endl;
	}

	double expected_time_to_wait_on_an_interview = vec[1];
	double exponential_dist = qexp(expected_time_to_wait_on_an_interview, vec[0]);

	double chance_i_will_wait_longer_than_3_days_for_an_interview = logistic(1, 10, exponential_dist, 3);
	double logistic_result = logistic(1, 10, vec[0], 0.5);

	std::cout << exponential_dist << std::endl;
	std::cout << chance_i_will_wait_longer_than_3_days_for_an_interview << std::endl;
	std::cout << logistic_result << std::endl;

#ifdef DEBUG
	std::cout << "debug message" << std::endl;
#endif

	return 0;
}

