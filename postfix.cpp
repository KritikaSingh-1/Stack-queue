#include<iostream>
#include<math.h>
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

int postfixEvaluation(string s){
	stack st;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]-'0');
		}
		else{
			int op2=st.Top();
			st.pop();
			int op1=st.Top();
			st.pop();
			
			switch(s[i])
			{
				case '+':st.push(op1+op2);
				break;
				
				case '-':st.push(op1-op2);
				break;
				
				case '/':st.push(op1/op2);
				break;
				
				case '*':st.push(op1*op2);
				break;
				
				case '^':st.push(pow(op1,op2));
				break;
				
				
			}
		}
	}
	
	return st.Top();
}

int main(){
	cout<<postfixEvaluation("46+2/5*2^")<<endl;
	
	return 0;
}