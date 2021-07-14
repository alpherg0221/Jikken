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
    int det() {
        // 正方行列かチェック
        if (row != column) {
            cout << "正方行列ではありません" << endl;
            exit(1);
        }

        if (row == 2) {
            return data[0][0] * data[1][1] - data[1][0] * data[0][1];
        } else {
            int ans = 0;
            for (int i = 0; i < row; i++) {
                vector<vector<int>> temp(row - 1, vector<int>(column - 1, 0));
                for (int j = 0; j < row; j++) {
                    for (int k = 1; k < column; k++) {
                        if (j < i) {
                            temp[j][k - 1] = data[j][k];
                        } else if (j == i) {
                            continue;
                        } else if (j > i) {
                            temp[j - 1][k - 1] = data[j][k];
                        }
                    }
                }
                ans += data[i][0] * (i % 2 == 0 ? 1 : -1) * Matrix(row - 1, column - 1, temp).det();
            }
            return ans;
        }
    }

    // 行列を表示するメソッド
    void show() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
};

int main() {
    vector<vector<int>> a1 = {{1, 5, 2},
                              {8, 4, 6},
                              {5, 2, 3}};
    vector<vector<int>> b1 = {{7, 1, 1},
                              {5, 2, 5},
                              {3, 1, 4}};
    vector<vector<int>> a2 = {{1, 5},
                              {8, 4}};
    vector<vector<int>> b2 = {{7, 1},
                              {5, 2}};
    vector<vector<int>> a3 = {{3, 4, -1},
                              {2, 5, -2},
                              {1, 6, -4}};

    Matrix aMatrix1(3, 3, a1);
    Matrix bMatrix1(3, 3, b1);
    Matrix aMatrix2(2, 2, a2);
    Matrix bMatrix2(2, 2, b2);
    Matrix aMatrix3(3, 3, a3);

    // 足し算
    aMatrix1.add(bMatrix1).show();

    // 引き算
    aMatrix1.sub(bMatrix1).show();

    // 内積
    aMatrix2.dot(bMatrix2).show();

    // 行列式
    cout << aMatrix3.det() << "\n\n";

    return 0;
}