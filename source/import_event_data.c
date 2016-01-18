#include "../include/import_event.h"

//�C�x���g�f�[�^���O���t�@�C������ǂݍ��݃C�x���g�f�[�^�\���̂ɃZ�b�g����
//�����F�C�x���g�f�[�^�\���̂̃|�C���^
//�߂�l�F�Ȃ�
void init_Event(event_data *event){
  FILE *fp;
  FILE *fp2;
  int i;
  char c[256];
  int d;

    if((fp=fopen("fixed_event.txt","r"))==NULL){
      printf("fixed_event.txt can not open");
      exit(1);
    }
    if((fp2=fopen("random_event.txt","r"))==NULL){
      printf("random_event.txt can not open");
      exit(1);
      }
    //�Œ�C�x���g�̃Z�b�g
  for(i=0;i<FIXEDEVENT_MAX;i++){
    fscanf(fp,"%d",&event->fixed_event[i].powerVar);
    fscanf(fp,"%d",&event->fixed_event[i].hpVar);
    fscanf(fp,"%d",&event->fixed_event[i].defenseVar);
    fscanf(fp,"%s",&event->fixed_event[i].message);
  }
  //�����_���C�x���g�̃Z�b�g
  for(i=0;i<RANDOMEVENT_MAX;i++){
    fscanf(fp2,"%d",&event->random_list[i].powerVar);
    fscanf(fp2,"%d",&event->random_list[i].hpVar);
    fscanf(fp2,"%d",&event->random_list[i].defenseVar);
    fscanf(fp2,"%s",&event->random_list[i].message);
    }

  fclose(fp);
  fclose(fp2);
}

//�����_���C�x���g���V���b�t������
//�����F�C�x���g�f�[�^�\���̂̃|�C���^
//�߂�l�F�Ȃ�
void shuffle(event_data *event)
{
  event_t tmp;
  int i,r;
  //�����_���C�x���g�������_���C�x���g�̐������V���b�t��
  for(i=0;i<RANDOMEVENT_MAX;i++){
    r=rand()%RANDOMEVENT_MAX;//����
    tmp=event->random_list[i];
    event->random_list[i]=event->random_list[r];
    event->random_list[r]=tmp;
    }
}
