#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50
int mtA[MAX][MAX];
int mtB[MAX][MAX];
int mtC[MAX][MAX];
int n,m,p;
void Nhap();
void Tinh();
void HienThi();
int main()
{
    while(1){
        system("cls");
        printf("%20s\n", "MENU");
        printf("1.Nhap hai ma tran\n2.Tinh tich hai ma tran\n3.Hien thi 3 ma tran\n4.Ket thuc\n");
        char chon=getch();
        switch(chon){
            case '1':
                Nhap();
                break;
            case '2':
                Tinh();
                break;
            case '3':
                HienThi();
                break;
            case '4':
                exit(0);
        }
    }
}
void Nhap(){
    system("cls");
    printf("-Nhap hai ma tran Anxp va Bpxm:\n\t+ n =");
    scanf("%d",&n);
    printf("\t+ p =");
    scanf("%d",&p);
    printf("\t+ m =");
    scanf("%d",&m);
    printf("-Nhap ma tran A\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("\tA[%d][%d] = ",i,j);
            scanf("%d",&mtA[i][j]);
        }
    }
    printf("-Nhap ma tran B\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<m;j++){
            printf("\tB[%d][%d] = ",i,j);
            scanf("%d",&mtB[i][j]);
        }
    }
}
void Tinh(){
    system("cls");
    //mac dinh cac gia tri ma tran C ve 0 :v
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mtC[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            for(int k=0;k<p;k++){
                mtC[i][j]+=mtA[i][k]*mtB[k][j];
            }
    }
    printf("Da tinh tich 2 ma tran xong\n");
    system("pause");
}
void HienThi(){
    system("cls");
    printf("Ma tran A\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            printf("%3d",mtA[i][j] );
        }
        printf("\n");
    }
    printf("\nMa tran B\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<m;j++){
            printf("%3d",mtB[i][j] );
        }
        printf("\n");
    }
    printf("\nMa tran C=AxB\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%3d",mtC[i][j] );
        }
        printf("\n");
    }
    system("pause");
}
//Hoang Huy
