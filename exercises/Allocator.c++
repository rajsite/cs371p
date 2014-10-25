// -------------
// Allocator.c++
// -------------

#include <algorithm> // fill
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // allocator

template <typename A, typename BI>
void my_destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}}

template <typename A, typename BI, typename U>
void my_uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        my_destroy(a, p, b);
        throw;}}

template <typename T, typename A = std::allocator<T> >
class my_vector {
    private:
        A                 _x;
        const std::size_t _s;
        T*    const       _a;

    public:
        explicit my_vector (std::size_t s = 0, const T& v = T(), const A& x = A()) :
                _x (x),
                _s (s),
                _a (_x.allocate(s)) {
            my_uninitialized_fill(_x, _a, _a + _s, v);}

        ~my_vector () {
            my_destroy(_x, _a, _a + _s);
            _x.deallocate(_a, _s);}};

int main () {
    using namespace std;
    cout << "Allocator.c++" << endl;

    my_vector<int> x;
    my_vector<int> y(10);
    my_vector<int> z(10, 2);
    my_vector<int> t(10, 2, allocator<int>());

    cout << "Done." << endl;
    return 0;}
