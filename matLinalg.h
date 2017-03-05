#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif

Matrix vstack(Matrix a,Matrix b){
	int rowa=a.row(),cola=a.col(),rowb=b.row(),colb=b.col();
	if(cola!=colb) return Matrix();
	Matrix newMat(rowa+rowb,cola);
	int i,j;
	for(i=1;i<=rowa;++i){
		for(j=1;j<=cola;++j){
			newMat(i,j)=a(i,j);
		}
	}
	for(i=1;i<=rowb;++i){
		for(j=1;j<=cola;++j){
			newMat(i+rowa,j)=b(i,j);
		}
	}
	return newMat;
}

Matrix hstack(Matrix a,Matrix b){
	int rowa=a.row(),cola=a.col(),rowb=b.row(),colb=b.col();
	if(rowa!=rowb) return Matrix();
	Matrix newMat(rowa,cola+colb);
	int i,j;

	for(i=1;i<=rowa;++i){
		for(j=1;j<=cola;++j){
			newMat(i,j)=a(i,j);
		}
		
	}

	for(i=1;i<=rowa;++i){
		for(j=1;j<=colb;++j){
			newMat(i,j+cola)=b(i,j);
		}
		
	}
	return newMat;
}