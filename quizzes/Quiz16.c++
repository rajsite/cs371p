/*
CS371p: Quiz #16 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. Define the class Fraction such that the following works.
    (6 pts)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
class Fraction {
    private:
        T _n;
        T _d;

    public:
        Fraction (const T& n, const T& d) :
                _n (n),
                _d (d)
            {}

        bool operator == (const Fraction& other) const {
            return (_n * other._d) == (_d * other._n);}

        Fraction operator * (const Fraction& other) const {
            return Fraction(_n * other._n, _d * other._d);}};

int main () {
    Fraction<int> x(2, 3);
    Fraction<int> y(4, 5);
    Fraction<int> z = x * y;           // z = x.operator*(y)
    assert(z == Fraction<int>(8, 15)); // z.operator==(Fraction<int>(8, 15))
    return 0;}
