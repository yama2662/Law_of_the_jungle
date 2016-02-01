#ifndef IMPORT_H
#define IMPORT_H

#define LINE_MAX 256//１行の最大文字数を仮定

int fixedevent_max=0;//固定イベントの最大数
int randomevent_max=0;//ランダムイベントの最大数

//ランダムイベントをシャッフルする
//引数：イベントデータ構造体のポインタ
//戻り値：なし
void shuffle(event_data *event);

//イベントデータを外部ファイルから読み込みイベントデータ構造体にセットする
//引数：イベントデータ構造体のポインタ
//戻り値：なし
void init_Event(event_data *event);

//ファイルの行数をカウントする
//引数：ファイルポインタ
//戻り値：ファイルの行数
int fileline_check(FILE *fp);

#endif
