#include<iostream>
using namespace std;

class Circularqueue{
	private:
		int front;
		int rear;
		int arr[5];
		int itemcount;
		
	public:
		Circularqueue(){
			itemcount=0;
			front =-1;
			rear=-1;
			for(int i=0;i<5;i++){
				arr[i]=0;
				cout<<endl;
			}
		}
			
			bool isEmpty(){
				if(front==-1 && rear==-1){
					return true;
				}
				else{
					return false;
				}
			}
			
			bool isfull(){
				//circular queue condition
				if((rear+1)%5==front){
					return true;
				}
				else{
					return false;
				}
			}
			
			void enqueue(int val){
				if(isfull()){
					cout<<"Queue is full"<<endl;
					return ;
				}
				else if(isEmpty()){
					rear=front=0;
					arr[rear]=val;
				}
				else{
					//circular queue
					rear=(rear+1)%5;
					arr[rear]=val;
				}
				itemcount++;
			}
			
			int dequeue(){
				int x;
				if(isEmpty()){
					cout<<"queue is empty";
					return 0;
				}
				else if(front==rear){
				     x=arr[front];
					front=rear=-1;
					arr[front]=0;
					return x;
				}
				else{
				   	x=arr[front];
					arr[front]=0;
					front=(front+1)%5;
					return x;
				}
				itemcount--;
			}
			
			int count(){
				return(itemcount);
			}
			
			void display(){
				cout<<"all values in the queue are:"<<endl;
				for(int i=0;i<5;i++){
					cout<<arr[i]<<" ";
				}
			}
	

};

int main(){
	Circularqueue c1;
	int option,value;
	
	 do{
 	 	cout<<"what operation do you want to perform ? select option number. Enter 0 to exit."<<endl;
 	 	cout<<"1. enqueue"<<endl;
 	 	cout<<"2. dequeue"<<endl;
 	 	cout<<"3. isempty"<<endl;
 	 	cout<<"4. isfull"<<endl;
 	 	cout<<"5. count"<<endl;
 	 	cout<<"6. display"<<endl;
 	 	cout<<"7. clear screen"<<endl;
 	 	
 	 	cin>>option;
 	 	
 	 	switch(option){
 	 		case 1: 
			  cout<<"Enqueue operation \nEnter an item  to Enqueue in the queue"<<endl;
			  cin>>value;
			  c1.enqueue(value);
 	 	   	  break;
 	 	   	  
 	 	   	case 2:
				 cout<<"dequeue operation \ndequeue value:"<<c1.dequeue()<<endl;
				 break;
				 
			case 3:
				if(c1.isEmpty()){
					cout<<"queue is empty"<<endl;
				}
				else{
					cout<<"Queue is not empty"<<endl;
				}
				break;
				   
			case 4:
				if(c1.isfull()){
					cout<<"queue is full"<<endl;
				}
				else{
					cout<<"queue is not full"<<endl;
				}
				break;
			
			case 5:
				cout<<"count the value in queue:"<<c1.count()<<endl;
				break;
			
			case 6:
				cout<<"display function called:"<<endl;
				c1.display();
				break;
			
			case 7:
			    system("cls");
			    break;
			    
 	 		default:
 	 			cout<<"enter proper option number"<<endl;
 	 			break;
		  }
 	 	
	  }while(option!=0);
	
	  
	return 0;

}

