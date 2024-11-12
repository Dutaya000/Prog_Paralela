#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int contador = 0;

void tarea() {
    for (int i = 0; i < 5; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        contador++;
        std::cout << "Contador: " << contador << " (Hilo: " << std::this_thread::get_id() << ")" << std::endl;
    }
}

int main() {
    std::thread t1(tarea);
    std::thread t2(tarea);

    t1.join();
    t2.join();

    std::cout << "Valor final: " << contador << std::endl;
    return 0;
}
