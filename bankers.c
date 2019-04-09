
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int processes[5] = {0, 1, 2, 3, 4};

	//Available instance of a process in the system
	int avail[] = {3, 3, 2};
//Maximum process to be allocated to the system
	int maxm[5][3] = {{7, 5, 3},
					{3, 2, 2},
					{9, 0, 2},
					{2, 2, 2},
					{4, 3, 3}};

	//Resources allocated to all process
	int allot[5][3] = {{0, 1, 0},
					{2, 0, 0},
					{3, 0, 2},
					{2, 1, 1},
					{0, 0, 2}};

	// Check system is in safe state or not
	Safe(processes, avail, maxm, allot);

	return 0;
}

