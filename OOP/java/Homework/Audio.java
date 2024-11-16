public class Audio extends Media implements NonVisual, Playable {
    // private data
    private String duration;
    private String otherInfo;
    // creating an Audio object
    public Audio(String name, String duration, String otherInfo) {
        super(name);
        this.duration = duration;
        this.otherInfo = otherInfo;
    }
    // overriding the info method from Playable
    @Override
    public void info() {
        System.out.println("Audio Name: " + name + "  Duration: " + duration + "  Info: " + otherInfo);
    }
}