/*
CS371p: Quiz #26 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. The keyword "static" as a modifier of a "local variable" causes what
    to NOT change?
    The keyword "static" as a modifier of a "global variable" causes what
    to change?
    (4 pts)

scope
scope
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (2 pts)

false
*/

#include <iostream> // cout, endl

template <typename T>
struct A {
    static int si;};

template <typename T>
int A<T>::si;

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    A<int>    x;
    A<double> y;
    cout << (&x.si == &y.si) << endl;

    return 0;}
