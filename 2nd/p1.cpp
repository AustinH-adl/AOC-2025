#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#include <unordered_set>
#include <cmath>

bool isInvalid(std::string s) {
    std::string first, second;
    int size = s.size();
    if (size%2!=0) return false;

    first = s.substr(0,size/2);
    second = s.substr(size/2, size);
    return (first==second);
}

int main() {
    std::ifstream file("input1.txt");
    if (!file.is_open()) {
        // std::cerr << "Problem openning file.";
        return 1;
    }
    std::string line, start, end;

    long long password = 0;
    while(std::getline(file, line, ',')) {
        // std::cout << line << std::endl;

        std::stringstream stream(line);
        
        std::getline(stream, start, '-');
        std::getline(stream, end, ' ');
        long startint = stol(start);
        long endint = stol(end);
        for (long i = startint; i < endint; i++) {
            if (isInvalid(std::to_string(i))) password += i;
        }
    }
    std::cout << password;
    return 0;
}