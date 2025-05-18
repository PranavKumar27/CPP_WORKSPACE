#include <iostream>
#include <thread>

using namespace std;

class Base
{
    public:
    static void static_print(int n)
    {
        while(n--)
            cout << n << ",";
        cout << endl;
    }
    
    void non_static_print(int n)
    {
        while(n--)
            cout << n << ",";
        cout << endl;
    }
};

int main()
{
    cout << "Thread Creation Using Non-static Member Function" << endl;
    Base b;
    thread t1(&Base::non_static_print,&b,10);
    t1.join();
    
    cout << "Thread Creation Using Static Member Function" << endl;
    thread t2(&Base::static_print,10);
    t2.join();

    return 0;
}
