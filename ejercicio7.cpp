//Crea un programa donde un hilo ejecute una función global que imprima los números del 1 al 5. 
//El hilo principal debe esperar hasta que el hilo secundario termine.

#include<iostream>
#include<thread>

void mostrar(int num){
    for(int i=1;i<=num;i++){
        std::cout<<i<<std::endl;
    }
}

int main(){
    std::thread t(mostrar,5);
    t.join();
    return 0;
}