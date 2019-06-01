#include<stdio.h>
#include<math.h>
#define MAX 50
//nhap ma tran
void NhapMT(int mt[MAX][MAX],int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Nhap A[%d][%d] = ",i,j);
            scanf("%d",&mt[i][j]);
        }
    }
}
void XuatMT(int mt[MAX][MAX],int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%4d",mt[i][j]);    
        }
        printf("\n");
    }
}
//Tim min max cua ma tran 
void MinMax(int mt[MAX][MAX],int n,int m)
{
    int max,min;
    max=min=mt[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mt[i][j]>max)
                max=mt[i][j];
            if(mt[i][j]<min)
                min=mt[i][j];
        }
    }
    printf("\nGia tri lon nhat cua ma tran la %d",max);
    printf("\nGia tri nho nhat cua ma tran la %d",min);
}
//hàm kiem tra so nguyên to
bool snt(int x)
{
    if(x<2)
        return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)
            return false;
    }
    return true;
}
//ham tinh tong so nguyen to
void TinhTongSnt(int mt[MAX][MAX],int n,int m)
{
    int tong=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(snt(mt[i][j])==true)
                tong+=mt[i][j];    
        }
    }
    printf("\nTong cac so nguyen to trong ma tran la : %d",tong);
}

int main()
{
    int n,m;
    int mt[MAX][MAX];
    printf("\nNhap m,n cua ma tran Anxm : ");
    scanf("%d%d",&n,&m);
    NhapMT(mt,n,m);
    XuatMT(mt,n,m);
    MinMax(mt,n,m);
    TinhTongSnt(mt,n,m);
}
//Hoang Huy
