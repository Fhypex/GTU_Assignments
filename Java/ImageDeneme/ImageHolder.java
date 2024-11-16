
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class ImageHolder {
    private BufferedImage image;

    public ImageHolder(String imagePath) {
        loadImage(imagePath);
    }

    private void loadImage(String imagePath) {
        try {
            image = ImageIO.read(new File(imagePath));
        } catch (IOException e) {
            System.out.println("Error loading image: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public BufferedImage getImage() {
        return image;
    }

    public void setImage(BufferedImage image) {
        this.image = image;
    }

    public void saveImage(String outputPath, String format) {
        try {
            ImageIO.write(image, format, new File(outputPath));
        } catch (IOException e) {
            System.out.println("Error saving image: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
