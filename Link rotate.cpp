#include<iostream>
using namespace std;
typedef struct Listnode{//����ṹ
	int val;
	Listnode *next;
}Listnode,*List;
void init(Listnode *head){//��ʼ������
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
void rotate(Listnode *head,int k){//��ת����
	int n=0;
	Listnode *curr=head,*oldhead,*tail;
	while(curr!=NULL){//ͳ��������
		n++;
		curr=curr->next;
	}
	curr=head;
	if(k>=n && n!=0)
		k=k%n;//��ֹ�������ȳ�������
	if(k==0) return;
	k=n-k;//Ҫ��ǰ�����ҵ���kλ�Ŀ�ͷ
	for(int i=0;i<k-1;i++)curr=curr->next;
		tail=curr;//�����µ�β
	oldhead=head;
	curr=curr->next;
	head=curr;//�Ѻ�kλ�Ŀ�ͷ��Ϊ����ͷ
	tail->next=NULL;//β��ָ��null
	while(curr->next!=NULL)curr=curr->next;
	curr->next=oldhead;//����β������ԭ����ͷ
	curr=head;
	while(curr!=NULL){
		cout<<curr->val<<" ";
		curr=curr->next;
	}
}
int main(){
	int k;
	Listnode *head;
	head=(List)malloc(sizeof(Listnode));//������ǰ����ռ䣬Ҫ��Ȼ�������Ҳ�����
	init(head);//��ʼ��
	cin>>k;
	rotate(head,k);
	return 0;
}