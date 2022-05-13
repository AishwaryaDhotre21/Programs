#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
void getdata(int *arr,int count);
void printdata(int *arr,int count);
void sortdata(int *arr,int count);
void swap(int *a,int *b);
int main()
{
	int count,arr[100];
	cout << "\nEnter the count of array:";
	cin >> count;
	getdata(arr,count);
	printdata(arr,count);
	sortdata(arr,count);
	printdata(arr,count);
}
 void getdata(int *arr,int count)
{
	for(int i=0;i<count;i++)
	{
		cin >> arr[i];
	}
}
void printdata(int * arr,int count)
{
	cout << "\nEntered data:";
	for(int i=0;i<count;i++)
	{
		cout << arr[i] << " ";
	}
}
void sortdata(int *arr,int count)
{
	int i,j,min;
	for(i=0;i<count-1;i++)
	{
		min=i;
		for(j=i+1;j<count;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		swap(&arr[i],&arr[min]);
	}
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

