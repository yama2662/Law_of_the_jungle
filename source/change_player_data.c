#include "GV.h"

//イベントをプレイヤーに反映する関数(反映させたいプレイヤー,反映させるイベント)
void change_player_data(player_t *player_data,event_t *event){
  //playerデータのpower,hp,defenseにevent分の変動値を加算
  player_data->power += event->powerVar;

  player_data->hp += event->hpVar;

  player_data->defense += event->defenseVar;

  //以下それぞれの最大値超えを確認
  //また，0以下になっていた場合も0へ修正する
  //HPは1

  //POW確認
  if(player_data->power > MAX_POWER){
    player_data->power = MAX_POWER;
  }else if(player_data->power < 0){ //最小値は0
    player_data->power = 0;
  }
  //HP確認
  if(player_data->hp > MAX_HP){
    player_data->hp = MAX_HP;
  }else if(player_data->hp < 1){ //最小値は1
    player_data->hp = 1;
  }

  //DEF確認
  if(player_data->defense >MAX_DEFENSE){
    player_data->defense = MAX_DEFENSE;
  }else if(player_data->defense < 0){
    player_data->defense = 0;
  }

  //メッセージを表示
  mvprintw(MESSAGE_UP, MESSAGE_LEFT, "%s",event->message);
  refresh();
  usleep(SLEEP_TIME*3);

}
