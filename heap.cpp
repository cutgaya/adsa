#include <iostream>

using namespace std;

class heap{
public:
	
	void accept(){
		int n;
		cout<<"Enter number of students\n";
		cin>>n;
		int a[n];//= { 12, 11, 13, 5, 6, 7 };
		for (int i=0;i<n;i++)
			cin>>a[i];
		heapsort(a,n);
		display(a,n);
	}

	void heapsort(int a[],int n){
		int i , temp;
		for (int i = n / 2 - 1; i >= 0; i--) 
        	heapify(a, i, n); 
		for (int i = n - 1; i >= 0; i--){
			temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			heapify(a ,0,i); 
		}
	}

	void heapify(int a[],int i,int n){
		int l,r,largest =i,temp;
		l = 2*i+1;
		r= 2*i+2;
		if(l < n && a[l]>a[i])
			largest = l;
		if(r < n && a[r]>a[i])
			largest = r;
		if(largest!=i){
			temp = a[i];
			a[i]=a[largest];
			a[largest]=temp;
			heapify(a,largest,n);
		}
	}

	void display(int a[],int n){
		for (int i = 0; i < n; i++){
	        cout<<a[i]<<endl;
	    }
		cout<<"Minimum marks obtained are:"<<a[0];
		cout<<"\nMaximum marks obtained are:"<<a[n-1];
	}


};

int main()
{
	heap obj;
	obj.accept();
	return 0;
}
