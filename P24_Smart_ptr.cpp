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
    cout << "!!!!!!!!!!!!!!!!!!!  Type 1  Auto PTR     !!!!!!!!!!!!!!!!" << endl;
    auto_ptr<Rectangle> R(new Rectangle(3,4));
    cout << "Area of R = " << R->area() << endl;

    cout << "!!!!!!!!!!!!!!!!!!!  Type 2  Unique PTR   !!!!!!!!!!!!!!!!" << endl;
    unique_ptr<Rectangle>R1(new Rectangle(5,6));
    cout << "R1 Area=" << R1->area() << endl;

    unique_ptr<Rectangle>R2;
    R2=move(R1);

    cout << "R2 Area=" << R2->area() << endl;
    if(R1==nullptr)
        cout << "R1 is Nullptr" << endl;
    else
        cout << "R1 has memory" << endl;

    cout << "!!!!!!!!!!!!!!!!!!!  Type 3  Shared PTR    !!!!!!!!!!!!!!!!" << endl;

    shared_ptr<Rectangle> Rect1( new Rectangle(11,22));
    cout << "Area of Rect1 = " << Rect1->area() << endl;

    shared_ptr<Rectangle> Rect2  = make_shared_ptr<Rectange>(new Rectangle(15,22);
    cout << "Area of Rect2 = " << Rect2->area() << endl;

    shared_ptr<Rectangle> Rect3 = Rect1;
    cout << "Area of Rect3 = " << Rect3->area() << endl;
    cout << "use count of Rect3 = " << Rect3.use_count() << endl;


    cout << "!!!!!!!!!!!!!!!!!!!  Type 4  Weak PTR      !!!!!!!!!!!!!!!!" << endl;

    weak_ptr<Rectangle> weakRect (Rect1);

    // Try to access the Rectangle object using the weak_ptr (INCORRECT)
    // cout << weak_ptr->area() << endl;  // This will cause an error

    // Correct way to access the object using lock()
    std::shared_ptr<Rectangle> TryLock = weakRect.lock();

    // Check if the lock was successful (if the object still exists)
    if (TryLock) {
        cout << "Area of weakRect =" << TryLock->area() << endl; // Access the object
    } else {
        cout << "The Rectangle object has been destroyed." << endl;
    }

    shared_ptr<int> t(new int(10));
    std::weak_ptr<int> wp = t;
    if (auto sp = wp.lock()) {
        // Object is still alive
        std::cout << *sp << std::endl;
    } else {
        // Object has been destroyed
    }

    //cout << weakRect->area() << endl;
    cout << "Use Count of Weak ptr R_ptr = " << weakRect.use_count() << endl;


    return 0;
}
