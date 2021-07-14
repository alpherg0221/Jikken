#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    int row;
    int column;
    vector<vector<int>> data;
public:
    // コンストラクタ
    Matrix(int r, int c, const vector<vector<int>> &d) {
        row = r;
        column = c;
        data = d;
    };

    // 和を求めるメソッド
    Matrix add(Matrix m) {
        vector<vector<int>> temp(row, vector<int>(column));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                temp[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return Matrix(3, 3, temp);
    };

    // 差を求めるメソッド
    Matrix sub(Matrix m) {
        vector<vector<int>> temp(row, vector<int>(column));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                temp[i][j] = data[i][j] - m.data[i][j];
            }
        }
        return Matrix(3, 3, temp);
    };

    // 内積を求めるメソッド
    Matrix dot(Matrix m) {
        vector<vector<int>> temp(row, vector<int>(m.column, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                for (int k = 0; k < m.column; k++) {
                    temp[i][k] += data[i][j] * m.data[j][k];
                }
            }
        }
        return Matrix(row, m.column, temp);
    };

    // 行列式を計算するメソッド
    Matrix determinant() {

    }

    // 行列を表示するメソッド
    void show() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    };
};

int main() {
    vector<vector<int>> a = {{1, 5, 2}, {8, 4, 6}, {5, 2, 3}};
    Matrix aMatrix(3, 3, a);

    vector<vector<int>> b = {{7, 1, 1}, {5, 2, 5}, {3, 1, 4}};
    Matrix bMatrix(3, 3, b);

    // 足し算
    //aMatrix.add(bMatrix).show();
    // 引き算
    //aMatrix.sub(bMatrix).show();

    aMatrix.dot(bMatrix).show();

    return 0;
}