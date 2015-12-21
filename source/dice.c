#include "../include/GV.h"

// ダイス操作関連

// ダイス初期設定 乱数のシード設定
// 引数：なし
// 戻り値：なし
void diceInit()
{
  srand((unsigned)time(NULL));
}

// ダイスを振る関数
// 引数：なし
// 戻り値：1〜6の整数
int diceRoll()
{
  int n;

  n = rand()%DICE_MAX+DICE_MIN;

  return n;
}
