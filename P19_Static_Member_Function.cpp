
#include <iostream>

using namespace std;

class Test
{
   static int x;  // Make x as const to make it immutable for the class
   //static const int x;
public:
    Test(int val)
    {
        x = val;
    }
    static int  getX()
    {
        return x;
    }
    int getX_non_static()
    {
        return x;
    }
};

int Test::x=100;  // Must

int main()
{
    
    cout << "X at start = " << Test::getX() << endl;
    
    Test t1(10);
    //cout << "X = " << Test::x << endl;
    cout << "X for Obj x1= " << Test::getX() << endl;
    cout << "t1.X Static Method= " << t1.getX() << endl;
    cout << "t1.X non static Method = " << t1.getX_non_static() << endl;
    
    Test t2(20);
    //cout << "X = " << Test::x << endl;
    cout << "X for obj x2= " << Test::getX() << endl;
    cout << "t2.X Static Method= " << t2.getX() << endl;
    cout << "t2.X non static Method = " << t2.getX_non_static() << endl;
    
    cout << "X at End = " << Test::getX() << endl;
    
    return 0;
}
