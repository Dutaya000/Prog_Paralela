//Crea un hilo que calcula un valor simple (por ejemplo, sumar dos números) y lo envía al hilo principal
// utilizando std::promise y std::future.
#include<iostream>
#include<thread>
#include<future>
using namespace std; 

void calcularSuma(promise<int>& prom,int a ,int b){
    int resultado = a+b;
    prom.set_value(resultado);
}

int main(){
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread hilo(calcularSuma, ref(prom),5,3);
    int resultado=fut.get();
    cout<<"la suma es "<<resultado<<endl;

    hilo.join();
    return 0;
}


