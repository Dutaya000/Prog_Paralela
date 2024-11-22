//Crea un programa donde dos hilos intenten incrementar un contador compartido. Usa std::mutex 
//para asegurarte de que sólo un hilo puede modificar el contador a la vez.

#include<iostream>
#include<thread>
#include<mutex>

int contador=0;
std::mutex mtx;

//crear hilo1
void hilo1(){
   // mtx.lock();
    contador++;
    std::cout<<contador<<std::endl;
    //mtx.unlock();
}

int main(){
    //creando 2 hilos 
    std::thread h1(hilo1);

    h1.join();
    return 0;
}
