#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
const int R=3;
const int P=5;
void calculateNeed(int need[P][R], int maxm[P][R],
                   int allot[P][R])
{
    // Calculating Need of each P
    int i,j;
    for (i = 0 ; i < P ; i++)
        for (j = 0 ; j < R ; j++)

            // Need of instance = maxm instance -
            //                    allocated instance
            need[i][j] = maxm[i][j] - allot[i][j];
}
// Function to find the system is in safe state or not
bool Safe(int processes[], int avail[], int maxm[P][R],
            int allot[P][R])
{
    int i;
    int need[P][R];

    // Function to calculate need matrix
    calculateNeed(need, maxm, allot);

    // Mark all processes as infinish
    /* this process must be initially initialized to 
    0 but c does not support variable size initialization
    so if we are doing it in c we can't initialize array initial to 1*/
    bool finish[P];

    // To store safe sequence
    int safeSeq[P];

    // Make a copy of available resources
    int work[R];
    for (i = 0; i < R ; i++)
        work[i] = avail[i];

    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < P)
    {
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
		int p;
        bool found = false;
        for (p = 0; p < P; p++)
        {
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0)
            {
                // Check if for all resources of
                // current P need is less
                // than work
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                // If all needs of p were satisfied.
                if (j == R)
                {
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
					int k;
                    for (k = 0 ; k < R ; k++)
                        work[k] += allot[p][k];

                    // Add this process to safe sequence.
                    safeSeq[count++] = p;

                    // Mark this p as finished
                    finish[p] = 1;

                    found = true;
                }
            }
        }

        // If we could not find a next process in safe
        // sequence.
        if (found == false)
        {
            printf("\nSystem is not in safe state");
            return false;
        }
    }

    // If system is in safe state then
    // safe sequence will be as below
    printf("System is in safe state.\n Safe sequence is: ");
    for (i = 0; i < P ; i++)
        //cout << safeSeq[i] << " ";
        printf("%d",safeSeq[i]);

    return true;
}
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
	bool a=Safe(processes, avail, maxm, allot);

	return 0;
}
