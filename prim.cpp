#include<iostream>
using namespace std;
#define MAX 0xfffffff
class wood{
public:
	int a;
	int b;
	int cost;
};
int m,*lowcost,n;
wood *roads;
int prim(){
	int max=0,sum=0,min,minN;
	lowcost[1]=0;
	for(int i=0;i<m;i++){
		if(roads[i].a==1)
			lowcost[roads[i].b]=roads[i].cost;
		else if(roads[i].b==1)
			lowcost[roads[i].a]=roads[i].cost;
	}
	while(sum<n-1){
		min=MAX;
		for(i=1;i<=n;i++)
			if(lowcost[i]!=0 && lowcost[i]<min){ //寻找与树相邻点中的最小值
				min=lowcost[i];
				minN=i;
			}
		if(min==MAX)
			return max;
		else{
			if(min>max)
				max=min;
			sum++;
			lowcost[minN]=0;
			for(i=0;i<m;i++){
				if(roads[i].a==minN && roads[i].cost<lowcost[roads[i].b])
					lowcost[roads[i].b]=roads[i].cost;
				else if(roads[i].b==minN && roads[i].cost<lowcost[roads[i].a])
					lowcost[roads[i].a]=roads[i].cost;
			}
		}
	}
	return max;
}
int main(){
	cin>>n>>m;
	lowcost=new int[n+1];
	roads=new wood[m];
	for(int i=1;i<=n;i++)//初始到每点的距离都为无穷大
		lowcost[i]=MAX;
	for(i=0;i<m;i++){//存储边
		cin>>roads[i].a>>roads[i].b>>roads[i].cost;
	}
	cout<<prim()<<endl;
	return 0;
}