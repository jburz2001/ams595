#include <vector>
#include "approximations.h"
#include "pi_approx.h"

// Function to compute approximations for each specified number of intervals
double* approximations(const std::vector<int>& intervals) {
    int size = intervals.size();
    double* results = new double[size];

    for (int i = 0; i < size; ++i) {
        results[i] = approx_pi(intervals[i]).error;
    }

    return results;
}
