/*
CS371p: Quiz #10 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. In the paper, "A Bug and a Crash" about the Ariane 5, what was the
    software bug?
    (2 pts)

the conversion of a 64-bit number to a 16-bit number
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (4 pts)

true
true
true
true
*/

#include <algorithm> // equal
#include <iostream>  // boolalpha, cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    char s[] = "abcabc";

    cout << equal(s,     s + 3, s)     << endl;
    cout << equal(s,     s + 3, s + 3) << endl;
    cout << equal(s + 3, s + 3, s)     << endl;
    cout << equal(s + 3, s + 6, s)     << endl;

    return 0;}
