#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

struct process{
	int id;
	int arrivalTime,burstTime,remaining,completionTime;
	int taTime,waitTime;
};

bool comp(process a,process b){
    if(a.arrivalTime==b.arrivalTime)
        return a.id<b.id;
    return a.arrivalTime<=b.arrivalTime;
}

static int timeQuantum=2;
int main(int argc, char const *argv[])
{
	int n;
	cout<<"\nEnter number of processes :";
	cin>>n;
	process p[n];

	cout<<"\nEnter the arrival time and burst time for processes :";

	for(int i=0;i<n;i++){
		p[i].id=i+1;
		cout<<"\nProcess "<<i+1<<" : ";
		cin>>p[i].arrivalTime>>p[i].burstTime;
		p[i].remaining=p[i].burstTime;
	}

	sort(p,p+n,comp);

	int time=0;
	list<process* >done;
	deque<process* > q;
	int gchart[100]={1};
	int gcount=1;

	while(true){
		if(time==p[0].arrivalTime){
			process* prun=p;
			q.push_back(prun);
			break;
		}
		else
			time++;
	}

	int i=1;
	while(!q.empty()){


		process *ready=q.front();
		q.pop_front();
		gchart[gcount++]=ready->id;

		if(ready->remaining>=timeQuantum){
			ready->remaining-=2;
			time+=2;
		}
		else if(ready->remaining<timeQuantum){
			time+=ready->remaining;
			ready->remaining=0;
		}

		while(time >= p[i].arrivalTime){
			process *prun=p+i;
			q.push_back(prun);
			i++;
		}
		if(ready->remaining==0){
			ready->completionTime=time;
			ready->taTime=(ready->completionTime)-(ready->arrivalTime);
			ready->waitTime=(ready->taTime)-(ready->burstTime);


		}
		else
			q.push_back(ready);

	}

	/*
	cout<<"\nOUTPUT\n";
    cout<<setw(10)<<"Process ID "<<setw(17)<<"Arrival Time(msec) "<<setw(17)<<"Burst Time(msec)  "<<setw(17)<<"Completion Time(msec)  "<<setw(17)<<"Waiting Time(msec)  "<<setw(17)<<"TA Time(msec)\n";
	for(int i=0;i<n;i++)
	{
		cout<<setw(10)<<p[i].id <<setw(17)<<p[i].arrivalTime <<setw(17)<<p[i].burstTime <<setw(17)<<p[i].completionTime<<setw(17)<<p[i].waitTime <<setw(17)<<p[i].taTime;

		cout<<endl;
	}*/

	cout<<"\n\nGaint chart:\n";

	int x=0;
	while((x++)<gcount-1)
		cout<<"P"<<gchart[x]<<" -> ";


	return 0;
}
/*input
Process Id	Arrival time	Burst time
P1	                   0	5
P2	                   1	3
P3	                   2	1
P4	                   3	2
P5	                   4	3

5
0 5
1 3
2 1
3 2
4 3

6
0 4
1 5
2 2
3 1
4 6
6 3

output:
gchart: 1 2 3 1 4 5 2 1 5
*/
