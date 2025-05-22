#include <iostream>
#include <memory>

using namespace std;

class Rectangle
{
    int length;
    int breadth;
public:
    Rectangle(int l,int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length*breadth;
    }
};

int main()
{
    cout << "Unique PTR" << endl;
    unique_ptr<Rectangle>R1(new Rectangle(5,6));
    cout << "R1 Area=" << R1->area() << endl;

    unique_ptr<Rectangle>R2;


    R2=move(R1);

    cout << "R2 Area=" << R2->area() << endl;
    if(R1==nullptr)
        cout << "R1 is Nullptr" << endl;
    else
        cout << "R1 has memory" << endl;

    return 0;
}
