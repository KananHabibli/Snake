
#include "cell.h"

struct cell C_new(int row, int col){
	struct cell c;
	c.row = row;
	c.col = col;
	return c;
}

void C_print(struct cell c, char *label){
	printf("%s : (%d,%d)\n", label , c.row , c.col);
}

void C_printNeighbors(struct cell c){
	printf("Upper : (%d,%d)\n", c.row-1 , c.col);
	printf("Lower : (%d,%d)\n", c.row+1 , c.col);
	printf("Left  : (%d,%d)\n", c.row , c.col-1);
	printf("Right : (%d,%d)\n", c.row , c.col+1);
}