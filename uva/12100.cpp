#include <iostream>
#include <queue>

using namespace std;

struct JOB{
	int priority, id;
};

int main(){
	int priority_count[10],testcase=0,my_job,minute,i,n;	
	JOB job,next_print;
	cin >> testcase;
	while(testcase--){
		next_print.id = -1;
		minute = 0;
		queue <JOB> job_q;
		cin >> n >> my_job;
		for(i=1;i<=9;i++)
			priority_count[i] = 0;
		for(i=0;i<n;i++){
			cin >> job.priority;
			job.id = i;
			job_q.push(job);
			priority_count[job.priority]++;
		}
		while(true){
			next_print = job_q.front();
			job_q.pop();
			for(i=9;i>next_print.priority && priority_count[i]==0;i--)
				;
			if(i == next_print.priority){	// no other has higher priority, print this one
				minute++;
				if(next_print.id == my_job)
					break;
				priority_count[next_print.priority]--;
			}
			else
				job_q.push(next_print);
		}
		cout << minute << endl;
	}
	return 0;
}