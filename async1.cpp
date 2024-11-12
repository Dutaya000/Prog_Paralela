#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main(){
    bool work(int num);
    future<bool> fut=async(work,123);
    bool r=fut.get();
    return 0;
}
