#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>


class counted_map {
private:

    std::map<int, int> _map;

public:

    int& operator[](const int& key) {
        return _map[key];
    }

    int add_or_increment(int key) {
        if (_map[key] > 0) {
            _map[key]++;
        } else {
            _map[key] = 1;
        }
        return _map[key];
    }

    int size() {
        return _map.size();
    }
    
    int importance_score(const int& key)  {
        return _map[key] * key;
    }
};
int main() {
    counted_map map {};
    std::vector<int> left {};
    std::ifstream infile("../../01/input_day1.txt");

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a, b;
        if (!(iss >> a >> b)) { throw std::invalid_argument("Could not read two integers into this " + line); } // error
        left.push_back(a);
        map.add_or_increment(b);
    }
    std::cout << "Read " << map.size() << " lines" << std::endl;

    long long int similarity {0};
    similarity = std::accumulate(left.begin(), left.end(), similarity, [&map](long long int acc, int left) {
        return acc + map.importance_score(left);
    });
    std::cout << "Result: " << similarity << std::endl;

    return 0;
}