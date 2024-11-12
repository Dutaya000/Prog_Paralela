#include <iostream>
#include <thread>

using namespace std;

void hello(){
    cout<<"Heello concurrency \n";
}

int main(){
    thread t(hello);
    t.detach();
    std::cout<<"Hilo principal"<<std::endl;
    return 0;
}