#include "File_Read.h"
 // nlohmann::jsonライブラリのヘッダファイルをインクルード

using json = nlohmann::json;
using namespace std;

bool File_Read::Read_Save(const char* filename_, const char* stageName, const char* isChar, const char* stageCount_){
    string fileName = filename_;

    ifstream reading_file(fileName);
    if (!reading_file.is_open()) {
        cerr << "Cannot open file: " << fileName << endl;
        return true;
    }

    json m_json;
    try {
        reading_file >> m_json;
    }
    catch (nlohmann::json::parse_error& e) {
        cerr << "JSON parse error: " << e.what() << endl;
        reading_file.close();
        return true;
    }
    reading_file.close();

    string stageName_ = stageName;
    string isChar_ = isChar;
    string stageCount = stageCount_;

    try {
        bool StageClear = m_json.at(stageName_).at(isChar_).get<int>() == 1;
        // 変数の値を出力
        cout << stageCount << (StageClear ? "Yes" : "No") << endl;
        return StageClear;
    }
    catch (nlohmann::json::type_error& e) {
        cerr << "Type error: " << e.what() << endl;
        return 1;
    }
    catch (nlohmann::json::out_of_range& e) {
        cerr << "Out of range error: " << e.what() << endl;
        return 1;
    }

    return false;
}


