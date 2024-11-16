#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Iterator{
    private:
        T** data;
        int rows;
        int columns;
        int currentCol;
        int currentRow;
    public:
    Iterator(T** arr, int row,int col){
        rows = row;
        columns = col;
        data = arr;
        currentCol = 0;
        currentRow = 0;
    }
    T* operator[](int index){
        return data[index];
    }
    void next(){
        if(currentCol < columns - 1){
            currentCol++;
        }else{
            currentRow = 0;
            currentCol = 0;
        }
    }
    void next_row(){
        if(currentRow < rows - 1){
            currentRow++;
            currentCol = 0;
        }else{
            currentRow = 0;
            currentCol = 0;
        }
    }
    T& operator*(){
        return data[currentRow][currentCol];
    }
    friend ostream& operator<<(ostream& os,Iterator& a){
        os << *a << endl;
    }

    

};




int main(){
    const int rows = 3;
    const int cols = 4;

    // Initialize the 2D array
    int** a = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        a[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            a[i][j] = i * cols + j + 1;
        }
    }
    Iterator<int> asd(a, rows, cols);
    cout << asd[1][2] << endl;
    return 0;
}