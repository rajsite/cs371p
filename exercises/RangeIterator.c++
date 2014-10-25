// -----------------
// RangeIterator.c++
// -----------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class range_iterator {
    private:
        T _n;

    public:
        range_iterator (const T& n) :
                _n (n)
            {}

        bool operator != (const range_iterator& other) const {
            return _n != other._n;}

        const T& operator * () const {
            return _n;}

        range_iterator& operator ++ () {
            ++_n;
            return *this;}

        range_iterator operator ++ (int) {
            range_iterator tmp = *this;
            ++_n;
            return tmp;}};

int main () {
    using namespace std;
    cout << "RangeIterator.c++" << endl;

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 2;
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "");
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 3;
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "2");
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 4;
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "23");
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 5;
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}
