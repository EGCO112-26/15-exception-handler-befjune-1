#include <iostream>
#include <exception>
using namespace std;

void check0(int);

class div0:public exception{ //class จัดการ ตัวหารเป็น 0
	public:
	virtual const char* what() const throw() {
		return "Divided by zero";
	}
};

class fail:public exception{ //class จัดการ func cin.fail
	public:
	virtual const char* what() const throw() {
		cin.clear();
		cin.ignore(50,'\n');
		return "Heyyyyy!! 2 integer!";
	}
}fail;

int main(){
	int x,y,a = 1;
	double d;
do{
try{
	cout<<"Enter 2 numbers: ";
	cin>>x>>y;

	/*curated exception handling*/
	if(cin.fail()){
		throw fail; //throw object
		//throw("Incorrect type entered");
		//cerr<<"Incorrect type entered"; return 1;
	}
	if(abs(x)>1000 ||abs(y)>1000){
		throw("Value out of range");
		//cerr<<"Value out of range"; return 1;
	}

	check0(y);
	a = 0;
	
	/*if (y==0) {
		throw("Error divide by zero");
		//cerr<< "Error divide by zero"; return 1;
	}*/

	/*normal code*/
	d=(double) x/y;
	cout<< "The result is " <<d<<endl;
	
	int i;
	double* myarray;
	cout<<"Allocating memory..."<<endl;
	for(i=0; i<100000000; i++){
		//cout<<"Allocating memory..."<<i<<endl;
		myarray = new double[500000000]; 
	}
	
	a=0;
}

/*catch(const char* error){ //จัดการ error
	cerr<<error<<endl;
	a=1;
	cin.clear();
	cin.ignore(50, '\n');
	//return -1;
}
catch(int e){
	switch(e){
		case 101: cerr<<"Incorrect numbers "<<endl; break;
		case 0: cerr<<"Divided by zero"<<endl; break;
	}
}*/
catch(exception &e){
	cout<<e.what()<<endl;
}
/*
catch(...){//ไม่เข้ากรณีไหนเลย ทำให้ pass parameter ไม่ได้ จะไม่รู้ว่า error ชนิดอะไร
	cout<<"Memory leak!!"<<endl;
}*/
}while(a);
	return 0;
}

void check0(int x){
	div0 e;
	if(x==0) throw e;
}
