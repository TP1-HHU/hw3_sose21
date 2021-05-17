# HW3

Due until Tue, 25.05.2021, 12:30

The file `newton2.cxx` contains the sample solution to lab 3. To arrive at the 
final Newton fractal plot the output via `p "out" w image` in gnuplot. 
In this code the calculation and the output are mixed. As soon as the pixel value
(i.e. the number of iterations for that particular starting position) is 
determined, the program writes out data into the file before continuing with the calculations for the next point.

The goal of this homework is to disentangle calculation from file output. 
* Create a sufficiently large dynamically allocated integer array in which
you store all the results.
* Only after all calculations are done, write the data to the output file.

Since you can only allocate one-dimensional dynamic arrays, you will need to map the two dimensional indices (i,j) to a one-dimensional index k. Follow the instructions given on the last slide of Chapter 2. 
