#include <iostream>

using namespace std;

int print(int val)
{
    cout << "val = " << val <<  endl;
    return val+10;
}

int main()
{
    cout << "Function Pointer" << endl;

    // Technique 1 : store function address in two steps
    //int (print)(int); // Function
    // Function pointer stores start address of Executable function code as
    // Normal pointer stores address

    int (*print_ptr1)(int); // Function Pointer
    print_ptr1 = &print;   // Assign Address of function to Function Pointer
    cout << "Function Ptr = " << print << endl;

    int res = print_ptr1(20);
    cout << "res = " << res << endl;




    // Technique 2 store function reference in two steps
    int (*print_ptr2)(int); // Function Pointer
    print_ptr2 = print;   // Assign Address of function to Function Pointer

    res = print_ptr2(5);
    cout << "res = " << res << endl;



    // Technique 3  store function address in 1 steps
    int (*print_ptr3)(int) = &print; // Function Pointer and
                                     // Assign Address of function to Function Pointer

    res = print_ptr3(25);
    cout << "res = " << res << endl;



    // Technique 3  store function reference in 1 steps
    int (*print_ptr4)(int) = print; // Function Pointer and
                                     // Assign Address of function to Function Pointer

    res = print_ptr4(44);
    cout << "res = " << res << endl;




    return 0;
}
