// Продемонстрируйте использование разделяемого будущего результата в двух потоках на std::shared_future [25]

#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// функция, результат которой будет разделяться
int compute_value() {
    std::this_thread::sleep_for(std::chrono::seconds(4)); // имитация долгого сложного вычисления 
    std::cout << "вычисление завершено" << std::endl;
    return 0;
}

// потоки, использующие общий результат
void use_shared_future(std::shared_future<int> f, const std::string& name) {
    std::cout << name << " ждёт результат..." << std::endl;
    int result = f.get();
    std::cout << name << " получил результат: " << result << std::endl;
}

int main() {
    // создаём future и преобразуем его в shared_future
    std::future<int> fut = std::async(std::launch::async, compute_value);
    std::shared_future<int> shared_fut = fut.share();

    // Создаём два потока, использующих один и тот же shared_future
    std::thread t1(use_shared_future, shared_fut, "Поток 1");
    std::thread t2(use_shared_future, shared_fut, "Поток 2");

    t1.join();
    t2.join();

    return 0;
}
