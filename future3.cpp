#include<iostream>
#include<future>


int calcular(){
    return 10+5;
}

int main(){
    std::future<int>fut = std::async(std::launch::async,calcular());

    int resultado = fut.get();
    std::cout<<"Resultado calculado: "<<resultado<<std::endl;
    return 0; 
}