#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

using namespace std;

void print_v(vector<int> v)
{
    for(auto d:v)
        cout <<  d << ",";

    cout << endl;
}

class Increase
{
public:
    int n;
    Increase(int v):n(v){ }

    int operator()(int incr_val)
    {
        return n+incr_val;
    }

};
int increment(int n)
{
    return (n+1);
}
int main()
{
    cout << "** Functors Not Function() **" << endl;

    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2(v1.size());

    print_v(v1);

    cout << "Reverse v1 and increase v1 by 1 in v2 " << endl;
    transform(v1.begin(),v1.end(),v2.rbegin(),[](int a)
                                              {
                                                return a+1;
                                              });

    print_v(v2);


    cout << "Sum of v1 and v2 in v" << endl;
    // Add v1 and v2 in v
    vector<int> v(v1.size());

    transform(v1.begin(),v1.end(),v2.begin(),v.begin(),[](int a,int b)
                                                         {
                                                             return (a+b);
                                                         });

    print_v(v);


    cout << "Increment v1 by 1 and make as v3" << endl;

    vector<int> v3(v1.size());
    transform(v1.begin(),v1.end(),v3.begin(),increment);
    // transform(v1.begin(),v1.end(),v3.begin(),increment(5));  --> Cannot Pass Argument as 5 Limitation of function Here
    print_v(v3);

    // So create a class which can increment


    cout << "Increment v1 by 5 and make as v4" << endl;

    vector<int> v4(v1.size());
    transform(v1.begin(),v1.end(),v4.begin(),Increase(5));
    // Increase is a functor, a c++ class that acts as a function.
    print_v(v4);

    thread t1(Increase(10),10);
    t1.join();


    return 0;
}
