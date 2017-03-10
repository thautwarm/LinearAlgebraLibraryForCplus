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
		double *value;
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
			this->value= new double[dim1*dim2];
		}
		double& operator()(int i,int j){
			return value[(i-1)*dim2+j-1];
		}
		
		int getdim2(){
			return dim2;
		}
		int getdim1(){
			return dim1;
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
	int index_style;
	int dim1;
	int dim2;
	IntVector dim1Index;
	IntVector dim2Index;
	Matrix(int row,int col)//默认行索引
	{
		index_style=0;
		Mat=new MatrixSource(row,col);
		dim1=row;
		dim2=col;
		this->dim1Index=*(new IntVector(1,this->dim1,1));
		this->dim2Index=*(new IntVector(1,this->dim2,1));
	}
	Matrix(){
		index_style=0;
		Mat=NULL;
		dim1=0;
		dim2=0;
		dim1Index=IntVector();
		dim2Index=IntVector();
	}
	Matrix(Matrix *mat){
		this->Mat=mat->Mat;
		this->dim1=mat->dim1;
		this->dim2=mat->dim2;
		this->index_style=mat->index_style;
		this->dim1Index=*(new IntVector(1,this->dim1,1));
		this->dim2Index=*(new IntVector(1,this->dim2,1));
	}
	Matrix(Vector Vec){
		Mat=new MatrixSource();
		Mat->dim1=Vec.size;
		Mat->dim2=1;
		index_style=0;
		dim1=Vec.size;
		dim2=1;
		dim1Index=*(new IntVector(1,this->dim1,1));
		dim2Index=*(new IntVector(1,this->dim2,1));
		Mat->value=Vec.value;

	
	}
	double& operator()(int i,int j){
			return  (index_style==0)?(*Mat)(dim1Index(i),dim2Index(j)):(*Mat)(dim1Index(j),dim2Index(i));
		}
	int col(){
		return (index_style==0)?dim2:dim1;
	}
	int row(){
			return (index_style==0)?dim1:dim2;
	}
	
	IntVector& getRowIndex(){
		return  (index_style==0)? this->dim1Index:this->dim2Index;
	}
	IntVector& getColIndex(){
		return  (index_style==0)? this->dim2Index:this->dim1Index;
	}
	Matrix copy(){
		Matrix newMat(dim1,dim2);
		Matrix oldMat=*this;
		newMat.dim1Index.copy(oldMat.dim1Index);   //!!!!!需要深拷贝！回来改
		newMat.dim2Index.copy(oldMat.dim2Index);
		newMat.index_style=oldMat.index_style;
		int row=oldMat.row();
		int col=oldMat.col();
		int i,j;
		for (i=1;i<=row;++i)
			for(j=1;j<=col;++j){
					newMat(i,j)= oldMat(i,j);
			}
		return newMat;
		}
		
	void copy(Matrix oldMat){
		Matrix newMat=*this;
		newMat.dim1Index.copy(oldMat.dim1Index);   //!!!!!需要深拷贝！回来改
		newMat.dim2Index.copy(oldMat.dim2Index);
		newMat.index_style=oldMat.index_style;
		int row=oldMat.row();
		int col=oldMat.col();
		int i,j;
		for (i=1;i<=row;++i)
			for(j=1;j<=col;++j){
					newMat(i,j)= oldMat(i,j);
			}
	}
	Matrix T(){
		Matrix mat(this);
		mat.index_style=(mat.index_style==0)?1:0;
		return mat;
		}
		
		
	#include "matMul.h"
	#include "matPlus.h"
	#include "matNeg.h"
	#include "matDiv.h"
	#include "matArg.h"
	
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
		
	Matrix inv();	
	Vector toVector();
	Matrix cut(int,int,int,int);
};


void matImmerse(Matrix &invmat, Matrix &mat,int row1,int row2,int col1,int col2,int descend=1){
		if (col2<col1) IntSwap(col1,col2);
		if (row2<row1) IntSwap(row1,row2);
		if (descend==1){
			int i;
			double div=mat(row2,col1)/mat(row1,col1);
			for(i=col1;i<=col2;++i){
			mat(row2,i)-=div*mat(row1,i);
			invmat(row2,i)-=div*invmat(row1,i);
			}
			for(i=1;i<col1;++i){
			invmat(row2,i)-=div*invmat(row1,i);
			}
			return;
		}
		if(descend==-1){
			int i;
			double div=mat(row1,col2)/mat(row2,col2);
			for(i=col2;i>=col1;--i){
			mat(row1,i)-=div*mat(row2,i);
			invmat(row1,i)-=div*invmat(row2,i);
			}
			for(i=invmat.col();i>col2;--i){
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
			double div=mat(row2,col1)/mat(row1,col1);
			for(i=col1;i<=col2;++i){
			mat(row2,i)-=div*mat(row1,i);
			}
			return;
		}
		if(descend==-1){
			int i;
			double div=mat(row1,col2)/mat(row2,col2);
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
		
		if(row!=col) return Matrix();
		
		Matrix Eye(row,row);
		
		
		Eye.toEye();
		Eye.disp();
		Matrix newMat=(*this).copy();
		int i,j,maxIndex;
		IntVector rowIndex=newMat.getRowIndex();
		IntVector eyeRowIndex=Eye.getRowIndex();
		for(i=1;i<=row-1;++i){
			maxIndex=newMat.argabsmax(i,i,-1,1);
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

Vector Matrix::toVector(){
	int col=(*this).col(),row=(*this).row();
	
	if(col!=1){
		return Vector();
	}
	Vector Vec=Vector();
	Vec.size=row;
	Vec.value=this->Mat->value;
	Vec.size=row;
	return Vec;
}
#include "matLinalg.h"
Matrix Matrix::cut(int row1, int row2,int col1, int col2){
	if(row2<row1) IntSwap(row1,row2);
	if(col2<col1) IntSwap(col1,col2);
	int row=row2-row1+1,col=col2-col1+1;
	Matrix newMat(row,col);
	Matrix oldMat=*this;
	int i,j;
	for(i=1;i<=row;++i)
		for(j=1;j<=col;++j){
			newMat(i,j)=oldMat(i+row1-1,j+col1-1);
		}
	return newMat;
}



