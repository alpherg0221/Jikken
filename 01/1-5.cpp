#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    string input, registered, registered_id, registered_min;
    int hamming_min = 2049;

    // 読み込むファイル名が入力されているかチェック
    if (argc != 3) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // 入力ファイルを開く
    ifstream fin1(argv[1]);
    ifstream fin2(argv[2]);

    // ファイルを開けなかった時のエラー処理
    if (!fin1 || !fin2) {
        cout << "ファイルを開けませんでした\n";
        return 1;
    }

    // 入力された虹彩データファイルの読み込み
    fin2 >> input;

    // ハミング距離の計算とハミング距離が最小の時の記録
    for (int i = 0; i < 300; i++) {
        int hamming = 0;

        // 登録されたデータの読み込み
        fin1 >> registered_id >> registered;

        // ハミング距離の計算
        for (int j = 0; j < registered.size(); j++) {
            if (input[j] != registered[j]) hamming++;
        }

        // 計算されたハミング距離が今までのものより小さかった場合の処理
        if (hamming < hamming_min) {
            hamming_min = hamming;
            registered_min = registered_id;
        }
    }

    // 結果の出力
    cout << registered_min << endl;
}