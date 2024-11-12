//Escribe una función tarea_pesada que simule una operación que tome varios segundos.
//Usa std::async con std::launch::deferred para lanzar esta función de forma diferida. 
//Realiza otras
// operaciones en el hilo principal antes de finalmente obtener el resultado de tarea_pesada.

#include <iostream>
#include <future>

int factorial(int num){
    int resultado=1;
    for(int i=1;i<=num;++i){
        resultado*=i;
    }
    return resultado;
}

int main(){
    
    std::future<int> resultado = std::async(std::launch::deferred,factorial,3); 
    std::cout<<"Hola mundo, esperando obtene el siguiente resultado"<<std::endl; 
    std::cout<<"Resultado: "<<resultado.get()<<std::endl; 
    return 0;
}