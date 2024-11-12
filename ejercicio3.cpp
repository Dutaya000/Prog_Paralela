//Crea un programa que tome un número N como 
//argumento de entrada y que imprima los números del 1 hasta N en un hilo.

#include <iostream>
#include <thread>

using namespace std;

void print(int num){
    for(int i=0;i<9;i++){
        cout<<i;
    }
    cout<<endl;
}
int main(){
    thread t(print,10);
    t.join();
    return 0;
}