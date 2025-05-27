#include <iostream>
#include <array>
#include <algorithm>
#include <memory>
#include <cstring>

using namespace std;

void print_arr(array<int,7>& Arr)
{
   for(auto &d:Arr)
        cout << d << ",";
    cout << endl;
}

int main()
{
    cout << "STL Array" << endl;
    array<int,7> arr = {3,5,6,1,2};

    for(auto &d:arr)
        cout << d << ",";

    sort(arr.begin(),arr.end());

    cout << "\nSorted Elements:\n";
    for(auto &d:arr)
        cout << d << ",";

    cout << endl;
    arr[6] = 17;
    print_arr(arr);

    cout << "arr addr = " << arr.data() << endl;
    cout << "data1 = " << *arr.data() << endl;
    cout << "data2 = " << *(arr.data()+3) << endl;
    cout << "data-10 = " << *(arr.data()+10) << endl;


    cout << "\n Array filled with 10\n";
    arr.fill(10);
    print_arr(arr);

    cout << "size of arr = " << arr.size() << endl;


    const char* str = "India is best";
    array<char,15> arr1;
    memcpy(arr1.data(),str,15);
    cout << "str = " << arr1.data() << endl;
    return 0;
}
