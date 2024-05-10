#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

const std::string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int findFirstAndLastWord(const std::string& line, char& first, char& last) {
    int firstWord = 999;
    int lastWord = -1;

    for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++) {
        size_t found = line.find(num[i]);
        if (found != std::string::npos) {
            if (static_cast<int>(found) < firstWord) {
                firstWord = found;
                first = '0' + i;
            }
            if (static_cast<int>(found) > lastWord) {
                lastWord = found;
                last = '0' + i;
            }
        }
    }

    return firstWord;
}

void findFirstAndLastDigit(const std::string& line, int firstWord, char& first, char& last) {
    for (size_t i = 0; i < line.length(); i++) {
        if (isdigit(line[i])) {
            if (first == '\0' || static_cast<int>(i) < firstWord) {
                first = line[i];
                firstWord = static_cast<int>(i);
            }
            if (last == '\0' || static_cast<int>(i) > firstWord) {
                last = line[i];
            }
        }
    }
}

int main() {
    std::string nazwaPliku = "text1.txt"; // trzeba bylo podac pelna sciezke
    std::ifstream file(nazwaPliku);
    std::string line;
    int sum = 0;

    if (!file.is_open()) {
        std::cerr << "Could not open file." << std::endl;
        return 1;
    } else {
        while (std::getline(file, line)) {
            char first = '\0';
            char last = '\0';

            int firstWord = findFirstAndLastWord(line, first, last);
            findFirstAndLastDigit(line, firstWord, first, last);

            if (first != '\0' && last != '\0') {
                std::string numberStr = {first, last};
                int number = std::stoi(numberStr);
                sum += number;
            }
        }

        file.close();
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}