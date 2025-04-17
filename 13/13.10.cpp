/*
Напишите программу, которая переименует все файлы в заданной директории. Например, Вы можете реали-
зовать изменение регистра символов в названиях файлов. Для переименования используйте функцию-член
replace_filename класса std::filesystem::path. Рекурсивный обход директории выполнять не требуется. [25]
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <algorithm>

namespace fs = std::filesystem;

// Функция для изменения регистра символов в имени файла
std::string toggle_case(const std::string& str) {
    std::string result = str;
    for (char& c : result) {
        if (std::islower(c)) {
            c = std::toupper(c);
        } else if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }
    return result;
}

void rename_files_in_directory(const std::string& dirPath) {
    // Проверка пути
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        std::cerr << "Указан неправильный путь: " << dirPath << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (fs::is_regular_file(entry.status())) {
            // Получение пути к файлу и его имени
            fs::path oldPath = entry.path();
            std::string newName = toggle_case(oldPath.filename().string());

            // Создание нового пути с измененным именем
            fs::path newPath = oldPath.parent_path() / newName;

            // Переименование файла
            try {
                fs::rename(oldPath, newPath);
                std::cout << "Переименовано: " << oldPath.filename() << " -> " << newPath.filename() << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Не получилось переименовать: " << e.what() << std::endl;
            }
        }
    }
}

int main() {
    std::string dirPath;

    // Запрос пути
    std::cout << "Введи путь к нужной папке: ";
    std::getline(std::cin, dirPath);

    // Переименование файлов
    rename_files_in_directory(dirPath);

    return 0;
}
