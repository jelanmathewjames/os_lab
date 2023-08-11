#include <stdio.h>
int main(){
	int alloc[50][10],avail[10],need[50][10],max[50][10];
	int r,p,i,j,s,curr=0,prev=0,poss,finish[50],safe[10];
	printf("Enter the number of resource : \n");
	scanf("%d",&r);
	printf("Enter the number of process : \n");
	scanf("%d",&p);
	printf("Enter available resources : \n");
	for(i=0;i<r;i++)
		scanf("%d",&avail[i]);
	printf("Enter allocated resources : \n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	printf("Enter max resources : \n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	for(i=0;i<p;i++)
		finish[i] = 0;
	while(1){
		for(i=0;i<p;i++){
			if(finish[i] == 0){
				poss=1;
				for(j=0;j<r;j++)
					if(avail[j]<need[i][j]){
						poss=0; break;
					}
			}
			if(poss==1){
				for(j=0;j<r;j++)
					avail[j]+= alloc[i][j];
				safe[s++]=i;
				finish[i] = 1;
				curr++; poss = 0;
			}
		}
		if(curr==p){
			printf("THERE IS NO DEADLOCK IN THE GIVEN SYSTEM\n");
			printf("SAFE SEQUENCE\n");
			for(i=0;i<s;i++)
        		printf("%d => ",safe[i]);
			break;
		}
		else if(curr==prev){
			printf("THE SYSTEM IS IN A DEADLOCKED STATE\n");
			break;
		}
		else if(curr>prev)
			prev=curr;
	}
}
