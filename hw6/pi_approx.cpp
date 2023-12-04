#include <iostream>
#include <vector>
#include <cmath>
#include "pi_approx.h"

double f(double x) {
    double arg = 1 - pow(x, 2);
    if (arg < 0) {
        arg *= -1;
    }
    return sqrt(arg);
}

double trapezoidal_rule(double a, double b, int N) {
    //step size
    double deltax = (b - a) / N;

    //discretize x-axis into N subintervals with N+1 points
    std::vector<double> xs(N+1);
    double x = a;
    for (long unsigned int i = 0; i < xs.size(); i++) {
        xs[i] = x;
        x += deltax;
    }

    //compute summand (assuming constant step size over domain)
    double sum = 0.0;
    for (long unsigned int i = 1; i < xs.size(); i++) {
        sum += f(xs[i]) + f(xs[i-1]);
    }

    return deltax * sum / 2;
}

PiResults approx_pi(int N) {
    double a = 0.0;
    double b = 1.0;

    double approx = 4*trapezoidal_rule(a, b, N);
    double error = std::abs(approx - M_PI);

    return {approx, error};
}