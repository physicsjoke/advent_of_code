#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::ifstream infile("../../01/input_day1.txt");
    std::string line;
    std::vector<int> left;
    std::vector<int> right;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { throw std::invalid_argument("Could not read two integers into this " + line); } // error

        left.push_back(a);
        right.push_back(b);
    }
    std::cout << "Read " << left.size() << " lines" << std::endl;

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    long long int distance {0};
    auto right_iter = right.begin();

    for (auto iter = left.begin(); iter != left.end(); iter++) {
        distance += std::abs(*iter - *right_iter);
        right_iter++;
    }
    std::cout << "Result: " << distance << std::endl;

    return 0;
}