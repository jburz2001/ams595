#ifndef PI_APPROX_H
#define PI_APPROX_H

double f(double);

double trapezoidal_rule(double, double, int);

struct PiResults {
    double approx;
    double error;
};

PiResults approx_pi(int);

#endif