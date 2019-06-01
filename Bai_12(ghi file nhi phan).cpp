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
long size=sizeof(SoLieu);
int n=0;
int stt=1;
SoLieu soLieu;
int tong=0;

FILE *f;
void Nhap(){
    stt=1;
	system("cls"); 
	f=fopen("SO_LIEU.C","wb");
	while(1){ 
		printf("\n-Nhap so lieu ban hang");
		printf("\n+Ten hang :");
		fflush(stdin);
		gets(soLieu.Ten_Hang);
		printf("\n+Don gia :");
		scanf("%d",&soLieu.Don_Gia);
		printf("\n+So luong :");
		scanf("%d",&soLieu.So_Luong);
        fwrite(&soLieu, size, 1, f);
        tong+=soLieu.Don_Gia*soLieu.So_Luong;
        printf("Ban co muon nhap tiep k?(c/k)\n");
        fflush(stdin);
        char chon=getch();
        if(chon=='k')
            break;
	}
	fclose(f);
	
}
void HienThi(){
    system("cls");
    f=fopen("SO_LIEU.C","rb");
    printf("%40s%s","","SO LIEU BAN HANG");
    printf("\n");
    printf("%5s%20s%15s%15s%20s","STT","Ten Hang","Don Gia","So Luong","Thanh Tien");
    printf("\n");
    stt=1;
    while(fread(&soLieu,size , 1, f)>0){
        printf("%5d%20s%15d%15d%20d",stt,soLieu.Ten_Hang,soLieu.Don_Gia,soLieu.So_Luong,soLieu.Don_Gia*soLieu.So_Luong);
        printf("\n");
        stt++;
    }
    fclose(f);
    printf("%45sTong tien:%20d\n","",tong );
    system("pause");
}
void BoXung(){
    system("cls"); 
    f=fopen("SO_LIEU.C","ab");
    while(1){ 
        printf("\n-Nhap so lieu ban hang bo xung");
        printf("\n+Ten hang :");
        fflush(stdin);
        gets(soLieu.Ten_Hang);
        printf("\n+Don gia :");
        scanf("%d",&soLieu.Don_Gia);
        printf("\n+So luong :");
        scanf("%d",&soLieu.So_Luong);
        fwrite(&soLieu,size,1,f);
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
				break;
			case '4':
				exit(0);
		}	
	}
	
}
//Hoang Huy