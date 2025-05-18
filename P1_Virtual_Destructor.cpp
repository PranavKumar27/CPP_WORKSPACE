#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Class Constructor" << endl;
    }
    virtual ~Base()
    {
        cout << "Base Class Destructor" << endl;
    }
};

class Derived:public Base
{
public:
    Derived()
    {
        cout << "Derived Class Constructor" << endl;
    }
    ~Derived()
    {
        cout << "Derived Class Destructor" << endl;
    }
};

int main()
{
    cout << "Do we need Virtual Destructor" << endl;
    Derived * dptr = new Derived();
    Base * bptr = dptr;
    delete(bptr);
    return 0;
}
