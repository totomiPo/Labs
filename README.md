# Labs
Part of the laboratory work for the 2nd semester on the basics of programming in C/C++

Lab 8:

Recursively describe the function C(n, m) of calculating the binomial coefficient using the following formula:                             
C(n, 0) = C(n, n) = 1; C(n, m) = C(n - 1, m) + C(n - 1, m - 1) at 0 < m < n. Write a testing program for it.

Lab 10:

For character files with text (containing abbreviations) and abbreviations, create a new file where all                          
abbreviations are replaced with the corresponding words.

Lab 11:

Write a char * find_keyword(char* line) function that returns a pointer to a C keyword                             
or NULL if there are no keywords in the string, and a testing program that reads the entire file line by line.

Lab 12:

Create a PriorityQueue class that stores integers as a sorted queue. Implement push operations (adding to an ascending array stored inside the class using binary search)   
and front (taking an element from the beginning of the queue - the smallest available). The queue size cannot exceed 16 items.          
In case of overflow, the push operation does not change the queue.
