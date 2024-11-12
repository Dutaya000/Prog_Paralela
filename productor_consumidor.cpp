#include<iostream>
#include<thread>
#include<queue>
#include<mutex>
#include<condition_variable>
#include<chrono>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
const int maxBufferSize = 5;

void producer(){
    int data = 0;
    while(data<10){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return buffer.size()<maxBufferSize;});

        buffer.push(data);
        std::cout<<"Productor ha producido"<<data<<std::endl;
        data++;
        
        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }
}

void consumer(){
    while(true){
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]{return !buffer.empty();});

        int data = buffer.front();
        buffer.pop();
        std::cout<<"Consumidor ha consumido"<<data<<std::endl;

        lock.unlock();
        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::microseconds(150));

        if(data>=9) break; 
    }
}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0; 
}
