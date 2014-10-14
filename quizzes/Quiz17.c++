/*
CS371p: Quiz #17 (7 pts) [Henry]
*/

/* -----------------------------------------------------------------------
 1. Redefine the following function without using the < operator on RI.
    (6 pts)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename RI>
bool palindrome2 (RI b, RI e) {
    --e;
    while (b < e) {
        if (*b != *e)
            return false;
        ++b;
        --e;}
    return true;}

template <typename BI>
bool palindrome (BI b, BI e) {
    while ((b != e) && (b != --e)) {
        if (*b != *e)
            return false;
        ++b;}
    return true;}

int main () {
    const char a[] = "radar";
    assert( palindrome(a, a));     // ""
    assert( palindrome(a, a + 1)); // "r"
    assert(!palindrome(a, a + 3)); // "rad"
    assert( palindrome(a, a + 5)); // "radar"
    return 0;}
