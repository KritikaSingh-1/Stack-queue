#include<iostream>
#include<string>
 using namespace std;
 
 class Stack{
 	private:
 		int top;
 		int arr[5];
 		
 	public:
	 Stack(){
	 	top=-1;
	 	for(int i=0;i<5;i++){
	 		arr[i]=0;
		 }
	 }
	 
	 bool isempty(){
	 	if (top==-1){
	 		return true;
		 }
		 else{
		 	return false;
		 }
	 }
	 
	 bool isfull(){
	 	if(top==4){
	 		return true;
		 }
		 else{
		 	return false;
		 }
	 }	
	 
	void  push(int val){
		if(isfull()){
			cout<<"stack overflow"<<endl;
		}
		else{
			top++;  //top=0
			arr[top]=val; //top[0]=val
		}
	}
	
	int pop(){
		if(isempty()){
			cout<<"stack underflow"<<endl;
			return 0;
		}
		else{
			int popvalue=arr[top];
			arr[top]=0;
			top--;
			return popvalue;
		}
	}
	
	int count(){
		return top+1;
	}
	
	int peek(int pos){
		if(isempty()){
			cout<<"stack underflow"<<endl;
			return 0;
		}
		else{
			return arr[pos];
		}
	}
	
	void change(int pos,int value){
		arr[pos]=value;
		cout<<"value change at location :"<<pos<<endl;
	}
	
	void display(){
		cout<<"all values in the stack are:"<<endl;
		for(int i=4;i>=0;i--){
			cout<<arr[i]<<endl;
		}
	}
 };
 
 int main(){
 	 Stack s1;
 	 int option,position,values;
 	 
 	 do{
 	 	cout<<"what operation do you want to perform ? select option number. Enter 0 to exit."<<endl;
 	 	cout<<"1. Push"<<endl;
 	 	cout<<"2. Pop"<<endl;
 	 	cout<<"3. isempty"<<endl;
 	 	cout<<"4. isfull"<<endl;
 	 	cout<<"5. Peek"<<endl;
 	 	cout<<"6. count"<<endl;
 	 	cout<<"7. change"<<endl;
 	 	cout<<"8. display"<<endl;
 	 	cout<<"9. clear screen"<<endl;
 	 	
 	 	cin>>option;
 	 	switch(option){
 	 		case 1: 
			  cout<<"enter the item to push in the stack"<<endl;
 	 		  cin>>values;
 	 		  s1.push(values);
 	 	   	  break;
 	 	   	  
 	 	   	case 2:
				 cout<<"enter the value pop function called:"<<s1.pop()<<endl;
				 break;
				 
			case 3:
				if(s1.isempty()){
					cout<<"stack is empty"<<endl;
				}
				else{
					cout<<"not empty"<<endl;
				}
				break;
				   
			case 4:
				if(s1.isfull()){
					cout<<"stack is full"<<endl;
				}
				else{
					cout<<"stack is not full"<<endl;
				}
				break;
		
			case 5:
				cout<<"enter the position of element you want to peek"<<endl;
				cin>>position;
				cout<<"peek function called-value of position"<<position<<" is "<<s1.peek(position)<<endl;
				break;
			
			case 6:
				cout<<"count the value in stack:"<<s1.count()<<endl;
				break;
			
			case 7:
				cout<<"change function called:"<<endl;
				cout<<"enter the position of the item you want to change:";
				cin>>position;
				cout<<"enter the value you want to change:";
				cin>>values;
				s1.change(position,values);
				break;
			
			case 8:
				cout<<"display function called:"<<endl;
				s1.display();
				break;
			
			case 9:
			    system("cls");
			    break;
			    
 	 		default:
 	 			cout<<"enter proper option number"<<endl;
 	 			
		  }
 	 	
	  }while(option!=0);
 	
	 return 0;
 }
