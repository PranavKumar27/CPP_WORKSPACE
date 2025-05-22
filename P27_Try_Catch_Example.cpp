#include <iostream>
#include <exception>

using namespace std;



int main()
{
    cout << "Testing Try Catch" << endl;

    try
    {
        int n;

        cout << "Enter a choice: \n1 Invalid Range \n2 Out of Range \n3 Bad Cast \n4 Bad Alloc \n5 No Error \n6 to Stop" << endl;
        cin >> n;
        if(n==1)
            throw invalid_argument("Invalid Range");
        else if(n==2)
            throw out_of_range("OutOfRange");
        else if(n==3)
            throw underflow_error("BadCast");
        else if(n==4)
            throw length_error("bad_alloc");
        else
            throw domain_error("UnExpectedError");
    }
    catch(invalid_argument e)
    {
        cout << "Caught exception = " << e.what() << endl;
    }
    catch(out_of_range e)
    {
        cout << "Caught exception = " << e.what() << endl;
    }
    catch(underflow_error e)
    {
        cout << "Caught exception = " << e.what() << endl;
    }
    catch(bad_alloc e)
    {
        cout << "Caught exception = " << e.what() << endl;
    }
    catch(domain_error e)
    {
        cout << "Caught exception = " << e.what() << endl;
    }
    catch(...)
    {
        cout << "Caught exception which is Generic " << endl;
    }

    return 0;
}
