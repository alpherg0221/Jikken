#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    // 引数の数が正しいかチェック
    if (argc != 3) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // お釣りに使えるお金のリスト
    vector<int> money = {5000, 1000, 500, 100, 50, 10, 5, 1};

    // 請求金額と支払金額を読み込んでお釣りを計算
    int price = stoi(argv[1]);
    int paid = stoi(argv[2]);
    int change = paid - price;
    vector<int> cnt = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // 必要な枚数を計算
    for (int i = 0; i < 8; i++) {
        while (change >= money[i]) {
            change -= money[i];
            cnt[i]++;
            cnt[8]++;
        }
    }

    // 結果の出力
    for (int i = 0; i < cnt.size() - 1; i++) {
        if (cnt[i] != 0) printf("%4d円 : %d枚\n", money[i], cnt[i]);
    }
    cout << "おつりの最小枚数の合計は" << cnt[8] << "枚です" << endl;
    cout << "おつりは" << paid - price << "円です" << endl;
}