#include <stdio.h>
#include <stdlib.h>	
#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif
#ifndef _VECTOR_
#include "Vec.h"
#define _VECTOR_
#endif
#include "iostream"
#ifndef _NUMCPP_
#include "NumCpp.h"
#define _NUMCPP_
#endif
#ifndef _NN_
#include "CPNet.h"
#define _NN_
#endif
#include "datasets.h"
#include "LinearModel.h"
//A Lightweight Release For C++98
#include "string.h"
int main(){
	inData a=Get_Datas();
	a.readyOut();
	Matrix mat=toMat(a,5);
	//LinearRegression
	
  	// Matrix A=mat.cut(1,150,1,4);
	// Matrix B=mat.cut(1,150,5,5);
	// LinearRegressor clf(A,B);
	// hstack(Matrix(clf.predict(A)),B).disp();
	
	
	
	//LinearModelParam
	// (*(clf.beta)).disp();
	
	//NN
	/*
	IntVector vec(4,1,-1);
	Matrix A=mat.cut(1,100,1,4);
	Matrix B=Cate(mat.cut(1,100,5,5),2);
	vec(1)=4;
	vec(2)=8;
	vec(3)=5;
	vec(4)=2;
	int i;
	
		int j,col=A.col(),row=A.row();
		double ss;
		for(j=1;j<=col;++j)
		{ss=0;
			for(i=1;i<=row;i++)
				ss+=A(i,j);
			ss/=row;
			for(i=1;i<=row;i++){
				A(i,j)-=ss;
			}
		}
		for(j=1;j<=col;++j)
		{ss=0;
			for(i=1;i<=row;i++)
				ss+=A(i,j)*A(i,j);
			ss/=row;
			ss=sqrt(ss);
			for(i=1;i<=row;i++){
				A(i,j)/=ss;
			}
		}

	ReluNet net(vec);
	j=i=1;
	
	Matrix C=vstack(A.cut(1,25,1,4),A.cut(51,75,1,4));
	Matrix Cy=vstack(B.cut(1,25,1,2),B.cut(51,75,1,2));
	Matrix D=vstack(A.cut(26,50,1,4),A.cut(76,100,1,4));
	Matrix Dy=vstack(B.cut(26,50,1,2),B.cut(76,100,1,2));
	while(i<=50){
		net.fit(C,Cy);
		i+=1;
		
	}
	
	hstack(net.predict(D),Dy).disp();
	*/
	
	IntVector vec(4,1,-1);
	Matrix A=mat.cut(1,150,1,4);
	Matrix B=Cate(mat.cut(1,150,5,5),3);
	vec(1)=4;
	vec(2)=30;
	vec(3)=30;
	vec(4)=3;
	int i;
	
		int j,col=A.col(),row=A.row();
		double ss;
		for(j=1;j<=col;++j)
		{ss=0;
			for(i=1;i<=row;i++)
				ss+=A(i,j);
			ss/=row;
			for(i=1;i<=row;i++){
				A(i,j)-=ss;
			}
		}
		for(j=1;j<=col;++j)
		{ss=0;
			for(i=1;i<=row;i++)
				ss+=A(i,j)*A(i,j);
			ss/=row;
			ss=sqrt(ss);
			for(i=1;i<=row;i++){
				A(i,j)/=ss;
			}
		}

	Network net(vec);
	j=i=1;
	// Matrix C=vstack(vstack(A.cut(1,25,1,4),A.cut(51,75,1,4)),A.cut(101,125,1,4));
	// Matrix Cy=vstack(vstack(B.cut(1,25,1,3),B.cut(51,75,1,3)),B.cut(101,125,1,3));
	// Matrix D=vstack(vstack(A.cut(26,50,1,4),A.cut(76,100,1,4)),A.cut(125,150,1,4));
	// Matrix Dy=vstack(vstack(B.cut(26,50,1,3),B.cut(76,100,1,3)),B.cut(125,150,1,3));
	while(i<=100){
		net.fit(A,B);
		i+=1;
		
	}
	
	
	hstack(net.predict(A),B).disp();

	
	

	// net.single_fit(C,D);
	
	// sort(A.getRowIndex());
	// sort(B.getRowIndex());
	// net.forward(A.cut(1,1,1,4)).disp();
	// net.forward(A.cut(12,12,1,4)).disp();
	// net.forward(A.cut(i,i,1,4)).disp();

	// net.single_fit(C,D);
	// net.forward(C).disp();
	// net.single_fit(C,D);
	// net.forward(C).disp();
	// net.single_fit(C,D);
	// net.forward(C).disp();
	// net.single_fit(C,D);
	// net.forward(C).disp();
	// net.single_fit(C,D);
	// net.forward(C).disp();
	// net.single_fit(C,D);
	// net.forward(C).disp();
	// Vector pred=net.predict(A);
	// Matrix mat(2,3);
	// int i,j;
	// mat(1,1)=1;mat(1,2)=2;mat(1,3)=5;
	// mat(2,1)=3;mat(2,2)=1;mat(2,3)=5;
	// Vector solution=GaussEq(mat);
	// solution.disp();
	// Matrix matc=hstack(mat,mat);
	// matc.disp();
	// Matrix matd=vstack(mat,mat);
	// matd.disp();
	// Matrix matc=mat.inv();
	// matc.disp();
	// mat.disp();
	// (matc*mat).disp();
	
	

	// Vector c=clf.predict(A);
	// c.disp();
	
	

	// float value;
		// value=a.out();
	// std::cout<<value;
	// for(int i=1;i<=10;i++){	
	// value=a.out();
	// std::cout<<value;
	// }

	// Vector solution=GaussEq(mat);
	// solution.disp();
	// Matrix matc=hstack(mat,mat);
	// matc.disp();
	// Matrix matd=vstack(mat,mat);
	// matd.disp();

	// mat.deleteData();
	// matc.deleteData();
	// matd.deleteData();
	}