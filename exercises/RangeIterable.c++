// -----------------
// RangeIterable.c++
// -----------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class range_iterable {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            private:
                T _n;

            public:
                iterator (const T& n) :
                        _n (n)
                    {}

                bool operator != (const iterator& other) const {
                    return _n != other._n;}

                const T& operator * () const {
                    return _n;}

                iterator& operator ++ () {
                    ++_n;
                    return *this;}};

        public:
            range_iterable (const T& b, const T& e) :
                    _b (b),
                    _e (e)
                {}

            iterator begin () const {
                return iterator(_b);}

            iterator end () const {
                return iterator(_e);}};

int main () {
    using namespace std;
    cout << "RangeIterable.c++" << endl;

    {
    range_iterable<int> x(2, 2);
    range_iterable<int>::iterator b = x.begin();
    range_iterable<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "");
    }

    {
    range_iterable<int> x(2, 3);
    range_iterable<int>::iterator b = x.begin();
    range_iterable<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "2");
    }

    {
    range_iterable<int> x(2, 4);
    range_iterable<int>::iterator b = x.begin();
    range_iterable<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "23");
    }

    {
    range_iterable<int> x(2, 5);
    range_iterable<int>::iterator b = x.begin();
    range_iterable<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}
