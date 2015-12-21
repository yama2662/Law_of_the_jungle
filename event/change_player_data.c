#include "../include/GV.h"

#define N 20

void change_player_data(player_t *player_data,event_t *event){
  //playerデータのpower,hp,defenseにevent分の変動値を加算
  player_data->power += event->powerVar;
  player_data->hp += event->hpVar;
  player_data->defense += event->defenseVar;

  //以下それぞれの最大値超えを確認
  //また，0以下になっていた場合も0へ修正する
  if(player_data->power > MAX_POWER){
    player_data->power = MAX_POWER;
  }else if(player_data->power < 0){
    player_data->power = 0;
  }
  if(player_data->hp > MAX_HP){
    player_data->hp = MAX_HP;
  }else if(player_data->hp < 0){
    player_data->hp = 0;
  }
  if(player_data->defense >MAX_DEFENSE){
    player_data->defense = MAX_DEFENSE;
  }else if(player_data->defense < 0){
      player_data->defense = 0;
  }
}

int main(void){
  player_t player[4];
  event_data event;

  event.fixed_event[0].hpVar = event.fixed_event[0].powerVar = event.fixed_event[0].defenseVar = 1;
  strcpy(player[0].name,"player1");
  player[0].hp = player[0].power = player[0].defense = 5;

  change_player_data(&player[0],&event.fixed_event[0]);
  printf("%d\n%d\n%d\n",player[0].hp,player[0].power,player[0].defense);
  return 0;
}
