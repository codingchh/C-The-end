#include <stdio.h>
#include <windows.h>
#include<string.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 50
int a[MAX],b[MAX],c[MAX];
int n,m;
int x;
int LuuThua(int x,int mu){
    if(mu==0)
        return 1;
    else
        return x*LuuThua(x,mu-1);
}
int NhapHSMotDaThuc(char mu,char soHang,int mang[],int soMu);
void TinhHSTong(int mang1[],int mang2[],int mang3[],int soMu1,int soMu2);
void Nhap();
void InHeSoMotDaThuc(char daThuc,char soHang,int mang[],int soMu);
void InHeSo3DT();
void TinhVaInGT(char daThuc ,int mang[],int soMu);
void InGiaTri3DT();
int main()
{
    while(1){
        system("cls");
        printf("%20s\n", "MENU");
        printf("1. Nhap he so cua 2 da thuc P,Q\n2. Tinh he so cua da thuc T\n3. In he so cua 3 da thuc P,Q,T\n4. In gia tri cua 3 da thuc P,Q,T\n5. Ket thuc\n");
        char chon=getch();
        switch(chon){
            case '1':
                Nhap();
                break;
            case '2':
                TinhHSTong(a,b,c,n,m);
                break;
            case '3':
                InHeSo3DT();
                break;
            case '4':
                InGiaTri3DT();
                break;
            case '5':
                exit(0);
        }
    }
}
int NhapHSMotDaThuc(char mu,char soHang,int mang[],int soMu){
    printf("Nhap gia tri %c cua da thuc \n",mu );
    scanf("%d",&soMu);
    printf("%s\n", "Nhap cac so hang cua da thuc :");
    for(int i=soMu;i>=0;i--){
        printf("%c[%d]=",soHang,i);
        scanf("%d",&mang[i]);
    }
    return soMu;
}
void Nhap(){
    system("cls");
    n=NhapHSMotDaThuc('n','a',a,n);
    printf("\n");
    m=NhapHSMotDaThuc('m','b',b,m);
}
void InHeSoMotDaThuc(char daThuc,char soHang,int mang[],int soMu){
    printf("Cac he so cua da thuc %c la:\n", daThuc);
    for(int i=soMu;i>=0;i--){
        printf("%c[%d]=%5d\n",soHang,i,mang[i] );
    }
}
void InHeSo3DT(){
    system("cls");
    InHeSoMotDaThuc('P','a',a,n);
    printf("\n");
    InHeSoMotDaThuc('Q','b',b,m);
    printf("\n");
    InHeSoMotDaThuc('T','c',c,n>m?n:m);
    system("pause");
}
void TinhVaInGT(char daThuc ,int mang[],int soMu){
    int tong=0;
    for(int i=0;i<=soMu;i++){
        tong+=mang[i]*LuuThua(x,i);
    }
    printf("%c = %5d",daThuc,tong );
}
void InGiaTri3DT(){
    printf("%s ", "Nhap he so x :");
    scanf("%d",&x);
    TinhVaInGT('P',a,n);
    printf("\n");
    TinhVaInGT('Q',b,m);
    printf("\n");
    TinhVaInGT('T',c,n>m?n:m);
    printf("\n");
    system("pause");
}
void TinhHSTong(int mang1[],int mang2[],int mang3[],int soMu1,int soMu2){
    system("cls");
    if(soMu1>soMu2){
        int i=0;
        for(;i<=soMu2;i++){
            mang3[i]=mang1[i]+mang2[i];
        }
        while(i<=soMu1){
            mang3[i]=mang1[i];
            i++;    
        }
    }
    else{
        int i=0;
        for(;i<=soMu1;i++){
            mang3[i]=mang1[i]+mang2[i];
        }
        while(i<=soMu2){ 
            mang3[i]=mang2[i];
            i++;    
        }
    }
    printf("%s\n", "Da tinh xong he so cua da thuc T");
    system("pause");
}
// Hoang Huy

