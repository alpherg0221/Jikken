#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    string line;

    // 読み込むファイル名が入力されているかチェック
    if (argc != 2) {
        cout << "引数の値が違います";
        return 1;
    }

    // 入力ファイルを開く
    ifstream fin(argv[1]);

    // 出力ファイルを開く
    ofstream fout("result.txt");

    // ファイルを開けなかった時のエラー処理
    if (!fin) {
        cout << "ファイルを開けませんでした";
        return 1;
    }

    // EOFまで読み込み
    while (!fin.eof()) {
        // 一行ずつ読み込み
        getline(fin, line);

        // 大文字<=>小文字 の変換
        for (char &i : line) {
            if (isupper(i)) i = static_cast<char>(tolower(i));
            else if (islower(i)) i = static_cast<char>(toupper(i));
        }

        // 一行ごとに出力
        if (!line.empty()) fout << line << "\n";
    }

    return 0;
}