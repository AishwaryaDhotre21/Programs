#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
void	getdata(int *arr,int count);
void	printdata(int *arr,int count);
void	sortdata(int *arr,int count);
void swap(int *a,int *b);
int main()
{
	int arr[100];
	cout << "\nEnter the count of total numbers:";
	int count;
	cin >> count;
	getdata(arr,count);
	printdata(arr,count);
	sortdata(arr,count);
	printdata(arr,count);
	return 0;
}
void	getdata(int *arr,int count)
{
	for(int i=0;i<count;i++)
	{
		cout << "\n Enter the " << i+1 << "th val:";
		cin >> arr[i];
	}
}
void	printdata(int *arr,int count)
{
	cout << "\n Entered data:\n";
	for(int i=0;i<count;i++)
	{
		cout << arr[i] << " ";
	}
	
}
void	sortdata(int *arr,int count)
{
	int min,i,j;
	for( i=0;i<count-1;i++)
	{
		min=i;
		for(j=i+1;j<count;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		swap(&arr[min],&arr[i]);
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

