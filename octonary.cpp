#include<iostream>
#include<string>
#include<vector>
using namespace std;
string octonary(int n){
	vector<char> temp;
	string answer;
	while(n!=0){
		temp.push_back(n%8+48);
		n=n/8;
	}
	while(!temp.empty()){
		answer+=temp[temp.size()-1];
		temp.pop_back();
	}
	return answer;
}
int main(){
	int n;
	cin>>n;
	cout<<octonary(n)<<endl;
	return 0;
}