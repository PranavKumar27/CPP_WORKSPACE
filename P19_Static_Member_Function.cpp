#include <iostream>

using namespace std;

class Test
{
   static int x;
public:
    Test()
    {
        x = 0;
    }
    static int  getX()
    {
        return x;
    }
};

int Test::x=100;  // Must

int main()
{
    Test t1;
    cout << "X = " << Test::getX() << endl;
    cout << "t1.X = " << t1.getX() << endl;
    return 0;
}
