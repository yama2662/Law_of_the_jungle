#include "../include/GV.h"

//結果の表示を行う
void disp_result(player_t *p){
  int i;
  player_t *pp=p;

  clear();
  for(i=0; i<PLAYER_NUM; i++,pp=pp->next){
    switch(pp->rank){
    case 1:
      attrset(COLOR_PAIR(PRINT_RED));
      mvprintw(7+pp->rank, 15, "1st  Player No.%d",pp->playerNo);
      break;
    case 2:
      attrset(COLOR_PAIR(PRINT_MAGENTA));
      mvprintw(7+pp->rank, 15, "2nd  Player No.%d",pp->playerNo);
      break;
    case 3:
      attrset(COLOR_PAIR(PRINT_GREEN));
      mvprintw(7+pp->rank, 15, "3rd  Player No.%d",pp->playerNo);
      break;
    default:
      attrset(COLOR_PAIR(PRINT_BLUE));
      mvprintw(7+pp->rank, 15, "%dth  Player No.%d",i+1,pp->playerNo);
      break;
    }
  }
  
  refresh();
}



//順位の決定を行う
//引数プレイヤから数える
void rank(player_t * p){
  int i,m=0;
  player_t * pp=p;

  for(i=0; i<PLAYER_NUM; i++){
    if(pp->rank != INIT_RANK)
      m++;
    pp=pp->next;
  }

  p->rank = PLAYER_NUM - m;

}



//ゲームの終了判定を行う
//全員のHPがゼロなら終了となる
int check_end(player_t * p){
  int i,lose=0;

  for(i=0; i<PLAYER_NUM; i++){
    if(p->hp <=0)
      lose++;
    p = p->next;
  }

  if(lose == PLAYER_NUM)
    return FALSE;
  else
    return TRUE;

}

