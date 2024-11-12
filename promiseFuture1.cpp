//Crea un programa donde un hilo secundario calcule el cuadrado de un número
// y envíe el resultado al hilo principal usando std::promise.
// El hilo principal debe esperar el resultado y luego imprimirlo.

#include<iostream>
#include<future>
#include<thread>
using namespace std;

void cuadrado(promise<int>prom,int num){
    int res=num*num;
    prom.set_value(res);
}
int main(){
    promise<int> prom;
    future<int> fut=prom.get_future();

    thread hs(cuadrado,move(prom),9);
    cout<<"Resultado: "<<fut.get()<<endl;
    hs.join();
    return 0;
}