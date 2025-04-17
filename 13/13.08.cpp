#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>

namespace fs = std::filesystem;

std::chrono::system_clock::time_point to_system_clock(fs::file_time_type file_time) {
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(file_time - fs::file_time_type::clock::now()
                      + system_clock::now());
    return sctp;
}

void delete_old_entries(const fs::path& directory, const std::chrono::system_clock::time_point& cutoff_time) {
    if (!fs::exists(directory) || !fs::is_directory(directory)) {
        std::cerr << "Неправильный путь: " << directory << std::endl;
        return;
    }

    for (const auto& entry : fs::directory_iterator(directory)) {
        auto file_time = fs::last_write_time(entry);
        auto system_time = to_system_clock(file_time);

        if (system_time < cutoff_time) {
            std::error_code ec;
            fs::remove_all(entry, ec);
            if (ec) {
                std::cerr << "Не получилось удалить: " << entry.path() << ": " << ec.message() << std::endl;
            } else {
                std::cout << "Удалено: " << entry.path() << std::endl;
            }
        }
    }
}

int main() {
    std::string dir_path;
    std::cout << "Введи путь к папке: ";
    std::getline(std::cin, dir_path);

    int days;
    std::cout << "Введи количество дней для отметки: ";
    std::cin >> days;

    // Вычисляем временную отсечку
    auto now = std::chrono::system_clock::now();
    auto cutoff = now - std::chrono::hours(24 * days);

    delete_old_entries(dir_path, cutoff);

    return 0;
}
