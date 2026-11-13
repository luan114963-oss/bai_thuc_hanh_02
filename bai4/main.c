#include<stdio.h>
#include<stdlib.h>
#include<string>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;
/////////////////////////////////////
void initList(LList *L)
    {
    	L->pHead = NULL;
    	L->pTail = NULL;
    	L->spt = 0;
    }
/////////////////////////////////////
int emptyList(LList L)
 {
    	return (L.spt == 0); 
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_tail(LList *L, Data x){
	Node *pp =(Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}else{
		L->pTail->link = pp;
		L->pTail = pp;
	}
	L->spt++;
}
void insert_After(LList *L, Node *q, Data x){
	if(q==NULL) return;
	Node *pp = (Node*) malloc(sizeof(Node));
	pp -> infor = x;
	pp -> link = q->link;
	q->link = pp;
	if(q==L->pTail){
		L->pTail = pp;
	}
	L->spt++;
}
Node *searchByMaSV(LList L, int ma){
	Node *p = L.pHead;
	while(p!= NULL){
		if(p->infor.masv == ma){
			return p;
		}
		p->link;
	}
	return NULL;
}
int deleteByMaSV(LList *L, int ma){
	if(emptyList(*L)) return 0;
	Node *p = L->pHead;
	Node *prev = NULL;
	
	while(p!= NULL && p->infor.masv !=ma){
		prev = p;
		p = p->link;
	}
	if(p==NULL) return 0;
	if(p==L->pHead){
		L->pHead = p->link;
		if(L->pHead==NULL) L->pTail = NULL;
	}else {
		prev->link = p->link;
		if(p==L->pTail) L->pTail = prev;
	}
	free(p);
	L->spt--;
	return 1;
}
float tinhDTB(Data x){
	return(x.d1 + x.d2 + x.d3)/3.0f;
}
void sortByDTB(LList *L){
	if(L->spt<2) return;
	for(Node *i = L->pHead; i!=NULL; i= i->link){
		for(Node *j = i->link; j!=NULL; j=j->link){
			if(tinhDTB(i->infor)<tinhDTB(j->infor)){
				Data tmp = i->infor;
				i->infor = j->infor;
				j->infor = tmp;
			}
		}
	}
}
void freeList(Data *x){
	Node *p = L->pHead;
	while(p!=NULL){
		Node *tmp = p;
		p=p->link;
		free(tmp);
	}
	initList(L);
}
///////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap ma sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in d? li?u trong node 
        	pp = pp->link;
    	}
}
/////////////////////////////////////////

int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); //tao ra 1 ds rong
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap so thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap so thông tin sv can them vao cuoi\n");
	            nhsp(&x);
	            if(x.masv>0){
	            	insert_tail(&L, x);
				}
            	break;
            case 3:
	            int matim;
	            printf("Nhap ma sv cua tung nut dung truoc: ");
	            scanf("%d", &matim);
	            Node *q = searchByMaSV(L, matim);
	            if(q==NULL){
	            	printf("Khong tim thay");
				}else{
					print("Nhap thong tin sinh vien moi can chen.\n");
					nhap(&x);
					if(x.masv>0){
						insert_After(&L, 1, x);
						printf("Da chen thanh cong.\n")
					}
				}
            	break;
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}










