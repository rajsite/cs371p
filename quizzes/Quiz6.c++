/*
CS371p: Quiz #6 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

3 false
3 true
*/

#include <iostream> // boolalpha, cout, endl

int*& f (int*& r) {
    ++*r;
    return r;}

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int  i = 2;
    int* p = &i;
    int* q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    {
    int   i = 2;
    int*  p = &i;
    int*& q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    return 0;}
