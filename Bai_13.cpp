#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<string.h>
#include<conio.h>
#define MAX 50
typedef struct Node
{
    int so_du;
    Node *next;
}Node;
Node *Head;
Node *pnode;
void push(int n){
    pnode=(Node*)malloc(sizeof(Node));
    pnode->so_du=n;
    pnode->next=Head;
    Head=pnode;
}
void pop(int *n){
    pnode=Head;
    *n=pnode->so_du;
    Head=Head->next;
    free(pnode);
}// chang de lam gi :v
void hienketqua(int n,int he)
{
    printf("\n%d => he %d =  ",n ,he);
    while(Head!=NULL){
        if(Head->so_du==10){
            printf("%c",'A' );
            Head=Head->next;
        }
        else if(Head->so_du==11){
            printf("%c",'B' );
            Head=Head->next;
        }
        else if(Head->so_du==12){
            printf("%c",'C' );
            Head=Head->next;
        }
        else if(Head->so_du==13){
            printf("%c",'D' );
            Head=Head->next;
        }
        else if(Head->so_du==14){
            printf("%c",'E' );
            Head=Head->next;
        }
        else if(Head->so_du==15){
            printf("%c",'F' );
            Head=Head->next;
        }
        else{
            printf("%d",Head->so_du );
            Head=Head->next;
        
        }
    }
}
void chuyen_co_so(int he);
int main()
{
    while(1){
        system("cls");
        printf("%20s\n","MENU" );
        printf("1.Chuyen mot so nguyen duong sang he 2\n2.Chuyen mot so nguyen duong sang he 8\n3.Chuyen mot so sang he 16\n4.Ket thuc\n");
        char chon=getch();
        switch(chon){
            case '1':
            chuyen_co_so(2);
            break;
            case '2':
            chuyen_co_so(8);
            break;
            case '3':
            chuyen_co_so(16);
            break;
            case '4':
            exit(0);
        }   
    }
}
void chuyen_co_so(int he){
    if(he==2){
        int n;
        system("cls");
        int luu;
        printf("%s", "Nhap so nguyen duong can chuyen sang he 2 :");
        scanf("%d",&n);
        luu=n;
        while(n!=0){
            push(n%2);
            n=n/2;
        }
        hienketqua(luu,2);
        printf("\n");
        system("pause");
    }
    if(he==8){
        int n;
        system("cls");
        int luu;
        printf("%s", "Nhap so nguyen duong can chuyen sang he 8 :");
        scanf("%d",&n);
        luu=n;
        while(n!=0){
            push(n%8);
            n=n/8;
        }
        hienketqua(luu,8);
        printf("\n");
        system("pause");
    }
    if(he==16){
        int n;
        system("cls");
        int luu;
        printf("%s", "Nhap so nguyen duong can chuyen sang he 16 :");
        scanf("%d",&n);
        luu=n;
        while(n!=0){
            push(n%16);
            n=n/16;
        }
        hienketqua(luu,16);
        printf("\n");
        system("pause");
    }
}
//Hoang Huy
