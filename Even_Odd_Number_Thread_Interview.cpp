
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

#define MAX 100

mutex m;
condition_variable cv;
int counter = 0;

void Print_Even()
{
    while(true)
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock,[](){ return counter%2 == 0;});
        
        if(counter>=MAX)
            break;
            
        cout << "Even = " << counter << endl;
        counter++;
        cv.notify_all();
    }
}

void Print_Odd()
{
    while(true)
    {
        unique_lock<mutex> lock(m);

        cv.wait(lock,[](){
                             return counter%2 == 1;
                        });
        
        if(counter>=MAX)
            break;
        
        cout << "Odd = " << counter << endl;
        counter++;
        cv.notify_all();
    }
}

int main()
{
    thread t1(Print_Even);
    thread t2(Print_Odd);
    
    if(t1.joinable())
        t1.join();
    if(t2.joinable())
        t2.join();
    return 0;
}
