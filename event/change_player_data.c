#include <stdio.h>
#include <string.h>

#define N 20

typedef struct eventList{
  int powerVar;
  int hpVar;
  int defenseVar; // このイベントによる防御力の増減値

  char message[255]; // このイベントで表示するメッセージ
}event_t;

typedef struct pList{
  char name[20];   // 名前
  int playerNo;    // 番号

  int power;       // 戦闘力
  int hp;          // HP
  int defense;     // 防御力
  int rank;        // ゲーム終了時の順位

  struct boardList *place; // 現在どのマスに止まっているか
  struct pList *next; // 次のプレイヤー
}player_t;

typedef struct event{
  int random_num;
  int random_list[N];
  event_t a[N];
}event_data;

void change_player_data(player_t *a,event_t *event){
  a->power += event->powerVar;
  a->hp += event->hpVar;
  a->defense += event->defenseVar;
}

int main(void){
  player_t player[4];
  event_data event;

  event.a[0].hpVar = event.a[0].powerVar = event.a[0].defenseVar = 1;
  strcpy(player[0].name,"player1");
  player[0].hp = player[0].power = player[0].defense = 5;

  change_player_data(&player[0],&event.a[0]);
  printf("%d\n%d\n%d\n",player[0].hp,player[0].power,player[0].defense);
  return 0;
}
