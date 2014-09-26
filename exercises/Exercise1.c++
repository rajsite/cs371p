/*
CS378: Exercise #1
*/

/* -----------------------------------------------------------------------
Define the function my_equal() such that it behaves as follows:
*/

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

bool equal_1 (const int* b, const int* e, const int* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

template <typename T>
bool equal_2 (T* b, T* e, T* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

template <typename T1, typename T2>
bool equal_3 (T1* b, T1* e, T2* x) {
    while (b != e) {
        if (*b != *x)
            return false;
        ++b;
        ++x;}
    return true;}

template <typename II1, typename II2>
bool equal_4 (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int main () {
    using namespace std;
    cout << "Exercise1.c++" << endl;

    {
    const int    a[] = {2, 3, 4};
    const int    b[] = {2, 3, 4, 5};
    const size_t s   = sizeof(a) / sizeof(a[0]);
    assert(equal_1(a, a + s, b));
    assert(equal_2(a, a + s, b));
    assert(equal_3(a, a + s, b));
    assert(equal_4(a, a + s, b));
    assert(equal  (a, a + s, b));
    }

    {
    const double a[] = {2, 3, 4};
    const double b[] = {2, 3, 4, 5};
    const size_t s   = sizeof(a) / sizeof(a[0]);
//  assert(equal_1(a, a + s, b));                // error: no matching function for call to 'equal_1'
    assert(equal_2(a, a + s, b));
    assert(equal_3(a, a + s, b));
    assert(equal_4(a, a + s, b));
    assert(equal  (a, a + s, b));
    }

    {
    const int    a[] = {2, 3, 4};
    const double b[] = {2, 3, 4, 5};
    const size_t s   = sizeof(a) / sizeof(a[0]);
//  assert(equal_1(a, a + s, b));                // error: no matching function for call to 'equal_1'
//  assert(equal_2(a, a + s, b));                // error: no matching function for call to 'equal_2'
    assert(equal_3(a, a + s, b));
    assert(equal_4(a, a + s, b));
    assert(equal  (a, a + s, b));
    }

    {
    const list<int>      x = {2, 3, 4};
    const vector<double> y = {2, 3, 4, 5};
//  assert(equal_1(x.begin(), x.end(), y.begin())); // error: no matching function for call to 'equal_1'
//  assert(equal_2(x.begin(), x.end(), y.begin())); // error: no matching function for call to 'equal_2'
//  assert(equal_3(x.begin(), x.end(), y.begin())); // error: no matching function for call to 'equal_3'
    assert(equal_4(x.begin(), x.end(), y.begin()));
    assert(equal  (x.begin(), x.end(), y.begin()));
    }

    cout << "Done." << endl;
    return 0;}
