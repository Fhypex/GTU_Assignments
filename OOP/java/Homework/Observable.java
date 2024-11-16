import java.util.ArrayList;
import java.util.List;

public class Observable {
    // list of observers (Player or Viewer)
    private List<Observer> observers = new ArrayList<>();
    // adding an observer
    public void register(Observer observer){
        observers.add(observer);
    }
    // removing an observer
    public void remove(Observer observer){
        observers.remove(observer);
    }
    // notifying the observers to remove
    protected void notifyObserversToRemove(Media media){
        for(Observer observer : observers){
            observer.remove(media);
        }
    }
    // notifying the observers to add
    protected void notifyObservers(Media media){
        for(Observer observer : observers){
            observer.update(media);
        }
    }
}