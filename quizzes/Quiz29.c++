/*
CS371p: Quiz #29 (7 pts) [Henry]
*/

/* -----------------------------------------------------------------------
1. Define operator != only in terms of ! and ==.
   Define the operators <=, >, and >= only in terms of ! and <.
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

class A {
    friend bool operator == (const A& lhs, const A& rhs) {
        return lhs._i == rhs._i;}

    friend bool operator < (const A& lhs, const A& rhs) {
        return lhs._i < rhs._i;}

    private:
        int _i;

    public:
        A (int i) {
            _i = i;}};

template <typename T>
bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}
