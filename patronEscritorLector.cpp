#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cond_var;
int read_count = 0;
bool write_flag = false;

void reader(int id){
    //comienza  de la lectura
    std::unique_lock<std::mutex> lock(mtx);
    while(write_flag){
        cond_var.wait(lock);
    }
    read_count++;
    lock.unlock();

    std::cout<<"Lector "<<id<<"Esta Leyendo"<<std::endl;
    // simula el tiempo de lectura

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    lock.lock();
    read_count--;
    if(read_count==0){
        cond_var.notify_all();
    }
    lock.unlock();
}

void writer(int id){
    //comienzo de la lectura
    std::unique_lock<std::mutex> lock(mtx);
    while(read_count>0||write_flag){
        cond_var.wait(lock);
    }
    write_flag = true;
    lock.unlock();
    std::cout<<"Escritor"<<id<<"Esta escribiendo "<<std::endl;

    std::this_thread::sleep_for(std::chrono::microseconds(1000));

    lock.unlock();
    write_flag=false;
    cond_var.notify_all();
    lock.unlock();
}

int main(){
    std::thread readers[5];
    std::thread writers[2];

    //lanza 5 escritores 

    for(int i=0;i<5;i++){
        readers[i]=std::thread(reader,i+1);
    
    }
    //lanzamos  2 escritores 
    for(int i=0;i<2;i++){
        writers[i]=std::thread(writer,i+1);
    }
    //esperar  a que todos los hilos terminen 
    for(int i=0;i<2;i++){
        readers[i].join();
    }
    for(int i=0;i<2;i++){
        writers[i].join();
    }
    return 0;
}
