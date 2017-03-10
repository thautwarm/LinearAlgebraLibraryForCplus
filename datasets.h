#ifndef _DATASETS_
#define _DATASETS_
#endif
#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif
#include <fstream>
#include "string.h"
class DataUnit{

	public :
	double data;
	DataUnit *next;
	DataUnit(){
	next=NULL;
	data=0;
	}
	DataUnit(double a){
	next=NULL;
	data=a;
	}
		
};
class inData{
	private:
	DataUnit *ptr;
	DataUnit *head;
	public:
	inData(){
		
		this->head=new DataUnit(0);
		this->ptr=this->head;
		int size=0;
	}
	void push_back(double a){
		head->data+=1;
		ptr->next=new DataUnit(a);
		ptr=ptr->next;
	}
	void disp(){
		if (!head) return;
		DataUnit *p=head;
		p=p->next;
		while(p){
			printf("%f ",p->data);
			p=p->next;
		}
	}
	int size(){
		return head->data;
	}
	void deleteData(){
		DataUnit *p=head;
		while(p){
			ptr=p;
			p=p->next;
			delete ptr;
		}
	head=NULL;
	}
	void readyOut(){
		ptr=head->next;
	}
	double out(){
		double value=ptr->data;
		ptr=ptr->next;
		return value;
	}
	
};
 inData Get_Datas()
 {
	std::ifstream in("C:\\Users\\Thautwarm\\Desktop\\JIAOTONG\\DataDealed.txt");
	double value;
	inData Data;	
	while(!in.eof())
	{	
		in>>value;
		Data.push_back(value);
	}
	in.close();
	return Data;
}
Matrix toMat(inData data,int col,int row=-1){
	
	int size=data.size();
	if (row==-1){
		row=size/col;
	}
	else{
		if(row*col!=size)
			row=size/col;
	}
	Matrix mat(row,col);
	data.readyOut();
	double value;
	int i,j;
	for(i=1;i<=row;++i){
		for(j=1;j<=col;++j)
		{	value=data.out();
			mat(i,j)=value;
		}
	}
	return mat;
}


