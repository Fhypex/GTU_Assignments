public abstract class Media {
    // each media common data
    protected String name;
    // constructor
    public Media(String name) {
        this.name = name;
    }
    // abstract method for abstract class
    public abstract void info();
}