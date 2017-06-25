#include<iostream>
using namespace std;
typedef struct node{
	int val;
	node *next;
}*pnode;
pnode head;
pnode curr;
int joseph(int n){
	head=(struct node *)malloc(sizeof(*head));
	curr=head;
	for(int i=1;i<=n;i++){
		pnode newnode=NULL;
		newnode=(struct node *)malloc(sizeof (*newnode));
		newnode->val=i;
		newnode->next=NULL;
		curr->next=newnode;
		curr=curr->next;
	}
	curr->next=head->next;
	curr=head;
	int sum=n,fence=2,cnt;
	while(sum!=1){
		cnt=1;
		do{
			if(cnt!=1){
				curr->next=curr->next->next;
				sum--;
			}
			else
				curr=curr->next;
			if(cnt==fence)
				cnt=1;
			else
				cnt++;
		}while(curr->next!=head->next);
		head->next=curr;
		curr=head;
		fence++;
	}
	return head->next->val;
}
int main(){
	int n;
	cin>>n;	
	cout<<joseph(n)<<endl;
	return 0;
}