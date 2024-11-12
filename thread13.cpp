//Crear un hilo que imprima un número fijo después de un retraso

#include<iostream>
#include<thread>

void imprimir(int n){
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout<<n<<std::endl;
}
int main(){
    std::thread t(imprimir,10);
    t.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    return 0; 
}