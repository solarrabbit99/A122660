# A122660
Simple and fast cpp program that generates integer sequence [A122660](https://oeis.org/A122660).

## Plantri
Plantri and a program developed to enumerate triangulations of planar graphs. Its source code can be downloaded and compiled [here](https://users.cecs.anu.edu.au/~bdm/plantri/). For our purpose, I included only the `plantri.c` file. You may compile the program similar to the following:
```
> gcc plantri.c -o plantri
```
We will be using this program to exhaust all maximal planar graphs to test for petrie-completeness.

## Main Program File
The main program file can be compiled similar to the following:
```
> g++ A122660.cpp -o A122660
```
To test for the number of petrie-complete graphs with n vertices, use the following command:
```
> ./plantri n | ./A122660
```
## Example Usage
```
> /plantri 17 | ./A122660
129664753 triangulations written to stdout; cpu=73.91 sec
41036436 petrie-complete graphs found in 218.953s
```
