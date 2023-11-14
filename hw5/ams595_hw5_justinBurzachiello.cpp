#include <iostream>
#include <fstream>
#include <vector>

void print_vector(std::vector<int>&);

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

    /* Printing a Vector */
    std::vector<int> vec;
    int size = 10;
    for (int i = 1; i <= size; i++) {
        vec.push_back(i);
    }
    print_vector(vec);

    return 0;
}

void print_vector(std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
}