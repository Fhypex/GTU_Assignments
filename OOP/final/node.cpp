#include <iostream>
#include <string>

using namespace std;
template<typename T> class LinkedList;
template<typename T>
class Node{
friend class LinkedList<T>;

    private:
        T data;
        Node* next;
    public:
        Node(T data): data(data), next(NULL){}
        void setData(T dat){
            data = dat;
        }
        void setPtr(Node* obj){ next = obj;}
        T& getData(){
            return data;
        }
        void addList(T& data){
            Node* nex = new Node(data);
            next = nex;
        }
        Node* Next(){
            return next;
        }
        
};

template<typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->Next();
            delete current;
            current = next;
        }
    }

    void addNode(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() const{
        Node<T>* current = head;
        while (current != nullptr){
            cout << current->getData() << " ";
            current = current->Next();
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list;

    list.addNode(1);
    list.addNode(4);
    list.addNode(7);

    list.printList();  // Output: 1 2 3

    return 0;
}

class Helloworld{

    private:
        Helloworld* data;
        char* m_data;

    public:
        Helloworld(int k): data(NULL),m_data(NULL){}
};