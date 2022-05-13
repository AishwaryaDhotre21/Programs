#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<algorithm>
using namespace std;
struct Job
{
	char id;
	int deadline;
	int profit;
};
bool comparison(Job a,Job b)
{
	return(a.profit > b.profit);
}
void printJobSchedue(Job arr[],int n)
{
	sort(arr,arr+n,comparison);
	cout << "\n\n\n Sorted data:\n\n";
	for(int i=0;i<n;i++)
	{
		cout << "\n\n**************************\n";
		cout << "\nID:" << arr[i].id;
		cout << "\nDeadline:" << arr[i].deadline;
		cout << "\nProfit:" << arr[i].profit;
	}
	int result[n];
	bool slot[n];
	for(int i=0;i<n;i++)
	{
		slot[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
		{
			if(slot[j]==false)	
			{
				slot[j]=true;
				result[j]=i;
				break;
			}
		}
	}
	cout  << "\n\n\nJob schedule:";
	for (int i=0; i<n; i++)
	if (slot[i])
		cout << arr[result[i]].id << " ";
}
int main()
{
	//	Job arr={{'a',2,100,},{'b',1,45},{'c',4,20}};
	Job arr[100];
	int count;
	cout << "\nEnter the count of jobs:";
	cin >> count;
	for(int i=0;i<count;i++)
	{
		cin >> arr[i].id;
		cin >> arr[i].deadline;
		cin >> arr[i].profit;
	}
	cout << "\nEntered data:";
	for(int i=0;i<count;i++)
	{
		cout << "\n\n**************************\n";
		cout << "\nID:" << arr[i].id;
		cout << "\nDeadline:" << arr[i].deadline;
		cout << "\nProfit:" << arr[i].profit;
	}
	int n=sizeof(arr)/sizeof(arr[0]);
	printJobSchedue(arr,count);
}
