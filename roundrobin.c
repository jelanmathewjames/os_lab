#include <stdio.h>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

struct process{
	char name[5];
	int at, bt, tt, ct, wt, rt,status;
}p[10];
int queue[10],rear = -1,front= -1;

void enqueue(int ele){
    if((rear+1)%10==front){
        printf("full at%d",rear);
        printf("Queue is full");
    }
    else{
        if(front == -1)
            front = 0;
        rear = (rear+1)%10;
        queue[rear] = ele;
     }   
	
}
int dequeue(){
    int temp;
    if(rear == -1)
		return -1;
    else if(front == rear) {
        temp =queue[front];
        front = -1; rear = -1;  
        return temp;  
    }
	else {
        temp = queue[front];
        front = (front+1)%10;
        return temp;
    }
}
int main(){
	int limit, min, curr_t=0, no_itr=0, i, k, qt,eq=0;
	float avwt,avtt;
	printf("\nEnter the time slice");
	scanf("%d", &qt);
	printf("\nEnter number of process\n(space allocated only for 10 processes)");
	printf("\nEnter process in order");
	scanf("%d",&limit);
	for(i=0;i<limit;i++){
		p[i].name[0] = 'p' ; p[i].name[1] = i+'0';
		printf("\nEnter arrival time of p%d: ",i); 
		scanf("%d",&p[i].at);
		printf("\nEnter burst time of process: ");
		scanf("%d",&p[i].bt);
		p[i].rt = p[i].bt;
		p[i].status = 0;
	}
	while(no_itr<limit){
		min=0;
		if((k=dequeue())==-1){
			for(i=0;i<limit;i++){
				if(p[i].at<p[min].at&&curr_t<p[i].at&&!p[i].status)
					min=i;
				if(p[i].at<=curr_t&&!p[i].status){
					enqueue(i);
					p[i].status = 1;
					eq++;				
				}
			}
		}
		if(eq == 0 && k==-1){
			p[min].status = 1;
			k = min;
		}else if(eq !=0 && k==-1)
			k = dequeue();
		if(p[k].rt > qt){
			p[k].rt -= qt;
			curr_t = curr_t>p[k].at
					?curr_t+qt :p[k].at+qt;	
		}
		else{
			curr_t = curr_t>p[k].at
					?curr_t+p[k].rt :p[k].at+p[k].rt;
			p[k].rt = 0;
			p[k].ct = curr_t;
			p[k].tt = curr_t-p[k].at;
			p[k].wt = p[k].tt - p[k].bt;
        	no_itr++;
		}
		for(i=0;i<limit;i++){
          if(p[i].status==0 && p[i].at<=curr_t){
            enqueue(i);
            p[i].status = 1;
          }
        }
        p[k].rt!=0?enqueue(k):NULL;	
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
