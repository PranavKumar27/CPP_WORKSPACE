#include <iostream>
#include <vector>

using namespace std;

class Base
{
    int *val;
public:
    Base()
    {
        cout << "Default Constructor Called" << endl;
        val = nullptr;
    }
    Base(int v)
    {
        val = new int;
        *val = v;
        cout << "Parameterized Constructor Called val= " << *val << endl;
    }
    Base(Base&& obj) noexcept
    {
        val = obj.val;

        cout << "Move Constructor Called val=" << *val << endl;
         //obj.val = nullptr;

    }
    Base(const Base& obj)
    {
        val = obj.val;
        cout << "obj.val=" << *(obj.val) << endl;
        cout << "Copy_Constructor Called" << endl;
    }
    void print()
    {
        if(val!=nullptr)
            cout << "val = " << *val << endl;
        else
            cout << "val = NULLPTR" << endl;
    }
    ~Base()
    {
        cout << "destructor called" << endl;
        if(val!=nullptr)
            cout << "val = " << *val << endl;
        else
            cout << "val = NULLPTR" << endl;

        delete(val);
    }
};


int main()
{
    cout << "$$$$$$$$$$$$$$  " << endl;


    int v = 5;
    Base obj1(v);
    Base &b_lvalue = obj1;
    Base &&b_rvalue = Base(60);
    Base obj2=move(b_lvalue);


    vector<Base> vB;
    //vB.reserve(2);
    vB.push_back(Base(10));
    vB.push_back(Base{20});

    vB.push_back(Base{30});
    vB.push_back(Base{40});

    return 0;
}
