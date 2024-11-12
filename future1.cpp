#include<iostream>
#include<thread>
#include<future>

int main(){
    std::future<int> fut = std::async([] { return 42; });
    int result = fut.get();  // Espera el resultado y obtiene 42
    std::cout<<"Resultado: "<<result;
    return 0;
}