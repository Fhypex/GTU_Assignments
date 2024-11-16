#include <iostream>
#include <string>
#include <vector>
using namespace std;


typedef struct Point{
    int x;
    int y;

}Point;
class Shape{

    private:
        Point center;
        string type;
    public:
        Shape(){
            
        }
        Shape(Point num, string asd){
            center = num;
            type = asd;
        }
        void setCenter(Point num){ center = num;}
        Point getCenter(){return center;}

};
class Triangle : public Shape{

    private:
        Point point1;
        Point point2;
        Point point3;
    public:
        Triangle(Point array[3], Point newcenter) : Shape(newcenter, "Triangle") {
        point1 = array[0];
        point2 = array[1];
        point3 = array[2];
    }
        
        void setCent(Point newcenter){
            setCenter(newcenter);
        }
        int type(){
            return 2;
        }
        void Print(){
            cout << "Center point: " << getCenter().x << " ," << getCenter().y << endl;
            cout << "Coordinates: ";
            
            cout << point1.x << ", " << point1.y << " - ";
            cout << point2.x << ", " << point2.y << " - ";
            
            cout << point3.x << ", " << point3.y << " - ";
            cout << endl;
            
        }


};
class Rectangle : public Shape{

    private:
        Point point1;
        Point point2;
        Point point3;
        Point point4;
    public:
        Rectangle(Point array[4], Point newcenter) : Shape(newcenter, "Rectangle") {
            point1 = array[0];
            point2 = array[1];
            point3 = array[2];
            point4 = array[3];
        }
        int type(){
            return 1;
        }
        void Print(){
            cout << "Center point: " << getCenter().x << " ," << getCenter().y << endl;
            cout << "Coordinates: ";
            cout << point1.x << ", " << point1.y << " - ";
            cout << point2.x << ", " << point2.y << " - ";
            
            cout << point3.x << ", " << point3.y << " - ";
            cout << point4.x << ", " << point4.y << " - ";
            cout << "      ===   ";
            cout << endl;
        }

};
class Frame : public Shape{

    private:
        vector<Triangle> triangles;
        vector<Rectangle> rectangles;
    public:
        Frame(Point newcenter, vector<Triangle> tr, vector<Rectangle> rec){
            triangles = tr;
            rectangles = rec;
            Shape(newcenter, "Frame");
        }       
        void addTr(Triangle obj){
            triangles.push_back(obj);
        }
        void addRec(Rectangle obj){
            rectangles.push_back(obj);
        }
        int type(){
            return 0;
        }
        void print(){
            for(int i = 0; i < triangles.size(); i++){
                cout << " triangles " << endl;
                triangles[i].Print();
                cout << " triangles " << endl;
            }
            cout << endl;
            for(int i = 0; i < rectangles.size(); i++){
                rectangles[i].Print();
            }
        }



};

int main(){
    
    Point p1 = {6, 9};
    Point p2 = {4, 3};
    Point p3 = {2, 10};
    Point p4 = {6, 6};
    Point center = {10, 5};
    Point center2 = {12,6};
    Point center3 = {14,8};
    Point array[4] = {p1, p2, p3, p4};
    Point array2[3] = {p1, p2, p3};

    Rectangle a(array, center);
    a.Print();
    Triangle b(array2,center2);
    vector<Triangle> vec;
    vec.push_back(b);
    vector<Rectangle> vec2;
    vec2.push_back(a);
    Frame c(center3,vec,vec2);
    c.print();

    return 0;
}