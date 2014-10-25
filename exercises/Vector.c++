// ----------
// Vector.c++
// ----------

#include <cassert>   // assert
#include <algorithm> // fill
#include <cstddef>   // size_t
#include <iostream>  // cout, endl

using namespace std;

template <typename T>
class my_vector {
    public:
        typedef T value_type;

    private:
        const size_t _s;
        T*    const  _a;

    public:
        my_vector (size_t s = 0, const T& v = T()) :
                _s (s),
                _a (s == 0 ? 0 : new T[s]) {
            fill(_a, _a + _s, v);}

        ~my_vector () {
            delete [] _a;}

        T& operator [] (size_t i) {
            return _a[i];}

        const T& operator [] (size_t i) const {
            return (*const_cast<my_vector<T>*>(this))[i];}};

int main () {
    using namespace std;
    cout << "Vector.c++" << endl;

    {
    my_vector<int> x;
    }

    {
    my_vector<int> x(10);
    assert(x[3] == 0);
    x[3] = 4;
    assert(x[3] == 4);
    }

    {
    my_vector<int> x(10, 2);
    assert(x[3] == 2);
    x[3] = 4;
    assert(x[3] == 4);
    }

    {
    const my_vector<int> x(10, 2);
    assert(x[3] == 2);
    }

    cout << "Done." << endl;
    return 0;}
