/*
CS371p: Quiz #18 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

-40
12
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T, std::size_t N>
class Allocator {
    private:
        char a[N];

    public:
        const int& view (int i) const {
            return *reinterpret_cast<const int*>(&a[i]);}

    ...};

int main () {
    assert(sizeof(double) == 8);

    Allocator<double, 100> x;

    x.allocate(5);
    x.allocate(3);

    cout << x.view(0)  << endl;
    cout << x.view(96) << endl;
    return 0;}
