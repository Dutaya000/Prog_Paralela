#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;
std::condition_variable cv;

bool data_ready = false;

void producer(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    lock_guard<mutex> lock(mtx);
    data_ready=true;
    cout<<"Data Produced!"<<endl;
    cv.notify_one();
}
void consumer(){
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []{ return data_ready;});
    cout<<"Data consumed!"<<endl;
}
int main(){
    thread c(consumer);
    thread p(producer);

    c.join();
    p.join();
    return 0;
}