#include "../include/import_event.h"

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
    fixedevent_max=fileline_check(fp1);//�Œ�C�x���g���J�E���g
    randomevent_max=fileline_check(fp2);//�����_���C�x���g���J�E���g
    //�Œ�C�x���g�̃Z�b�g
  for(i=0;i<fixedevent_max;i++){
    fscanf(fp1,"%d",&event->fixed_event[i].powerVar);
    fscanf(fp1,"%d",&event->fixed_event[i].hpVar);
    fscanf(fp1,"%d",&event->fixed_event[i].defenseVar);
    fscanf(fp1,"%s",&event->fixed_event[i].message);
  }
  //�����_���C�x���g�̃Z�b�g
  for(i=0;i<randomevent_max;i++){
    fscanf(fp2,"%d",&event->random_list[i].powerVar);
    fscanf(fp2,"%d",&event->random_list[i].hpVar);
    fscanf(fp2,"%d",&event->random_list[i].defenseVar);
    fscanf(fp2,"%s",&event->random_list[i].message);
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
  //�����_���C�x���g�������_���C�x���g�̐������V���b�t��
  for(i=0;i<randomevent_max;i++){
    r=rand()%randomevent_max;//����
    tmp=event->random_list[i];
    event->random_list[i]=event->random_list[r];
    event->random_list[r]=tmp;
    }
}

int fileline_check(FILE *fp){
  char dummy[LINE_MAX];
  int line=0;
  while ( fgets(dummy,LINE_MAX,fp) != NULL ) {
        line++;
    }
fseek(fp, 0L, SEEK_SET);
 return line;
}
