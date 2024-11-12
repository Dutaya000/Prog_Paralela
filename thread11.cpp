//Crear un hilo que imprima un saludo y se desprenda

#include<iostream>
#include<thread>

void saludar(){
    std::cout<<"Hola desde el hilo desprendido"<<std::endl; 
}
int main(){
    std::thread t(saludar);//crear un hilo 
    t.detach();//desprender el hilo 

    std::cout<<"Hilo principal ejecutandose:"<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(30));

    return 0;
}

