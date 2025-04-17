/*
Напишите программу, которая удалит все пустые и пробельные строки из пользовательского текстового файла. [25]
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

// Проверка на то, состоит строка только из пробелов или нет
bool isSpaceOnly(const std::string& line) {
    return std::all_of(line.begin(), line.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";

    std::ifstream in(inputFile);

    std::ofstream out(outputFile);

    std::string line;
    while (std::getline(in, line)) {
        if (!line.empty() && !isSpaceOnly(line)) {
            out << line << std::endl;
        }
    }

    std::cout << "Результат записан в " << outputFile << std::endl;

    return 0;
}
