#include<iostream>
using namespace std;
#define MAX 100000
bool *checked;
int *lowcost,**map,n,m;
int dijkstra(int start){
	int max=0,min,minN;
	lowcost[start]=0;
	checked[start]=true;
	for(int i=1;i<=n;i++){
			lowcost[i]=map[start][i];
			checked[i]=false;
	}
	for(i=1;i<=n;i++){
		min=MAX;
		for(int j=0;j<=n;j++)
			if(!checked[j] && lowcost[j]<min){ //寻找与树相邻点中的最小值
				min=lowcost[j];
				minN=j;
			}
		if(min==MAX) break;
		checked[minN]=true;//加入已选点集合
		for(j=0;j<=n;j++)
			if(!checked[j] && map[minN][j]<MAX && lowcost[minN]+map[minN][j]<lowcost[j])
					lowcost[j]=lowcost[minN]+map[minN][j];
	}
	return lowcost[n];
}
int main(){
	int x,y,cost;
	cin>>m>>n;
	lowcost=new int[n+1];
	checked=new bool[n+1];
	map=new int *[n+1];
	for(int i=0;i<=n;i++)
		map[i]=new int[n+1];
	for(i=0;i<=n;i++){//初始到每点的距离都为无穷大
		for(int j=0;j<=n;j++)
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=MAX;
	}
	for(i=0;i<m;i++){//存储边
		cin>>x>>y>>cost;
		map[x][y]=cost;
	}

	cout<<dijkstra(0)<<endl;
	return 0;
}