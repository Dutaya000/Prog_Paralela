#include <iostream>
#include <future>
using namespace std;
int cuadrado(int x){
    return x*x;
}

int main(){
    future<int> fut = async(launch::async,cuadrado,4);
    cout<<"Calculadndo el cuadrado"<<endl;
    cout<<"Resultado: "<<fut.get()<<endl;
    return 0; 
}