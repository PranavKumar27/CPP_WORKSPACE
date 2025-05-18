#include <iostream>

using namespace std;

class Test
{
public:
    int a;
    Test(){};
    explicit Test(int x)
    {
        a = x;
    }
    Test(const Test& t)
    {
        a = t.a;
    }
    void print_a()
    {
        cout << "a=" << a << endl;
    }
    /*
    operator int()
    {
        return *(this);
    }
    */
};

int main()
{
    cout << "Conversion Operator" << endl;
    Test t1(3);
    Test t2 = static_cast<Test>(5);

    t1.print_a();
    t2.print_a();
    return 0;
}
