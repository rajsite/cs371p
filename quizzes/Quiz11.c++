/*
CS371p: Quiz #10 (7 pts) [Henry]
*/

/* -----------------------------------------------------------------------
 1. What are the two reasons to use inheritance?
    [Sec. 8.1, Pg. 163]
    (2 pts)

code    reuse (implementation)
concept reuse (interface)
*/

/* -----------------------------------------------------------------------
 2. Define the function my_copy() generically, such that the following
    works.
    (4 pts)
*/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

template <typename II, typename OI>
void my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}}

int main () {
    using namespace std;

    list<int>   x = {2, 3, 4};
    vector<int> y = {5, 6, 7};
    assert(!equal(x.begin(), x.end(), y.begin()));
    my_copy(x.begin(), x.end(), y.begin());
    assert(equal(x.begin(), x.end(), y.begin()));

    return 0;}
