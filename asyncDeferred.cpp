#include<iostream>
#include<future>
#include<cmath>

int potencia(int b, int e){
    return std::pow(b,e);
}

int main(){
    std::future<int> resultado = std::async(std::launch::deferred,potencia,2,4);
    std::cout<<"El resultado es : "<<resultado.get();
    return 0;
}
