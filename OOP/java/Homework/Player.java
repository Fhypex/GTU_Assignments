import java.util.ArrayList;
import java.util.List;

public class Player implements Observer{
    // list of playable media objects
    private List<Playable> playList = new ArrayList<>();
    // current Index of the player
    private int currentIndex = 0;
    // overriding the update function to add to list
    @Override
    public void update(Media media) {
        if (media instanceof Playable) {
            playList.add((Playable) media);
        }
    }
    // overriding the remove function to remove from list
    @Override
    public void remove(Media media){
        if(media instanceof Playable){
            playList.remove((Playable) media);
        }
    }
    // printing the list
    public void showList(){
        for(Playable media : playList) {
            media.info();
        }
    }
    // returing a playable object from player to create an object
    public Playable currentlyPlaying() {
        if (playList.isEmpty()) {
            return null; 
        }
        return playList.get(currentIndex);
    }
    // next "type" file in the player to set as currentlyPlaying
    public void next(String type) {
        boolean flag = true; // flag to indicate whether or not the object has been found
        if(type.equals("audio") || type.equals("video")){
            for(int i = currentIndex + 1; i < playList.size(); i++){ // iterate through the list
                if(type.equals("audio") && playList.get(i) instanceof Audio){
                    currentIndex = i;   // set the index
                    flag = false;   
                    break;
                }else if(type.equals("video") && playList.get(i) instanceof Video){
                    currentIndex = i;
                    flag = false;
                    break;
                }
            }
            if(flag){   // if the object is not found roll back to beginning
                for(int i = 0; i < currentIndex ; i++){
                    if(type.equals("audio") && playList.get(i) instanceof Audio){
                        currentIndex = i;
                        break;
                    }else if(type.equals("video") && playList.get(i) instanceof Video){
                        currentIndex = i;
                        break;
                    }
                }
            }
            
        }else{
            throw new IllegalArgumentException("Invalid media type: " + type + ". Expected 'audio' or 'video'.");
        }
    }
    // previous "type" file in the player to set as currentlyPlaying
    public void previous(String type){
        boolean flag = true;
        if(type.equals("audio") || type.equals("video")){
            for(int i = currentIndex - 1; i >= 0; i--) {
                if(type.equals("audio") && playList.get(i) instanceof Audio){
                    currentIndex = i;
                    flag = false;
                    break;
                }else if(type.equals("video") && playList.get(i) instanceof Video){
                    currentIndex = i;
                    flag = false;
                    break;
                }
            }
            if(flag){   // roll back to the end
                for(int i = playList.size() - 1; i >= currentIndex; i--){
                    // start from the end
                    if(type.equals("audio") && playList.get(i) instanceof Audio){
                        currentIndex = i;
                        break;
                    }else if (type.equals("video") && playList.get(i) instanceof Video){
                        currentIndex = i;
                        break;
                    }
                }
            }
            
        }else{
            throw new IllegalArgumentException("Invalid media type: " + type + ". Expected 'audio' or 'video'.");
        }
    }
}