#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m=3,n=2;
	int A[m][n]={{140,100},{20,100},{60,70}};
	int assigned[m],waiting[n];
	memset(assigned,0,sizeof(assigned));
	memset(waiting,0,sizeof(waiting));
	int count = 0;
	while(count<m)
	{
		int min_t[m],assigned_server[m];
		for(int i=0;i<m;i++)
		{
			if(assigned[i]==0)
			{
				int min_time=A[i][0] + waiting[0];
				assigned_server[i] = 0;
				for(int j=1;j<n;j++)
				{
					if(A[i][j]+waiting[j] < min_time)
					{
						min_time = A[i][j]+waiting[j];
						assigned_server[i] = j;
					}
				}
				min_t[i] = min_time;
			}
			else
			{
				min_t[i] = INT_MAX;
			}
		}
		int overall_min = min_t[0];
		int task =0;
		for(int i=0;i<m;i++)
		{
			if(assigned[i]==0)
			{
				if(overall_min > min_t[i])
					{overall_min = min_t[i];task =i;}
			}
		}
		cout<<task+1<<" to machine number "<<assigned_server[task]+1<<"\n";
		assigned[task] =1;
		waiting[assigned_server[task]]+=A[task][assigned_server[task]];
		count++;
	}
	int max_t = waiting[0];
	for(int i=0;i<n;i++)
	{
	
		if(max_t < waiting[i])
			max_t=waiting[i];
	}
	cout<<"Makespan = "<<max_t;
}
