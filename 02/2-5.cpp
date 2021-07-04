#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>

using namespace std;

int main(int argc, char *argv[]) {
    DIR *dp;
    dirent *entry;
    vector<string> file_list;

    // 引数の数が正しいかチェック
    if (argc != 2) {
        cout << "引数の値が違います\n";
        return 1;
    }

    // ディレクトリの読み込みとエラーチェック
    dp = opendir(argv[1]);
    if (dp == nullptr) {
        cout << "指定されたファイルは存在しません" << endl;
        return 1;
    }

    // ディレクトリ内のファイル一覧取得
    do {
        entry = readdir(dp);
        if (entry != nullptr && string(entry->d_name).find('.') == string::npos)
            file_list.insert(file_list.end(), string(argv[1]) + entry->d_name);
    } while (entry != nullptr);

    return 0;
}