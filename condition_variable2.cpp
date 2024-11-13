//Crear dos hilos. El primer hilo debería 
//esperar a que el segundo hilo realice una
// acción específica, 
//usando std::condition_variable.

#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
std::condition_variable cv;
bool listo=false;

void hiloEsperar(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[]{return listo;});
    std::cout<<"Hilo 1 : condicion cumplida, continuando...";
}
void hiloSenal(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lock(mtx);
        listo=true;
        std::cout<<"Hilo2: Condicion establecida,notificando...";
    }
    cv.notify_one();
}
int main(){
    std::thread t1(hiloEsperar);
    std::thread t2(hiloSenal);

    t1.join();
    t2.join();
    return 0;
}