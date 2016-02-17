#include "../include/GV.h"

//���ʂ�\��
void disp_result(player_t *p){
  int i;
  int cmd;
  player_t *pp=p;

  clear();
  for(i=0; i<PLAYER_NUM; i++,pp=pp->next){
    switch(pp->rank){
    case 1:
      attrset(COLOR_PAIR(PRINT_RED));
      mvprintw(7+pp->rank, 15, "1st  %s",pp->name);
      break;
    case 2:
      attrset(COLOR_PAIR(PRINT_MAGENTA));
      mvprintw(7+pp->rank, 15, "2nd  %s",pp->name);
      break;
    case 3:
      attrset(COLOR_PAIR(PRINT_GREEN));
      mvprintw(7+pp->rank, 15, "3rd  %s",pp->name);
      break;
    default:
      attrset(COLOR_PAIR(PRINT_BLUE));
      mvprintw(7+pp->rank, 15, "%dth  %s",i+1,pp->name);
      break;
    }
  }
  
  refresh();

  timeout(-1);
  cmd = getch();
}



//���ʕt��
void rank(player_t * p){
  int a,i,m=0;
  player_t * pp=p;

  //�S��hp���m�F�����ʕt��
  for (a = 0; a < PLAYER_NUM; a++) {
	  if (p->rank == INIT_RANK) {
		  if (p->hp <= 0) {
			  for (i = 0; i < PLAYER_NUM; i++) {
				  if (pp->rank != INIT_RANK)
					  m++;
				  pp = pp->next;
			  }
			  p->rank = PLAYER_NUM - m;
		  }
	  }
	  p = p->next;
  }
}



//�Q�[���̏I������
//�S������ł���I��
int check_end(player_t * p){
  int i,lose=0;

  for(i=0; i<PLAYER_NUM; i++){
    if(p->hp <=0)
      lose++;
    p = p->next;
  }

  if(lose == PLAYER_NUM-1)
    return FALSE;
  else
    return TRUE;

}

