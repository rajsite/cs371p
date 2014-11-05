// -------------
// Singleton.c++
// -------------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string>   // ==

using namespace std;

class Singleton_1 {
    private:
        static Singleton_1 _only;

        Singleton_1 ()
            {}

        Singleton_1 (const Singleton_1&);

    public:
        static Singleton_1& only () {
            return _only;}

        std::string f () const {
            return "Singleton_1::f()";}};

Singleton_1 Singleton_1::_only;

class Singleton_2 {
    private:
        static Singleton_2* _only;

        Singleton_2 ()
            {}

        Singleton_2 (const Singleton_2&);

    public:
        static Singleton_2& only () {
            if (_only == 0)
                _only = new Singleton_2();
            return *_only;}

        std::string f () const {
            return "Singleton_2::f()";}};

Singleton_2* Singleton_2::_only;

class Singleton_3 {
    private:
        Singleton_3 ()
            {}

        Singleton_3 (const Singleton_3&);

    public:
        static Singleton_3& only () {
            static Singleton_3 x;
            return x;}

        std::string f () const {
            return "Singleton_3::f()";}};

int main () {
    cout << "Singleton.c++" << endl;

    assert(&Singleton_1::only()    == &Singleton_1::only());
    assert(Singleton_1::only().f() == "Singleton_1::f()");

    assert(&Singleton_2::only()    == &Singleton_2::only());
    assert(Singleton_2::only().f() == "Singleton_2::f()");

    assert(&Singleton_3::only()    == &Singleton_3::only());
    assert(Singleton_3::only().f() == "Singleton_3::f()");

    cout << "Done." << endl;
    return 0;}
