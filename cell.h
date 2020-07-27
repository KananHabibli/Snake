#ifndef snake
#define snake
#include <stdio.h>
struct cell{
	int row,col;
};

struct cell C_new(int row, int col);
void C_print(struct cell c, char *label);
void C_printNeighbors(struct cell c);


#endif 