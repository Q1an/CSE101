// Tester for PA1 Worm
//
// DO NOT MODIFY

#include "Worm.hpp"
#include "TestGraph.hpp"

int main(int argc, char * argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid number of arguments; expecting 1 for file name" << std::endl;
        exit(1);
    }

    std::ifstream input (argv[1], std::ios::in);
    std::string line;

    int n;            // board size
    int s1, s2;       // start coordinates
    int d1, d2;       // end coordinates
    std::list<int> o; // obstacle list

    // read board size
    if (getline(input, line)) {
        std::stringstream stream(line);
        stream >> n;
    }
    else {
        std::cerr << "Invalid test file format for Worm" << std::endl;
        exit(1);
    }

    // read starting coor
    if (getline(input, line)) {
        std::stringstream stream(line);
        stream >> s1;
        stream >> s2;
    }
    else {
        std::cerr << "Invalid test file format for Worm" << std::endl;
        exit(1);
    }

    // read ending coor
    if (getline(input, line)) {
        std::stringstream stream(line);
        stream >> d1;
        stream >> d2;
    }
    else {
        std::cerr << "Invalid test file format for Worm" << std::endl;
        exit(1);
    }

    // read list of food locations
    if (getline(input, line)) {
        std::stringstream stream(line);
        int food;
        while (stream >> food) {
            o.push_back(food);
        }
    }
    else {
        // in case last line is omitted to indicate no food.. no error
    }

    std::cout << "Result of Worm: " << canReachBed(n, s1, s2, d1, d2, o) << std::endl;

    return 0;
}
