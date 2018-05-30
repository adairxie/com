#include <iostream>
using namespace std;

class A {
};

class B {
public:
    B(){}
    ~B(){}
};

class C {
public:
    C(){}
    virtual ~C(){}
};

int main(int argc, char** argv)
{
    cout << "class A's size is " << sizeof(A) << endl;
    cout << "class B's size is " << sizeof(B) << endl;
    cout << "class C's size is " << sizeof(C) << endl;
    cout << "hello" << endl;
}
