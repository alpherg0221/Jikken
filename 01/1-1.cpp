#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // xとyが入力されているかチェック
    if (argc != 3) {
        cout << "引数の数が違います" << "\n";
        return 1;
    }

    // 1つ目の引数と2つ目の引数をxとyに代入
    double x = stof(argv[1]);
    double y = stof(argv[2]);

    // 何分後にすれ違うか計算
    double t = 10000 / (x + y);

    // Sからの距離の計算
    double l = (x < y) ? x * t : y * t;

    // 結果の出力
    cout << "すれ違う時間は" << t << "分後\n";
    cout << "Sからの距離は" << l << "m\n";

    return 0;
}