# WHAT IS IT?
A simple script which tests your push_swap against all permutations of 3, 4 and 5 numbers.
It ONLY checks the number of instructions needed and does not check if the numbers are sorted correctly.
It creates success and error files for the three different number sets.

# WHERE TO INSTALL? 
Put the script in the same directory where your push_swap executable is.

# HOW TO RUN?
bash run_tests.sh

# MORE?
Use -d flag to delete generated log files when you no longer need them:
bash run_tests.sh -d

# Work to be done:
DRY: it is very stupid to have the same block of code 3 times, I KNOW, but the idea here was to do something quickly with no prior knowledge about bash.
- figure out how to create permutations (or re-write in python)
- make another loop so as not to repeat three times
- format output to be prettier
