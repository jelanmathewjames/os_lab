#include <stdio.h>

struct process{
	char name[5];
	int at, bt, tt, ct, st, wt, status;
}p[10], temp;

int main(){
	int limit, min, curr_t=0, no_itr=0, i, j;
	float avwt,avtt;
	printf("\nEnter number of process\n(space allocated only for 10 processes)");
	scanf("%d",&limit);
	for(i=0;i<limit;i++){
		p[i].name[0] = 'p' ; p[i].name[1] = i+'0';
		printf("\nEnter arrival time of p%d: ",i); 
		scanf("%d",&p[i].at);
		printf("\nEnter burst time of process: ");
		scanf("%d",&p[i].bt);
		p[i].status = 0;
	}
	while(no_itr<limit){
		min=0;
		for(i=0; i<limit; i++)
			if(!p[i].status){
				if(curr_t>=p[i].at && curr_t>=p[min].at && p[min].bt > p[i].bt)
					min=i;
				else if(p[min].at > p[i].at)
					min=i;
				else if(p[min].at==p[i].at && p[min].bt > p[i].bt || p[min].status)
					min=i;
			}
		(p[i].at > curr_t)
    		? (p[i].ct = p[i].at + p[i].bt, curr_t = p[i].at + p[i].bt)
    		: (p[i].ct = curr_t + p[i].bt,  curr_t += p[i].bt);
		p[i].tt = p[i].ct-p[i].at;
		p[i].wt = p[i].tt-p[i].bt;
		p[min].status = 1;
		no_itr++;
	}
	printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n");
  	for(int i=0;i<limit;i++){
    	printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i].name,p[i].ct,p[i].wt,p[i].tt);
    	avwt+=p[i].wt;
    	avtt+=p[i].tt;
  	}
  	printf("\n\nAVERAGE WAITING TIME : %f",(avwt/limit));
  	printf("\nAVERAGE TURNAROUND TIME : %f\n",(avtt/limit));
}
