#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

	int option;
	int isVerbose = 0;
	double percentage;
	int num_trials;
	//getting arguments from command line
	while((option= getopt(argc, argv, "p:v::")) != -1)
	{	
		switch(option)
		{
	   	case 'p':
	   		//printf("Percentage: %f\n", atof(argv[2]));
			break;
	   	case 'v':
	   		//printf("verbose option\n");
			isVerbose = 1;
			break;
		  case '?':
	   		if(optopt == 'p')
				 fprintf(stderr, "Percentage required\n");
         return 0;
         break;
	   	default:
	   		printf("Invalid input\n");
		}	
 }

	//verbose option
	if(isVerbose == 1)
	{
		num_trials = atoi(argv[4]);
		//printf("Number of trials: %d\n", num_trials);
	}	
	else
	{
		num_trials = atoi(argv[3]);
		//printf("Number of trials: %d\n", num_trials);
	}
 
	int i;
	pid_t pid;
  int status;
  //counts number of successes
  int sucCounter = 0;
  
  
 //verbose option
 if(isVerbose == 1)
 {
	//creating child procss
	 for(i = 0; i < num_trials; i++)
	 {
		pid = fork();
	
		if(pid > 0)
		{
			//printf("I created a child process\n");
      //pid represents child PID
			waitpid(pid, &status, 0);
      if(status == 0)
      {
        printf("PID %d returned failure.\n", pid);
      }
      else
      {
        sucCounter++;
        printf("PID %d returned success.\n", pid);
      }
		}
		else if(pid == 0)
		{
			//printf("I am a new born process\n");
			//printf("Child process: %d\n", getpid());
			//printf("My parent process: %d\n", getppid());
      nanosleep(1);
			execv("./demo", argv);
      exit(1);
		}
		else 
		{
			//error
			printf("Error");
		}	
	 }
 }
 
 
   //non verbose option
   else
   {

   }
   
   //final result
   printf("\nCreated %d process.\n", num_trials);
   printf("number of success: %d\n", sucCounter);
   double success = ((float)sucCounter / num_trials) * 100;
   printf("Success - %.2f %\n", success);
   printf("Failure - %.2f %\n", 100 - success);
 
     
	  return 0;
}
