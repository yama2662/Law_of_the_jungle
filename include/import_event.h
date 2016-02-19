#ifndef IMPORT_H
#define IMPORT_H

//ランダムイベントをシャッフルする
//引数：イベントデータ構造体のポインタ
//戻り値：なし
void shuffle(event_data *event);

//イベントデータを外部ファイルから読み込みイベントデータ構造体にセットする
//引数：イベントデータ構造体のポインタ
//戻り値：なし
void init_event(event_data *event);

#endif
