#include "arena.h"



struct arena A_new(int nb_rows, int nb_cols){
	struct arena a;
	a.nb_cols = nb_cols;
	a.nb_rows = nb_rows;
	return a;
}

int A_isInside(struct cell c, struct arena ar){
	if(c.row < ar.nb_rows && c.col < ar.nb_cols && c.row >= 0 && c.col >= 0){
		return 1;
	}
	return 0;
}


struct cellList A_neighbors(struct cell c, struct arena ar){
	struct cellList cl = CL_new();
	struct cellList cl1 = CL_neighbors(c);
	int check;
	for (int i = 0; i < cl1.size; ++i)
	{
		check =  A_isInside(cl1.arr[i],ar);
		if(check == 1){
			cl = CL_add(cl,cl1.arr[i]);
		}
	}
	return cl;
}

// struct cellList A_randomPath(struct cell start, int nb_cells, struct arena ar){
// 	struct cellList list = CL_new();
// 	list=CL_add(list,start);
// 	int check;
// 	if(A_isInside(start,ar) == 0){
// 		exit(1);
// 	}
// 	struct cell next;
// 	struct cell prev;
// 	for(int i=1;i< nb_cells ; i++){
// 		prev = list.arr[i-1];
// 		next = CL_random(A_neighbors(prev,ar));
// 		list=CL_add(list,next);

// 	}
// 	return list;
// }


// struct cellList A_randomPath(struct cell start, struct arena ar){
// 	if(A_isInside(start,ar) == 0) exit(1);
// 	struct cellList list = CL_new();
// 	struct cellList nb = CL_new();
// 	list=CL_add(list,start);
// 	int size = ar.nb_cols * ar.nb_rows;
// 	int count = 0;
// 	int i = 1;
// 	int test[size];
// 	int position = (start.row + 1) * (start.col + 1);
// 	test[position] = 1;
// 	struct cell next;
// 	struct cell prev;
// 	while(count <= 3){
// 		count = 0;
// 		prev = list.arr[i-1];
// 		nb = A_neighbors(prev,ar);
// 		next = CL_random(nb);
// 		position = (next.row + 1) * (next.col + 1);
// 		while(count <=3 || test[position] == 1){
// 			next = nb.arr[count];
// 			position = (next.row + 1) * (next.col + 1);
// 			count++;
// 		}
// 		list=CL_add(list,next);
// 		test[position] == 1;
// 		i++;

// 	}
// 	return list;
// }


struct cellList CL_randomPath(struct cell start, int nb_cells, struct arena ar){
	struct cellList cl=CL_new();
	// struct cell random_following;
	struct cell c;
	cl=CL_add(cl,start);
	int area[ar.nb_rows][ar.nb_cols];
	// cl.arr[0]=start;
	for(int i=0;i<=ar.nb_rows;i++){
		for(int j=0;j<ar.nb_cols;j++){
			area[i][j]=0;
		}
	}
	area[start.row][start.col]=1;
	int i=1;
	int k=0;
	while(i<(nb_cells)){
		struct cell random_following = CL_random(CL_neighbors(cl.arr[i-1],ar));
		// printf("%d-----------sdasd---\n",ar.arr[random_following.row][random_following.col]);
		C_print(random_following,"sad");
		if(area[random_following.row][random_following.col]==0 && random_following.row>0 && random_following.col>0){
			area[random_following.row][random_following.col]=1;
			// printf("%d\n",area[random_following.row][random_following.col]);
			//C_print(random_following,"sad");
			cl=CL_add(cl,random_following);
			i++;
		}else{
			// int c=0;
			k++;
			// printf("%d----K---\n",k);
			if(k==100) break;
		}
		
	}
	return cl;
}