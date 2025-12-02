#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#include <unordered_set>
#include <cmath>

bool isValidB(long id) {
    std::string str = std::to_string(id);

    for(size_t i = 1; i <= str.size() / 2; i++) {
        for(size_t j = i; j < str.size(); j += i) {
            if(strncmp(str.c_str(), str.c_str() + j, i) != 0) {
                goto valid;
            }
        }

        return false;
        valid: ;
    }

    return true;
}


bool hasDifferentChunk(const std::string& s, int size) {
    if (size <= 0) return false;

    std::string first = s.substr(0, size);

    for (std::size_t pos = size; pos < s.size(); pos += size) {
        std::string chunk = s.substr(pos, size);
        if (chunk != first) {
            return true;
        }
    }

    return false; // All chunks were equal
}

// bool isInvalid(std::string s) {
//     int n = s.size();
//     bool flag = false;

//     for (int i = 1; i < n/2; i++) {
//         flag = !hasDifferentChunk(s, i) | HalfisInvalid(s) | flag;
        
//     }
//     return flag;
// }

int main() {
    std::ifstream file("input2.txt");
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
            if (!isValidB(i)) password += i;
        }
    }
    std::cout << password;
    return 0;
}