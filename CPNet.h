#ifndef _NN_
#define _NN_
#endif
#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif
#ifndef _VECTOR_
#include "Vec.h"
#define _VECTOR_
#endif
#ifndef _NUMCPP_
#include "NumCpp.h"
#define _NUMCPP_
#endif
#ifndef _MATH_
#define _MATH_
#include <math.h>
#endif

class MatrixCell{
	public:
		Matrix mat;
		MatrixCell *next;
		MatrixCell *forward;
	MatrixCell(){
		mat=Matrix();
		next=NULL;
		forward=NULL;
	}
	void setMat(Matrix &m){
		mat=m;
	}
	Matrix& getMat(){
		return mat;
	}
	
};
class MatrixStack{
	public:
		int size;
		int rev;
		MatrixCell *head;
		MatrixCell *tail;
		MatrixCell *ptr;
	MatrixStack(){
		head=new MatrixCell();
		tail=NULL;
		ptr=head;
		rev=0;
	}
	void push_back(Matrix mat){
		(*ptr).setMat(mat);
		tail=ptr;
		MatrixCell *cellptr=new MatrixCell();
		cellptr->forward=ptr;
		ptr->next=cellptr;
		ptr=ptr->next;
	}
	void disp(){
		MatrixCell *p=(rev==0)?head:tail;
		while(p){
			p->mat.disp();
			p=(rev==0)?p->next:p->forward;
		}
	}
	int isNotEnd(){
		return (rev==0)?ptr->forward!=tail:ptr!=NULL;
	}
	void clear(){
		rev=0;
		ptr=head;
	}
	void reset(){
		ptr=(rev==0)?head:tail;
		}
	void next(){
		ptr=(rev==0)?ptr->next:ptr->forward;
	}
	void reverse(){
		rev=(rev==0)?1:0;
	}
	Matrix& getMat(){
		Matrix& mat=(*ptr).getMat();
		return mat;
	}
	Matrix& getLastMat(){
		Matrix& mat=(rev==0)?(*(ptr->forward)).getMat():(*(ptr->next)).getMat();
	}
};

double sigmoid(double x){
	return 1.0/(1+exp(-x));
}
void doSigmoid(Matrix vector,Matrix &output){
	int row=vector.row(),i;
	for(i=1;i<=row;++i) output(i,1)=(vector(i,1)>-10)?sigmoid(vector(i,1)):0;
}
Matrix primeSigmoid(Matrix output){
	int row=output.row(),i;
	Matrix newMat(row,1);
	double v;
	for(i=1;i<=row;++i) {
	v=output(i,1);
	newMat(i,1)=sigmoid(v)*(1-sigmoid(v));
	}
	return newMat;
}
void doRelu(Matrix vector,Matrix &output){
	int row=vector.row(),i;
	double v;
	for(i=1;i<=row;++i){
		v=vector(i,1);
		output(i,1)=( v > 0 )? v:0;
	}
	}

Matrix primeRelu(Matrix output){
	int row=output.row(),col=output.col();
	int i,j;
	Matrix newMat(row,col);
	for(i=1;i<=row;++i)
		for(j=1;j<=col;++j){
			newMat(i,j)=(output(i,j)>0)?1:0;
		}
	return newMat;
	
}

Matrix primeLinear(int size){
	Matrix newMat(size,1);
	int i;
	for(i=1;i<=size;++i) newMat(i,1)=1;
	return newMat;
	
}
// Matrix MSE(Matrix input,Matrix output,Matrix y){  //最后一层线性激活
	 
	 // return (output-y);

// }
class ReluNet{  //激活函数为relu的神经网络
	public:
		
		MatrixStack weight;
		MatrixStack bias;
		MatrixStack Error;
		
		MatrixStack input;
		MatrixStack output;
		
	ReluNet(IntVector Layer){
		int size=Layer.size;
		int i=1;
		input.push_back(Matrix(Layer(i),1));
		output.push_back(Matrix(Layer(i),1));
		bias.push_back(randomMat(Layer(i+1),1));
		weight.push_back(randomMat(Layer(i),Layer(i+1)).T());

		for(i=2;i<=size-1;++i){
			input.push_back(Matrix(Layer(i),1));
			output.push_back(Matrix(Layer(i),1));
			Error.push_back(Matrix(Layer(i),1));
			bias.push_back(-randomMat(Layer(i+1),1));
			weight.push_back(randomMat(Layer(i),Layer(i+1)).T());
		}
			
			input.push_back(Matrix(Layer(i),1));
			output.push_back(Matrix(Layer(i),1));
			Error.push_back(Matrix(Layer(i),1));
	}
	void clear(){
		weight.clear();
		bias.clear();
		Error.clear();
		input.clear();
		output.clear();
	}
	
	
	
	int input_size(){
	return input.head->mat.row();
	}
	int output_size(){
	return output.tail->mat.row();
	}
	
	Matrix forward(Matrix x){

		clear();
		input.getMat().copy(x);	
		output.getMat().copy(x);
		input.next();
		while(input.isNotEnd()){
				input.getMat().getLinear(weight.getMat(),output.getMat(),bias.getMat());
				// input.getMat().copy(weight.getMat()*output.getMat()+bias.getMat());
				weight.next();
				output.next();
				bias.next();
				doSigmoid(input.getMat(),output.getMat());
				input.next();
		}
		return output.getMat();
		
	}
	
	void BackProp(Matrix y){
		weight.reverse();
		weight.reset();
		output.reverse();
		output.reset();	
		Error.reverse();
		Error.reset();
		Error.getMat().getSub(output.getMat(),y.T());
		Error.next();
		output.next();
		while(Error.isNotEnd()){
			
			Error.getMat().Hadamard(weight.getMat().T()*(Error.getLastMat()),primeSigmoid(output.getMat()));

			
			weight.next();
			
			Error.next();
			
			output.next();
			
			
		}
	}
	
	void WeightRenew(){
		clear();
		
		double r=1.0*rand()/RAND_MAX/8;
		while(weight.isNotEnd()){
			weight.getMat().getSub(weight.getMat(),(Error.getMat()*input.getMat().T())*r);
			bias.getMat().getSub(bias.getMat(),Error.getMat()*r);
			weight.next();
			bias.next();
			input.next();
			Error.next();
		}
		// weight.disp();
	}
	void single_fit(Matrix x,Matrix y){
		// printf("tag: \n");
		// y.disp();
		// printf("out:");
		// forward(x).T().disp();
		forward(x);
		BackProp(y);
		WeightRenew();
	}
	void fit(Matrix X , Matrix y){
		int row=X.row();
		int col=X.col();
		int y_col=y.col();
		int i;
		
		while(weight.isNotEnd()){
			weight.getMat().randomShack();
			weight.next();
		}
		for(i=1;i<=row;++i)
		{	
			int j=20;
			while(--j){
			single_fit(X.cut(i,i,1,col),y.cut(i,i,1,y_col));
			}
		}
	}
	Matrix predict(Matrix X){
		clear();
		int row=X.row(),col=input_size(),i,j,y_col=output_size();
		Matrix pred(row,y_col); 
		for(i=1;i<=row;++i)
		{	
				for(j=1;j<=y_col;j++)
					pred(i,j)=forward(X.cut(i,i,1,col))(j,1);
		}
		return pred;
	}
};