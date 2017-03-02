#ifndef _MATRIX_
#define _MATRIX_
#endif
#ifndef _IO_
#include "stdio.h"
#define _IO_
#endif
#ifndef _STDLIB_
#include "stdlib.h"
#define _STDLIB_
#endif
#ifndef _MALLOC_
#include <malloc.h>
#define _MALLOC_
#endif
#ifndef _MATH_
#define _MATH_
#include <math.h>
#endif
#ifndef _VECTOR_
#include "Vec.h"
#define _VECTOR_
#endif
#ifndef _LINALG_
#include "matLinalg.h"
#define _LINALG_
#endif
#ifndef _UTIL_
#include "utilMat.h"
#define _UTIL_
#endif

void unittest(){
	static int a=1;
	printf("%d\n",a++);
}
void unittest(int a){
	printf("%d\n",a);
}



class MatrixSource{
		public:
		float *value;
		int dim1;
		int dim2;
		MatrixSource(){
			value=NULL;
			dim1=0;
			dim2=0;
		}
		MatrixSource(int dim1,int dim2){
			this->dim1=dim1;
			this->dim2=dim2;
			this->value= new float[dim1*dim2];
		}
		float& operator()(int store_style,int i,int j){
			int line=(store_style==0)?dim2:dim1;
			return value[(i-1)*line+j];
		}
		
		int getdim2(int store_style){
			return (store_style==0)?dim2:dim1;
		}
		int getdim1(int store_style){
			return (store_style==0)?dim1:dim2;
		}
		


		
		~MatrixSource(){
			printf("end-mat\n");
			if(this){
				delete []value;
				}
		}
		
};

class Matrix{
	public:
	MatrixSource *Mat;
	int store_style;
	int dim1;
	int dim2;
	IntVector dim1Index;
	IntVector dim2Index;
	Matrix(int row,int col)//默认行索引
	{
		store_style=0;
		Mat=new MatrixSource(row,col);
		dim1=row;
		dim2=col;
		this->dim1Index=*(new IntVector(1,this->dim1,1));
		this->dim2Index=*(new IntVector(1,this->dim2,1));
	}
	Matrix(Matrix *mat){
		this->Mat=mat->Mat;
		this->dim1=mat->dim1;
		this->dim2=mat->dim2;
		this->store_style=mat->store_style;
		this->dim1Index=*(new IntVector(1,this->dim1,1));
		this->dim2Index=*(new IntVector(1,this->dim2,1));
	}
	float& operator()(int i,int j){
			return (store_style==0)?Mat->value[(dim1Index(i)-1)*dim2+dim2Index(j)-1]:Mat->value[(dim2Index(j)-1)*dim2+dim1Index(i)-1];
		}
	int col(){
		return (store_style==0)?dim2:dim1;
	}
	int row(){
			return (store_style==0)?dim1:dim2;
	}
	
	IntVector& getRowIndex(){
		return  (store_style==0)? this->dim1Index:this->dim2Index;
	}
	IntVector& getColIndex(){
		return  (store_style==0)? this->dim2Index:this->dim1Index;
	}
	Matrix copy(){
		Matrix newMat(dim1,dim2);
		Matrix oldMat=*this;
		newMat.dim1Index.copy(oldMat.dim1Index);   //!!!!!需要深拷贝！回来改
		newMat.dim2Index.copy(oldMat.dim2Index);
		newMat.store_style=oldMat.store_style;
		int row=oldMat.row();
		int col=oldMat.col();
		int i,j;
		for (i=1;i<=row;++i)
			for(j=1;j<=col;++j){
					newMat(i,j)= oldMat(i,j);
			}
		return newMat;
		}
	Matrix T(){
		Matrix mat(this);
		mat.store_style=(mat.store_style==0)?1:0;
		return mat;
		}
		
		
	#include "matMul.h"
	#include "matPlus.h"
	#include "matNeg.h"
	#include "matDiv.h"
	
	int argmaxRow(int row,int begin=1,int end=-1){
		Matrix mat=*this;
		int i,maxIndex=begin;
		if (end==-1){
			end=mat.col();
		}
		if(begin>end){
			IntSwap(begin,end);
		}
		for(i=begin;i<=end;++i){
			if (mat(row,i)>mat(row,maxIndex)){
				maxIndex=i;
			}
		}
		return maxIndex;
	}
	int argmaxCol(int col,int begin=1,int end=-1){
		Matrix mat=*this;
		int i,maxIndex=begin;
		if (end==-1){
			end=mat.row();
		}
		if(begin>end){
			IntSwap(begin,end);
		}
		for(i=begin;i<=end;++i){
			if (mat(i,col)>mat(maxIndex,col)){
				maxIndex=i;
			}
		}
		return maxIndex;
	}
	int argmax(int line,int begin,int end,int dim)
	{	
		if (dim==0){
			return (*this).argmaxRow(line,begin,end);			
		}
		if (dim==1){
			return (*this).argmaxCol(line,begin,end);
		}
	}
	
	void toEye(){
		Matrix mat=*this;
		int row= mat.row();
		int col= mat.col();
		int i,j;
		for(i=1;i<=row;++i){
			for(j=1;j<=col;++j){
				mat(i,j)=(i!=j)?0:1;
			}
		}
	}
	
	Matrix inv();	
	void disp(){
		int i,j;
		int row=this->row(),col=this->col();
		Matrix mat=*this;
		for(i=1;i<=row;++i){
			for(j=1;j<=col;++j){
				printf("%f ",mat(i,j));
			}
			printf("\n");
			}
		printf("\n");
		
}
	void deleteData(){
		delete Mat;
		dim1Index.deleteData();
		dim2Index.deleteData();
		}
};


void matImmerse(Matrix &invmat, Matrix &mat,int row1,int row2,int col1,int col2,int descend=1){
		if (col2<col1) IntSwap(col1,col2);
		if (row2<row1) IntSwap(row1,row2);
		if (descend==1){
			int i;
			float div=mat(row2,col1)/mat(row1,col1);
			for(i=col1;i<=col2;++i){
			mat(row2,i)-=div*mat(row1,i);
			invmat(row2,i)-=div*invmat(row1,i);
			}
			return;
		}
		if(descend==-1){
			int i;
			float div=mat(row1,col2)/mat(row2,col2);
			for(i=col2;i>=col1;--i){
			mat(row1,i)-=div*mat(row2,i);
			invmat(row1,i)-=div*invmat(row2,i);
			}
			return;
		}
}
void matImmerse(Matrix &mat,int row1,int row2,int col1,int col2,int descend=1){
		if (col2<col1) IntSwap(col1,col2);
		if (row2<row1) IntSwap(row1,row2);
		if (descend==1){
			int i;
			float div=mat(row2,col1)/mat(row1,col1);
			for(i=col1;i<=col2;++i){
			mat(row2,i)-=div*mat(row1,i);
			}
			return;
		}
		if(descend==-1){
			int i;
			float div=mat(row1,col2)/mat(row2,col2);
			for(i=col2;i>=col1;--i){
			mat(row1,i)-=div*mat(row2,i);
			}
			return;
		}
}
void matStandard(Matrix &invmat, Matrix &mat){
		int row=mat.row();
		int col=mat.col();//行列不同则无法对角标准化。
		if(row!=col)return;
		int i,j;
		for(i=1;i<=row;++i)
		{	
			for(j=1;j<=row;++j)
				invmat(i,j)/=mat(i,i);
		}
}

Matrix Matrix::inv(){
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		if(row!=col) return NULL;
		Matrix Eye(row,row);
		Eye.toEye();
		Matrix newMat=(*this).copy();
		int i,j,maxIndex;
		IntVector rowIndex=newMat.getRowIndex();
		IntVector eyeRowIndex=Eye.getRowIndex();
		for(i=1;i<=row-1;++i){
			maxIndex=newMat.argmax(i,i,-1,1);
			rowIndex.swap(i,maxIndex);
			eyeRowIndex.swap(i,maxIndex);
			for(j=i+1;j<=row;++j){
				matImmerse(Eye,newMat,i,j,i,row,1);
			}
			
		}
		for(i=row;i>=2;--i){
			for(j=i-1;j>=1;--j){
				matImmerse(Eye,newMat,j,i,1,i,-1);
			}
		}
		matStandard(Eye,newMat);
		return Eye;	
	
}



