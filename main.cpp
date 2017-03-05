#include <stdio.h>
#include <stdlib.h>	
#include <malloc.h>
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

int main(){
	inData a=Get_Datas();
	a.readyOut();
	

	Matrix mat=toMat(a,5);
	mat.disp();
	
	
	//LinearRegression
	
	
	// Matrix A=mat.cut(1,150,1,4);
	// Matrix B=mat.cut(1,150,5,5);
	// LinearRegressor clf(A,B);
	// hstack(Matrix(clf.predict(A)),B).disp();
	// (*(clf.beta)).disp();
	
	
	
	
	//NN
	/*
	IntVector vec(3,1,-1);
	Matrix A=mat.cut(1,100,1,4);
	Matrix B=Cate(mat.cut(1,100,5,5),2);
	vec(1)=4;
	vec(2)=8;
	vec(3)=2;
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
	while(i<=80){
		net.fit(A.cut(i,i+20,1,4),B.cut(i,i+20,1,2));
		i+=8;
	}
	
	
	sort(A.getRowIndex());
	hstack(net.predict(A),mat.cut(51,150,5,5)).disp();
	*/
	

	
	

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