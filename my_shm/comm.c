#include "comm.h"

static int commshm(int size,int flag)
{
  key_t _key = ftok(PATHNAME,PROJ_ID);
  if(_key < 0)
  {
    printf("ftok error\n");
    exit(1);
  }
  int shmid = 0;
  if((shmid = shmget(_key,size,flag)) <0)
  {
    printf("shm error\n");
    exit(1);
  }
  return shmid;
}

int createshm(int size)
{
  return commshm(size,IPC_CREAT|IPC_EXCL|0x666);
}

int destory(int shmid)
{
  if(shmctl(shmid,IPC_RMID,NULL)<0)
  {
    printf("shmclt error\n");
    exit(-1);
  }
  return 0;
}

int getshm(int size){
  return commshm(size,IPC_CREAT);
}
