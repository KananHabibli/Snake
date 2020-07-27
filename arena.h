#ifndef __ARENA_h_
#define __ARENA_h_


#include <stdio.h>
#include <stdlib.h>
#include "cell.h"
#include "cellList.h"

struct arena{
	int nb_rows,nb_cols;
};


struct arena A_new(int nb_rows, int nb_cols);
int A_isInside(struct cell c, struct arena ar);
struct cellList A_neighbors(struct cell c, struct arena ar);
// struct cellList A_randomPath(struct cell start, int nb_cells, struct arena ar);
struct cellList A_randomPath(struct cell start, struct arena ar);

#endif