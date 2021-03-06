#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int q[20], top=-1,front = -1, rear=-1, a[20][20], vis[20], stack[20];
int del();

void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();
int main() {
	system("title Program DFS dan BFS");
	system("color f1");
	int n,i,s,ch,j;
	char c,dummy;
	printf("Masukan Angka : ");
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		for(j=1; j <= n; j++){
			printf("Masukan 1 jika %d terhubung dengan %d selain itu masukan 0",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nMatriks Adjensi\n");
	for(i=1; i<=n; i++){
		for(j=1; j <= n; j++){
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	do{
		for(i=1;i<=n;i++)
			a: vis[i]=0;
		printf("\nMenu");
		printf("\n1. BFS");
		printf("\n1. DFS");
		printf("\n1. Pilihan: ");
		scanf("%d",&ch);
		printf("\nMasukan Simpul Sumber: ");
		scanf("%d",&s);
		switch(ch){
			case 1:bfs(s,n);
			break;
			case 2:dfs(s,n);
			break;
		}
		printf("\nApakah Ingin Melanjutkan ? (Y/N): ");
		scanf("%c",&dummy);
		scanf("%c",&c);
		
		 }
 		while((c == 'y')||(c =='Y'));
 
}

void bfs(int s, int n){
	int p,i;
	add(s);
	vis[s]=1;
	p=del();
	if(p!=0)
		printf("%d",p);
	while(p!=0){
		for(i=1;i<=n;i++)
			if((a[p][i] != 0)&&(vis[i]==0)){
				add(i);
				vis[i]=1;
			}
			p=del();
			if(p!=0)
				printf("%d",p);
	}
	for(i=1;i<=n;i++)
		if(vis[i] == 0)
			bfs(i,n);
}
void add(int item){
	if(rear==19)
		printf("Antrian Full");
	else
		if(rear==-1){
			q[++rear]=item;
			front++;
		}
		else
			q[++rear]=item;
}
int del(){
 	int k;
 	if ((front > rear) || (front == -1))
 		return (0);
	else {
		k = q[front++];
		return (k);
	} 
 }
 void dfs(int s, int n) {
 	 int i, k;
 	 push(s);
 	 vis[s] = 1;
 	 k = pop();
 	if (k != 0)
 	 	printf("%d ", k);
 	while (k != 0) {
 		for (i = 1; i <= n; i++)
 		if ((a[k][i] != 0) && (vis[i] == 0)){
 			push(i);
 			vis[i] = 1;	
		 }
		k = pop();
		if (k != 0)
			printf("%d ", k);
	 }
	 for (i = 1; i <= n; i++)
	 	if (vis[i] == 0)
			dfs(i, n);
 }
 void push(int item){
 	if (top == 19)
 		printf("stack overflow");
 	else
 		stack[++top] = item;
 }
 int pop() {
 	int k;
 	if (top == -1)
 		return(0);
 	else {
 		k = stack[top--];
 		return(k);
	 }
 }
