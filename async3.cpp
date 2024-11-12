//crear una funcion que  calcule  el doble de un numero de 
//forma  asincrona  para  luego recuperar el valor con future

#include<iostream>
#include<future>


int doble(int num){
    return num*2;
}

int main(){

    
    std::future<int> resultado=std::async(std::launch::async,doble,7);

    std::string name;
    std::cout<<"your names: ";
    std::cin>>name;
    
    std::cout<<"Hola"<<name<<std::endl;

    int valor =resultado.get();
    std::cout<<"El resultado de la tarea asincrona es : "<<valor<<std::endl; 
    return 0;
}