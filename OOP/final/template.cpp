#include <iostream>
#include <algorithm> // For std::sort
#include <stdexcept> // For std::out_of_range
using namespace std;
template <typename T>
class Container {
private:
    T* data;
    size_t size;
    size_t capacity;

    // Function to resize the internal array
    
public:
    // Constructor
    Container() : data(new T[5]), size(0), capacity(5) {}

    // Destructor
    ~Container() {
        delete[] data;
    }

    // Add element
    void add(const T& value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    // Access element
    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Const version for read-only access
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Get size
    size_t getSize() const {
        return size;
    }

    // Sort elements
    void sort() {
        std::sort(data, data + size);
    }
    void resize(){
        capacity *= 2;
        T* temp = new T[capacity];
        for(int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;       
    }
};

int main() {
    Container<int> container;
    Container<char> asd;
    // Adding elements to the container
    for (int i = 0; i < 10; ++i) {
        container.add(15 - i); // Add elements in reverse order
    }
    for (int i = 0; i < 10; ++i) {
        asd.add('a');
        asd.add('b');
        asd.add('c'); // Add elements in reverse order
    }

    // Sorting the container
    container.sort();
    asd.sort();
    // Printing the sorted elements
    for (size_t i = 0; i < container.getSize(); ++i) {
        std::cout << container[i] << " ";
    }
    cout << "\n";
    for (size_t i = 0; i < asd.getSize(); ++i) {
        std::cout << asd[i] << " ";
    }

    return 0;
}