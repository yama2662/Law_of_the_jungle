#include <stdio.h>
#include <string.h>

struct eventList{
  int powerVar;
  int hpVar;
  int defenseVar; // このイベントによる防御力の増減値

  char message[255]; // このイベントで表示するメッセージ
};

struct pList{
  char name[20];   // 名前
  int playerNo;    // 番号

  int power;       // 戦闘力
  int hp;          // HP
  int defense;     // 防御力
  int rank;        // ゲーム終了時の順位

  struct boardList *place; // 現在どのマスに止まっているか
  struct pList *next; // 次のプレイヤー
};

void change_player_data(struct pList *a,struct eventList *event){
  a->power += event->powerVar;
  a->hp += event->hpVar;
  a->defense += event->defenseVar;
}


int main(void){
  struct pList player[4];
  struct eventList event[20];

  event[0].hpVar = event[0].powerVar = event[0].defenseVar = 1;
  strcpy(player[0].name,"player1");
  player[0].hp = 5;
  player[0].power = 5;
  player[0].defense = 5;

  change_player_data(&player[0],&event[0]);
  printf("%d\n%d\n%d\n",player[0].hp,player[0].power,player[0].defense);
  return 0;
}
