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
    std::vector<std::vector<int>> banks;
    int index = 0;
    while(std::getline(file, line)) {
        std::vector<int> bank(line.size());
        for (int i = 0; i < line.size(); i++) {
            bank[i]=(int(line[i]-'0'));
        }
        banks.push_back(bank);
        index++;
    }
    long long value = 0;
    
    for (std::vector<int> bank : banks) {
        int pos = 0;
        long long joltage = 0;
        for (int i = 12-1; i >= 0; i--) {
            int digit = 0;
            for (int j = pos; j < bank.size()-i; j++) {
                if (digit < bank[j]) {
                    digit = bank[j];
                    pos = j + 1;
                }
            }
            joltage *= 10;
            joltage += digit;
        }
        std::cout << joltage << std::endl;
        value += joltage;
    }
    std::cout << value << std::endl;
    return 0;
}