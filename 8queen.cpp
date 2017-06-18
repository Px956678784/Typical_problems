#include<iostream>
#include<string>
using namespace std;
int chessboard[8][8],sum=0;
string queen,answer[100];
void chess(int raw){
	if(queen.length()==8){
		sum++;
		answer[sum]=queen;
		return;
	}
	else{
		for(int i=0;i<8;i++){
			if(chessboard[raw][i]==0){
				queen+=char(i+49);
				for(int j=0;j<8;j++){
					chessboard[j][i]++;
				}
				for(j=1;j<8;j++){
					if(raw+j<8 && i+j<8) chessboard[raw+j][i+j]++;
					if(raw+j<8 && i-j>=0) chessboard[raw+j][i-j]++;
					if(raw-j>=0 && i-j>=0) chessboard[raw-j][i-j]++;
					if(raw-j>=0 && i+j<8) chessboard[raw-j][i+j]++;
				}
/*				cout<<raw<<i<<endl;
				for(int k=0;k<8;k++){
					for(int t=0;t<8;t++)
						cout<<chessboard[k][t]<<" ";
					cout<<endl;
				}
				cout<<queen<<endl;
				system("pause");*/
				chess(raw+1);
				for(j=1;j<8;j++){
					if(raw+j<8 && i+j<8) chessboard[raw+j][i+j]--;
					if(raw+j<8 && i-j>=0) chessboard[raw+j][i-j]--;
					if(raw-j>=0 && i-j>=0) chessboard[raw-j][i-j]--;
					if(raw-j>=0 && i+j<8) chessboard[raw-j][i+j]--;
				}
				for(j=0;j<8;j++)
					chessboard[j][i]--;
				queen=queen.substr(0,queen.length()-1);
			}
		}
	}
}
int main(){
	int n;
	chess(0);
	while(cin>>n)
		cout<<answer[n]<<endl;
	return 0;
}