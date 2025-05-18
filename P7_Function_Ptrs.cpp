#include <iostream>
#include <string>

using namespace std;

int add(int a,int b)
{
    return(a+b);
}

int sub(int a,int b)
{
    return (a>b)?a-b:b-a;
}

int mul(int a,int b)
{
    return a*b;
}

int divd(int a,int b)
{
    return (b!=0)?a/b:1e9;
}

int mod(int a,int b)
{
    return (a>b)?a%b:b%a;
}

void Calculator_Wrapper(int (*Calculator_Ptr[])(int,int))
{
    cout << __FUNCTION__ << endl;
    cout << "sum=" << Calculator_Ptr[0](2,3) << endl;
    cout << "sub=" << Calculator_Ptr[1](2,3) << endl;
    cout << "mul=" << Calculator_Ptr[2](2,3) << endl;
    cout << "div=" << Calculator_Ptr[3](2,3) << endl;
    cout << "mod=" << Calculator_Ptr[4](2,3) << endl;
    //cout << "Random=" << Calculator_Ptr[5](2,3) << endl;
}

string divide_Wrapper(int (*divPtr)(int,int),int v1,int v2)
{
    int ans = divPtr(v1,v2);
    if(ans==1e9)
        return "Division by Zero Infinity";
    else
        return ""+ans;
}
void print_Message()
{
    cout << "!!!    Welcome to Program on Array of Function Pointers Test    !!!" << endl;
}
int main()
{

    void (*print_Message_ptr)() = print_Message;   // No Parameters in Function Pointer
    print_Message_ptr();

    int (*divd_Ptr)(int,int) = divd;               // 2 Parameter  in Function Ptr
    cout << "3/0 = " << divide_Wrapper(divd_Ptr,3,0) << endl;


    int (*Calculator_Ptr[])(int,int) = {add,sub,mul,divd,mod};  // 2 Parameter  in Array of Function Ptr
    Calculator_Wrapper(Calculator_Ptr);

    return 0;
}
