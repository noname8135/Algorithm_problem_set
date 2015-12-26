#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

struct graph{
	int value;
	graph* next;
};

int end_point;

int search(graph point[200], int start, int n){ //return the point with the max distance
	int i, distance[200],a,b;
	int in_queue[200];	//in queue count
	graph* walker;
	queue <int> Q;
	Q.push(start);
	for(i=1;i<=n;i++)
		distance[i] = in_queue[i] = 0;
	in_queue[start] = 1;

	while(!Q.empty()){
		a = Q.front(); Q.pop();
		if(--in_queue[a] > 0)
			continue;
		for(walker = (&(point[a]))->next; walker; walker=walker->next){
			b = walker->value;
			if(distance[b] < distance[a]+1){
				distance[b] = distance[a]+1;
				Q.push(b);
				in_queue[b]++;
			}
		}
		queue <int> tmp(Q);
	}
	int max=0;
	end_point = start;
	for(i=1;i<=n;i++)
		if(distance[i]>max || (distance[i]==max && i<end_point)){
			max = distance[i];
			end_point = i;
		}
	if(max == 0)
		end_point = start;
	return max;
}

int main(){
	int n=0,v,u,i,j,tmp;
	int start,point_num;
	graph point[200],*walker;
	graph* tail[200];

	while(scanf("%d",&point_num) && point_num){
		cin >> start;
		for(j=1;j<=point_num;j++){
			point[j].value = j;
			point[j].next = NULL;
			tail[j] = &(point[j]);
		}
		while(scanf("%d %d",&v,&u)){
			if(v==0 && u==0)
				break;
			else if(v == u)
				continue;
			tail[v]->next = new graph;
			tail[v] = tail[v]->next;
			tail[v]->value = u;
			tail[v]->next = NULL;
		}
		int max = search(point,start,point_num);
		cout << "Case " << ++n <<": The longest path from " << start << " has length " << max << ", finishing at " << end_point << ".\n\n";
	}
	return 0;
}