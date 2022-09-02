#include<bits/stdc++.h>
using namespace std;

class stack1{
   int N;
	
	queue<int> q1;
	queue<int> q2;
	
	
	public:
		
		stack1(){
		N=0;
	}
	
		void push(int x){
			q2.push(x);
			N++;
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			
			queue<int> temp=q1;
			q1=q2;
			q2=temp;
		}
		
		void pop(){
			if(q1.empty()){
				cout<<"Stack is empty"<<endl;
				return;
			}
			q1.pop();
			N--;
		}
		
		int top(){
			return q1.front();
		}
		
		int size(){
			return N;
		}
};

int main(){
	stack1 s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	s.push(5);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	s.pop();
	cout<<s.size()<<endl;
	return 0;
}