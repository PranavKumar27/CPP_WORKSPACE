// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
#include <thread>


using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull findEven_Sum(ull start,ull end)
{
    ull sum = 0;
    for(ull ev = start;ev<=end;ev++)
    {
        if(ev%2==0)
         sum+=ev;
    }
    cout << "Even SUM = " << sum << endl;
    return sum;
}

ull findOdd_Sum(ull start,ull end)
{
    ull sum = 0;
    for(ull odd = start;odd<=end;odd++)
    {
        if(odd%2==1)
         sum+=odd;
    }
    cout << "Odd SUM = " << sum << endl;
    return sum;
}



int main()
{

    ull start = 1;
    ull end = 100000000;
    const auto start_time = high_resolution_clock::now();

    thread t1(findEven_Sum,start,end);
    //ull EvenSum = findEven_Sum(start,end);

   thread t2(findOdd_Sum,start,end);
    //ull OddSum = findOdd_Sum(start,end);

    t1.join();
    t2.join();
    const auto end_time = high_resolution_clock::now();
    const duration<double> duration = end_time - start_time;
    // Duration without thread 0.52346  and duration with threads .256789
    cout << "duration = " << duration.count() << endl;  
    return 0;
}
