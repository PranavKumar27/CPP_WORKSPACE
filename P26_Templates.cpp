#include <iostream>
//#include <string>

using namespace std;

//Class as template

template<typename T1,typename T2=int>
class Base
{
    T1 a;
    T2 b;
public:
    Base() {}
    Base(T1 x,T2 y)
    {
        a=x;
        b=y;
    }
    void show_val()
    {
        cout << a << " , " << b << endl;
    }
};

// Function as Template
template<typename T> T maximum(T x,T y)
{
    return (x>y)?x:y;
}


// Template as Variable
template<typename T> constexpr T pi = T(3.14789725896);


int sum()
{
    return 0;
}
// Variadic Template
template <typename T,typename... Args> T sum(T first,Args... args)
{
    // Recursive call with remaining args
    return first+sum(args...);
}
int main()
{
    cout << "##########  TEMPLATES ###########" << endl;
    cout << "----------------- Type 1: Function Templeates ----------------- " << endl;
    cout << "max of 2,3 = " << maximum(2,3) << endl;
    cout << "max of 4.2,3.7 = " << maximum(4.2,3.7) << endl;

    cout << "max of a,t = " << maximum('a','t') << endl;

    cout << "max of 22.3456,22.345789 = " << maximum(22.3456,22.345789) << endl;


    cout << "-----------------  Type 2: Class Templates ----------------- " << endl;
    Base<int,int> b1(2,3);
    Base<float,float> b2(2.3,5.997);
    Base<string,string> b3("Hello","Bro");

    b1.show_val();
    b2.show_val();
    b3.show_val();

    Base<string,int> b4("Sunny Kumar",11);
    b4.show_val();

    Base<string> b5("Navin Kulkarni",12);
    b5.show_val();

    cout << "-----------------  Type 3: Variable Templates ----------------- " << endl;

    cout << "Pie value in float = " <<  pi<float> << endl;
    cout << "Pie value in double = " <<  pi<double> << endl;

    cout << "-----------------    Variadic Templates ----------------- " << endl;
    cout << "Add n numbers" << endl;
    cout << "sum1 =" << sum(1,2,3,4) << endl;
    cout << "sum2 =" << sum(7,8,9) << endl;


    return 0;
}
