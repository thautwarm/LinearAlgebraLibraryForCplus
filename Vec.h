#ifndef _VECTOR_
#define _VECTOR_
#endif
#ifndef _ZERO_
#define _ZERO_ 0.00001
#endif
#ifndef _MATH_
#include <math.h>
#define _MATH_
#endif
class VectorSource{
		
	public:
		float *value;
		int size;
	
	VectorSource(int size){
		this->size=size;
		this->value=new float[size];
	}
	float& operator()(int i){
		return value[i-1];
	}
	~VectorSource(){
	printf("end-vec\n");
	delete []value;
	}
};

class Vector{
	public :
	int size;
	VectorSource *vec;
	
	Vector(){
		size=0;
		vec=NULL;
	}
	Vector(int size){
		this->size=size;
		vec=new VectorSource(size);
	}
	Vector(int start,int end,int interval=1){
		int i;
		int num= (end-start)/interval+1;
		size=num;
		vec=new VectorSource(num);
		for(i=1;i<=num;++i)
		{
			vec->value[i-1]=(i-1)*interval+start;
		}
	}
	float& operator()(int i){
		return  (*vec)(i);
	}
	void disp(){
		int i;
		Vector vec=*this;
		for(i=1;i<=size;++i)
			printf("%f ",vec(i));
	}
	void deleteData(){
		delete vec;
	}
	void swap(int i,int j){
		float a=(*vec)(i);
		(*vec)(i)=(*vec)(j);
		(*vec)(j)=a;
	}
	Vector& init(int size){
		delete vec;
		this->size=size;
		vec=new VectorSource(size);
	}
	Vector copy(){
		Vector newVec(size);
		Vector oldVec=*this;
		int i;
		
		for(i=1;i<=size;++i){
			newVec(i)=oldVec(i);
		}
		return newVec;
	}
	void copy(Vector oldVec){
		size=oldVec.size;
		Vector newVec=*this;
		if (size!=newVec.size) return;//只能拷贝相同维度的向量
		int i;
		for(i=1;i<=size;++i){
			newVec(i)=oldVec(i);
		}
		return;
	}



};


class IntVectorSource{
		
	public:
		int *value;
		int size;
	
	IntVectorSource(int size){
		this->size=size;
		this->value=new int[size];
	}
	int& operator()(int i){
		return value[i-1];
	}
	


	~IntVectorSource(){
	printf("end-vec\n");
	delete []value;
	}
};

class IntVector{
	public :
	int size;
	IntVectorSource *vec;
	
	IntVector(){
		size=0;
		vec=NULL;
	}
	IntVector(int size){
		this->size=size;
		vec=new IntVectorSource(size);
	}
	IntVector(int start,int end,int interval=1){
		int i;
		int num= (end-start)/interval+1;
		size=num;
		vec=new IntVectorSource(num);
		for(i=1;i<=num;++i)
		{
			vec->value[i-1]=(i-1)*interval+start;
		}
	}
	int& operator()(int i){
		return  (*vec)(i);
	}
	void disp(){
		int i;
		IntVector vec=*this;
		for(i=1;i<=size;++i)
			printf("%d ",vec(i));
		printf("\n");
	}
	void deleteData(){
		delete vec;
	}
	void swap(int i,int j){
		int a=(*vec)(i);
		(*vec)(i)=(*vec)(j);
		(*vec)(j)=a;
	}
	IntVector& init(int size){
		delete vec;
		this->size=size;
		vec=new IntVectorSource(size);
	}
	IntVector copy(){
		IntVector newVec(size);
		IntVector oldVec=*this;
		int i;
		
		for(i=1;i<=size;++i){
			newVec(i)=oldVec(i);
		}
		return newVec;
	}
	void copy(IntVector oldVec){
		size=oldVec.size;
		IntVector newVec=*this;
		if (size!=newVec.size) return;//只能拷贝相同维度的向量
		int i;
		for(i=1;i<=size;++i){
			newVec(i)=oldVec(i);
		}
		return;
	}
};


void argsort(Vector valueSeq,Vector indexSeq,int head,int tail){
			int index,cake=head;
			if (tail==head){
				return ;
			}
			for(index=head+1;index<=tail;++index)
				if(valueSeq(index)<valueSeq(head))
				{	
					++cake;
					valueSeq.swap(index,cake);
					indexSeq.swap(index,cake);
				}
			
			valueSeq.swap(head,cake);
			indexSeq.swap(head,cake);
			argsort(valueSeq,indexSeq,head,cake-1);
			argsort(valueSeq,indexSeq,cake+1,tail);
}


