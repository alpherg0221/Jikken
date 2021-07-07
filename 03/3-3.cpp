#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int x = 0x12345678;
    uint8_t *y;

    // xのアドレスをuint8_tのポインタに変換
    y = reinterpret_cast<uint8_t *>(&x);

    // 各アドレスとそれが指す値を出力
    for (int i = 0; i < 4; i++) printf("%p : 0x%x\n", y+i, *(y+i));

    // 結果の出力
    cout << (*y == 0x78 ? "little endian" : "big endian") << endl;
}