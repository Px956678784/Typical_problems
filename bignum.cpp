#include<iostream>
#include<string>
using namespace std;
int justify(string &num1,string &num2){
	if(num1.length()>num2.length())
		return 1;
	else if(num1.length()<num2.length()){
		swap(num1,num2);
		return 0;
	}
	else{
		for(int i=0;i<num1.length();i++){
			if(num1[i]>num2[i])
				return 1;
			if(num1[i]<num2[i]){
				swap(num1,num2);
				return 0;
			}
		}
		return 2;
	}
}

string minus(string num1,string num2){//减法
	int i1=num1.length()-1,i2=num2.length()-1;
	while(i1>=0 && i2>=0){
		int subtrahend=int(num1[i1]-'0'),
			minuend=int(num2[i2]-'0');
		if(subtrahend>=minuend)
			subtrahend-=minuend;
		else{//0不能借位，直到找到可以借位的,借位后0全部变成9
			int j=i1-1;
			while(num1[j]=='0'){
				num1[j]='9';
				j--;
			}
			num1[j]--;
			subtrahend=subtrahend+10-minuend;
		}
		num1[i1]=char(subtrahend+'0');
		i1--;i2--;
	}
	for(int i=0;i<num1.length() && num1[i]=='0';i++);
	num1=num1.substr(i,num1.length()+1);
	return num1;
}

string plus(string num1,string num2){
	int i1=num1.length()-1,i2=num2.length()-1;
	while(i1>=0 && i2>=0){
		int addend1=int(num1[i1]-'0'),
			addend2=int(num2[i2]-'0');
		if(addend1+addend2<10)
			addend1+=addend2;
		else{
			int j=i1-1;
			while(j>=0 && num1[j]=='9'){
				num1[j]='0';
				j--;
			}
			if(j<0){
				string temp=num1;
				num1='1';
				num1+=temp;
				i1++;
			}
			else
				num1[j]++;
			addend1=addend1+addend2-10;
		}
		num1[i1]=char(addend1+'0');
		i1--;i2--;
	}
	return num1;
}
int main(){
	string num1,num2,result;
	int positive;
	cin>>num1>>num2;
	if(num1[0]=='-' && num2[0]!='-'){
		num1=num1.substr(1,num1.length()+1);
		positive=justify(num1,num2);
		if(positive==2)
			result='0';
		else{			
			if(positive==1) result='-';
			result+=minus(num1,num2);
		}
	}
	else if(num1[0]!='-' && num2[0]=='-'){
		num2=num2.substr(1,num2.length()+1);
		positive=justify(num1,num2);
		if(positive==2)
			result='0';
		else{			
			if(positive==0) result='-';
			result+=minus(num1,num2);
		}
	}
	else if(num1[0]=='-' && num2[0]=='-'){
		num1=num1.substr(1,num1.length()+1);
		num2=num2.substr(1,num2.length()+1);
		positive=justify(num1,num2);
		result='-';
		result+=plus(num1,num2);
	}
	else{
		positive=justify(num1,num2);
		result=plus(num1,num2);
	}
	cout<<result<<endl;
	return 0;
}