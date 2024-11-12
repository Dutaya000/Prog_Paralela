#include <iostream>
#include <future>

using namespace std;

int calcularCuadrado(int numeros){
    return numeros*numeros;
}

int main(){
    std::future<int> fut = std::async(std::launch::async, calcularCuadrado, 5);
    cout<<"Resultado: "<<fut.get()<<endl;
    return 0;
}
