/*
CS371p: Quiz #14 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

A(int) A(int) A(int)
~A() ~A() ~A()

A(int) A(int) A()
~A() ~A() ~A()

A() A() A()
~A() ~A() ~A()
*/

#include <iostream> // cout, endl

using namespace std;

struct A {
    A  ()    {cout << "A() ";}    // default constructor
    A  (int) {cout << "A(int) ";} // int constructor
    ~A ()    {cout << "~A() ";}}; // destructor

int main () {
    {
    A a[] = {2, 3, 4};
    cout << endl;
    }
    cout << endl << endl;

    {
    A a[3] = {2, 3};
    cout << endl;
    }
    cout << endl << endl;

    {
    A a[3];
    cout << endl;
    }
    cout << endl;

    return 0;}
