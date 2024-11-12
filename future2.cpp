#include<iostream>
#include<future>
#include<thread>

void calcularValor(std::promise<int>& prom){
    int resultado = 5+10;
    prom.set_value(resultado);
}
int main(){
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread hiloSecundario(calcularValor,std::ref(prom));

    std::cout<<"Resultado del hilo: "<<fut.get()<<std::endl;
    return 0;
    hiloSecundario.join();
    }