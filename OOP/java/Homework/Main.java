public class Main {
   /*
    * 
    Makefile calisiyor mu emin degilim deneme sansim olmadi kusura bakmayin hocam
    *
    */
public static void main(String args[]){
    // create dataset
    Dataset ds = new Dataset();
    // create observers
    Player p1 = new Player();
    Player p2 = new Player();
    Viewer v1 = new Viewer();
    Viewer v2 = new Viewer();
    // create registers
    ds.register(p1);
    ds.register(p2);
    ds.register(v1);
    ds.register(v2);
    // add the media to dataset
    ds.add(new Image("imagename1", "dimension info1", "other info1"));
    ds.add(new Image("imagename2", "dimension info2", "other info2"));
    ds.add(new Image("imagename3", "dimension info3", "other info3"));
    ds.add(new Image("imagename4", "dimension info4", "other info4"));
    ds.add(new Image("imagename5", "dimension info5", "other info5"));
    ds.add(new Audio("audioname1", "duration1", "other info1"));
    ds.add(new Audio("audioname2", "duration2", "other info2"));
    ds.add(new Audio("audioname3", "duration3", "other info3"));
    ds.add(new Video("videoname1", "duration1", "other info1"));
    ds.add(new Video("videoname2", "duration2", "other info2"));
    ds.add(new Video("videoname3", "duration3", "other info3"));
    ds.add(new Text("textname1", "other info1"));
    ds.add(new Text("textname2", "other info2"));
    ds.add(new Text("textname3", "other info3"));


    Playable po = p1.currentlyPlaying();
    po.info();
    ds.remove(po);  // remove currentlyPlaying which is current index for default
    System.out.println("== Removing current index object which is the default index '0' ==");
    p1.next("video");   // set current to next video
    System.out.println();
    Playable pov = p1.currentlyPlaying();       // get current object
    pov.info();
    System.out.println("== Removing current index object which is next video media ==");
    ds.remove(pov); // remove video 1
    System.out.println();

    NonPlayable np = v1.currentlyViewing();
    np.info();
    System.out.println();
    // show all playables on p1
    System.out.println("== PlayableList ==");
    p1.showList();
    System.out.println();
    // show all playables on p2
    System.out.println("== NonPlayableList ==");
    v1.showList(); 
    Playable asd = p1.currentlyPlaying();
    System.out.println("== Current Object to delete is ==");
    asd.info();
    ds.remove(asd);
    // show all playables on p1
    System.out.println("== PlayableList ==");
    System.out.println();
    p1.showList();
    // keep track
    System.out.println();
    System.out.println("== Current Object playing is ==");
    System.out.println();
    asd = p1.currentlyPlaying();
    asd.info();
    System.out.println();
    System.out.println("== Set to next audio ==");
    System.out.println();
    p1.next("audio");
    asd = p1.currentlyPlaying();
    asd.info();
    System.out.println();
    System.out.println("== Set to next audio one more time ==");
    System.out.println();
    p1.next("audio");
    asd = p1.currentlyPlaying();
    asd.info();
    System.out.println();
    System.out.println("== Set to previous audio ==");
    System.out.println();
    p1.previous("audio");
    asd = p1.currentlyPlaying();
    asd.info();
    System.out.println();
    System.out.println("=== Viewer Handling ===");
    NonPlayable obj = v1.currentlyViewing();
    obj.info();
    v1.next("image");
    obj = v1.currentlyViewing();
    System.out.println();
    System.out.println("=== Next Image Media ===");
    obj.info();
    v1.next("image");
    obj = v1.currentlyViewing();
    System.out.println();
    System.out.println("=== Next Image Media 1 more time ===");
    obj.info();
    v1.previous("image");
    obj = v1.currentlyViewing();
    System.out.println();
    System.out.println("=== Previous Image Media ===");
    obj.info();
    System.out.println();
    System.out.println("=== Removing Current Object which is Image 2 ===");
    ds.remove(obj);
    System.out.println();
    System.out.println("=== printing the Viewer list again ===");
    v1.showList();
    
}
}
