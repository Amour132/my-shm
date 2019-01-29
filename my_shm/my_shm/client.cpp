#include "comm.hpp"

int main()
{

  Shm shm(4096);
  int shmid = shm.getshm();
  sleep(1);
  char *addr = (char*)shmat(shmid,NULL,0);
  sleep(2);
  int i = 0;
  while(i<26)
  {
    addr[i] = 'A'+i;
    i++;
    addr[i] = 0;
    sleep(1);
  }
  shmdt(addr);
  sleep(2);
  return 0;
}
