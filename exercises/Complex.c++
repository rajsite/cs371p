// -----------
// Complex.c++
// -----------

#include <cassert>  // assert
#include <complex>  // complex
#include <iostream> // cout, endl
#include <utility>  // !=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

} // rel_ops
} // std;
*/

template <typename T>
class my_complex {
    friend bool operator == (const my_complex& lhs, const my_complex& rhs) {
        return (lhs._r == rhs._r) && (lhs._i == rhs._i);}

    friend T real (const my_complex& v) {
        return v._r;}

    friend T imag (const my_complex& v) {
        return v._i;}

    private:
        T _r;
        T _i;

    public:
        my_complex (const T& r = T(), const T& i = T()) :
                _r (r),
                _i (i)
            {}
/*
        my_complex (const my_complex& rhs) :
                _r (rhs._r),
                _i (rhs._i)
            {}

        my_complex& operator = (const my_complex& rhs) {
            _r = rhs._r;
            _i = rhs._i;
            return *this;}

        ~my_complex ()
            {}
*/
        my_complex& operator += (const my_complex& rhs) {
            _r += rhs._r;
            _i += rhs._i;
            return *this;}

        my_complex& conj () {
            _i = -_i;
            return *this;}};

template <typename T>
my_complex<T> operator + (my_complex<T> lhs, const my_complex<T>& rhs) {
    return lhs += rhs;}

template <typename T>
my_complex<T> conj (my_complex<T> v) {
    return v.conj();}

template <typename T>
void test () {
    my_complex<int> x;
    my_complex<int> y(2);
    my_complex<int> z(2, 3);

    assert(real(z) == 2);
    assert(imag(z) == 3);

    my_complex<int> t(y);
    assert(t == y);

    my_complex<int>& u = (t = z);
    assert( t ==  z);
    assert(&u == &t);

    my_complex<int>& v = (x += y);
    assert(x == my_complex<int>(2,  0));
    assert(&v == &x);

    v = (x + y);
    assert(v == my_complex<int>(4,  0));

    my_complex<int> w = conj(z);
    assert(z == my_complex<int>(2,  3));
    assert(w == my_complex<int>(2, -3));}

int main () {
    using namespace std;
    using namespace std::rel_ops;
    cout << "Complex.c++" << endl;

    test<my_complex<int>>();
    test<   complex<int>>();

    cout << "Done." << endl;
    return 0;}
