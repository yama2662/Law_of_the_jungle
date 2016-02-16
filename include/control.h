#ifndef CONTROL_H
#define CONTROL_H


// 手番プレイヤーをセットする
player_t* set_player(player_t *now_p);

// ダイスの乱数シード値設定
void init_dice();

// ダイスロール処理
int roll_dice();

// どちら回りにコマを進めるかルートを選択する
// TRUE:時計回り FALSE:反時計回り
char choice_way();

// 手番プレイヤーをダイスの目だけ進める
// この関数の内部で戦闘処理、マスのイベント処理を行う
void move_player(char way, int dice_num, player_t *now_p, player_t *p, board_t *b ,event_data *e);

// 出番プレイヤーが止まったマスのイベント処理を行う
void change_parameter(player_t *now_p);

// ターン終了時の処理
void end_turn();

#endif