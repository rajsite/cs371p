// ---------------
// Assertions.java
// ---------------

// http://docs.oracle.com/javase/7/docs/technotes/guides/language/assert.html

final class Assertions {
    public static int cycle_length (int n) {
        assert n > 0;
        int c = 0;
        while (n > 1) {
            if ((n % 2) == 0)
                n = n / 2;
            else
                n = (3 * n) + 1;
            ++c;}
        assert c > 0;
        return c;}

    public static void main (String[] args) {
        System.out.println("Assertions.java");

        assert cycle_length( 1) == 1;
        assert cycle_length( 5) == 6;
        assert cycle_length(10) == 7;

        System.out.println("Done.");}}

/*
% javac -Xlint Assertions.java



% java -ea Assertions
Assertions.java
Exception in thread "main" java.lang.AssertionError
	at Assertions.cycle_length(Assertions.java:17)
	at Assertions.main(Assertions.java:23)



% java Assertions
Assertions.java
Done.
*/
