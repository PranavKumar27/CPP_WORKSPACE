#include <iostream>
#include <typeinfo>

using namespace std;

class student
{
private:
     int roll;
public:
    student(){}
    student(int v)
    {
        roll = v;
    }
    void updateRoll(int v) const
    {
        cout << __FUNCTION__ << endl;
        student* ptr = const_cast<student*>(this);
        ptr->roll = 5;
        //this->roll = 7; Read - only Objects
    }
    void getRoll()
    {
        cout << __FUNCTION__ << endl;
        cout << "Roll = " << roll << endl;
    }
};
int main()
{
    cout << "C++ Casting" << endl;
    //student S(3);
    //S.getRoll();
    //S.updateRoll(5);
    //S.getRoll();

    /*
    const int a = 10;
    const int *a_ptr = &a;
    cout << "a=" << a << endl;
    int *ptr = const_cast<int*>(&a);
    cout << "ptr=" << ptr << " a=" << a_ptr << endl;
    cout << "*ptr=" << *ptr << " a=" << *a_ptr << endl;
    *ptr=(*ptr)+5;

    cout << "a=" << a << endl;
    cout << "*ptr=" << *ptr << endl;
    cout << "ptr=" << ptr << " a=" << a_ptr << endl;
    */

    int a1 = 4;
    const volatile int * b1 = &a1;
    cout << "type id of b1=" << typeid(b1).name() << endl;

    int * b2 = const_cast<int*>(b1);
    cout << "type id of b2=" << typeid(b2).name() << endl;

    int * ptr = new int(69);
    char *ch_ptr = reinterpret_cast<char*>(ptr);
    cout << "ptr=" << ptr << " ch_ptr =" << ch_ptr << endl;
    cout << "*ptr=" << *ptr << " *ch_ptr =" << *ch_ptr << endl;

    bool b = false;
    bool* v = reinterpret_cast<bool*>(&b);
    cout << "v=" << *v << endl;
    return 0;
}
