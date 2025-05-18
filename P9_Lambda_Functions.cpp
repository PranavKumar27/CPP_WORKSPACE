#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_v(vector<int> v)
{
    for(auto d:v)
        cout <<  d << ",";

    cout << endl;
}

class Test {
public:
  int x;
  mutable int y;
  Test() { x = 4; y = 10; }
};

int main()
{
    const Test t1;
    t1.y = 8;
    cout << "x=" << t1.x << " y=" << t1.y <<endl ;
    //return 0;

    cout << "Lambda Functions" << endl;
    auto res = [](int n)
    {
        return n+n;
    };

    cout << res(5) << endl;


    auto Numbers = [](int n)
    {
        while(n--)
        {
            cout << n << ",";
        }
    };

    Numbers(6);

    cout << endl;

    vector<int> v1;
    vector<int> v2;

    auto InsertByRef = [&](int a,int b)
    {
        v1.push_back(a);
        v2.push_back(b);
    };

    auto InsertByVal = [=](int a,int b) mutable
    {
        v1.push_back(a);
        v2.push_back(b);
    };

    auto mixed = [=,&v1](int a,int b) mutable
    {
        v1.push_back(a);
        v2.push_back(b);
    };

    InsertByRef(10,20);
    InsertByVal(50,60);
    mixed(25,75);

    print_v(v1);
    print_v(v2);

    // Sort a vector in descending order
    vector<int> Arr = {1,2,4,5,3};

    cout << "Before Sort" << endl;
    print_v(Arr);

    sort(Arr.begin(),Arr.end(),[](int a,int b)
                                {
                                    return (a>b)?true:false;
                                });
    cout << "After Sort" << endl;
    print_v(Arr);

    // Find first number divisible by 3

    vector<int> Num = {4,5,6,8,9};

    auto itr = find_if(Num.begin(),Num.end(),[](int n)
                                            {
                                                return (n%3==0);
                                            });

    cout << "first number divisible by 3 =" << *itr << endl;

    return 0;
}
