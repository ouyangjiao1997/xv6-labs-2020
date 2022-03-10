#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"     

void print(char* split[]){
  if(fork()==0){
     exec(split[0],split);
     exit(0);
    }else{
      wait((int*)0);
    }
}
int
main(int argc, char *argv[])
{
  char buf[512],arr[32][32];
  char *argv2[32] ,*split[32];
  int k=0,j=0,m=0,n=0;
  if(argc > 32){
    printf("too much args");
    exit(0);
  }
  for(int i=1;i<argc;i++)
   split[m++]=argv[i];
  read(0,buf,sizeof(buf));
  for(int i=0 ;buf[i]!='\0';i++){
    if(buf[i]=='\n'){
      arr[n][j]='\0';
      argv2[k++]=arr[n++];
      j=0;
    }else{
      arr[n][j++]=buf[i];
    }
  }
  for(int i=0;i<k;i++){   
    split[m]=argv2[i];
    print(split);
   }
  exit(0);
}
