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
    std::vector<std::vector<int>> grid;
    long long password = 0;
    std::vector<char> operations;
    while(std::getline(file, line)) {
        // std::cout << line << std::endl;

        std::stringstream stream(line);
        std::string str;
        std::vector<int> temp;
        
        while(std::getline(stream, str, ' ')) {
            if (str.empty()) continue;
            
            if (str == "*" || str == "+") {
                operations.push_back(str[0]);
                continue;
            }
            temp.push_back(stoi(str));
        }
        grid.push_back(temp);

    }
    long long res = 0;
    bool add;
    std::cout << grid.size() << " " << grid[0].size() << std::endl;
    for (int col = 0; col < grid[0].size(); col++) {
        bool add = (operations[col]=='+');
        long tempres = 0;
        // std::cout << "col = " << col << std::endl;
        for (int row = 0; row < grid.size()-1; row++) {
            // std::cout << grid[row][col] << std::endl;
            if (add || row==0) {
                tempres += grid[row][col];
            } else {
                tempres *= grid[row][col]; 
            }
        }
        std::cout << tempres << std::endl;
        res +=tempres;
    }

    std::cout << res << std::endl;

    return 0;
}