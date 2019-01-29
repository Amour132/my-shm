#pragma once

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define PATHNAME "."
#define PROJ_ID 0x666 



class Shm
{
  public:
    Shm(int size):_size(size),_shmid(0)
    {}

    void destoryshm()
    {
      if(shmctl(_shmid,IPC_RMID,NULL) < 0)
      {
        std::cerr << "shmctl error" << std::endl;
        exit(2);
      }
    }

    ~Shm()
    {
      destoryshm();
    }

    int createshm()
    {
      return commshm(IPC_CREAT|IPC_EXCL|0x666);
    }

    int getshm()
    {
      return commshm(IPC_CREAT);
    }

  private:
    int commshm(int flag)
    {
      key_t key = ftok(PATHNAME,PROJ_ID);
      if(key < 0)
      {
        std::cerr << "ftok error" << std::endl;
        exit(2);
      }
      if((_shmid = shmget(key,_size,flag)) < 0)
      {
        std::cerr << "shmget error " << std::endl;
        exit(2);
      }
      return _shmid;
    }
  private:
    int _size;
    int _shmid;
};

