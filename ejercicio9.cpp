#include<iostream>

class Suma{
    public:
        int operator()(int a, int b){
            return a+b;
        }
};

int main(){
    Suma suma;
    int resultado = suma(3,4);
    std::cout<<"Resultado: "<<resultado<<std::endl;
    return 0;
}