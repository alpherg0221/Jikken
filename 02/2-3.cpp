#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 関数の宣言
void histogram(vector<long> list);

void histogram(vector<double> list);

int main(int argc, char *argv[]) {
    long input1;
    double input2;
    vector<long> list1;
    vector<double> list2;

    // 引数の数が正しいかチェック
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

    // 1つ目のファイルの読み込み
    while (!fin1.eof()) {
        fin1 >> input1;
        list1.insert(list1.end(), input1);
    }

    // 2つ目のファイルの読み込み
    while (!fin2.eof()) {
        fin2 >> input2;
        list2.insert(list2.end(), input2);
    }

    cout << argv[1] << "のヒストグラムです" << endl;
    histogram(list1);
    cout << argv[2] << "のヒストグラムです" << endl;
    histogram(list2);

    return 0;
}

void histogram(vector<long> list) {
    vector<vector<long>> hlist;
    long interval;

    // ソートして最小値と最大値から1階級当たりの範囲を求める
    sort(list.begin(), list.end());
    interval = (list[list.size() - 1] - list[0] - 1) / 10;

    // 各階級の下限と上限を小数第1位で求めて配列に格納
    hlist.insert(hlist.end(), {list[0], list[0] + interval, 0});
    for (int i = 1; i < 9; i++) {
        hlist.insert(hlist.end(), {hlist[i - 1][1] + 1, hlist[i - 1][1] + interval, 0});
    }
    hlist.insert(hlist.end(), {hlist[8][1] + 1, list[list.size() - 1], 0});

    // listの格要素の数を階級ごとの配列hlistに格納
    for (long e : list) {
        for (int i = 0; i < 10; i++) {
            if (hlist[i][0] <= e && e <= hlist[i][1]) hlist[i][2]++;
        }
    }

    // 各階級値の桁数の最小を求める
    long min = 10e14;
    int min_digit;
    for (int i = 0; i < 10; i++) {
        if (min > hlist[i][2]) min = hlist[i][2];
    }
    min_digit = floor(log10(min));

    // 結果の出力
    for (int i = 0; i < 10; i++) {
        printf("%6ld -%6ld\t", hlist[i][0], hlist[i][1]);
        for (int j = 0; j < hlist[i][2] / static_cast<long>(pow(10, min_digit)); j++) cout << "*";
        cout << endl;
    }
}

void histogram(vector<double> list) {
    vector<vector<double>> hlist;
    double interval;

    // ソートして最小値と最大値から1階級当たりの範囲を求める
    sort(list.begin(), list.end());
    interval = (list[list.size() - 1] - list[0] - 0.1) / 10;

    // 各階級の下限と上限を小数第1位で求めて配列に格納
    hlist.insert(hlist.end(), {list[0], list[0] + round(interval * 10) / 10, 0});
    for (int i = 1; i < 9; i++) {
        hlist.insert(hlist.end(), {hlist[i - 1][1] + 0.1, round((hlist[i - 1][1] + interval) * 10) / 10, 0});
    }
    hlist.insert(hlist.end(), {hlist[8][1] + 0.1, list[list.size() - 1], 0});

    // listの格要素の数を階級ごとの配列hlistに格納
    for (double e : list) {
        for (int i = 0; i < 10; i++) {
            if (hlist[i][0] <= e && e <= hlist[i][1]) hlist[i][2]++;
        }
    }

    // 各階級値の桁数の最小を求める
    double min = 10e14;
    int min_digit;
    for (int i = 0; i < 10; i++) {
        if (min > hlist[i][2]) min = hlist[i][2];
    }
    min_digit = floor(log10(min) + 1);

    // 結果の出力
    for (int i = 0; i < 10; i++) {
        printf("%6.1lf -%6.1lf\t", hlist[i][0], hlist[i][1]);
        for (int j = 0; j < hlist[i][2] / pow(10, min_digit); j++) cout << "*";
        cout << endl;
    }
}