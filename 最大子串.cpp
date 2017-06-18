#include<iostream>
#include<string>
using namespace std;
int find(string A,string B,int n,int m){
	int i,j,max[302][302];
for(i=0;i<=n;i++)
	max[i][0]=0;
	for(j=0;j<=m;j++)
		max[0][j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(A[i-1]==B[j-1]){
			cout<<i<<j<<endl;
				max[i][j]=max[i-1][j-1]+1;
			}
			else
				max[i][j]=(max[i-1][j]>max[i][j-1])?max[i-1][j]:max[i][j-1];
			
	for(i=0;i<=n;i++){
	for(j=0;j<=m;j++)
		cout<<max[i][j]<<" ";
	cout<<endl;
			}
	return max[n][m];
}
int main(){
	string A,B;
	int n,m;
	cin>>A>>n>>B>>m;
	cout<<find(A,B,n,m)<<endl;
return 0;
}