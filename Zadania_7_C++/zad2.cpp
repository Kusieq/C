#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define LINE_MAX_LENGTH 1024
#define LIMIT_RED 12
#define LIMIT_GREEN 13
#define LIMIT_BLUE 14

void processFile(const std::string &filename);
void analyzeLine(const std::string &line, int &red, int &green, int &blue);
int extractColorValue(const std::string &line, int index);

int main() {
    processFile("text2.txt"); // trzeba podac pelna sciezke
    return 0;
}

void processFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;
    int suma = 0;
    int mocsuma = 0;
    int lineId = 0;
    int red, green, blue;

    while (std::getline(file, line)) {
        lineId++;
        red = green = blue = 0;
        analyzeLine(line, red, green, blue);

        if (red <= LIMIT_RED && green <= LIMIT_GREEN && blue <= LIMIT_BLUE) {
            suma += lineId;
        }

        int moc = red * green * blue;
        mocsuma += moc;
    }

    file.close();

    std::cout << "\nsuma: " << suma << std::endl;
    std::cout << "\nmoc: " << mocsuma << std::endl;
}

void analyzeLine(const std::string &line, int &red, int &green, int &blue) {
    std::vector<std::string> colors = {"red", "green", "blue"};
    for (size_t i = 0; i < colors.size(); i++) {
        size_t found = line.find(colors[i]);
        while (found != std::string::npos) {
            int index = static_cast<int>(found);
            int value = extractColorValue(line, index);
            switch (i) {
                case 0:
                    if (value > red) red = value;
                    break;
                case 1:
                    if (value > green) green = value;
                    break;
                case 2:
                    if (value > blue) blue = value;
                    break;
            }
            found = line.find(colors[i], found + 1);
        }
    }
}

int extractColorValue(const std::string &line, int index) {
    int value;
    if (std::isdigit(line[index - 3])) {
        std::string numberStr = line.substr(index - 3, 2);
        value = std::stoi(numberStr);
    } else {
        std::string numberStr = line.substr(index - 2, 1);
        value = std::stoi(numberStr);
    }
    return value;
}
