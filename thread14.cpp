//Crear un hilo que simplemente espera un momento antes de imprimir un mensaje.

#include<iostream>
#include<thread>

void message(){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"Message"<<std::endl;
}

int main(){
    std::thread t(message);
    t.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout<<"Message main thread"<<std::endl; 
    return 0;
}