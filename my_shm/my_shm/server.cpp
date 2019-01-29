#include "comm.hpp"

int main()
{
  Shm shm(4096);
  int shmid = shm.createshm();
  char *addr = (char*)shmat(shmid,NULL,0);
  sleep(2);
  int i = 0;
  while(i++<26)
  {
    std::cout << "client#" << addr << std::endl;
    sleep(1);
  }
  shmdt(addr);
  sleep(2);
  return 0;
}
