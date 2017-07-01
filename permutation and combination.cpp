#include<iostream>
using namespace std;
int ans,n,m,repeat[15];
int multiplity(int num){
	if(num==1 || num==0)return 1;
	return num*multiplity(num-1);
}
void select(int num,int sum,int repeatsum){
	if(sum>m)return;
	if(num==n){
		if(sum==m)
			ans+=multiplity(m)/repeatsum;
		return;
	}
	for(int i=0;i<=repeat[num];i++)
		select(num+1,sum+i,repeatsum*multiplity(i));
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;i++)
			cin>>repeat[i];
		ans=0;
		select(0,0,1);
		cout<<ans<<endl;
	}
return 0;
}