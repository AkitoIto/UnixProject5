#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdlib.h>
#include <gsl/gsl_rng.h>

int main(int argc, char *argv[])
{
  int option;
  double percentage;
 
  while((option= getopt(argc, argv, "p:v::")) != -1)
	{	
     switch(option)
     {
	   	case 'p':
              percentage = atof(argv[2]);
              break;
      }
	}	
  

  //random number generator
   const gsl_rng_type * T;
   gsl_rng * r;
   gsl_rng_env_setup();
   T = gsl_rng_mt19937;
   r = gsl_rng_alloc(T);
   gsl_rng_set(r, getpid());
   double random = gsl_rng_uniform(r);
   random = random * 100;
   //printf("Random number: %f\n", random);
   gsl_rng_free(r);
  
  if(random < percentage)
  {
    //printf("SUCCESS!\n");
    return 1;
  }
  else
  {
    //printf("FAILURE!\n");
    return 0;
  }
}


