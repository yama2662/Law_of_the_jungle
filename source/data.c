#include "../include/GV.h"

// データ構造関連ファイル

// プレイヤー情報初期化
void initPlayer(player_t *p)
{
  int i, j;

  for(i=0; i<PLAYER_NUM; i++){
    strcpy((p+i)->name, "Player");
    (p+i)->name[6] = i + '1';
    (p+i)->name[7] = '\0';
    (p+i)->playerNo = i;
    (p+i)->power =   INIT_POWER;
    (p+i)->hp =      INIT_HP;
    (p+i)->defense = INIT_DEFENSE;
    (p+i)->rank =    INIT_RANK;
    //(p+i)->place = とりあえず後で

    //プレイヤの順番はリング構造 最後プレイヤの次は最初プレイヤ
    if(i < PLAYER_NUM-1)
      (p+i)->next = (p+i+1);
    else
      (p+i)->next = p;
  }
}

// ボード情報初期化
void initBoard(board_t *b)
{
  int i,j;

  for(i=0; i<BOARD_MAX; i++){
    (b+i)->boardNo = i;
    (b+i)->randEvend = FALSE;
    (b+i)->event = FALSE;
    for(j=0; j<PLAYER_NUM; j++)
      (b+i)->player[j] = NULL;

    //マップは双方向リング構造 最後マスの次は最初マス
    if(i < BOARD_MAX-1)
      (b+i)->next = (b+i+1);
    else
      (b+i)->next = b;
    //逆向きも然り
    if(i == 0)
      (b+i)->prev = (b+BOARD_MAX-1);
    else
      (b+i)->prev = (b+i-1);
    
  }
}

// イベント情報初期化
void initEvent(event_t *e)
{
  int i;

  // 暫定的にHPが+1されるイベントで埋め尽くしておく
  for(i=0; i<EVENT_MAX; i++){
    (e+i)->powerVar = 0;
    (e+i)->hpVar = 1;
    (e+i)->defenseVar = 0;

    strcpy((e+i)->message, "TEST EVENT");
  }
}

// ボードの各マスにイベントを設定
void setEvent(board_t *b, event_t *e)
{
  int i;

  // 暫定的にすべてイベント0を設定
  for(i=0; i<BOARD_MAX; i++){
    (b+i)->event = (e+0);
  }
}