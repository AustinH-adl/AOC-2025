#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#include <unordered_set>
#include <cmath>
#include <algorithm>

int main() {
    std::ifstream file("input2.txt");
    if (!file.is_open()) {
        // std::cerr << "Problem openning file.";
        return 1;
    }

    std::string line;
    std::vector<std::vector<long>> ranges;
    bool brk = false;
    std::string start;
    std::string end;
    while(std::getline(file, line)) {
        if (line.empty()) break;
        std::stringstream stream(line);
        
        std::getline(stream, start, '-');
        std::getline(stream, end, ' ');
        ranges.push_back({stol(start), stol(end)});
    }

    std::sort(ranges.begin(), ranges.end());
    std::vector<std::vector<long>> sortrange;
    sortrange.push_back(ranges[0]);
    for(int i = 1; i < ranges.size(); i++) {
        std::vector<long>& last = sortrange.back();
        std::vector<long>& curr = ranges[i];

        if (curr[0] <= last[1]) {
            last[1] = std::max(last[1], curr[1]);
        } else {
            sortrange.push_back(curr);
        }
    }
    long res = 0;
    for (auto i : sortrange) {
        std::cout << i[0] << " " << i[1] << std::endl;
        res += i[1]-i[0]+1;
    }

    std::cout << res << std::endl;
    return 0;
}