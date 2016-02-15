#include "GV.h"

//イベントデータを外部ファイルから読み込みイベントデータ構造体にセットする
//引数：イベントデータ構造体のポインタ
//戻り値：なし

void init_Event(event_data *event){
  FILE *fp1;
  FILE *fp2;
  int i;

  if((fp1=fopen("fixed_event.txt","r"))==NULL){
    printf("fixed_event.txt can not open");
    exit(1);
  }
  if((fp2=fopen("random_event.txt","r"))==NULL){
    printf("random_event.txt can not open");
    exit(1);
  }

  //固定イベントのセット
  for(i=0;i<FIXEDEVENT_MAX;i++){
    fscanf(fp1,"%d",&event->fixed_event[i].powerVar);
    fscanf(fp1,"%d",&event->fixed_event[i].hpVar);
    fscanf(fp1,"%d",&event->fixed_event[i].defenseVar);
    fscanf(fp1,"%s",&*event->fixed_event[i].message);
  }
  //ランダムイベントのセット
  for(i=0;i<RANDOMEVENT_MAX;i++){
    fscanf(fp2,"%d",&event->random_list[i].powerVar);
    fscanf(fp2,"%d",&event->random_list[i].hpVar);
    fscanf(fp2,"%d",&event->random_list[i].defenseVar);
    fscanf(fp2,"%s",&*event->random_list[i].message);
  }

  fclose(fp1);
  fclose(fp2);
}

//ランダムイベントをシャッフルする
//引数：イベントデータ構造体のポインタ
//戻り値：なし
void shuffle(event_data *event)
{
  event_t tmp;
  int i,r;
  //ランダムイベントをランダムイベントの数だけシャッフル
  for(i=0;i<RANDOMEVENT_MAX;i++){
    r=rand()%RANDOMEVENT_MAX;//乱数
    tmp=event->random_list[i];
    event->random_list[i]=event->random_list[r];
    event->random_list[r]=tmp;
  }
}
