#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void printprimes(int a[35],int count){
  int b[35];
  int p[2],j=0;
  pipe(p);
  printf("prime %d\n",a[0]);
  if(count==1) exit(0);
  if(fork()>0){
    for(int i=1;i<count;i++)
      if(a[i]%a[0]!=0)
    	b[j++]=a[i];
    int c[1]={j};
    write(p[1],c,4);
    write(p[1],b,4*j);
    close(p[1]);
    wait((int*)0);
    exit(0);
  }else{
   // sleep(1);
    int c[1];
    read(p[0],c,4);
    read(p[0],b,4*c[0]); 
    close(p[0]);
//    for(int i=0;i<30;i++)
//	    printf("%d  :" ,b[i]);
    printprimes(b,c[0]);
  }

}
int
main(int argc, char *argv[])
{ 
  int a[35];
  for(int i=0;i<34;i++){
    a[i]=i+2;
  }
  printprimes(a,34);
  exit(0);
}
