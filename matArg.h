#ifndef _MATH_
#include <math.h>
#define _MATH_
#endif
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
	int argabsmaxRow(int row,int begin=1,int end=-1){
		Matrix mat=*this;
		int i,maxIndex=begin;
		if (end==-1){
			end=mat.col();
		}
		if(begin>end){
			IntSwap(begin,end);
		}
		for(i=begin;i<=end;++i){
			if (fabs(mat(row,i))>fabs(mat(row,maxIndex))){
				maxIndex=i;
			}
		}
		return maxIndex;
	}
	int argabsmaxCol(int col,int begin=1,int end=-1){
		Matrix mat=*this;
		int i,maxIndex=begin;
		if (end==-1){
			end=mat.row();
		}
		if(begin>end){
			IntSwap(begin,end);
		}
		for(i=begin;i<=end;++i){
			if ( fabs(mat(i,col))> fabs(mat(maxIndex,col))){
				maxIndex=i;
			}
		}
		return maxIndex;
	}
	int argabsmax(int line,int begin,int end,int dim)
	{	
		if (dim==0){
			return (*this).argabsmaxRow(line,begin,end);			
		}
		if (dim==1){
			return (*this).argabsmaxCol(line,begin,end);
		}
	}