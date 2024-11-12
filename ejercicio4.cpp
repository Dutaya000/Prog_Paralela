//Crea un programa que defina una función llamada mostrarMensaje que imprima 
//"¡Hola, mundo!" en la consola.Luego, crea un hilo que ejecute esta función.

#include <iostream>
#include <thread>
using namespace std;

void mostrarMensaje(){
    cout<<("Hola mundo!!!");
}
int main(){
    thread t(mostrarMensaje);
    t.join();
    return 0;
}