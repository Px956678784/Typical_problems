#include<iostream>
using namespace std;
typedef struct Listnode{//链表结构
	int val;
	Listnode *next;
}Listnode,*List;
void init(Listnode *head){//初始化链表
	Listnode *curr,*newnode;
	head->val=1;head->next=NULL;
	curr=head;
	for(int i=2;i<=5;i++){
		newnode=(List)malloc(sizeof(Listnode));
		newnode->val=i;	newnode->next=NULL;
		curr->next=newnode;
		curr=curr->next;
	}
}
void rotate(Listnode *head,int k){//旋转链表
	int n=0;
	Listnode *curr=head,*oldhead,*tail;
	while(curr!=NULL){//统计链表长度
		n++;
		curr=curr->next;
	}
	curr=head;
	if(k>=n && n!=0)
		k=k%n;//防止回旋长度超过长度
	if(k==0) return;
	k=n-k;//要从前到后找到后k位的开头
	for(int i=0;i<k-1;i++)curr=curr->next;
		tail=curr;//保存新的尾
	oldhead=head;
	curr=curr->next;
	head=curr;//把后k位的开头作为链表头
	tail->next=NULL;//尾部指向null
	while(curr->next!=NULL)curr=curr->next;
	curr->next=oldhead;//链表尾连接上原来的头
	curr=head;
	while(curr!=NULL){
		cout<<curr->val<<" ";
		curr=curr->next;
	}
}
int main(){
	int k;
	Listnode *head;
	head=(List)malloc(sizeof(Listnode));//必须提前分配空间，要不然主函数找不回来
	init(head);//初始化
	cin>>k;
	rotate(head,k);
	return 0;
}