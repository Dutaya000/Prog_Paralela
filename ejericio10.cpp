//Crear un hilo que imprima un mensaje después de un pequeño retraso
#include<iostream>
#include<thread>

void imprimirMensaje(){
    for(int i=0;i<5;++i){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout<<"Mensaje desde un hilo desprendido"<<std::endl;
    }
}

int main(){
    std::thread t(imprimirMensaje);
    t.detach();

    std::cout<<"Hilo  principal continua su ejecucion "<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout<<"Fin del hilo principal"<<std::endl;
    return 0;
}