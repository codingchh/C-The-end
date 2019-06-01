#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25
struct Sinh_Vien{
	char Ho_ten[MAX];
	int Tuoi;
	int Diem_TB;
}SV;
typedef struct Node{
	Sinh_Vien sv;
	Node* next;
}Node;
Node* Head;
Node* Tail;
Node* pnode;
Node* CreateNode(Sinh_Vien sv)
{
	pnode=(Node*)malloc(sizeof(Node));
	if(pnode==NULL){
		printf("\nLoi cap phat bo nho !\n");
		exit(0);
	}
	else{
		pnode->sv=sv;
		pnode->next=NULL;
	}
}
void addHead(Sinh_Vien sv)
{
	if(Head==NULL)
		Head=Tail=pnode;
	else{
		pnode->next=Head;
		Head=pnode;
	}
}
void addTail(Sinh_Vien sv)
{
	if(Head==NULL)
		Head=Tail=pnode;
	else{
		Tail->next=pnode;
		Tail=pnode;
	}
}
void TaoDanhSach()
{
	while(1)
	{
		Sinh_Vien sv;
		system("cls");
		printf("-Nhap thong tin sinh vien :\n");
		printf("\t+Ten sinh vien : ");
		fflush(stdin);
		gets(sv.Ho_ten);
		printf("\t+Tuoi sinh vien :");
		scanf("%d",&sv.Tuoi);
		printf("\t+Diem TB :");
		scanf("%d",&sv.Diem_TB);
		
		CreateNode(sv);
		addTail(sv);
		
		printf("\nBan co muon nhap tiep khong ?(c/k)");
		fflush(stdin);
		char chon=getch();
		if(chon=='k'||chon=='K')
			break;
	}
} 
void ChenMotSV()
{
	Sinh_Vien sv;
	Node* pTim;
	char ten[MAX];
	system("cls");
	printf("-Nhap thong tin sinh vien :\n");
	printf("\t+Ten sinh vien : ");
	fflush(stdin);
	gets(sv.Ho_ten);
	printf("\t+Tuoi sinh vien :");
	scanf("%d",&sv.Tuoi);
	printf("\t+Diem TB :");
	scanf("%d",&sv.Diem_TB);
	
	printf("\nBan muon chen sau sinh vien ten gi : ");
	fflush(stdin);
	gets(ten);
	
	pTim=Head;
	while(pTim!=NULL&&(strcmpi(ten,pTim->sv.Ho_ten)!=0))
		pTim=pTim->next;
	if(pTim==NULL){
		printf("\nKhong co ten nhu vay trong danh sach !\n");
		system("pause");
		return;
	}
	else{	
		CreateNode(sv); 
		pnode->next=pTim->next; 
		pTim->next=pnode; 
		printf("\nDa chen sinh vien thanh cong!\n");	
		system("pause");
	}
}
void XoaSV()
{
	char ten[MAX];
	system("cls");
	printf("Nhap ten sinh vien ban can xoa : ");
	gets(ten);
	Node* pTim=Head;
	Node* pTruoc;
	while(pTim!=NULL&&strcmpi(pTim->sv.Ho_ten,ten)!=0){
		pTruoc=pTim;
		pTim=pTim->next;
	}
	if(pTim==NULL){
		printf("\nKhong co sinh vien nao co ten nhu vay !\n");
		system("pause");
	}
	else{
		if(pTim->next==NULL)
			pTruoc->next=NULL;
		else{
			if(pTim==Head)
				Head=pTim->next;
			else{
				pTruoc->next=pTim->next;
				free(pTim);
				printf("\nDa xoa sinh vien thanh cong !\n");
				system("pause");
			}
		}
	}
}
void SuaSV()
{
	system("cls");
	char ten[MAX];
	printf("Nhap ten sinh vien can sua: ");
	gets(ten);
	
	Node* pTim=Head;
	while(pTim!=NULL&&strcmpi(pTim->sv.Ho_ten,ten)!=0)
		pTim=pTim->next;
	if(pTim==NULL){
		printf("Khong co sinh vien nao co ten nhu vay!\n");
		system("pause");
	}
	else{
		Sinh_Vien sv;
		printf("\n-Nhap thong tin sinh vien :\n");
		printf("\t+Ten sinh vien : ");
		fflush(stdin);
		gets(sv.Ho_ten);
		printf("\t+Tuoi sinh vien :");
		scanf("%d",&sv.Tuoi);
		printf("\t+Diem TB :");
		scanf("%d",&sv.Diem_TB);
		strcpy(pTim->sv.Ho_ten,sv.Ho_ten);
		pTim->sv.Tuoi=sv.Tuoi;
		pTim->sv.Diem_TB=sv.Diem_TB;
		printf("\nSua thong tin sinh vien thanh cong!\n");
		system("pause");
	}
}
void HienDS()
{
	system("cls");
	int stt=1;
	pnode=Head;
	printf("\n%15sDANH SACH SINH VIEN\n","");
	printf("\n%5s%18s%10s%10s","STT","Ho ten","Tuoi","Diem TB");
	while(pnode!=NULL){
		printf("\n%5d%18s%10d%10d",stt,pnode->sv.Ho_ten,pnode->sv.Tuoi,pnode->sv.Diem_TB);
		stt++;
		pnode=pnode->next;
	}
	printf("\n");
	system("pause");
}
int main()
{
	Sinh_Vien sv;
	while(1){
		system("cls");
		printf("%15sMENU");
		printf("\n1.Tao danh sach sinh vien\n2.Hien thi danh sach sinh vien\n3.Chen them sinh vien\n4.Xoa mot sinh vien\n5.Sua mot sinh vien\n6.Ket thuc");
		printf("\n%5sBan chon :","");
		char chon=getch();
		switch(chon){
			case '1':
				TaoDanhSach();
				break;
			case '2':
				HienDS();
				break;
			case '3':
				ChenMotSV();
				break;
			case '4':
				XoaSV();
				break;
			case '5':
				SuaSV();
				break;
			case '6':
				exit(0);
		}
	}
}
//Hoang Huy