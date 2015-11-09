#include<stdio.h>
#include<stdlib.h>

int main(void){
  FILE *fp;
  int i;
  int N=4;
  char ss[N];
    if((fp=fopen("test.txt","r"))==NULL){
      printf("ファイルをオープンできません．\n");
      exit(1);
    }
  for(i=0;i<N;i++){
    fscanf(fp,"%s",&ss[i]);
    printf("%c\n",ss[i]);
  }
   fclose(fp);
  return 0;
}

