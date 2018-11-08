#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

#define PATHNAME "."
#define PROJ_ID 0x6666 

int createshm(int size);
int getshm(int size);
int destory(int shmid);


