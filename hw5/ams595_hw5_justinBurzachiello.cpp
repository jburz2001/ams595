#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

void print_vector(std::vector<int>&);

bool isprime(int);
std::vector<int> factorize(int);
std::vector<int> prime_factorize(int);
void pascal_row(int);

void test_isprime();
void test_factorize();
void test_prime_factorize();


int main() {
    /* Q1 Conditional Statements */
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    switch(n) {
        case -1:
            std::cout << "negative one\n";
            break;
        case 0:
            std::cout << "zero\n";
            break;
        case 1:
            std::cout << "positive one\n";
            break;
        default:
            std::cout << "other value\n";
            break;
    }
    std::cout << "\n";

    /* Q2 Printing a Vector */
    std::vector<int> vec;
    int size = 10;
    for (int i = 1; i <= size; i++) {
        vec.push_back(i);
    }
    std::cout << "Printing a vector of size " << size << ":\n";
    print_vector(vec);
    std::cout << "\n";

    /* Q3 While Loops */
    int max = 4000000;
    std::vector<int> fibs{1, 2};
    int fib = fibs[fibs.size()-1] + fibs[fibs.size()-2];
    while (fib <= max) {
        fibs.push_back(fib);
        fib = fibs[fibs.size()-1] + fibs[fibs.size()-2];
    }
    std::cout << "Last 3 Fibonacci numbers less than 4,000,000: " << fibs[fibs.size()-1] << ", " << fibs[fibs.size()-2] << ", and " << fibs[fibs.size()-3] << ".\n";

    /* Q4a If Prime */
    std::cout << "\nTesting whether the following arguments to isprime are prime numbers:\n";
    test_isprime();
    std::cout << "\n";

    /* Q4b Factorize */
    std::vector<int> vec2   = factorize(2);
    std::vector<int> vec72  = factorize(72);
    std::vector<int> vec196 = factorize(196);

    std::cout << "Factors of numbers " << 2 << ", " << 72 << ", and " << 196 << ":\n";
    print_vector(vec2);
    print_vector(vec72);
    print_vector(vec196);
    // test_factorize();
    std::cout << "\n";

    /* Q4c Prime Factorization */
    std::vector<int> vec2_prime   = prime_factorize(2);
    std::vector<int> vec72_prime  = prime_factorize(72);
    std::vector<int> vec196_prime = prime_factorize(196);

    std::cout << "Prime factorizations of numbers " << 2 << ", " << 72 << ", and " << 196 << ":\n";
    print_vector(vec2_prime);
    print_vector(vec72_prime);
    print_vector(vec196_prime);
    // test_prime_factorize();
    std::cout << "\n";

    /* Q5 Recursive Functions and Loops */
    n = 5;
    std::cout << "The first " << n << " rows of Pascal's Triangle:\n";
    pascal_row(n);
    
    return 0;
}

void print_vector(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

bool isprime(int n) {
    bool result;
    result = true;
    
    if (n <= 1) {
        result = false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
}

std::vector<int> factorize(int n) {
    std::vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }    
    return answer;
}

// void test_factorize() {
//     print_vector(factorize(2));
//     print_vector(factorize(72));
//     print_vector(factorize(196));
// }

std::vector<int> prime_factorize(int n) {
    std::vector<int> answer;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            answer.push_back(i);
            n = n / i;
        }
    }
    return answer;
}

// void test_prime_factorize() {
//     print_vector(prime_factorize(2));
//     print_vector(prime_factorize(72));
//     print_vector(prime_factorize(196));
// }

void pascal_row(int n) {
    std::vector<std::vector<int>> rows;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            std::vector<int> row{1};
            rows.push_back(row);
        }
        else if (i == 1) {
            std::vector<int> row{1, 1};
            rows.push_back(row);
        }
        else {
            std::vector<int> prev_row = rows[rows.size()-1];
            std::vector<int> row(i+1, 1);
            for (int j = 1; j < prev_row.size(); j++) {
                row[j] = prev_row[j] + prev_row[j-1];
            }
            rows.push_back(row);
        }
    }
    for (int i = 0; i < rows.size()-1; i++){
        print_vector(rows[i]);
    }
}