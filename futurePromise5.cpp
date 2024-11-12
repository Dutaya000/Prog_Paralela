#include <iostream>
#include <thread>
#include <future>
using namespace std;

void calcularDoble(promise<int> prom,int num){
    prom.set_value(num*2);    
}
int main(){
    promise<int> prom;
    future<int> fut=prom.get_future();

    thread t(calcularDoble,move(prom),10);

    cout<<"Esperando el resultado del hilo"<<endl;
    cout<<"Resultado: "<<fut.get()<<endl; 

    t.join();
    return 0;
}