#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input1.txt");
    if (!file.is_open()) {
        std::cerr << "Problem openning file.";
        return 1;
    }

    std::string line;
    int location = 50;
    int zeros = 0;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char dir = line[0];

        int val = stoi(line.substr(1)); // string to int from 1st char
        if (dir=='L') { // lower
            location -= val;
        } else if (dir=='R') {
            location += val;
        }
        location = (location%100);
        if (location==0) {
            zeros++;
        }
    }
    std::cout << "zeros: " << zeros << std::endl;
    return 0;
}