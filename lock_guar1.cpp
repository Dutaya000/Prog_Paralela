#include<iostream>
#include<thread>
#include<mutex>

int contador = 0; 
std::mutex mtx;

void incrementar(){
    std::lock_guard<std::mutex> guard(mtx);
    contador++;
    std::cout<<"Contador: "<<contador<<std::endl;
}
int main(){
    std::thread t(incrementar);
    std::thread t1(incrementar);

    t.join();
    t1.join();
    
    return 0;
}