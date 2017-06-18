#include<iostream>
#include<queue>
using namespace std;
int *tree,n;
class wood{
public:
	int a;
	int b;
	int cost;
	bool operator<(const wood &b)const{
		return cost>b.cost;
	}
};
int find(int x){//是否成环
	int i=x;
	while(i!=tree[i]) i=tree[i];
	int t;
	while(i!=tree[x]){
		t=tree[x];
		tree[x]=i;
		x=t;
	}
	return i;	
}
void united(int a,int b){//将其两个根部归为一类!!!!
	a=find(a);
	b=find(b);
	if(a!=b)
		tree[a]=b;
}
int krus(priority_queue<wood> &roads){
	int max=0;
	wood now;
	while(!roads.empty()){
		now=roads.top();
		roads.pop();
		if(find(now.a)!=find(now.b)){
			united(now.a,now.b);
			if(now.cost>max)
				max=now.cost;
		}
	}
	return max;
}
int main(){
	int m;
	priority_queue<wood> roads;
	cin>>n>>m;
	tree=new int[n+1];
	for(int i=1;i<=n;i++)//每一点只和自己相连
		tree[i]=i;
	for(i=0;i<m;i++){//存储边
		wood temp;
		cin>>temp.a>>temp.b>>temp.cost;
		roads.push(temp);
	}
	cout<<krus(roads)<<endl;
	return 0;
}