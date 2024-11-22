#include <iostream>
#include <thread>
#include <semaphore>
using namespace std;
std::counting_semaphore<3> semaforo(2);  // Permite hasta 2 hilos al mismo tiempo

void tarea() {
    semaforo.acquire();  // Decrementar el contador
    std::cout << "Hilo en ejecución." << std::endl;
    semaforo.release();  // Incrementar el contador
}

int main() {
    std::thread t1(tarea), t2(tarea), t3(tarea);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

