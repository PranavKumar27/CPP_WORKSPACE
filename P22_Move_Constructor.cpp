#include <iostream>

using namespace std;

class Base
{
    int *val;
public:
    Base()
    {
        val = nullptr;
    }
    Base(int* v)
    {
        val = v;
    }
    Base(Base&& obj)
    {
        val = obj.val;
        obj.val = nullptr;
    }
    print()
    {
        if(val!=nullptr)
            cout << "val = " << *val << endl;
        else
            cout << "val = NULLPTR" << endl;
    }
};



int main()
{
    cout << "Move Constructor" << endl;

    int v = 5;
    Base obj1;
    Base obj2(&v);
    obj1.print();
    obj2.print();
    return 0;
}
