#include "File_White.h"
// nlohmann::jsonライブラリのヘッダファイルをインクルード

using json = nlohmann::json;
using namespace std;

bool File_White::White_Save(const char* filename_, const char* stageName, const char* Name,const int isNumber){
    // JSONオブジェクトの作成
    json m_json;

    // ファイルが存在する場合は既存のデータを読み込む
    ifstream input_file(filename_);
    if (input_file.is_open()) {
        try {
            input_file >> m_json;
        }
        catch (nlohmann::json::parse_error& e) {
            cerr << "JSON parse error: " << e.what() << endl;
        }
        input_file.close();
    }

    m_json[stageName] = { {Name,isNumber} };

    // JSONデータをファイルに書き込む
    ofstream writing_file(filename_, ios::out);
    if (!writing_file.is_open()) {
        cerr << "Cannot open file: " << filename_ << endl;
        return true;
    }

    writing_file << m_json.dump(4) << endl; // 4スペースのインデントで整形
    writing_file.close();


    return false;
}
