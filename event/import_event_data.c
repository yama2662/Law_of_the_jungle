#include<stdio.h>
#include<stdlib.h>
#include "../include/GV.h"

void shuffle(event_data *event);

int main(void){
  srand((unsigned)time(NULL));
  event_data event;
  init_Event(&event);
  shuffle(&event);
  return 0;
}

int init_Event(event_data *event){
  FILE *fp;
  FILE *fp2;
  int i;
  char c[256];
  int d;

    if((fp=fopen("fixed_event.txt","r"))==NULL){
      printf("fixed_event.txt not open");
      exit(1);
    }
    if((fp2=fopen("random_event.txt","r"))==NULL){
      printf("random_event.txt not open");
      exit(1);
      }
  for(i=0;i<FIXEDEVENT_MAX;i++){
    fscanf(fp,"%d",&event->fixed_event[i].powerVar);
    fscanf(fp,"%d",&event->fixed_event[i].hpVar);
    fscanf(fp,"%d",&event->fixed_event[i].defenseVar);
    fscanf(fp,"%s",&event->fixed_event[i].message);
    printf("%d ",event->fixed_event[i].powerVar);
    printf("%d ",event->fixed_event[i].hpVar);
    printf("%d\n",event->fixed_event[i].defenseVar);
    printf("%s\n",event->fixed_event[i].message);
  }
  printf("\nrandom\n");
  for(i=0;i<RANDOMEVENT_MAX;i++){
    fscanf(fp2,"%d",&event->random_list[i].powerVar);
    fscanf(fp2,"%d",&event->random_list[i].hpVar);
    fscanf(fp2,"%d",&event->random_list[i].defenseVar);
    fscanf(fp2,"%s",&event->random_list[i].message);
    printf("%d ",event->random_list[i].powerVar);
    printf("%d ",event->random_list[i].hpVar);
    printf("%d\n",event->random_list[i].defenseVar);
    printf("%s\n",event->random_list[i].message);
  }

  fclose(fp);
  fclose(fp2);
  
  

  return 0;
}

void shuffle(event_data *event)
{
  event_t tmp;
  int i,r;
    
  for(i=0;i<RANDOMEVENT_MAX;i++){
    r=rand()%RANDOMEVENT_MAX;
    tmp=event->random_list[i];
    event->random_list[i]=event->random_list[r];
    event->random_list[r]=tmp;
    }
  printf("\nshuffle\n");
 for(i=0;i<RANDOMEVENT_MAX;i++){
    printf("%d ",event->random_list[i].powerVar);
    printf("%d ",event->random_list[i].hpVar);
    printf("%d\n",event->random_list[i].defenseVar);
    printf("%s\n",event->random_list[i].message);
  }
}
