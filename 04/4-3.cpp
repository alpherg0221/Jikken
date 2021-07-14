#include <iostream>

using namespace std;

class Matrix {
private:
    int row;
    int column;
    int data[];
public:
    Matrix(int r, int c, int d[]);

    void add(Matrix m);

    void sub(Matrix m);

    //Matrix dot(Matrix m);

    void show();
};

Matrix::Matrix(int r, int c, int d[]) {
    row = r;
    column = c;
    *data = *d;
}

void Matrix::add(Matrix m) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            data[column * i + j] += m.data[column * i + j];
        }
    }
}

void Matrix::sub(Matrix m) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            data[column * i + j] -= m.data[column * i + j];
        }
    }
}

void Matrix::show() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << data[column * i + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[9] = {1, 5, 2, 8, 4, 6, 5, 2, 3};
    int b[9] = {7, 1, 1, 5, 2, 5, 3, 1, 4};
    //Matrix aMatrix(3, 3, a);
    Matrix bMatrix(3, 3, b);

    //aMatrix.add(bMatrix);
    bMatrix.show();

    return 0;
}