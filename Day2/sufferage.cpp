#include<bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > matrix;
int main()
{
	ifstream fin;
	fin.open("input_sufferage.txt");
	int m,n;
	fin>>m>>n;
	int ect[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			fin>>ect[i][j];
		}
	}
	int scheduled[m],busy_wait[n];
	memset(scheduled,0,sizeof(scheduled));
	memset(busy_wait,0,sizeof(busy_wait));
	int jobs_assigned = 0;
	while(jobs_assigned<m)
	{
		int sufferage[m],assigned_server[m];
		for(int i=0;i<m;i++)
		{
			if(scheduled[i]==0)
			{
				int min_time=ect[i][0] + busy_wait[0];
				int _2nd_min_time = INT_MAX;
				assigned_server[i] = 0;
				for(int j=1;j<n;j++)
				{
					if(ect[i][j]+busy_wait[j] < min_time)
					{
						min_time = ect[i][j]+busy_wait[j];
						assigned_server[i] = j;
					}
				}
				for(int j=0;j<n;j++)
				{
					if(ect[i][j]+busy_wait[j] < _2nd_min_time && j!=assigned_server[i])
						_2nd_min_time = ect[i][j] + busy_wait[j]; 
				}
				sufferage[i] = _2nd_min_time - min_time;
			}
			else
			{
				sufferage[i] = INT_MIN;
			}
		}
		int overall_max = -1;
		int task =0;
		for(int i=0;i<m;i++)
		{
			if(scheduled[i]==0)
			{
				if(overall_max < sufferage[i])
					{overall_max = sufferage[i];task =i;}
			}
		}
		cout<<"task "<<task+1<<" is assigned to server "<<assigned_server[task]+1<<"\n";
		scheduled[task] =1;
		busy_wait[assigned_server[task]]+=ect[task][assigned_server[task]];
		jobs_assigned++;
	}
	int max_t = busy_wait[0];
	for(int i=0;i<n;i++)
	{
		if(max_t < busy_wait[i])
			max_t=busy_wait[i];
	}
	cout<<"total time = "<<max_t;
}