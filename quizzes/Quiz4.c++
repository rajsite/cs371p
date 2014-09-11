/*
CS371p: Quiz #4 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

g1 f1 f2 g2 g4
g1 f1 g3 g4
g1 f1
*/

#include <iostream>  // cout, endl
#include <stdexcept> // domain_error, range_error

using namespace std;

void f (int n) {
    cout << "f1 ";
    if (n == 1)
        throw domain_error("");
    else if (n == 2)
    	throw range_error("");
    cout << "f2 ";}

void g (int n) {
    try {
        cout << "g1 ";
        f(n);
        cout << "g2 ";}
    catch (domain_error& e) {
        cout << "g3 ";}
    cout << "g4 " << endl;}

int main () {
    try {
        g(0);
        g(1);
        g(2);}
    catch (exception& e) {
        cout << endl;}
    return 0;}
