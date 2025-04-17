/*
Напишите программу, которая выведет в консоль отформатированную таблицу с информацией о запущенных
в системе процессах. Для каждого процесса необходимо вывести его название, идентификатор, статус и вла-
дельца. Создайте структуру для представления процесса и контейнер для хранения процессов. Данные для
нескольких процессов можно сгенерировать самостоятельно, не требуется обращаться к операционной системе. [25]
*/

#include <iostream>
#include <vector>
#include <iomanip>

// Структура для процесса
struct Process {
    std::string name;        // Название
    int pid;                 // Идентификатор 
    std::string status;      // Статус 
    std::string owner;       // Владелец 
};

// Функция для вывода заголовка таблицы
void printHeader() {
    std::cout << std::left
              << std::setw(30) << "Process Name" << "| "
              << std::setw(10) << "PID" << "| "
              << std::setw(15) << "Status" << "| "
              << std::setw(10) << "Owner" << std::endl;

    std::cout << std::string(30, '-') << "+-"
              << std::string(10, '-') << "+-"
              << std::string(15, '-') << "+-"
              << std::string(10, '-') << std::endl;
}

// Вывод информации о процессе
void printProcess(const Process& p) {
    std::cout << std::left
              << std::setw(30) << p.name << "| "
              << std::setw(10) << p.pid << "| "
              << std::setw(15) << p.status << "| "
              << std::setw(10) << p.owner << std::endl;
}
int main() {
    // Вектор процессов
    std::vector<Process> processes = {
        {"chrome", 1234, "Running", "galiia"},
        {"firefox", 2345, "Suspended", "galiia"},
        {"vlc", 3456, "Terminated", "galiia"},
        {"code", 4567, "Running", "galiia"},
        {"systemd", 1, "Running", "root"},
        {"bash", 7890, "Running", "galiia"}
    };

    // Печать заголовка таблицы
    printHeader();

    // Печать информации о процессах
    for (const auto& process : processes) {
        printProcess(process);
    }

    return 0;
}
