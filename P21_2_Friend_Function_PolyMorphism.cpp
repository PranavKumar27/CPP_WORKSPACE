#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const {
        cout << "Animal speaks generically." << endl;
    }

    friend void reveal(const Animal& a);  // Friend function
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog barks!" << endl;
    }

    friend void reveal(const Dog& d);  // Overloaded friend function (not override!)
};

// Friend function for Animal
void reveal(const Animal& a) {
    cout << "Friend sees: Animal's identity." << endl;
}

// Friend function for Dog (overload, not override)
void reveal(const Dog& d) {
    cout << "Friend sees: Dog's identity." << endl;
}

int main() {
    Dog d;
    Animal* a = &d;

    cout << "🔁 Virtual Function Call:" << endl;
    a->speak();  // ✅ Polymorphic: calls Dog::speak()

    cout << "\n👀 Friend Function Call:" << endl;
    reveal(*a);  // ❌ Not polymorphic: calls reveal(const Animal&)

    return 0;
}
