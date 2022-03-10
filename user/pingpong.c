#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{ 
  char buf[1];
  int pid,p[2];
  pipe(p);
  if((pid=fork())>0){
    write(p[1],buf,1);
    close(p[1]);
    wait((int*)0);
    read(p[0],buf,1);
    close(p[0]);
    printf("%d: received pong\n",getpid());
  }else{
    sleep(20);
    read(p[0],buf,1);
    close(p[0]);
    printf("%d: received ping\n",getpid());
    write(p[1],buf,1);
    close(p[1]);
    exit(0);
  }
  exit(0);
}
