#include "LoadMapChip.h"



int LoadMapChip::MapChipLood(int** map, const char* c){
    int err;
    FILE* fp;
    err = fopen_s(&fp, c, "r");

    int a = 0;
    int w = 0;
    int h = 0;

    int furag = 0;  // boolに対応する変数 (0: false, 1: true)

    if (err != 0 || fp == NULL) {
        printf("ファイルが開けませんでした。\n");
        return 1;
    }

    while ((a = fgetc(fp)) != EOF) {
        if (a == ',') {
            w++;
            furag = 0;
        } else if (a == '\n') {
            h++;
            w = 0;
            furag = 0;
        } else if (a >= '0' && a <= '9') {  // 数字以外を無視する
            if (!furag) {
                map[h][w] = a - '0';  // 1桁目の数字
                furag = 1;
            } else {
                a -= '0';
                map[h][w] = a + map[h][w] * 10;  // 2桁目以降の数字
            }
        }
    }

    fclose(fp);
    return 0;
}
