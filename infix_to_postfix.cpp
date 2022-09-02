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

int prec(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

string infixToPostfix(string s){
	stack st;
	string res;
	
	for(int i=0;i<s.length();i++){
		
		if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
			res+=s[i];
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty() && st.Top()!='('){
				res+=st.Top();
				st.pop();
			}
			if(!st.empty()){
				st.pop();
			}
		}
		else{
			while(!st.empty() && prec(st.Top())>prec(s[i])){
				res+=st.Top();
				st.pop();
		    }
		    st.push(s[i]);
		}
		
	}
	while(!st.empty()){
		res+=st.Top();
		st.pop();
	}
	return res;
}

int main(){
	
	cout<<infixToPostfix("(a-b/c)*(a/k-l)");
	
	return 0;
}