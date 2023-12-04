#include <vector>
#include <iostream>
#include <cmath>
#include "approximations.h"
#include "pi_approx.h"

int main() {
    const int N = 10000;
    PiResults pi_approx = approx_pi(N);
    std::cout << "Approximate value of pi for N = " << N << ": " << pi_approx.approx << std::endl;
    std::cout << "Absolute error of approximation of pi for N = " << N << ": " << pi_approx.error << std::endl;

    std::vector<int> num_elements{static_cast<int>(pow(10, 1)),
                                  static_cast<int>(pow(10, 2)),
                                  static_cast<int>(pow(10, 3)),
                                  static_cast<int>(pow(10, 4)),
                                  static_cast<int>(pow(10, 5)),
                                  static_cast<int>(pow(10, 6)),
                                  static_cast<int>(pow(10, 7))};
    int sz = num_elements.size();
    double* pi_approximations = approximations(num_elements);
    std::cout << std::endl;
    for (int i = 0; i < sz; i++) {
        std::cout << "Approximation value of Pi for N = " << num_elements[i] << ": " << pi_approximations[i] << std::endl;
    }

    return 0;
}
