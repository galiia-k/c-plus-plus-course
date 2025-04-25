// Реализуйте алгоритм вычисления числа π методом Монте-Карло, используя несколько параллельных потоков. [25]
// Описание используемого метода находится в файле 14.03.md

#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include <atomic>

// создание общей переменной для всех потоков 
std::atomic<long long> inside_circle{0}; 

// функция, которая обновляет общее значение точек в круге
void monte_carlo_pi(int samples) {
    // создание случайного набора чисел, распределенных равновероятно на промежутке [0, 1]
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    int local_inside = 0;
    for (int i = 0; i < samples; ++i) {
        double x = dist(gen);
        double y = dist(gen);
        if (x * x + y * y <= 1.0) {
            ++local_inside;
        }
    }
    inside_circle += local_inside;
}

int main() {
    int total_samples = 1'000'000; // общее число точек для М-К
    int num_threads = std::thread::hardware_concurrency(); // количество потоков
    int samples_per_thread = total_samples / num_threads; // количество точек на один поток

    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(monte_carlo_pi, samples_per_thread);
    }

    for (auto& t : threads) {
        t.join();
    }

    double pi_estimate = 4.0 * inside_circle / total_samples;
    std::cout << "Примерное значение числа пи:" << pi_estimate << std::endl;

    return 0;
}