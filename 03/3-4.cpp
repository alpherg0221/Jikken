#include <iostream>
#include <fstream>

using namespace std;

int **read_image(const string &fname, int *header);

void output_grayscale(int *header, int **pixel);

void output_edge(int *header, int **pixel);

int main(int argc, char *argv[]) {
    int header[3];

    // 引数の数が正しいかチェック
    if (argc != 2) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // 画像の読み込み
    int **pixel = read_image(string(argv[1]), header);

    // 画像の読み込みに失敗したときのエラー処理
    if (pixel == nullptr) return 1;

    // グレースケール画像の出力
    output_grayscale(header, pixel);

    // エッジ抽出画像の出力
    output_edge(header, pixel);

    // 確保したメモリの開放
    for (int i = 0; i < header[1]; i++) {
        delete pixel[i];
    }
    delete[] pixel;
}

// グレースケールで画像を読み込む関数
int **read_image(const string &fname, int *header) {
    string type;
    char buf[3];

    // 入力ファイルを開く
    ifstream fin(fname, ios::binary);

    // ファイルを開けなかった時のエラー処理
    if (!fin) {
        cout << "ファイルを開けませんでした\n";
        return nullptr;
    }

    // ヘッダの読み込み
    fin >> type >> header[0] >> header[1] >> header[2];

    // 改行の読み飛ばし
    fin.read(buf, 1);

    // グレースケール画像のピクセル情報を格納する2次元配列
    int **pixel = new int *[header[1]];
    for (int i = 0; i < header[1]; i++) {
        pixel[i] = new int[header[0]];
    }

    // 1ピクセルごとに読み込んでグレースケールに変換
    for (int i = 0; i < header[1]; i++) {
        for (int j = 0; j < header[0]; j++) {
            fin.read(buf, 3);
            int r = static_cast<int>(static_cast<unsigned char>(buf[0]));
            int g = static_cast<int>(static_cast<unsigned char>(buf[1]));
            int b = static_cast<int>(static_cast<unsigned char>(buf[2]));

            // NTSC係数による加重平均法を用いてグレースケールに変換する関数
            pixel[i][j] = static_cast<int>(0.298912 * r + 0.586611 * g + 0.114478 * b);
        }
    }

    return pixel;
}

// グレースケール画像を出力する関数
void output_grayscale(int *header, int **pixel) {
    // 出力ファイルを開く
    ofstream fout("out_gray.pgm");

    // ファイルを開けなかった時のエラー処理
    if (!fout) {
        cout << "ファイルを開けませんでした\n";
    }

    // ヘッダの出力
    fout << "P2" << "\n";
    fout << header[0] << " " << header[1] << "\n";
    fout << header[2] << "\n";

    // 画像の出力
    for (int i = 0; i < header[1]; i++) {
        for (int j = 0; j < header[0]; j++) {
            fout << pixel[i][j] << " ";
        }
    }
}

// エッジ抽出画像を出力する関数
void output_edge(int *header, int **pixel) {
    // エッジ抽出画像のピクセル情報を格納する2次元配列
    int **edge = new int *[header[1]];
    for (int i = 0; i < header[1]; i++) {
        edge[i] = new int[header[0]]();
    }

    // 出力ファイルを開く
    ofstream fout("out_edge.pgm");

    // ファイルを開けなかった時のエラー処理
    if (!fout) {
        cout << "ファイルを開けませんでした\n";
    }

    // フィルタをかけてエッジの抽出
    for (int i = 1; i < header[1] - 1; i++) {
        for (int j = 1; j < header[0] - 1; j++) {
            edge[i][j] = pixel[i - 1][j] + pixel[i + 1][j] + pixel[i][j - 1] + pixel[i][j + 1] - (4 * pixel[i][j]);
        }
    }

    // ヘッダの出力
    fout << "P2" << "\n";
    fout << header[0] << " " << header[1] << "\n";
    fout << header[2] << "\n";

    // 画像の出力
    for (int i = 0; i < header[1]; i++) {
        for (int j = 0; j < header[0]; j++) {
            fout << edge[i][j] << " ";
        }
    }

    // 確保したメモリの開放
    for (int i = 0; i < header[1]; i++) {
        delete edge[i];
    }
    delete[] edge;
}