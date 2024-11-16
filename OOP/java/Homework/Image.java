public class Image extends Media implements Visual, NonPlayable {
    // private data
    private String dimensionInfo;
    private String otherInfo;
    // Image object constructor
    public Image(String name, String dimensionInfo, String otherInfo) {
        super(name);
        this.dimensionInfo = dimensionInfo;
        this.otherInfo = otherInfo;
    }
    // overriding the info method from NonPlayable
    @Override
    public void info() {
        System.out.println("Image Name: " + name + "  Dimension: " + dimensionInfo + "  Info: " + otherInfo);
    }
}