public class Video extends Media implements Visual, Playable {
    // private data
    private String duration;
    private String otherInfo;
    // Video constructor
    public Video(String name, String duration, String otherInfo) {
        super(name);
        this.duration = duration;
        this.otherInfo = otherInfo;
    }
    // overriding the info method from Playable
    @Override
    public void info() {
        System.out.println("Video Name: " + name + "  Duration: " + duration + "  Info: " + otherInfo);
    }
}