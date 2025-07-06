#include <iostream>
#include <cstring>
using namespace std;

class STRING
{
    char *ptr;
    int c_sz;
public:
    STRING(char* str)
    {
        cout << "Constructer" << endl;
        int sz = strlen(str);
        c_sz = sz+1;
        ptr = new char(c_sz);
        strcpy(ptr,str);
        cout << ptr <<  endl;
    }
    STRING(STRING& other)
    {
        int sz = other.c_sz;
        c_sz = sz+1;
        ptr = new char(c_sz);
        strcpy(ptr,other.ptr);
    }
    STRING(STRING&& other)
    {
        int sz = other.c_sz;
        c_sz = sz+1;
        ptr = new char(c_sz);
        strcpy(ptr,other.ptr);
        other.c_sz = 0;
        other.ptr=nullptr;
    }
    void print()
    {
        if(ptr)
            cout << "String = " << ptr << endl;
        else
           cout << "String has been Moved" << endl;
    }
};

int main()
{
    STRING S("Hello");
    STRING P = std::move(S);
    S.print();
    P.print();
    return 0;
}
