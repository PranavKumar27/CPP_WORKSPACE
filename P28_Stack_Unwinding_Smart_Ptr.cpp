#include <iostream>
#include <exception>
#include <memory>

using namespace std;

int func3(int v)
{
    cout << __FUNCTION__ << endl;
    shared_ptr<int> S(new int(v));
    shared_ptr<int> Q = S;
    weak_ptr<int> P1(S);

    cout << "Weak ptr ref Count = " << P1.use_count() << " Excluding Weak Ptr Count" << endl;

    //unique_ptr<int> P2 = move(P1); // Move COnstructor

    if(!P1.expired())
    {
        shared_ptr<int> TryLock = P1.lock();
        cout << "P1 is not null " << endl;
        cout << "Data pointed by weak Ptr = " << *(TryLock.get()) << endl;
        //cout << "Data pointed by weak Ptr = " << *(P1.get()) << endl;  <-- Error
    }
    else
        cout << "P1 is null" << endl;

    //throw 55;
}

int func2(int v)
{
    cout << __FUNCTION__ << endl;
    unique_ptr<int> P1(new int(v));

    unique_ptr<int> P2 = move(P1); // Move COnstructor

    if(P1!=nullptr)
        cout << "P1 is not null " << endl;
    else
        cout << "P1 is null" << endl;

    throw 55;
}

int func1(int v)
{
    cout << __FUNCTION__ << endl;
    shared_ptr<int> P1(new int(v));

    shared_ptr<int> P2( P1 );

    cout << "val of P1 = " << P1 << endl;
    cout << "val of P2 = " << P2 << endl;

    cout << "Shared PTR use Count = " << P2.use_count() << endl;

    throw 99;
}

int main()
{
    cout << "Stack Unwinding" << endl;
    try
    {
        func3(100);
        func2(55);
        func1(10);
    }
    catch(exception e)
    {
        cout << "Exception caught = " << e.what() << endl;
    }
    return 0;
}
