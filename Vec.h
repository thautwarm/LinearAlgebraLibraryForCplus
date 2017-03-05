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
class Vector{
	public :
	int size;
	double *value;
	Vector(){
		size=0;
		value=NULL;
	}
	Vector(int size){
		this->size=size;
		value=new double[size];
	}
	Vector(int start,int end,int interval=1){
		int i;
		int num= (end-start)/interval+1;
		size=num;
		value=new double[num];
		for(i=1;i<=num;++i)
		{
			value[i-1]=(i-1)*interval+start;
		}
	}
	double& operator()(int i){
		return value[i-1];
	}
	void disp(){
		int i;
		Vector vec=*this;
		for(i=1;i<=size;++i)
			printf("%f ",vec(i));
		printf("\n");
	}
	void deleteData(){
		delete []value;
	}
	void swap(int i,int j){
		Vector vec=*this;
		double a=vec(i);
		vec(i)=vec(j);
		vec(j)=a;
	}
	Vector& init(int size){
		delete []value;
		this->size=size;
		value=new double[size];
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
    ~Vector(){
		
		if(!size){
        delete []value;
		size=0;
		}
        }


};

class IntVector{
                public :
        int size;
        int *value;
                
        IntVector(){
                size=0;
                value=NULL;
        }
        IntVector(int size){
                this->size=size;
                value=new int[size];
        }
        IntVector(int start,int end,int interval=1){
                int i;
                int num= (end-start)/interval+1;
                size=num;
                value=new int[num];
                for(i=1;i<=num;++i)
                {
                        value[i-1]=(i-1)*interval+start;
                }
        }
		IntVector& toOnes(){
			IntVector& vec=*this;
			int i;
			for(i=1;i<=size;++i) vec(i)=1;
		}
        int& operator()(int i){
                return value[i-1];
        }
        void disp(){
                int i;
                IntVector vec=*this;
                for(i=1;i<=size;++i)
                        printf("%d ",vec(i));
                printf("\n");
        }
        void deleteData(){
                delete []value;
        }
        void swap(int i,int j){
                IntVector vec=*this;
                int a=vec(i);
                vec(i)=vec(j);
                vec(j)=a;
        }
        IntVector& init(int size){
                delete []value;
                this->size=size;
                value=new int[size];
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
		void toRandom(){
			int i,j,k;
			int n=size*3;
			for(i=1;i<=n;++i)
			{
				k=rand()%(size)+1;
				j=rand()%(size)+1;
				swap(k,j);
				
			}
		}
        ~IntVector(){
                
                if(!size){
        delete []value;
                size=0;
                }
        }


};
// void sort(Vector valueSeq){
	// int head=1,tail=valueSeq.size;
	// sort(valueSeq,head,tail);
// }
// void sort(Vector valueSeq,int head,int tail){
			// int index,cake=head;
			// if (tail==head){
				// return ;
			// }
			// for(index=head+1;index<=tail;++index)
				// if(valueSeq(index)<valueSeq(head))
				// {	
					// ++cake;
					// valueSeq.swap(index,cake);
				// }
			
			// valueSeq.swap(head,cake);
			// sort(valueSeq,head,cake-1);
			// sort(valueSeq,cake+1,tail);
// }

void sort(IntVector &valueSeq,int head,int tail){
			int index,cake=head;
			if (tail<=head){
				return ;
			}
			for(index=head+1;index<=tail;++index)
				if(valueSeq(index)<valueSeq(head))
				{	
					++cake;
					valueSeq.swap(index,cake);
				}
			
			valueSeq.swap(head,cake);
			sort(valueSeq,head,cake-1);
			sort(valueSeq,cake+1,tail);
}
void sort(IntVector &valueSeq){
	
	int head=1,tail=valueSeq.size;
	sort(valueSeq,head,tail);
	
}

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


