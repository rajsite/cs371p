// -------------------
// DynamicBinding.java
// -------------------

class A {
    public String f1 () {
        return f2();}

    public String f2 () {
        return "A.f2";}

    public String g1 () {
        return g2();}

    private String g2 () {
        return "A.g2";}}

class B extends A {
    public String f2 () {
        return "B.f2";}

    public String g2 () {
        return "B.g2";}}

final class DynamicBinding {
    public static void main (String[] args) {
        System.out.println("DynamicBinding.java");

        A x = new B();
        assert x.f1() == "B.f2";
        assert x.g1() == "A.g2";

        System.out.println("Done.");}}
