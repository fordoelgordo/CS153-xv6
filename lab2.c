#include "types.h"
#include "user.h"

int PScheduler(void);
int Priorityset(void);

int main(int argc, char *argv[])
{
	

  printf(1, "\n This program tests the correctness of your lab#2\n");
	
	if (atoi(argv[1]) == 1)
          Priorityset();
        else if (atoi(argv[1]) == 2)
          PScheduler();  
	
	// End of testing
	exit(0);
	return 0;
 }
  
int Priorityset(void) {
	printf(1, "\n Step 1: Testing to ensure that the set priority function works properly\n");
	int id, i;
	int n = 2;
	double x = 0, k;
	// Create some processes and set their priority
	for (i = 0; i < n; i++){
		id = fork();
		if (id < 0) {
 			printf(1, "%d failed to fork\n", getpid());
		}
		else if (id > 0){ //Entered parent
			printf(1, "Parent %d creating child %d\n", getpid(), id);
			wait(0);
		}
		else { //Child code
			printf(1, "Child %d created\n", getpid());
			setpriority(31 - 10*i);
			printf(1, "Child %d changed priority\n", 31 - 10*i);
			for (k = 0; k < 100000.0; k+= 0.01){
				x = x + 3.14 * 89.64; // Calculations to consume CPU time
			}
			cps();
			break;
		}
	}
		
	return 0;
}   
  
  int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 31
    // 0 is the highest priority and 31 is the lowest priority.  

  int pid;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 31\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 10\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {

		setpriority(30-10*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<1000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),30-10*i);		
		exit(0);
        }
        else {
			printf(2," \n Error \n");
			
        }
	}

	if(pid > 0) {
		for (i = 0; i <  3; i++) {
			wait(0);

		}
                     printf(1,"\n if processes with highest priority finished first then its correct \n");
}
	exit(0);		
	return 0;}
