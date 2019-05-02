#include<iostream>
#include<cstring>
using namespace std;

class data{
	public:
	int ind;
	char name[20];
};

class linear{
	public:
	data arr[10],temp;
	int i;
	linear(){
		for(i=0;i<10;i++){
			arr[i].ind=-1;
			strcpy(arr[i].name,"\0");
		}
	}

	void add(int ind,int roll , char name[]){
		if(arr[ind % 10].ind==-1){
			arr[ind % 10].ind=roll;
			strcpy(arr[ind % 10].name,name);
			return;
		}
		else if(arr[ind % 10].ind % 10 != ind % 10){
			temp.ind = arr[ind % 10].ind;
			strcpy(temp.name,arr[ind % 10].name);
			
			arr[ind % 10].ind=roll;
			strcpy(arr[ind % 10].name,name);
			
			roll = temp.ind;
			strcpy(name,temp.name);
			
			ind+=1;
			add(ind,roll,name);                    
			                         
			                         
		}
		else{
			ind+=1;
			add(ind,roll,name);
		}
		
	}
	
	void search(int ind,int roll){
		if(arr[ind % 10].ind==roll){
			cout<<"Record Found\n";
			cout<<arr[ind % 10].ind<<">>"<<arr[ind % 10].name<<endl;
			return ;
		}
		else{
			ind+=1;
			search(ind,roll);
		}
	}
	
	void disp(){
		for(i=0;i<10;i++){
			cout<<i<<":  "<<arr[i].ind<<">>"<<arr[i].name<<endl;
		}
	}
};

int main(){
	
	linear obj;
	char ch,name[20];
	int ind;
	Again:
	cout<<"\nEnter:\n1.Add\n2.Search\n3.Dispaly\n0.Exit\n";
	cin>>ch;
	switch(ch){
		case '1':
			cout<<"Enter index and name\n";
			cin>>ind>>name;
			obj.add(ind,ind,name);
			goto Again;
		case '2':
			cout<<"Enter index\n";
			cin>>ind;
			obj.search(ind,ind);
			goto Again;
		case '3':
			obj.disp();
			goto Again;	
		case '0':
			break;		
		default:
			cout<<"Wrong Choice\n";
			break;
	}

	return 0;
}
