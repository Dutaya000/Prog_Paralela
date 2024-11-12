//#Crea un programa que tenga un contador compartido entre dos hilos que lo incrementen. 
//Usa un mutex para asegurarte de que solo un hilo pueda incrementarlo a la vez.

#include<iostream>
#include<thread>
#include<mutex>

int cont = 0; 
std::mutex mtx; 

void incrementar(){
    mtx.lock();
    cont+=3;
    std::cout<<"Contador"<<cont<<std::endl;
    mtx.unlock();
}
int main(){
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();
    return 0; 
}