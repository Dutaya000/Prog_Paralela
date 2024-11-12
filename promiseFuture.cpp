//Crea un programa donde un hilo secundario calcule el doble de un número dado 
//y lo envíe al hilo principal usando std::promise. 
//El hilo principal debe esperar a que el resultado esté listo y luego imprimirlo en pantalla.

#include<iostream>
#include<thread>
#include<future>
using namespace std;

void doble(promise<int> prom,int num){
    int var=2*num;
    prom.set_value(var);
}
int main(){

    promise<int> prom;
    future<int> fut=prom.get_future();
    thread hs(doble,move(prom),5);
    cout<<"Resultado: "<<fut.get()<<endl;
    hs.join();
    return 0;
}