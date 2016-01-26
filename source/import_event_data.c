#include "../include/import_event.h"

//ã‚¤ãƒ™ãƒ³ãƒˆãƒ‡ãƒ¼ã‚¿ã‚’å¤–éƒ¨ãƒ•ã‚¡ã‚¤ãƒ«ã‹ã‚‰èª­ã¿è¾¼ã¿ã‚¤ãƒ™ãƒ³ãƒˆãƒ‡ãƒ¼ã‚¿æ§‹é€ ä½“ã«ã‚»ãƒƒãƒˆã™ã‚‹
//å¼•æ•°ï¼šã‚¤ãƒ™ãƒ³ãƒˆãƒ‡ãƒ¼ã‚¿æ§‹é€ ä½“ã®ãƒã‚¤ãƒ³ã‚¿
//æˆ»ã‚Šå€¤ï¼šãªã—
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
    fixedevent_max=fileline_check(fp1);//ŒÅ’èƒCƒxƒ“ƒg”ƒJƒEƒ“ƒg
    randomevent_max=fileline_check(fp2);//ƒ‰ƒ“ƒ_ƒ€ƒCƒxƒ“ƒg”ƒJƒEƒ“ƒg
    //ŒÅ’èƒCƒxƒ“ƒg‚ÌƒZƒbƒg
  for(i=0;i<fixedevent_max;i++){
    fscanf(fp1,"%d",&event->fixed_event[i].powerVar);
    fscanf(fp1,"%d",&event->fixed_event[i].hpVar);
    fscanf(fp1,"%d",&event->fixed_event[i].defenseVar);
    fscanf(fp1,"%s",&event->fixed_event[i].message);
  }
  //ƒ‰ƒ“ƒ_ƒ€ƒCƒxƒ“ƒg‚ÌƒZƒbƒg
  for(i=0;i<randomevent_max;i++){
    fscanf(fp2,"%d",&event->random_list[i].powerVar);
    fscanf(fp2,"%d",&event->random_list[i].hpVar);
    fscanf(fp2,"%d",&event->random_list[i].defenseVar);
    fscanf(fp2,"%s",&event->random_list[i].message);
    }

  fclose(fp1);
  fclose(fp2);
}

//ãƒ©ãƒ³ãƒ€ãƒ ã‚¤ãƒ™ãƒ³ãƒˆã‚’ã‚·ãƒ£ãƒƒãƒ•ãƒ«ã™ã‚‹
//å¼•æ•°ï¼šã‚¤ãƒ™ãƒ³ãƒˆãƒ‡ãƒ¼ã‚¿æ§‹é€ ä½“ã®ãƒã‚¤ãƒ³ã‚¿
//æˆ»ã‚Šå€¤ï¼šãªã—
void shuffle(event_data *event)
{
  event_t tmp;
  int i,r;
  //ƒ‰ƒ“ƒ_ƒ€ƒCƒxƒ“ƒg‚ğƒ‰ƒ“ƒ_ƒ€ƒCƒxƒ“ƒg‚Ì”‚¾‚¯ƒVƒƒƒbƒtƒ‹
  for(i=0;i<randomevent_max;i++){
    r=rand()%randomevent_max;//—”
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
