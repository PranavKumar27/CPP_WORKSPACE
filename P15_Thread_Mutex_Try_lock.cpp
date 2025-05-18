#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Note: Try lock is used  for non-blockig call as mutex.lock is a blocking call
mutex m;
int common_data = 0;
int run(int n)
{
    // update common data
    
    cout << "At start common_data=" << common_data << endl;
   for(int i=0;i<n;i++)
   {
       if(m.try_lock())
       {
           common_data++;
       }
       m.unlock();
            
   }
    
    cout << "At end common_data=" << common_data << endl;
    return common_data;
}

int main()
{
    cout << __FUNCTION__ << " starts Here " << endl;
    
    int n = 1000000;
    
    thread t1(run,n);
    thread t2(run,n);
    
    t1.join();
    t2.join();
    
    cout << __FUNCTION__ << " ends Here " << endl;

    return 0;
}
