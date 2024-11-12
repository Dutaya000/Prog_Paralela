//Implementa un programa que simule la 
//comunicación entre un hilo productor y un hilo consumidor
#include<iostream>
#include<future>
#include<thread>

int sumar(int a,int b){
    return a+b;
}

int main(){
    std::promise<int> prom;
    std::future<int> fut =prom.get_future();

    std::thread hilo1();
    return 0;
}