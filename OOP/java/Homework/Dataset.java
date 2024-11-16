import java.util.ArrayList;
import java.util.List;

public class Dataset extends Observable {
    // list of Media objects
    private List<Media> mediaList = new ArrayList<>();
    // add function to add to list and notify observers for them to also add
    public void add(Media media) {
        mediaList.add(media);
        notifyObservers(media);
    }
    // remove function to remove from list and notify observers for them to also remove
    public void remove(Media media){
        System.out.println("asdasdasdasdad");
        mediaList.remove(media);
        notifyObserversToRemove(media);

    }
    // removing a Playable object by downcasting
    public void remove(Playable playable) {
        
        Media media = (Media) playable; // Typecast Playable to Media
        mediaList.remove(media); // Remove the Media object from the list
        notifyObserversToRemove(media); // Notify observers
    }
    // removing a nonPlayable object by downcasting
    public void remove(NonPlayable nonPlayable) {
        
        Media media = (Media) nonPlayable; // Typecast nonPlayable to Media
        mediaList.remove(media); // Remove the Media object from the list
        notifyObserversToRemove(media); // Notify observers
    } 
    
    // getList
    public List<Media> getList() {
        return new ArrayList<>(mediaList);
    }
}