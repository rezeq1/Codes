#include<stdio.h>
#include<stdlib.h>
/* Structures declarations */
struct Point{
	int x, y;
};
struct Polygon{
	struct Point* pol;
	int numPol;
};
/* Functions declarations */
void InputP(struct Point* );
void PrintP(struct Point);
void InputPolygon(struct Polygon* );
void PrintPolygon(struct Polygon);
/* main function */
int main(){

	struct Polygon polygon;
	InputPolygon(&polygon);
	PrintPolygon(polygon);
	free(polygon.pol);
	polygon.pol = NULL;

	return 0;
}
/* functions implementations */
void InputP(struct Point* PointPtr){
	printf("Enter a data for point: ");
	scanf("%d%d", &PointPtr->x, &PointPtr->y);
}
void PrintP(struct Point point){
	printf(" (%d,%d)\t",  point.x, point.y);
}
void InputPolygon(struct Polygon* ptrPol){
	int i;
	scanf("%d", &ptrPol->numPol);
	ptrPol->pol = (struct Point*)malloc(ptrPol->numPol*sizeof(struct Point));
	if (ptrPol->pol == NULL) exit(1);
	for (i = 0; i < ptrPol->numPol; i++)
		InputP(&ptrPol->pol[i]);
}
void PrintPolygon(struct Polygon pol){
	int i;
	for (i = 0; i < pol.numPol; i++){
		PrintP(pol.pol[i]);
	}

}
