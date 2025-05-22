#include <iostream>

using namespace std;

class Base
{
public:
    int val;
    Base(int v)
    {
        val = v;
        cout << "Parameterized Construct called" << endl;
    }
};

class Test
{
public:
    static Base b;

    void show_values()
    {
        cout << "val=" << b.val << endl;
    }
};

Base Test::b = Base(11);

int main()
{
    cout << "Static Demo and Test" << endl;
    Test t;
    t.show_values();

    return 0;
}
