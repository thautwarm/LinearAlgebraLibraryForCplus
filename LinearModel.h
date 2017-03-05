#ifndef _MATRIX_
#include "Mat.h"
#define _MATRIX_
#endif
#ifndef _NUMCPP_
#include "NumCpp.h"
#define _NUMCPP_
#endif
// Vector LinearRegression(Matrix X,Vector y){
	// int row=X.row(),col=X.col(),y_col=y.size;
	// if (row<col||y_col!=row){
	// return Vector();
	// }
	// Matrix  yMat(y);
	// Matrix XT= X.T();
	// Matrix C=hstack(XT*X,XT*yMat);
	// Vector beta=GaussEq(C,0);
	// return beta;
// }
// Vector LinearRegression(Matrix X,Matrix y){
	// int row=X.row(),col=X.col(),y_col=y.col(),y_row=y.row();
	// if (row<col||y_col!=1||y_row!=row){
	// return Vector();
	// }
	// Matrix  yMat(y);
	// Matrix XT= X.T();
	// Matrix C=hstack(XT*X,XT*yMat);	 
	// Vector beta=GaussEq(C,0);
	// return beta;
// }
Vector LinearRegression(Matrix X,Vector y){
	int row=X.row(),col=X.col(),y_col=y.size;
	if (row<col||y_col!=row){
	return Vector();
	}
	Matrix  yMat(y);
	Matrix XT= X.T();
	Matrix beta= (XT*X).inv()*(XT*yMat);
	return beta.toVector();
}

class LinearRegressor{
	public:
	Vector beta;
	LinearRegressor(Matrix X,Vector y){
		beta=LinearRegression(X,y);
	}
	LinearRegressor(Matrix X,Matrix y){
		Vector yVec=y.toVector();
		beta=LinearRegression(X,yVec);
	}
	double predict(Vector x){
		int size=beta.size;
		double tag;
		if(x.size!=size){
			return 233.233; 
		}
		else{
			tag=0;
			int i;
			for(i=1;i<=size;++i)
				tag+=x(i)*beta(i);
		}
		return tag;
	}
	Vector predict(Matrix X){
		int size=beta.size, col=X.col();
		Matrix betaMat(beta);
		if (col!=betaMat.row()){
			return Vector();
		}
		Vector tag= (X*betaMat).toVector();
		return tag;
	}
	
};

