#include <iostream>
#include <algorithm>

using namespace std;

// 関数テンプレート
// 最も小さい数をチェック
template<class T>
void min(T x, T y, T z) {
    T min = x;
    if (y < min) min = y;
    if (z < min) min = z;

    // 結果の出力
    cout << "3つの引数のうち最も小さい引数は" << min << endl;
}

int main(int argc, char *argv[]) {
    // 引数の数が正しいかチェック
    if (argc != 4) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // 各コマンドライン引数の型を記録する配列
    // 0なら数値, 1なら文字列
    int type[3] = {0, 0, 0};

    // 入力された値が数値か文字列かチェック
    // 実際に数値に変換してみてエラーが出れば文字列
    for (int i = 0; i < 3; i++) {
        try {
            stof(argv[i + 1]);
        } catch (invalid_argument &e) {
            type[i] = 1;
        }
    }

    // 各コマンドライン引数の型によってdouble型に変換するかstring型に変換するか決める.
    if (type[0] == 0 && type[1] == 0 && type[2] == 0) {
        min(stof(argv[1]), stof(argv[2]), stof(argv[3]));
    } else if (type[0] == 1 && type[1] == 1 && type[2] == 1) {
        // char*型だと二文字以上のとき処理が複雑になるためstringに変換
        min(string(argv[1]), string(argv[2]), string(argv[3]));
    } else {
        cout << "引数に数値と文字列の両方が入力されています" << endl;
        return 1;
    }

    return 0;
}