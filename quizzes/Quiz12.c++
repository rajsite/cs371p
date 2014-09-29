/*
CS371p: Quiz #12 (7 pts) [Thanh]
*/

/* -----------------------------------------------------------------------
 1. Taken independently, which of the following lines does compile and
    which of the following lines does not compile?
    (6 pts)

compiles
doesn't compile
compiles
*/

int main () {
          int i  = 2;
    const int ci = 2;

    const int*  p  = &i;
//  int*  const pc = &ci;
    const int&  r  = i;

    return 0;}
