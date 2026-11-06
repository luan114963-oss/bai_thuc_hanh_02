#include<stdio.h>
#include <stdlib.h>
struct sinhvien{
	char hoten[50];
	char msv[15];
	float diem1;
	float diem2;
	float diem3;
};
typedef struct sinhvien sv;
struct node{
	sv data;
	struct node *next;
};
typedef struct node  NODE;
struct linklist{
	NODE *head;
};
typedef struct linklist LIST;

int main(){
	return 0;	
}
