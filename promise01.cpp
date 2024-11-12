#include<iostream>
#include<thread>
#include<future>
#include<stdexcept>
using namespace std;
void lanzarException(promise<int>& prom){
    try{
        throw runtime_error("Error: Fallo en la operacion");
    }catch(...){
        prom.set_exception(std::current_exception());
    }
}

int main(){
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread hilo(lanzarException,ref(prom));

    try{
        int resultado = fut.get();
        cout<<"Resultado: "<<resultado<<endl;
    }catch(const exception& e){
        cout<<"Exception capturada:"<<e.what()<<endl;   
    }
    hilo.join();
    return 0;
}