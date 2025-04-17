#include <iostream>
#include <string>
#include <cctype> // для использования isalpha, toupper, tolower

std::string CapitalizeWords(const std::string& input) { 
    std::string result = input;
    bool newWord = true; // флаг начала нового слова

    for (char& c : result) {
        if (std::isalpha(c)) { // проверка того, является ли символ буквой
            if (newWord) {
                c = std::toupper(c); // перевод первой буквы слова в верхний регистр
                newWord = false;
            } else {
                c = std::tolower(c); // перевод оставшихся букв в нижний регистр
            }
        } else {
            newWord = true;
        }
    }

    return result;
}

int main() {
    std::string text = "heLLo, woRLD";
    std::string capitalized = CapitalizeWords(text);
    std::cout << capitalized << std::endl; 
    return 0;
}
