#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> answer;
void move(string left,string right){
	string temp="move from "+left+" to "+right;
	answer.push_back(temp);
}
void hanoi(int n,string left,string mid,string right){
	if(n==1) move(left,right);
	else{
		hanoi(n-1,left,right,mid);
		move(left,right);
		hanoi(n-1,mid,left,right);
	}
}
int main(){
	int n;
	cin>>n;
	string left="left",mid="mid",right="right";
	hanoi(n,left,mid,right);
	for(vector<string>::iterator iter1=answer.begin(); iter1!=answer.end(); ++iter1 ){
        for(size_t sty=0;sty!=(*iter1).size(); sty++){
            cout<<(*iter1)[sty] ; //*iter1才是string数据
        }
        cout <<endl ;
    }
	return 0;
}