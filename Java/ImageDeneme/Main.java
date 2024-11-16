
import java.awt.image.BufferedImage;

public class Main {
    public static void main(String[] args) {
        // Load an image
        ImageHolder imageHolder = new ImageHolder("D:\\Codes\\Java\\ImageDeneme\\image.png");

        // Retrieve the image
        BufferedImage img = imageHolder.getImage();

        // Optionally save the image to a different location
        imageHolder.saveImage("D:\\Codes\\Java\\ImageDeneme\\asd", "png");
    }
}