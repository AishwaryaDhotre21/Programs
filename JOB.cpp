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
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void 	printJobScheduling(Job arr[], int n)
{
	sort(arr,arr+n,comparison);
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
	for (int i=0; i<n; i++)
	if (slot[i])
		cout << arr[result[i]].id << " ";
}
int main()
{
	Job arr[]={{'a',2,100},{'b',3,12},{'c',4,50},{'d',3,25},{'e',6,20}};
	int n=sizeof(arr)/sizeof(arr[0]);
	printJobScheduling(arr, n);
}
