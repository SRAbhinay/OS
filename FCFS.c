#include<stdio.h>
void waittime(int pro[], int n, int bt[], int wt[])
{
	wt[0] = 0;
	for (int i = 1; i < n ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}
void tatime( int pro[], int n, int bt[], int wt[], int tat[])
{
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
void findavgTime( int pro[], int n, int bt[])
{
	int wt[n], tat[n], tt_wt = 0, tt_tat = 0;
	waittime(pro, n, bt, wt);
	tatime(pro, n, bt, wt, tat);
	printf("pro Burst time WT TAT\n");
	for (int i=0; i<n; i++)
	{
		tt_wt = tt_wt + wt[i];
		tt_tat = tt_tat + tat[i];
		printf(" %d ",(i+1));
		printf("	 %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	 %d\n",tat[i] );
	}
	int s=(float)tt_wt / (float)n;
	int t=(float)tt_tat / (float)n;
	printf("Average WT = %d",s);
	printf("\n");
	printf("Average TAT = %d ",t);
}
int main()
{
	int pro[] = { 1, 2, 3};
	int n = sizeof pro / sizeof pro[0];
	int burst_time[] = {10, 5, 8};
	findavgTime(pro, n, burst_time);
	return 0;
}
