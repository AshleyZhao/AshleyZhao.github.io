#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int A(int y)
{ 
        int total = 0;
        for(int i=0; i<=floor(y/2);i++) total = total + i;
        return total;
}

// B is a function that computes the sum of [(y/2)+1] + [((y+1)/2)+1] + [((y+2)/2)+1] + ... [((y+k)/2)+1] + ... + y
int B(int y) 
{ 
        int total = 0;
        for(int i=(floor(y/2)+1);i<=y;i++) total = total + i;
        return total;
}

void main (int argc, char *argv[]) 
{

        int Total =0; //Let Total be the total computed sum to be returned at the end of the program
        pid_t pid; 


	//The program tests whether the user has input a parameter to the program or not. If not, the program exits.
	//Note that argc contain the number of parameters, whereas argv contains the parameters,
	//Hence, argv[0] contains the first parameter which is the name of the executable file e.g., a.out 
	// argv[1] the second, argv[2] the third, and ...

        if(argc==1 || argc>2)
        { 
                printf("The program needs one parameter to be executed (e.g., ./a.out 13)\n"); 
                exit(0);
        }

        //The program grabs the second parameter and converts that into an integer.
	int x = atoi(argv[1]);

	//The program tests whether the input paramter is greater than 0. If not the program exits.
        if (x<=0)
        { 
                printf("Unvalid parameter: The parameter should be greater than 0, exiting ... \n");
                exit(0);
        }

	//The program (process) create a new child process and a value is return from fork() into pid variable. 
        pid = fork();
    /Users/Ashley.Zhao@ibm.com/Desktop/CISC324/Labs/L1_Files/eXer_2.c
	//The program exits if the fork() primitive failes
	if (pid < 0)
	{
		fprintf(stderr, "Fork() system call failed");
		return;
	}

	//If process is the child process then pid==0, else it is the parent (the value contains the PID of the child).
        
	//Parent process
	if (pid != 0) 
        {
		//printf("%d\n",pid);
		//call function A to perform the summation from x to [x/2]
                Total = Total + A(x);
        	printf("Total of parent: %d\n",Total);
	}
	
	//Child process
        else 
        {
		//printf("%d\n",pid);
		//call function B to perform the summation from [(x/2)+1] to x.
                Total = Total + B(x);
		printf("Total of Child: %d\n",Total);
		exit(Total);
        }


	int status;
	wait(&status);
	printf("%d",WIFEXITED(status));
       //The parent process displays the total and final summation:
       if (pid != 0)
       {
		Total = Total + (WEXITSTATUS(status));
                printf("The total is: %d\n",Total) ;
       }

       return;
}

