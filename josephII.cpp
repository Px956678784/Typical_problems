#include<iostream>
using namespace std;
class node{
public:
	int val;
	node *next;
	node(const int &element,node *nextval=NULL){
		val=element;
		next=nextval;
	}
	node(node *nextval=NULL){
		next=nextval;
	}
};
int main(){
	int n,m,cnt=1,sum;
	cin>>n>>m;
	node *head;
	node *curr;
	head=new node;
	curr=head;
	for(int i=1;i<=n;i++){
		curr->next=new node(i);
		curr=curr->next;
	}
	curr->next=head->next;
	curr=head;
	sum=n;
	while(sum!=1){
		if(cnt==m){
			curr->next=curr->next->next;
			cnt=1;sum--;
		}
		else{
			curr=curr->next;
			cnt++;
		}
	}
	cout<<curr->next->val<<endl;
	return 0;
}