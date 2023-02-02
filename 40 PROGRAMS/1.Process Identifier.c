#include<stdio.h>
#include<unistd.h>
int main()
{
	int processid,parent_processid;
	processid=getpid();
	parent_processid=getppid();
	printf("\nPROCESS ID : %d\n\n",processid);
	printf("PARENT PROCESS ID : %d",parent_processid);
}
