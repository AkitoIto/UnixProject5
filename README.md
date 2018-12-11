# UnixProject5
Dealer.c will take three arguments from command line. 
-p follwed by percentage.
-v verbose option(optional).
And after these, number of trials.

Then, Dealer.c create number of trials child process.
Child process will execute hand (hand.c has to be compiled before)
which generates random number and return
whether is is success or failure based on the percentage given.

With verbose option it will display the child process ID each time
and the result(success/failure).

At the end, Dealer.c will display how many processes it created,
and the percentage of success/failure.
