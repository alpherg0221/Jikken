#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// 差表を格納する構造体
struct Point {
    double x;
    double y;
};

Point gravity(Point *p);

double side(Point p1, Point p2);

double area(Point *p);

int main(int argc, char *argv[]) {
    double x, y;
    Point g{};
    Point p[3];

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

    // 値の読み込み
    for (Point &e : p) {
        fin >> x >> y;
        e = {x, y};
    }

    // 結果を計算して出力
    g = gravity(p);
    cout << "重心は(" << g.x << "," << g.y << ")" << endl;
    cout << "各辺の長さは" << side(p[0], p[1]) << " " << side(p[1], p[2]) << " " << side(p[0], p[2]) << endl;
    cout << "面積は" << area(p) << endl;
}

// 重心を求める関数
Point gravity(Point *p) {
    double x = (p->x + (p + 1)->x + (p + 2)->x) / 3;
    double y = (p->y + (p + 1)->y + (p + 2)->y) / 3;
    return {x, y};
}

// 辺の長さを求める関数
double side(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// 面積を求める関数
double area(Point *p) {
    double ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += ((p + i % 3)->x) * ((p + (i + 1) % 3)->y - (p + (i + 2) % 3)->y);
    }
    return abs(ans) / 2;
}