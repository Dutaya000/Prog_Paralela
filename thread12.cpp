//Crear un hilo que cuente hasta 3 con un pequeño retraso entre cada número

#include<iostream>
#include<thread>

void contar(){
    for(int i=0;i<3;++i){
        std::cout<<i+1<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }
}

int main(){
    std::thread t(contar);
    t.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(2400));
    return 0; 
}