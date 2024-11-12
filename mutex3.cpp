#include<iostream>
#include<thread>
#include<mutex>

int cont=0;
std::mutex mtx;
void incrementar(){
    mtx.lock();
    cont++;
    std::cout<<"Contador: "<<cont<<std::endl; 
    mtx.unlock();
}

int main(){
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();
    return 0;
}