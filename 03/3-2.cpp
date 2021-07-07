#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void swap(int *i, int *k);

int main(int argc, char *argv[]) {
    int input;
    vector<int> list;

    // 引数の数が正しいかチェック
    if (argc != 2) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // 入力ファイルを開く
    ifstream fin(argv[1]);

    // ファイルを開けなかった時のエラー処理
    if (!fin) {
        cout << "ファイルを開けませんでした\n";
        return 1;
    }

    // ファイルの読み込み
    while (!fin.eof()) {
        fin >> input;
        list.insert(list.end(), input);
    }

    // 選択ソート
    for (int i = static_cast<int>(list.size()) - 1; i > 0; i--) {
        // maxは最大値のアドレスを入れる
        int *max = &list[i];
        for (int j = 0; j <= i; j++) {
            // maxの値より大きければその値のアドレスをmaxに代入
            if (*max < list[j]) max = &list[j];
        }
        // maxの値とlist[i]の値を交換
        swap(max, &list[i]);
    }

    // 結果の出力
    for (int e : list) cout << e << " ";
    cout << endl;

}

// 2つのアドレスを受け取ってアドレスの指す値を交換する関数
void swap(int *i, int *k) {
    int temp;
    temp = *i;
    *i = *k;
    *k = temp;
}