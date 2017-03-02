#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif
#ifndef _VECTOR_
#include "Vec.h"
#define _VECTOR_
#endif
#ifndef _UTIL_
#include "utilMat.h"
#define _UTIL_
#endif
#ifndef _LINALG_
#include "matLinalg.h"
#define _LINALG_
#endif
Vector GaussEq(Matrix &augmentedMat,int copy=1){

	
	Matrix mat(augmentedMat);
	if (copy){
		mat=augmentedMat.copy();
	}
	//mat 是一个增广矩阵
	int row=mat.row(),col=mat.col();
	if(row!=(col-1)) {printf("Error\n");return Vector();}; //满足增广矩阵
	int i,j,maxIndex;
	IntVector rowIndex=mat.getRowIndex();
	for(i=1;i<=row-1;++i){
		maxIndex=mat.argmax(i,i,-1,1);
		rowIndex.swap(i,maxIndex);
		for(j=i+1;j<=row;++j){
			matImmerse(mat,i,j,i,col,1);
			}
		}
	mat.disp();
	Vector solution(row);
	for(i=row;i>=1;--i){
		solution(i)=mat(i,col);
		for(j=row;j>i;--j)
			solution(i)-=solution(j)*mat(i,j);
		solution(i)/=mat(i,i);
	}
	return solution;
	
	
	
}

