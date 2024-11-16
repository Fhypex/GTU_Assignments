import java.util.ArrayList;
import java.util.List;

public class Viewer implements Observer {
    // list of nonPlayable media objects
    private List<NonPlayable> viewList = new ArrayList<>();
    // to hold current object
    private int currentIndex = 0;
    // overriding the update method 
    @Override
    public void update(Media media) {
        if(media instanceof NonPlayable){
            viewList.add((NonPlayable) media);
        }
    }
    // overriding the remove method
    @Override
    public void remove(Media media){
        if(media instanceof NonPlayable){
            viewList.remove((NonPlayable) media);
        }
    }
    // printing the list
    public void showList(){
        for(NonPlayable media : viewList){
            media.info();
        }
    }
    // returning a nonPlayable object to assign
    public NonPlayable currentlyViewing(){
        if(viewList.isEmpty()){
            return null; 
        }
        return viewList.get(currentIndex);
    }
    // setting current object to next "type" object
    public void next(String type){
        boolean flag = true; // flag to indicate whether or not the object has been found
        if(type.equals("text") || type.equals("image")){

            for(int i = currentIndex + 1; i < viewList.size(); i++){ // go through the list
                if(type.equals("text") && viewList.get(i)instanceof Text){
                    currentIndex = i;       // update the index
                    flag = false;
                    break;
                }else if(type.equals("image") && viewList.get(i) instanceof Image){
                    currentIndex = i;
                    flag = false;
                    break;
                }
            }
            if(flag){
                for(int i = 0; i < currentIndex; i++){
                    // roll back to beginning
                    if(type.equals("text") && viewList.get(i)instanceof Text){
                        currentIndex = i;
                        break;
                    }else if(type.equals("image") && viewList.get(i) instanceof Image){
                        currentIndex = i;
                        break;
                    }
                }
            }
            
        }else{
            throw new IllegalArgumentException("Invalid media type: " + type + ". Expected 'text' or 'image' ");
        }
    }
    // setting current object to previous "type" object
    public void previous(String type){
        boolean flag = true;
        if(type.equals("text") || type.equals("image")){
            for(int i = currentIndex - 1; i >= 0; i--){
                if(type.equals("text") && viewList.get(i) instanceof Text){
                    currentIndex = i;
                    flag = false;
                    break;
                }else if (type.equals("image") && viewList.get(i) instanceof Image){
                    currentIndex = i;
                    flag = false;
                    break;
                }
            }
            if(flag){
                // roll back to the end
                for(int i = viewList.size() - 1; i >= currentIndex; i--){
                    if(type.equals("text") && viewList.get(i) instanceof Text){
                        currentIndex = i;
                        break;
                    }else if (type.equals("image") && viewList.get(i) instanceof Image){
                        currentIndex = i;
                        break;
                    }
                }
            }             
        }else{
            throw new IllegalArgumentException("Invalid media type: " + type + ". Expected 'text' or 'image' ");
        }
    }
}