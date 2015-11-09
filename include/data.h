#ifndef DATA_SET_H
#define DATA_SET_H

#define MAP_MAX  24

#define DICE_MAX 6
#define DICE_MIN 1

#define PLAYER_NUM   4
#define INIT_POWER   3
#define INIT_HP      10
#define INIT_DEFENSE 0
#define INIT_RANK    0

#define TRUE 1
#define FALSE 0

// ボードで発生するイベントの構造
typedef struct eventList{
  int powerVar;  // このイベントによる攻撃力の増減値
  int hpVar;     // このイベントによるHPの増減値
  int defenseVar // このイベントによる防御力の増減値

  char message[255]; // このイベントで表示するメッセージ
}

// 共通ボードの構造
typedef struct boardList{
  int boardNo; // 番号
  int randEvend; // ランダムイベントかどうか

  struct eventList *event; // このマスによるイベント
  struct pList* player[PLAYER_NUM]; // このマスに止まっているプレイヤーのアドレス

  struct boardList *next;  // 次のマス(右回り)
  struct boardList *prev;  // 前のマス(左回り)
}

// プレイヤーコマの構造
typedef struct pList{
  char name[20];   // 名前
  int playerNo;    // 番号

  int power;       // 戦闘力
  int hp;          // HP
  int defense;     // 防御力
  int rank;        // ゲーム終了時の順位

  struct boardList *place; // 現在どのマスに止まっているか
  struct pList *next; // 次のプレイヤー
}









#endif
