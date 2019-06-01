#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50
#define KT 256
int mtA[MAX][MAX];
int mtB[MAX][MAX];
int mtC[MAX][MAX];
int n,m;
FILE *f;
char link[]="MA_TRAN.C";
void DocTep();
void HienThi();
void GhiTep();
int main()
{
    while(1){
        system("cls");
        printf("%20s\n", "MENU");
        printf("1. Doc tep MA_TRAN.C\n2. Ghi ma tran C bo sung vao cuoi tep tren\n3. Ket thuc\n");
        char chon=getch();
        switch(chon){
            case '1':
                DocTep();
                break;
            case '2':
               GhiTep();
                break;
            case '3':
                exit(0);
        }
    }
}
void DocTep(){
    f=fopen(link,"w+");
    system("cls");
    printf("-Nhap hai ma tran Anxm va Bnxm:\n\t+ n =");
    scanf("%d",&n);
    fprintf(f, "%5d", n);
    printf("\t+ m =");
    scanf("%d",&m);
    fprintf(f, "%d", m);
    fputc(10,f);
    printf("-Nhap ma tran A\n");
    fprintf(f, "%s\n", "Ma tran A");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("\tA[%d][%d] = ",i,j);
            scanf("%d",&mtA[i][j]);
            fprintf(f, "%5d", mtA[i][j]);
        }
        fputc(10,f);
    }
    printf("-Nhap ma tran B\n");
    fprintf(f, "%s\n", "Ma tran B");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("\tB[%d][%d] = ",i,j);
            scanf("%d",&mtB[i][j]);
            fprintf(f, "%5d", mtB[i][j]);
        }
        fputc(10,f);
    }
    fclose(f);
}
void GhiTep(){
    system("cls");
    //mac dinh cac gia tri ma tran C ve 0 :v
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mtC[i][j]=0;
        }
    }
    fopen(link,"a+");
    fprintf(f, "%s\n", "Ma tran C");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mtC[i][j]=mtA[i][j]+mtB[i][j];
            fprintf(f, "%5d", mtC[i][j]);
        }
        fputc(10,f);
    }
    fclose(f);
    printf("Da ghi bo sung ma tran C thanh cong\n");
    system("pause");
    HienThi();
}
void HienThi(){
    system("cls");
    fopen(link,"r");
    fseek(f,6,SEEK_SET);
    // khi ghi n va m va tep thi da lay 6 byte nen long=6
    while(!feof(f)){
        char x=fgetc(f);
        printf("%c",x );
    }
    fclose(f);
    system("pause");
}
//Hoang Huy
