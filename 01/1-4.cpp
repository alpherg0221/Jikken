#include <iostream>
#include <fstream>
#include <set>
#include <regex>

using namespace std;

int main(int argc, char *argv[]) {
    string word;
    set<string> diff1st, diff2st, cmnst;
    regex re(R"(;|,|\.)");

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

    // diff1の単語を読み込んでdiff1stに格納
    // 置き換え前にピリオドやコンマを消す
    while (!fin1.eof()) {
        fin1 >> word;
        word = regex_replace(word, re, "");
        diff1st.insert(word);
    }

    // diff2の単語を読み込んでdiff2stに格納
    // diff1とdiff2で共通する単語をcmnstに格納
    // 置き換え前にピリオドやコンマを消す
    while (!fin2.eof()) {
        fin2 >> word;
        word = regex_replace(word, re, "");
        diff2st.insert(word);
        if (diff1st.count(word)) cmnst.insert(word);
    }

    // diff1stとdiff2stから共通の単語を削除
    for (const string &e : cmnst) if (diff1st.count(e)) diff1st.erase(e);
    for (const string &e : cmnst) if (diff2st.count(e)) diff2st.erase(e);

    // ターミナルへの結果の出力
    cout << "diff1にのみ含まれる単語" << "\n";
    if (!diff1st.empty()) for (const string &e : diff1st) cout << e << "\n"; else cout << "なし" << "\n";
    cout << "\ndiff2にのみ含まれる単語" << "\n";
    if (!diff2st.empty()) for (const string &e : diff2st) cout << e << "\n"; else cout << "なし" << "\n";
    cout << "\n両方に含まれる単語" << "\n";
    if (!cmnst.empty()) for (const string &e : cmnst) cout << e << "\n"; else cout << "なし" << "\n";

    // ファイルへの結果の出力
    fout << "diff1にのみ含まれる単語" << "\n";
    if (!diff1st.empty()) for (const string &e : diff1st) fout << e << "\n"; else fout << "なし" << "\n";
    fout << "\ndiff2にのみ含まれる単語" << "\n";
    if (!diff2st.empty()) for (const string &e : diff2st) fout << e << "\n"; else fout << "なし" << "\n";
    fout << "\n両方に含まれる単語" << "\n";
    if (!cmnst.empty()) for (const string &e : cmnst) fout << e << "\n"; else fout << "なし" << "\n";

    return 0;
}