#include<iostream>
#include<string>
#include<vector>
using namespace std;
string binary(int num){
	vector<char> temp;
	string binnum,padding;
	while(num!=0){
		if(num%2==0) temp.push_back('0');
		else temp.push_back('1');
		num/=2;
	}
	while(!temp.empty()){
		binnum+=temp[temp.size()-1];
		temp.pop_back();
	}
	if(binnum.length()<16){
		for(int i=1;i<=16-binnum.length();i++)
			padding+='0';
		padding+=binnum;
		binnum=padding;
	}
	return binnum;
}
string possible(int a,int b){
	string bin1=binary(a),bin2=binary(b),temp;
	for(int i=0;i<16;i++){
		temp=bin1[0];
		bin1=bin1.substr(1,bin1.length()+1);
		bin1+=temp;
		if(bin1.compare(bin2)==0)
			return "YES";
	}
	return "NO";
}
int main(){
	int n,number1,number2;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>number1>>number2;
		cout<<possible(number1,number2)<<endl;
	}
	return 0;
}