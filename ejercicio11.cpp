//Define una función que reciba un número 
//como parámetro e imprima ese número. Luego crea tres hilos y pásales valores diferentes.

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mtx;

void id(int i){
    std::cout << "Hilo " << id << " está en ejecución." << std::endl;
}

int main(){

    std::thread hilo1(id,1);
    std::thread hilo2(id,2);
    std::thread hilo3(id,3);
    
    hilo1.join();
    hilo2.join();
    hilo3.join();
    return 0;
}
