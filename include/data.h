#ifndef DATA_SET_H
#define DATA_SET_H

#define PLAYER_NUM 4

// ボードで発生するイベントの構造
typedef struct eventList{
  int powerVar;  // このイベントによる攻撃力の増減値
  int hpVar;     // このイベントによるHPの増減値
  int defenseVar; // このイベントによる防御力の増減値

  char message[255]; // このイベントで表示するメッセージ
} event_t;

// 共通ボードの構造
typedef struct boardList{
  int boardNo; // 番号
  int randEvend; // ランダムイベントかどうか

  struct eventList *event; // このマスによるイベント
  struct pList* player[PLAYER_NUM]; // このマスに止まっているプレイヤーのアドレス

  struct boardList *next;  // 次のマス(時計回り) 
  struct boardList *prev;  // 前のマス(反時計回り)
} board_t;

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
} player_t;


// プレイヤー情報初期化
void init_player(player_t *p);

// ボード情報初期化
void init_board(struct boardList *p);

// イベント情報初期化
void init_event(event_t *e);

// ボードの各マスにイベントを設定
void set_event(board_t *b, event_t *e);

// ゲームの初期化
void init_game(player_t *p, board_t *b);

#endif
