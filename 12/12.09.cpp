/*
Реализуйте алгоритм сжатия строк вида aaabbbccc, состоящих только из латинских букв, в строки вида a3b3c3
*/

#include <iostream>
#include <string>

std::string CompressString(const std::string& input) {
    if (input.empty()) return "";

    std::string result;
    char currentChar = input[0];
    int count = 1;

// Перебор строки по символам
    for (size_t i = 1; i < input.size(); ++i) {
    // Проверка одинаковости подряд идущих символов 
    //(если символы одинаковы, увеличиваем счетчик, если нет, записываем текущую букву и число её повторений)
        if (input[i] == currentChar) {
            ++count;
        } else {
            result += currentChar + std::to_string(count);
            currentChar = input[i];
            count = 1;
        }
    }

    result += currentChar + std::to_string(count); // добавляем последнюю группу
    return result;
}

int main() {
    std::string input = "aaabbbccc";
    std::string compressed = CompressString(input);
    std::cout << compressed << std::endl; 
    return 0;
}
