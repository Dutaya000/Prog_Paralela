//Comprobar si un numero es par  o impar


#include<iostream>
#include<future>
#include<thread>
using namespace std;

void esPar(promise<bool> prom,int num){
    bool var;
    if(num%2==0){
        var=true;
    }else{
        var=false;
    }
    prom.set_value(var);
}
int main(){
    promise<bool> prom;
    future<bool> fut=prom.get_future();
    thread hs(esPar,move(prom),3);
    cout<<"Resultado: "<<fut.get()<<endl;
    hs.join();
    return 0;
}