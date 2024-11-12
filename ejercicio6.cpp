//Crea una función llamada sumar que acepte dos números enteros como parámetros y imprima su suma. 
//Inicia un hilo que llame a esta función pasando dos números enteros (por ejemplo, 5 y 10).

#include <iostream>
#include <thread>
#include <future>


int sumar(int a,int b){
    return a+b;
}

int main(){
    std::promise<int> prom;
    std::future<int> fut= prom.get_future();


    std::thread hilo([&prom](){
        int resultado = sumar(2,10);
        prom.set_value(resultado);
    });

    hilo.join();
    int resultadoFinal=fut.get();
    std::cout<<"La suma final es: "<<resultadoFinal<<std::endl;
    return 0;
}