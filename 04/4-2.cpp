#include <iostream>

using namespace std;

// 基本クラス
class Classroom {
protected:
    string name;
    int exam_capacity;
    int seat_capacity;
    bool has_projector;
public:
    Classroom();

    virtual void show_info();

    void set(string classroom_name, int exam, int seat, bool projector);
};

// 派生クラス
class PcClassroom : public Classroom {
private:
    int pc_num;
    int projector_num;
    bool has_microphone;
    bool has_wireless;
public:
    PcClassroom();

    void show_info() override;

    void setPc(int pc, int projector, bool microphone, bool wireless);
};

// 基本クラスのコンストラクタ
Classroom::Classroom() {
    exam_capacity = 0;
    seat_capacity = 0;
    has_projector = false;
}

// 基本クラスのクラスメンバ関数定義
void Classroom::show_info() {
    // オブジェクト情報の表示
    cout << name << endl;
    cout << "試験定員は" << exam_capacity << "人です" << endl;
    cout << "座席定員は" << seat_capacity << "人です" << endl;
    cout << "プロジェクターは" << (has_projector ? "あります" : "ありません") << "\n\n";
}

// 基本クラスのクラスメンバ関数定義
void Classroom::set(string classroom_name, int exam, int seat, bool projector) {
    name = move(classroom_name);

    // 試験定員の値チェック
    if (exam >= 0) exam_capacity = exam;
    else cout << "試験定員に誤りがあります" << endl;

    // 座席定員の値チェック
    if (exam >= 0) seat_capacity = seat;
    else cout << "座席定員に誤りがあります" << endl;

    has_projector = projector;
}

// 派生クラスのコンストラクタ
PcClassroom::PcClassroom() {
    pc_num = 0;
    projector_num = 0;
    has_microphone = false;
    has_wireless = false;
}

// 派生クラスのクラスメンバ関数定義
void PcClassroom::show_info() {
    // 派生クラスのメンバのセット
    setPc(50, has_projector ? 2 : 0, true, true);

    // オブジェクト情報の表示
    cout << name << endl;
    cout << "試験定員は" << exam_capacity << "人です" << endl;
    cout << "座席定員は" << seat_capacity << "人です" << endl;
    cout << "PCの台数は" << pc_num << "台です" << endl;
    if (has_projector)
        cout << "プロジェクターの台数は" << projector_num << "台です" << endl;
    else
        cout << "プロジェクターはありません" << endl;
    cout << "マイクは" << (has_microphone ? "あります" : "ありません") << endl;
    cout << "無線LANは" << (has_wireless ? "あります" : "ありません") << "\n\n";
}

// 派生クラスのクラスメンバ関数定義
void PcClassroom::setPc(int pc, int projector, bool microphone, bool wireless) {
    // PCの台数の値チェック
    if (pc >= 0) pc_num = pc;
    else cout << "PCの台数に誤りがあります" << endl;

    // プロジェクターの台数の値チェック
    if (projector >= 0) projector_num = projector;
    else cout << "プロジェクターの台数に誤りがあります" << endl;

    has_microphone = microphone;
    has_wireless = wireless;
}

int main() {
    Classroom classroom1, classroom2;
    PcClassroom pcClassroom1, pcClassroom2;
    Classroom *classrooms[4];

    classrooms[0] = &classroom1;
    classrooms[0]->set("classroom1", 50, 100, true);

    classrooms[1] = &classroom2;
    classrooms[1]->set("classroom2", 25, 50, false);

    classrooms[2] = &pcClassroom1;
    classrooms[2]->set("pcClassroom1", 50, 100, true);

    classrooms[3] = &pcClassroom2;
    classrooms[3]->set("pcClassroom2", 25, 50, false);

    for (auto &classroom : classrooms) classroom->show_info();

    return 0;
}