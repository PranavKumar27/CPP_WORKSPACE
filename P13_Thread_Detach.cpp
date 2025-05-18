#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

int run(int n)
{
    while(n--)
    {
        cout << "Thread --~~~~" << n << endl;
    }
    cout << endl;
    return -1;
}

int main()
{
    cout << __FUNCTION__ << " starts Here " << endl;
    cout << "Test Join and Joinable on Thread" << endl;
    
    int (*run_ptr)(int) = run;
    thread t1(run_ptr,10);
    
    cout << "Thread Going for sleep 3 seconds" << endl;
    // wait for 3 seconds
    t1.detach();  // If detatched, Can't join back so else is called

    this_thread::sleep_for(chrono::seconds(3));
    
    cout << "Thread Woke up From Sleep" << endl;
    
    if(t1.joinable())
    {
       cout << "Thread Joinable so Join" << endl;
       t1.join(); 
    }
    else
    {
        cout << "Thread No Longer Joinable" << endl;
    }
        
    try
    {
        t1.join();
    }
    catch(exception& e)
    {
        cout << "Exception = " << e.what() << endl;
    }
    
    cout << __FUNCTION__ << " ends Here " << endl;

    return 0;
}
