#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cstring>
#include <unordered_set>
#include <cmath>

int main() {
    std::ifstream file("input1.txt");
    if (!file.is_open()) {
        // std::cerr << "Problem openning file.";
        return 1;
    }

    std::string line;
    std::vector<std::string> row;
    
    while(std::getline(file, line)) {
        row.push_back(line);
    }
    int res = 0;
    std::vector<std::pair<int,int>> adj = {{-1,-1}, {-1,0}, {-1,1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < row.size(); i++) {
        for (int j = 0; j < row[i].size(); j++) {
            int numadj = 0;
            if (row[i][j]=='@') {
                for (auto dir : adj) {
                    if (i+dir.first>=0 && j+dir.second>=0 && i+dir.first < row.size() && j+dir.second < row[i].size()) {
                        if (row[i+dir.first][j+dir.second]=='@') {
                            numadj++;
                        }
                    }
                }
                if (numadj<4) {
                    res++;
                }
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}