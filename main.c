#include "cell.h"
#include "cellList.h"
#include "arena.h"



void main(){
	// struct cellList cl = CL_new();
	// cl = CL_add(cl,C_new(0,0)); 
	// cl = CL_add(cl,C_new(1,0)); 
	// cl = CL_add(cl,C_new(1,1));
	// cl = CL_add(cl,C_new(2,1));
	// cl = CL_add(cl,C_new(2,2));
	// cl = CL_add(cl,C_new(3,2));
	// cl = CL_add(cl,C_new(3,3));
	// cl = CL_add(cl,C_new(4,3));
	// cl = CL_add(cl,C_new(4,4));
	srand(time(NULL));
	struct arena ar = A_new(10,10);
	// int a = A_isInside(C_new(9,0),ar);
	// printf("%d\n", a);
	// struct cellList cl1 = A_neighbors(C_new(9,0),ar);
	// CL_print(cl1,"");
	// struct cellList cl2 = A_randomPath(C_new(5,5),10,ar);
	// CL_print(cl2,"");
	struct cellList cl3 = A_randomPath(C_new(5,5),ar);
	CL_print(cl3,"");
	CL_animate(cl3, 10, 10, "snake");
	}


// struct cellList cl1 = CL_neighbors(C_new(3,5));
// 	struct cell c2 = CL_random(cl1);
// 	C_print(c2," ");

// CL_draw(cl, 10, 10, "snake");

// 	CL_animate(cl, 10, 10, "snake");


// struct cellList cl = CL_new();
	// cl = CL_add(cl,C_new(3,5)); 
	// cl = CL_add(cl,C_new(4,5)); 
	// cl = CL_add(cl,C_new(4,6));
	// cl = CL_add(cl,C_new(8,6));
	// cl = CL_add(cl,C_new(0,6));
	// cl = CL_add(cl,C_new(3,2));
	// cl = CL_add(cl,C_new(9,6));
	// cl = CL_add(cl,C_new(8,5));
	// cl = CL_add(cl,C_new(1,2));
	// struct cell c1 = CL_get(cl,1);
	// C_print(c1," ");
	


// C_print(c,"my first cell");
// C_printNeighbors(c);