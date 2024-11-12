#include<iostream>
#include<thread>
#include<future>
using namespace std;

void calcularCuadrado(promise<int> prom,int numero){
    int resultado=numero*numero;
    prom.set_value(resultado);
}

int main(){
    promise<int> prom;
    future<int> fut = prom.get_future();

    thread hs(calcularCuadrado,move(prom),5);
    cout<<"Resultado: "<<fut.get()<<std::endl;
    hs.join();
    return 0;
}