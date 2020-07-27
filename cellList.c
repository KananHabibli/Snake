#include "cellList.h"
#include "cell.h"


struct cellList CL_new(){
	struct cellList cl;
	cl.size = 0 ;
	return cl;
}

struct cellList CL_add(struct cellList cl, struct cell c){
	cl.arr[cl.size++] = c;
	return cl; 
}

void CL_print(struct cellList cl, char *label){
	printf("%s\n", label);
	for (int i = 0; i < cl.size; ++i)
	{
		printf("%d : (%d,%d)\n", i , cl.arr[i].row,cl.arr[i].col);
	}
}

struct cell CL_get(struct cellList cl, int ind){
	if(cl.size == 0){
		printf("Empty cellList\n");
		exit(1);
	}
	if(ind >= cl.size){
		printf("Oversize\n");
		exit(1);
	}
	return cl.arr[ind];
}

struct cell CL_random(struct cellList cl){
	if(cl.size == 0){
		printf("Empty cellList\n");
		exit(1);
	}
	// srand(time(NULL));
	int ind = rand() % cl.size;
	return cl.arr[ind];
}

struct cellList CL_neighbors(struct cell c){
	struct cellList cl = CL_new();
	struct cell c1;
	c1.col = c.col;
	c1.row = c.row-1;
	cl = CL_add(cl,c1);
	c1.row = c.row+1;
	cl = CL_add(cl,c1);
	c1.col = c.col-1;
	c1.row = c.row;
	cl = CL_add(cl,c1);
	c1.col = c.col+1;
	cl = CL_add(cl,c1);
	return cl;
}


struct cellList CL_randomPath(struct cell start, int nb_cells){
	struct cellList list = CL_new();
	list=CL_add(list,start);
	struct cell next;
	struct cell prev;
	for(int i=1;i< nb_cells ; i++){
		prev = list.arr[i-1];
		next = CL_random(CL_neighbors(prev));
		list=CL_add(list,next);

	}
	return list;
}

void CL_draw(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name)
{
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.7;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	struct cell c = CL_get(cl,0);
	img = PPM_drawCell(img, c.row, c.col);

	for(int i=1; i<cl.size;i++)
	{
		struct cell c = CL_get(cl,i);
		struct cell c2 = CL_get(cl,i-1);
		img = PPM_drawLink(img, c.row, c.col, c2.row, c2.col);
		img = PPM_drawCell(img, c.row, c.col);
	}
	sprintf(ppm_file_name,"%s.ppm",ppm_name);
	PPM_save(img,ppm_file_name);
}

void CL_animate(struct cellList cl, int nb_rows, int nb_cols, char *ppm_name)
{
	int pixels_per_cell = 20;
	char ppm_file_name[50];
	float proportion_serpent = 0.7;
	struct ppm img = PPM_new(nb_rows, nb_cols, pixels_per_cell, proportion_serpent);
	img = PPM_drawBG(img);

	struct cell c = CL_get(cl,0);
	img = PPM_drawCell(img, c.row, c.col);
	sprintf(ppm_file_name,"%s_%02d.ppm",ppm_name,0);
	PPM_save(img,ppm_file_name);

	for(int i=1; i<cl.size;i++)
	{
		struct cell c = CL_get(cl,i);
		struct cell c2 = CL_get(cl,i-1);
		img = PPM_drawLink(img, c.row, c.col, c2.row, c2.col);
		img = PPM_drawCell(img, c.row, c.col);

		sprintf(ppm_file_name,"%s_%02d.ppm",ppm_name,i);
		PPM_save(img,ppm_file_name);
	}
}

















