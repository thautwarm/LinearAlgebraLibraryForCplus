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
int main(){
	inData a=Get_Datas();
	a.readyOut();
	Matrix mat=toMat(a,4);
	mat.disp();
	mat/=255;
	Matrix X=mat.cut(1,350,1,3);
	Matrix y=mat.cut(1,350,4,4);
	IntVector vec(3);
	vec(1)=3;
	vec(2)=7;
	vec(3)=1;
	Network net(vec);
	net.fit(X,y);
	net.predict(X).disp();

}