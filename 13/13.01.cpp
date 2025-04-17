/*
Реализуйте алгоритм преобразования коллекции 8-битных целых чисел в строку шестнадцатиричных цифр.
Например, коллекция 0xBA, 0xAD должна быть преобразована в строку "BAAD". Для хранения коллекции
можно использовать контейнер std::vector. Используйте строковый поток вывода и манипуляторы потоков. [25]
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

// Функция преобразования коллекции 8-битных чисел в строку шестнадцатиричных цифр
std::string toHexString(const std::vector<uint8_t>& bytes) {
    std::ostringstream oss;
    oss << std::uppercase << std::hex; // Вывод в верхнем регистре и шестнадцатиричном (hex) формате

    for (uint8_t byte : bytes) {
        oss << std::setw(2) << std::setfill('0') << static_cast<int>(byte); // Задание двух символов на байт (чтобы обеспечить, что 0x0A -> 0A, а не 0x0A -> A)
    }

    return oss.str();
}

int main() {
    std::vector<uint8_t> data = {0xBA, 0xAD, 0xF0, 0x0D};

    std::string hexString = toHexString(data);
    std::cout << hexString << std::endl;

    return 0;
}
