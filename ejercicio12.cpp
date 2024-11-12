//Implementar dos hilos que incrementen un contador global hasta 500
// cada uno y luego usen join() para sincronizarlos.

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;

int contador=0;

void incrementar(){
    for (int i = 1; i <= 500; i++)
    {
        contador++;
    }
}

int main(){
    std::thread hilo1(incrementar);
    std::thread hilo2(incrementar);

    hilo1.join();
    hilo2.join();

    std::cout<<"Resultado final: "<<contador<<std::endl;
    return 0;
}
