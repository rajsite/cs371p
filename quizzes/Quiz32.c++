/*
CS371p: Quiz #32 (7 pts) [Henry]
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

B::g()
A::h()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    void f () {
        g();
        h();}

    virtual void g () {
        cout << "A::g()" << endl;}

    void h () {
        cout << "A::h()" << endl;}};

struct B : A {
    void g () {
        cout << "B::g()" << endl;}

    virtual void h () {
        cout << "B::h()" << endl;}};

int main () {
    B x;
    x.f();
    return 0;}
