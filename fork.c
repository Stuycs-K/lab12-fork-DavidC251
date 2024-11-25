#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "fork.h"
void ChildProcess(){
	int RandomFile = open("/dev/random", O_RDONLY, 0);
	int RandomNum;
	read(RandomFile, &RandomNum, sizeof(int));
	printf("RANDOM: %d", RandomNum);
	//sleep(RandomNum);
	//printf("%d finished after %d seconds", , );
	


}

void ParentProcess(){



}
