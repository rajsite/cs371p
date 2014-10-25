// --------
// Copy.c++
// --------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm> // copy, equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

template <typename II, typename OI>
OI my_copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

int main () {
    using namespace std;
    cout << "Copy.c++" << endl;

    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = copy(x.begin(), x.end(), y.begin() + 1);
    assert(p == y.begin() + 4);
    assert(equal(x.begin(), x.end(), y.begin() + 1));

    cout << "Done." << endl;
    return 0;}
