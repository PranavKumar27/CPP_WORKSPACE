#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

void incBy2(int x)
{
    cout << x*2 << ",";
}

struct IncBy3
{
    void operator()(int x)
    {
        cout << x*3 << ",";
    }
}obj1;

void incBy100(int x)
{
    cout << x*100 << ",";
    if(x==1)
        throw 100;
}

int main()
{
    cout << "For Each Test" << endl;
    vector<int> Arr = {5,3,4,1,2};

    cout << "\n Arr = " << endl;
    for_each(Arr.begin(),Arr.end(),[](int x)
                                    {
                                        cout << x << ",";
                                    });


    cout << "\n Increase by 2 " << endl;
    for_each(Arr.begin(),Arr.end(),incBy2);

    cout << "\n Increase by 3 " << endl;
    for_each(Arr.begin(),Arr.end(),obj1);

    cout << "\n Increase by n = 10 " << endl;
    for_each(Arr.begin(),Arr.end(),[](int x)
                                    {
                                        cout << x+10 << ",";
                                    });

    cout << "\n Increase by n = 100 " << endl;
    try
    {
      for_each(Arr.begin(),Arr.end(),incBy100);
      // If Exception is thrown in for_each then for_each itself terminates
    }
    catch(exception e)
    {
        cout << "An exception occured = " << e.what() <<endl;
    }


    return 0;
}
