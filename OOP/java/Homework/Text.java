public class Text extends Media implements NonVisual, NonPlayable {
    // private data 
    private String otherInfo;
    // Text constructor
    public Text(String name, String otherInfo) {
        super(name);
        this.otherInfo = otherInfo;
    }
    // overriding the info function from NonPlayable
    @Override
    public void info() {
        System.out.println("Text Name: " + name + "  Info: " + otherInfo);
    }
}