#include <iostream>
#include <map>

using namespace std;
/*
Upper Bound
first element in a sorted range that is strictly greater than a given number
Lower Bound
first element in a sorted range that is not less than (i.e., greater than or equal to) a given value.
*/
    
int main()
{
    cout << "Upper and Lower Bounds" << endl;

    map<int,int> Mp = { {12,4},{3,9},{14,78},{5,66},{22,33} };

    auto itr = Mp.upper_bound(7);

    cout << "Upper Bound Key = " << itr->first << " val = " << itr->second << endl;

    itr = Mp.upper_bound(14);

    cout << "Upper Bound Key = " << itr->first << " val = " << itr->second << endl;


    itr = Mp.upper_bound(27);

    cout << "Upper Bound Key = " << itr->first << " val = " << itr->second << endl;



    auto itr1 = Mp.lower_bound(5);

    cout << "Lower Bound Key = " << itr1->first << " val = " << itr1->second << endl;


    itr1 = Mp.lower_bound(10);

    cout << "Lower Bound Key = " << itr1->first << " val = " << itr1->second << endl;


    itr1 = Mp.lower_bound(28);

    cout << "Lower Bound Key = " << itr1->first << " val = " << itr1->second << endl;

    return 0;
}


// Output

/*

Upper and Lower Bounds
Upper Bound Key = 12 val = 4
Upper Bound Key = 22 val = 33
Upper Bound Key = 5 val = 6487760
Lower Bound Key = 5 val = 66
Lower Bound Key = 12 val = 4
Lower Bound Key = 5 val = 0

*/
