#include<iostream>
#include<thread>
#include<mutex>

int contador = 0; 
std::mutex mtx;
void incrementar(){
    mtx.lock();
    contador++;
    std::cout<<"Contador:"<<contador<<std::endl;
    mtx.unlock();
}
int main(){
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();
    return 0;
}