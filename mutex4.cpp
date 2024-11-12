#include <iostream>
#include <thread>

int contador = 0;

void incrementar() {
    for (int i = 0; i < 5; ++i) {
        contador++;
        std::cout << "Contador: " << contador << std::endl;
    }
}

int main() {
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    return 0;
}
