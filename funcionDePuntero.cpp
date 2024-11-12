#include <iostream>
#include <thread>

using namespace std;

int foo(int a){
    return  a=a+1;
}

int main(){
    thread thead_obj(foo,2);
    return 0;
}