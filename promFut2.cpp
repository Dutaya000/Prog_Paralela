#include<iostream>
#include<thread>
#include<future>
using namespace std;

void dividir(promise<int> prom,int numerador,int denominador){
    if(denominador==0){
        prom.set_exception(std::make_exception_ptr(std::runtime_error("Division por cero")));
    }else{
        prom.set_value(numerador/denominador);
    }
}

int main(){
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread hs(dividir,move(prom),10,0);

    try
    {
        int resultado = fut.get();
        cout<<"Resultado: "<<resultado;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    hs.join();
    return 0;    
}