//Modifica el programa anterior para que el hilo imprima "¡Hola, desde el hilo!" en lugar de "¡Hola, mundo!". 
//Asegúrate de que el hilo principal espera a que el hilo termine su ejecución.
#include <iostream>
#include <thread>


void mostrarMensaje(){
    std::cout<<("Hola, desde el hilo")<<std::endl;
}

int main(){
    std::thread t(mostrarMensaje);
    t.join();

    std::cout<<"El hilo principal ha terminado!!"<<std::endl;
    return 0;
}

