#ifndef DICE_SET_H
#define DICE_SET_H

#define DICE_MAX 6
#define DICE_MIN 1

// ダイス初期設定 乱数のシード設定
// 引数：なし
// 戻り値：なし
void diceInit();

// ダイスを振る関数
// 引数：なし
// 戻り値：1〜6の整数
int diceRoll();


#endif
