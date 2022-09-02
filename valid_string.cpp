#include<iostream>
using namespace std;

#define n 100

class stack{
	int *arr;
	int top;
	
	public:
		stack(){
			arr=new int[n];
			top=-1;
		}
	
	void push(int x){
		if(top==n-1){
			cout<<"Stack overflow"<<endl;
			return;
			
		}
		top++;
		arr[top]=x;
	}
	
	void pop(){
		if(top==-1){
			cout<<"stack is empty"<<endl;
			return;
		}
		top--;
	}
	
	int Top(){
		if(top==-1){
			cout<<"stack is empty"<<endl;
			return -1;
		}
		return arr[top];
	}
	
	bool empty(){
		return top==-1;
	}
	
};

int valid(string s){
	stack st;
	bool ans=true;
	for(int i=0;i<s.length();i++){
		if(s[i]=='{' || s[i]=='(' || s[i]=='['){
			st.push(s[i]);
		}
		else if( s[i]==')'){
			if(!st.empty() && st.Top()=='('){
				st.pop();
			}
			else{
				ans=0;
				break;
			}
		}
		
		else if( s[i]=='}'){
			if(!st.empty() && st.Top()=='{'){
				st.pop();
			}
			else{
				 ans=0;
				 break;
			}
		}
		
		else if( s[i]==']'){
			if(!st.empty() && st.Top()=='['){
				st.pop();
			}
			else{
				 ans=0;
				 break;
			}
		}
		else{
			 ans=0;
			 break;
		}
	}
	
	if(!st.empty()){
		return 0;
	}
	
	return 1;
}

int main(){
	string s="{[()]}";
	if(valid(s)==1){
		cout<<"valid string"<<endl;
	}
	else{
		cout<<"invalid"<<endl;
	}
	return 0;
}