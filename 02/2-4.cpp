#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    string word;
    vector<string> word_list;

    // 引数の数が正しいかチェック
    if (argc != 2) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // 入力ファイルを開く
    ifstream fin1(argv[1]);

    // ファイルを開けなかった時のエラー処理
    if (!fin1) {
        cout << "ファイルを開けませんでした\n";
        return 1;
    }

    // ファイルの読み込み
    while (!fin1.eof()) {
        fin1 >> word;
        word_list.insert(word_list.end(), word);
    }

    // ソート
    sort(word_list.begin(), word_list.end(), greater<string>());

    // 結果の出力
    for (const string& e : word_list) {
        cout << e << endl;
    }
}