//crear 2 funciones que   saluden y que lo hagan de  forma paralela y concurrente 
#include <iostream>
#include <thread>
using namespace std;

void message1(){
    cout<<"Hello wordl1 "<<endl;
}
void message2(){
    cout<<"Hello wordl2"<<endl;
}

int main(){
    thread t(message1);
    thread t1(message2);
    t.join();
    t1.join();
    return 0;
}