#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

mutex m;

std::chrono::milliseconds interval(100);

int shared = 0;
int exclusive = 0;

void Job1()
{
    this_thread::sleep_for(interval);
    while(true)  //  <-- IMP so that exclusive Job keeps on running when try lock returns false
    {
        if(m.try_lock())
        {
            shared++;
            cout << "shared Job is Progress shared = " << shared << endl;
            m.unlock();
            return;
        }
        else
        {
            exclusive++;
            cout << "Running Exclusive Work exclusive = " << exclusive << endl;
            std::this_thread::sleep_for(interval);
        }
    }
    
}

void Job2()
{
    m.lock();
    shared++;
    this_thread::sleep_for(5*interval);
    cout << "Running Shared Work  = " << shared << endl;
    m.unlock();
}
    

int main()
{
    
     cout << __FUNCTION__ << " starts Here " << endl;
     
    thread t1(Job1);
    thread t2(Job2);
    
    t1.join();
    t2.join();
    

    
    cout << __FUNCTION__ << " ends Here " << endl;

    return 0;
}
