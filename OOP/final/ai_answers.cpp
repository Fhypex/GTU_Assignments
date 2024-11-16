#include <iostream>

template<typename T>
class Array2D {
private:
    T** data;
    int rows;
    int columns;

public:
    Array2D(int rowCount, int colCount) : rows(rowCount), columns(colCount) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[columns];
        }
    }

    ~Array2D() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Overload for row access
    T* operator[](int rowIndex) {
        if (rowIndex >= 0 && rowIndex < rows) {
            return data[rowIndex];
        }
        throw std::out_of_range("Row index out of range");
    }

    // Overload for row access (const version)
    const T* operator[](int rowIndex) const {
        if (rowIndex >= 0 && rowIndex < rows) {
            return data[rowIndex];
        }
        throw std::out_of_range("Row index out of range");
    }

    int getRowCount() const { return rows; }
    int getColCount() const { return columns; }
};

int main() {
    Array2D<int> array(3, 4);

    // Populate the array
    for (int i = 0; i < array.getRowCount(); ++i) {
        for (int j = 0; j < array.getColCount(); ++j) {
            array[i][j] = i * array.getColCount() + j + 1;
        }
    }

    // Print the array
    for (int i = 0; i < array.getRowCount(); ++i) {
        for (int j = 0; j < array.getColCount(); ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}