#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
    string word;
    set<string> diff1st, diff2st, cmnst;

    // 読み込むファイル名が入力されているかチェック
    if (argc != 3) {
        cout << "引数の値が違います";
        return 1;
    }

    // 入力ファイルを開く
    ifstream fin1(argv[1]);
    ifstream fin2(argv[2]);

    // 出力ファイルを開く
    ofstream fout("result.txt");

    // ファイルを開けなかった時のエラー処理
    if (!fin1 || !fin2) {
        cout << "ファイルを開けませんでした";
        return 1;
    }

    // diff1_2021.txtの単語を読み込んでsetに格納
    while (!fin1.eof()) {
        fin1 >> word;
        diff1st.insert(word);
    }

    // diff2_2021.txtの単語を読み込んでsetに格納
    while (!fin2.eof()) {
        fin2 >> word;
        diff2st.insert(word);
    }

    // diff1とdiff2の単語を比較
    for (const string &e : diff1st) {
        if (diff2st.count(e)) {
            cmnst.insert(e);
            diff2st.erase(e);
        }
    }
    for (const string &e : cmnst) {
        if (diff1st.count(e)) {
            diff1st.erase(e);
        }
    }

    // 結果の出力
    cout << "diff1にのみ含まれる単語" << "\n";
    for (const string &e : diff1st) cout << e << " ";
    cout << "\ndiff2にのみ含まれる単語" << "\n";
    for (const string &e : diff2st) cout << e << " ";
    cout << "\n両方に含まれる単語" << "\n";
    for (const string &e : cmnst) cout << e << " ";

    return 0;
}