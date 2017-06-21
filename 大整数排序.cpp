#include<iostream>
#include<string>
using namespace std;
int bigger(string a,string b){//比较字符串大小
	int lengtha=a.length(),lengthb=b.length();
	if(lengtha>lengthb)
		return 1;
	else if(lengtha<lengthb)
		return 0;
	else{
		for(int i=0;i<lengtha;i++){
			if(a[i]<b[i]){
				return 0;
			}
			if(a[i]>b[i])
				return 1;
		}
		return 2;
	}
}
void qsort(string a[],int low,int high){//快排
	if(low>=high)return;
	string mid=a[(low+high)/2];
	int i=low,j=high;
	while(i<j){
		while(bigger(a[i],mid)==0)i++;
		while(bigger(a[j],mid)==1)j--;
		if(i<=j)
			swap(a[i++],a[j--]);
	}
	qsort(a,low,j);
	qsort(a,i,high);
}
int main(){
	int n;
	cin>>n;
	string number[102];
	for(int i=0;i<n;i++)
		cin>>number[i];
	qsort(number,0,n-1);
	for(i=0;i<n;i++)
		cout<<number[i]<<endl;
	return 0;
}