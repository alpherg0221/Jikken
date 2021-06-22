#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string serial;
    int kakaku, chumonryo, waribikiritsu;
    int sum = 0;

    // 出力先ファイルを開く
    ofstream fout("result.txt");

    //出力情報の各列の情報を出力
    fout << "商品番号 " << "割引価格(1個) " << "割り引いた額(1個) " << "割引後税込み価格(1個)\n";
    cout << "商品番号 " << "割引価格(1個) " << "割り引いた額(1個) " << "割引後税込み価格(1個)\n";

    // EOFまで読み込み
    while (!cin.eof()) {
        // 一行ごとに読み込み
        cin >> serial >> kakaku >> chumonryo >> waribikiritsu;

        // 空行があった場合スキップ
        if (cin.fail()) continue;

        // 計算
        int waribikigo = kakaku * (100 - waribikiritsu) / 100;
        int waribikareta = kakaku * waribikiritsu / 100;
        int zeikomi = static_cast<int>(waribikigo * 1.1);
        sum += zeikomi * chumonryo;

        // 計算結果の出力
        fout << serial << " " << waribikigo << " " << waribikareta << " " << zeikomi << "\n";
        cout << serial << " " << waribikigo << " " << waribikareta << " " << zeikomi << "\n";
    }

    //合計金額の出力
    fout << "合計金額 " << sum;
    cout << "合計金額 " << sum;

    return 0;
}