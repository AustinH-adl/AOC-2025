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
    long value = 0;
    for (std::vector<int> bank : banks) {
        int maxidx = bank.size()-1;
        int secmax = 0;
        for(int i = bank.size()-1; i >=0; i--) {
            if (bank[maxidx] <= bank[i]) {
                maxidx = i;
            }
        }
        secmax = bank[bank.size()-1];
        if (maxidx != bank.size()-1) {
            for(int i = bank.size()-1; i > maxidx; i--) {
                secmax = std::max(secmax, bank[i]);
            }
            value += (bank[maxidx]*10) + secmax;
        } else {
            secmax = 0;
            for(int i = 0; i < maxidx; i++) {
                secmax = std::max(secmax, bank[i]);
            }
            value += (secmax*10) + bank[maxidx];
        }
    }
    std::cout << value << std::endl;
    return 0;
}