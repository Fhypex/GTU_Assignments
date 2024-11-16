#include <iostream>
#include <string>

class Pointer{

    private:
        int data;
        Pointer* p;
    public:
    Pointer(){
        p = NULL;
        data = 0;       
    }
    Pointer(int data){
        data = data;
        p = NULL;
    }
    void setP(int data){
        this->data = data;
    }
    int getData(){
        return data;
    }
    Pointer* getPointer(){
        return p;
    }
    void addPointer(int newdata){
        Pointer* a = new Pointer(newdata);
        p = a;
    }
    static void free(Pointer* head){
        while (head != nullptr) {
            Pointer* temp = head;
            head = head->getPointer();
            delete temp;
        }
    }
    


};


template<typename T>
class Container{

    private:
        T* data;
        int size;
        int capacity;

        void resize(){
            capacity *= 2;
            T* new_data = new T[capacity];
            for(int i = 0; i  < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

};




int main(){












    return 0;
}