
#include <iostream>
#include <functional>

using namespace std;

int add(int x, int y) { return x+y; }
int sub(int x, int y) { return x-y; }

int invoke_1(int x, int y,int (*fptr)(int,int))
{
    return fptr(x,y);
}

int invoke_2(int x, int y,function<int(int,int)>f)
{
    return f(x,y);
}


int main()
{
    cout << "Function Callbacks" << endl;

    cout << "Type 1: Using Function Ptr" << endl;
    cout << "Add res = " << invoke_1(2,3,&add) << endl;
    cout << "Sub res = " << invoke_1(2,3,&sub) << endl;

    cout << "Type 2: Using Function Wrapper" << endl;
    cout << "Add res = " << invoke_2(2,3,&add) << endl;
    cout << "Sub res = " << invoke_2(2,3,&sub) << endl;

    cout << "Type 3: Using Lambda Function Wrapper" << endl;
    cout << "Add res = " << invoke_2(2,3,[](int x,int y)
                                            {
                                                return x+y;
                                            }) << endl;
    cout << "Sub res = " << invoke_2(2,3,[](int x,int y) -> int
                                            {
                                                return abs(x-y);
                                            }) << endl;

    return 0;
}
