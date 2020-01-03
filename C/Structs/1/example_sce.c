#define SIZE 30
#define CODE_ERROR -1
#define SUCCESS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Declaration of structures*/
struct Student{
	char name[SIZE];
	int id;
};
struct Class{
	char* teacher;
	int num_st;
	struct Student* st;
};
/*Declaration of functions*/
void InputStudent(struct Student*);
void PrintStudent(struct Student);
int InputClass(struct Class*);
int InitSCE(struct Class**);
int FindStudent(struct Class*,int,char*,int*);
void FreeAll(struct Class**, int);
/*The main function*/
int main(){
	struct Class* sce = NULL;
	int size,classNo,index;
	char name[SIZE];
	size = InitSCE(&sce);
	printf("\nEnter student's name for the search :\n");
	scanf("%s", name);
	classNo = FindStudent(sce, size, name, &index);
	if (classNo == -1)
		printf("\nNo data was found!\n");
	else
		PrintStudent(sce[classNo].st[index]);
	FreeAll(&sce, size);
	return 0;
}
/*Implementation of functions*/
void InputStudent(struct Student* pSt){
	/*A function that fills student's fields*/
	printf("\nEnter data for the student: name and id :\n");
	scanf("%s%d", pSt->name, &pSt->id);
}
void PrintStudent(struct Student st){
	/*A function that prints student's fields*/
	printf("\nStudent's name %s: , id := %d \n",st.name,st.id);
}
int InputClass(struct Class* pCls){
	/*A function that fills the fields of a structure named Class*/
	char buffer[SIZE];
	int i;
	printf("\nEnter a Teacher's name:\n");
	scanf("%s", buffer);
	pCls->teacher = (char*)malloc(strlen(buffer) + 1);
	strcpy(pCls->teacher, buffer);
	printf("\nEnter the number of students:\n");
	scanf("%d", &pCls->num_st);
	pCls->st = (struct Student*)malloc(sizeof(struct Student)*pCls->num_st);
	if (pCls->st == NULL){
		printf("Not enouth memory");
		return CODE_ERROR;
	}
	printf("\nEnter data for  %d students:\n", pCls->num_st);
	for (i = 0; i < pCls->num_st; i++)
		InputStudent(&pCls->st[i]);
	return SUCCESS;
}
int InitSCE(struct Class** pClass){
	/*A function that builds a dynamic array of elements from the type of struct Class*/
	int size, i,status;
	printf("\nEnter the number of classes:\n");
	scanf("%d", &size);
	*pClass = (struct Class*)malloc(sizeof(struct Class)*size);
	if (*pClass == NULL){
		printf("Not enouth memory");
		exit(1);
	}
	printf("\nEnter data for  %d classes:\n", size);
	for (i = 0; i < size; i++){
		status = InputClass(&(*pClass)[i]);
		if (status == CODE_ERROR){
			printf("Not enouth memory");
			FreeAll(pClass,i);
			exit(1);
		}
	}
		
	return size;
}
int FindStudent(struct Class* arClasses, int size, char* fname, int* pJ){
	/*A function that searches for a student named fname*/
	int i,j;
	for (i = 0; i < size;i++)
		for (j = 0; j < arClasses[i].num_st;j++)
		if (strcmp(arClasses[i].st[j].name, fname) == 0){
				*pJ = j;
				return i;
			}
			return CODE_ERROR;
}
void FreeAll(struct Class** pClasses, int countClasses){
	/*A function that frees all of the dynamic memory*/
	int i;
	for (i = 0; i < countClasses; i++){
		free((*pClasses)[i].teacher);
		free((*pClasses)[i].st);
	}
	free(*pClasses);
}
