#include <iostream>
#include <string>
#include <pthread.h>
#include <Windows.h>

using namespace std;
#define NUM 4
typedef  unsigned long long Uint64;
pthread_mutex_t loc;
pthread_cond_t cond;
pthread_attr_t attr;

int count;

void *increment1(void* id){
    Uint64 status;
    status = (Uint64)id;
    while(1){
        pthread_mutex_lock(&loc);
        count++;
        cout << "This is thread " + to_string((Uint64)id) + ": count is " + to_string(count) << endl;
        if (count%5==0){
            pthread_cond_signal(&cond);
        }
        Sleep(1);
        pthread_mutex_unlock(&loc);
    }
    pthread_exit(&status);
}

void *increment10(void* id){
    Uint64 status;
    status = Uint64(id);
    pthread_mutex_lock(&loc);
    cout << "This is thread " + to_string((Uint64)id) + ": watch starts." << endl;
    while(1){
        pthread_cond_wait(&cond, &loc);
        cout << "This is thread " + to_string((Uint64)id) + ": count is " + to_string(count) << endl;
        count+=10;
        Sleep(1);
    }
    pthread_exit(&status);
}

int main(){
    int i, ret;
    void *status[3];
    pthread_t pId[NUM];
    pthread_mutex_init(&loc, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    ret = pthread_create(&pId[0], &attr, increment10, (void *)1);
    if (ret!=0){
        cout << "thread 0 create fail" << endl;
        exit(-1);
    }
    for(i=1;i<=2;i++){
        ret = pthread_create(&pId[i], &attr, increment1, (void *)i);
        if (ret!=0){
            cout << "thread "+ to_string(i) + " create fail" << endl;
            exit(-1);
        }
    }

    for(i=0;i<3;i++){
        pthread_join(pId[i], &status[i]);
        cout << (Uint64)status[i] << endl;
    }

}