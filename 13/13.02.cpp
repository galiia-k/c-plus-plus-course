/*
Напишите программу, которая выведет корректно отформатированные первые 10 строк треугольника Паскаля. [25]
*/

#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    const int rows = 10;
    std::vector<std::vector<int>> triangle;

    // Генерация значений треугольника Паскаля
    for (int i = 0; i < rows; ++i) {
        triangle.push_back(std::vector<int>(i + 1, 1));
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Задаем максимальную ширину (ширина последней строки)
    const int width = 6;
    const int maxWidth = rows * width; 

    // Вывод

    for (int i = 0; i < rows; ++i) {
        // Расчет количества отступов (пробелов)
        int spaces = (maxWidth - (i + 1) * width) / 2;

        // Вывод передних отступов
        for (int s = 0; s < spaces; ++s) {
            std::cout << " ";  
        }

        // Вывод чисел с шириной 6
        for (int num : triangle[i]) {
            std::cout << std::setw(width) << num; 
        }

        std::cout << std::endl;
    }
    return 0;
}
