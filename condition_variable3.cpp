#include <iostream>
#include <thread>
#include<mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

bool hilo1Terminado = false;
bool hilo2Terminado = false;
void hilo2(){   
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[]{return hilo1Terminado;});
    std::cout<<"Hilo 2 : Ejecutando segundo "<<std::endl;
    hilo2Terminado=true;
    cv.notify_all();
}

void hilo1(){
    std::cout<<"Hilo1: Ejecutando primero";
    {
        mtx.lock();
        hilo1Terminado = true;
        mtx.unlock();
    }
    cv.notify_all();
}

void hilo3(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[] {return hilo2Terminado;});
    std::cout<<"Hilo3: Ejecutando tercero"<<std::endl;
}
int main(){
    std::thread t1(hilo1);
    std::thread t2(hilo2);
    std::thread t3(hilo3);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}