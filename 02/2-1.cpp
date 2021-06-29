#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // 引数の数が正しいかチェック
    if (argc != 3) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // xをmに, yをnに代入
    int m = stoi(argv[1]);
    int n = stoi(argv[2]);

    // rをmをnで割った余りで初期化
    int r = m % n;

    // rが0ならnが最大公約数
    while(r != 0) {
        m = n;
        n = r;
        r = m % n;
    }

    // 結果の出力
    cout << argv[1] << "と" << argv[2] << "の最大公約数は" << n << "です\n";
}