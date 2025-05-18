#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class String
{
public:
    char* str;
    int len;
    String(){}
    String(char* s)
    {
        len = strlen(s);
        cout << "len=" << len << endl;
        cout << "Before Strcpy" << endl;
        str = new char[len+1];
        strcpy(str,s);
        cout << "Strcpy" << endl;
        str[len] = '\0';
        cout << "str=" << str << endl;
    }
    String(const String& s);
    String change(char* s);
    void print()
    {
        cout << "str=" << str << " len=" << len << endl;
    }
};

String::String(const String& S)
{
    len = S.len;
    str = new char[len+1];
    strcpy(str,S.str);
    cout << "Copy Constructor =" << str << endl;
}

String String::change(char* s)
{
    delete[]str;
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    return str;
}


int main()
{
    cout << "Copy Constructors" << endl;

    String S1("LinkedIn");

    String S2("Youtube");

    String S3 = S2;
    S3.print();

    S2.change("Google");
    cout << "S3=" << endl;
    S3.print();

    cout << "S2=" << endl;
    S2.print();

    S3 = S2;
    cout << "S3=" << endl;
    S3.print();


    return 0;
}
