//import libraries:
//  iostream to handle inputs and outputs of data
//  fstream to handle files
//  vector to store data in dynamic arrays
//  cmath to handle mathematical operations
//  string to instantiate string objects
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

//declare the following functions so that the compiler
//  understands what their titles refer to
void print_vector(std::vector<int>);
bool isprime(int);
std::vector<int> factorize(int);
std::vector<int> prime_factorize(int);
void pascal_row(int);
void test_isprime();
void test_factorize();
void test_prime_factorize();

//define the main function that is run upon executing the compiled file
int main() {
    /* Q1 Conditional Statements */
    //ask the user to input a number that assigns variable n its value
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;

    //based the on value of n, perform some action ...
    switch(n) {
        //if n==-1, output "negative one" to the console
        case -1:
            std::cout << "negative one\n";
            break;
        //if n==0, output "negative one" to the console
        case 0:
            std::cout << "zero\n";
            break;
        //if n==1, output "negative one" to the console
        case 1:
            std::cout << "positive one\n";
            break;
        //else, output "negative one" to the console
        default:
            std::cout << "other value\n";
            break;
    }
    std::cout << "\n";

    /* Q2 Printing a Vector */
    //instantiate an empty vector then use a for loop to populate it
    std::vector<int> vec;
    int size = 10;
    for (int i = 1; i <= size; i++) {
        vec.push_back(i);
    }
    //print out the vector to the console element by element via print_vector
    std::cout << "Printing a vector of size " << size << ":\n";
    print_vector(vec);
    std::cout << "\n";

    /* Q3 While Loops */
    //set the max element of the Fibonacci sequence
    int max = 4000000;
    //initialize the Fibonacci sequence to be 1, 2
    std::vector<int> fibs{1, 2};
    //compute a new element of the Fibonacci sequence by adding the last two elements of the current sequence
    int fib = fibs[fibs.size()-1] + fibs[fibs.size()-2];
    //continue computing Fibanacci sequence values while they are less than the max value of 4,000,000
    //  append each newly computed value to the end of the Fibonacci sequence vector
    while (fib <= max) {
        fibs.push_back(fib);
        fib = fibs[fibs.size()-1] + fibs[fibs.size()-2];
    }
    std::cout << "Last 3 Fibonacci numbers less than 4,000,000: " << fibs[fibs.size()-1] << ", " << fibs[fibs.size()-2] << ", and " << fibs[fibs.size()-3] << ".\n";
    std::cout << "\n";

    /* Q4a If Prime */
    //run the test function to check results of isprime
    test_isprime();
    std::cout << "\n";

    /* Q4b Factorize */
    //run the test function to check results of factorize
    test_factorize();
    std::cout << "\n";

    /* Q4c Prime Factorization */
    //run the test function to check results of prime_factorize
    test_prime_factorize();
    std::cout << "\n";

    /* Q5 Recursive Functions and Loops */
    //print the n=5th row of Pascal's Triangle via pascal_row function
    n = 5;
    std::cout << "The first " << n << " rows of Pascal's Triangle:\n";
    pascal_row(n);
    
    //return 0 at the end of the main function
    //  since the code got to this line without raising an error
    return 0;
}

void print_vector(std::vector<int> v) {
    /*
    Print the contents of a vector by iterating through
    its elements, printing each one with a whitespace after it.
    A newline is added after the last element of the vector
    has been output to the console.
    */
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

bool isprime(int n) {
    /*
    Check whether or not a number, n, is prime.
    If n == 1, return 0 since 1 is not prime.
    Otherwise, iterate from 2 to n-1, finding the modulus of
    n with that number. If this modulus, n % i == 0, then we 
    know that n is evenly divisible by this i such that there exists an
    integer not equal to 1 or n that divides n. If this is true,
    then the number is not prime, so return 0.
    Otherwise, return 1 since no even divisors exist.
    */
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
    /*
    Test the isprime function through 3 use cases.
    */
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
}

std::vector<int> factorize(int n) {
    /*
    Find the numbers that evenly divide a number, n.
    To do this, iterate from 1 to n, inclusively, finding the 
    modulus, n % i. For each modulus where n % i == 0, append 
    this number to a vector of numbers that is eventually returned
    after all iterates have been considered. Since a number evenly
    divides n if n % i == 0, then such a condition defines a number, i,
    as a factor of n.
    */
    std::vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }    
    return answer;
}

void test_factorize() {
    /*
    Test the factorize function through 3 use cases.
    */
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

std::vector<int> prime_factorize(int n) {
    /*
    Find the prime factors of a number, n.
    A number is a prime factor of n if it is an element
    of the set of prime numbers whose product yields the 
    number, n. Thus, to find the prime factors, begin with
    the number n and find the smallest prime number that evenly
    divides it. Once found, store this iterate then divide n by it
    before beginning the process with the next iterate which is 
    less than or equal to n. This process continues for all integers
    between 2 and n, inclusively.
    */
    std::vector<int> answer;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            answer.push_back(i);
            n = n / i;
        }
    }
    return answer;
}

void test_prime_factorize() {
    /*
    Test the prime_factorize function through 3 use cases.
    */
    print_vector(prime_factorize(2));
    print_vector(prime_factorize(72));
    print_vector(prime_factorize(196));
}

void pascal_row(int n) {
    /*
    Function that returns the first n rows of Pascal's Triangle.
    To return these rows, we consider Pascal's Triangle to be a 
    vector of integer-carrying vectors, with the ith integer-carrying
    vector being the (i+1)th row of the triangle.
    To return these rows, iterate an integer, i, 0 to n, inclusively.
    If i == 0, then append the first row as a vector, {1}, onto the vector of vectors.
    If i == 1, then append the second row as a vector {1, 1} onto the vector of vectors.
    Otherwise, append the (i+1)th row as a vector of vectors constructed as follows:
        Step 1: Store the previous row (the last element in the vector of vectors) as a
                local variable, prev_row.
        Step 2: Initialize the (i+1)th row as a local vector variable, row, 
                to be a vector of 1s with size (i+1).
        Step 3: Iterate an int, j, from 1 to the number of elements in the previous row minus 1.
                At each step, make the jth element of row the sum of the jth and (j-1)th elements
                    of prev_row.
        Step 4: Append the local variable within this else branch's scope, row, to the vector of vectors.
    Once each row of Pascal's Triangle has been stored in the vector of vectors, iterate through this
    vector of vectors, printing each vector to the console via print_vector.
    */
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