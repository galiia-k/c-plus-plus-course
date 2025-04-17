/*
Реализуйте алгоритм конкатенации коллекции строк в одну строку через заданный пользователем разделитель
*/

#include <iostream>
#include <vector>
#include <string>

std::string JoinStrings(const std::vector<std::string>& strings, const std::string& delimiter) {
    if (strings.empty()) return "";

    std::string result;
    for (size_t i = 0; i < strings.size(); ++i) {
        result += strings[i]; // прибавление к итоговой строке одной из изначальных строк
        if (i != strings.size() - 1) {
            result += delimiter; // добавление разделителя
        }
    }
    return result;
}

int main() {
    std::vector<std::string> words = {"one", "two", "three"}; // задание вектора строк, которые надо объединить
    std::string delimiter = " + "; // задание разделителя

    std::string joined = JoinStrings(words, delimiter);
    std::cout << joined << std::endl;

    return 0;
}
