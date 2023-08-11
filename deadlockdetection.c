#include <stdio.h>
int main(){
	int alloc[50][10],avail[10],finish[50],req[50][10];
	int r,p,i,j,curr=0,prev=0,poss;
	printf("\nEnter the number of resource : ");
	scanf("%d",&r);
	printf("\nEnter the number of process : ");
	scanf("%d",&p);
	printf("\nEnter available resources : ");
	for(i=0;i<r;i++)
		scanf("%d",&avail[i]);
	printf("\nEnter allocated resources : ");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	printf("\nEnter request resources : ");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&req[i][j]);
	for(i=0;i<p;i++)
		finish[i] = 0;
	while(1){
		for(i=0;i<p;i++){
			if(finish[i] == 0){
				poss=1;
				for(j=0;j<r;j++)
					if(avail[j]<req[i][j]){
						poss=0; break;
					}
			}
			if(poss==1){
				for(j=0;j<r;j++)
					avail[j]+= alloc[i][j];
				finish[i] = 1;
				curr++; poss = 0;
			}
		}
		if(curr==p){
			printf("THERE IS NO DEADLOCK IN THE GIVEN SYSTEM");
			break;
		}
		else if(curr==prev){
			printf("THE SYSTEM IS IN A DEADLOCKED STATE");
			break;
		}
		else if(curr>prev)
			prev=curr;
	}
}
	
