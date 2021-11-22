#include<stdio.h>
#define Max 100


void input(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Nhap phan tu thu %d:",i+1);
		scanf("%d",&arr[i]);
	}
}

void output(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t", arr[i]);
	}
}

int OddCheck(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==1)
			return 1;
	
	}
	return 0;
}

int SumCheck(int arr[],int n)
{
	int i,x;
	do
	{
		printf("\n Nhap vi tri  can xet:");
		scanf("%d",&x);
		if(x<3)
			printf("\n Diem xet khong hop le,nhap lai");
	}while(x<3);
	for(i=x;i<n;i++)
	{
	    if(arr[i]==arr[i-1]+arr[i-2])
		    return 1;
		return 0;
    }	
}

void chenx(int arr[],int *n)
{
	int i,k,x;
	do
	{
		printf("\nHay nhap vi tri can chen:");
		scanf("%d",&k);
		if(k<0 || k>*n )
			printf("Sai roi,hay nhap vi tri thich hop.");
	}while(k<0 || k>*n);
	printf("\nHay nhap gia tri can chen:");
	scanf("%d",&x);
	++*n;
	for(i=*n-1;i>=k;i--)
	{
		
		arr[i+1]=arr[i];
		
	}
	arr[k]=x;
}

void decrease(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(arr[j]>arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
}

int vitrichen(int arr[],int n,int x)
{
	if(arr[0]<x)
		return 0;
	if(arr[n-1]>x)
		return n;
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]<=x)
			return i;
	}
}
void ChenX2(int arr[],int *n,int x,int k)
{
	int i;
	++*n;
	for(i=*n-1;i>k;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[k]=x;
}

void XoaPT(int arr[],int *n,int x)
{
    int i;
    for(i=0;i<*n;i++)
    {
        if(arr[i]>x)
        {           
            
            arr[i]=arr[i+1];
        
            
        }
        *n=*n-1;

    }

}

int main()
{
	int n,x;
	int arr[Max];
	do
	{
		printf("\nHay nhap so phan tu n le(n>0):");
		scanf("%d",&n);
		if(n%2==0 || n<=0 || n>Max)
			printf("Sai roi,nhap lai:");
	}while(n%2==0 || n<=0 || n>Max);
	
	input(arr,n);
	printf("Mang:");
	output(arr,n);
	
	if(OddCheck(arr,n)==1)
		printf("\nMang co ton tai so le!");
	else
		printf("\nMang KHONG ton tai so le!");
		
	if(SumCheck(arr,n)==1)
		printf("\n Gia tri tai diem dang xet = tong 2 phan tu lien truoc do!");
	else
		printf("\n Gia tri tai diem dang xet KHONG = tong 2 phan tu lien truoc do!");
	
	chenx(arr,&n);
	printf("\nMang sau khi chen la:");
	output(arr,n);
	
	
	decrease(arr,n);
	printf("\nMang giam dan la:");
	output(arr,n);
	
	printf("\nNhap gia tri X muon nhap vao:");
	scanf("%d",&x);
	int k=vitrichen(arr,n,x);
	ChenX2(arr,&n,x,k);
	printf("\nMang sau khi chen X vao:");
	output(arr,n);
	
	
	XoaPT(arr,&n,x);
	printf("\nMang sau khi xoa cac phan tu lon hon x:");
	output(arr,n);
	
	
	return 0;
}