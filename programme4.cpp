#include <iostream>
using namespace std;

class A {
public:
    void f_stat() {             // liaison statique
        cout << "A::f_stat (statique)\n";
    }

    virtual void f_dyn() {      // liaison dynamique
        cout << "A::f_dyn (dynamique)\n";
    }
};

class B : public A {
public:
    void f_dyn() override {     // redéfinition dynamique
        cout << "B::f_dyn (dynamique)\n";
    }
};

class C : public B {
public:
    void f_dyn() override {     // redéfinition dynamique
        cout << "C::f_dyn (dynamique)\n";
    }
};

int main() {
    A a;
    B b;
    C c;

    A* ptr;

    cout << "--- Appel statique sur A ---\n";
    ptr = &a;
    ptr->f_stat();  // toujours statique

    cout << "\n--- Appel dynamique sur A ---\n";
    ptr = &a;
    ptr->f_dyn();   // appelle A::f_dyn

    cout << "\n--- Appel dynamique sur B ---\n";
    ptr = &b;
    ptr->f_dyn();   // appelle B::f_dyn

    cout << "\n--- Appel dynamique sur C ---\n";
    ptr = &c;
    ptr->f_dyn();   // appelle C::f_dyn

    return 0;
}
