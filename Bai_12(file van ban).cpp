#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<string.h>
#include<conio.h>
#define MAX 50
#define KT 256
typedef struct {
	char Ten_Hang[MAX];
	int Don_Gia;
	int So_Luong;
	int Thanh_Tien;
}SoLieu;

int stt=1;
SoLieu soLieu;
int tong=0;
void Nhap(){
	system("cls");
	stt=1;
	FILE *f;
	f=fopen("SO_LIEU.C","w+");
	fprintf(f,"%40s%s","","SO LIEU BAN HANG");
	putc('\n',f);
	fprintf(f,"%5s%20s%15s%15s%20s","STT","Ten Hang","Don Gia","So Luong","Thanh Tien");
	putc('\n',f);
	while(1){ 
		printf("\n-Nhap so lieu ban hang");
		printf("\n+Ten hang :");
		fflush(stdin);
		gets(soLieu.Ten_Hang);
		printf("\n+Don gia :");
		scanf("%d",&soLieu.Don_Gia);
		printf("\n+So luong :");
		scanf("%d",&soLieu.So_Luong);
		fprintf(f, "%5d%20s%15d%15d%20d",stt,soLieu.Ten_Hang,soLieu.Don_Gia,soLieu.So_Luong,soLieu.Don_Gia*soLieu.So_Luong);
        fputc(10,f);
        stt++;
        tong+=soLieu.Don_Gia*soLieu.So_Luong;
        printf("Ban co muon nhap tiep k?(c/k)\n");
        fflush(stdin);
        char chon=getchar();
        if(chon=='k')
            break;
	}
	fclose(f);
	
}
void HienThi(){
    system("cls");
    FILE *f;
    f=fopen("SO_LIEU.C","r+");
    while(!feof(f)){
        char x=getc(f);
        printf("%c",x );
    }
    fclose(f);
}
void BoXung(){
    system("cls");
    FILE *f;
    f=fopen("SO_LIEU.C","a+");
    while(1){ 
        printf("\n-Nhap so lieu ban hang bo xung");
        printf("\n+Ten hang :");
        fflush(stdin);
        gets(soLieu.Ten_Hang);
        printf("\n+Don gia :");
        scanf("%d",&soLieu.Don_Gia);
        printf("\n+So luong :");
        scanf("%d",&soLieu.So_Luong);
        fprintf(f, "%5d%20s%15d%15d%20d",stt,soLieu.Ten_Hang,soLieu.Don_Gia,soLieu.So_Luong,soLieu.Don_Gia*soLieu.So_Luong);
        fputc(10,f);
        stt++;
        tong+=soLieu.Don_Gia*soLieu.So_Luong;
        printf("Ban co muon nhap tiep k?(c/k)\n");
        fflush(stdin);
        char chon=getch();
        if(chon=='k')
            break;
    }
    fclose(f);
}
int main()
{
	while(1)
	{
		system("cls");
		printf("%20s","MENU");
		printf("\n1.Nhap so lieu ban hang len tep\n2.Ghi bo sung so lieu ban hang vao cuoi tep SO_LIEU.C\n3.Hien thi noi dung tep SO_LIEU.C\n4.Ket thuc\n\tBan chon : ");
		char chon=getch();
		switch(chon){
			case '1':
				Nhap();
				break;
			case '2':
                BoXung();
                break;
			case '3':
				HienThi();
                printf("%45sTong tien:%19d\n","",tong);
                system("pause");
				break;
			case '4':
				exit(0);
		}	
	}
	
}
//Hoang Huy