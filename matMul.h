//乘法

	Matrix operator* (Matrix matb){
			Matrix mata=*this;
			int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
			if(rowb!=cola){
				return NULL;
			}
			int i,j,k;
			Matrix retMat(rowa,colb);
			for(i=1;i<=rowa;++i){
				for(j=1;j<=colb;++j)
					{	
						retMat(i,j)=0;
						for(k=1;k<=rowb;++k){
							retMat(i,j)+=mata(i,k)*matb(k,j);
						}
					}
			}
			return retMat;
	}
	
	Matrix operator*=(Matrix matb){
			Matrix mata=*this;
			int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
			if(rowb!=cola){
				return NULL;
			}
			int i,j,k;
			Matrix retMat(rowa,colb);
			for(i=1;i<=rowa;++i){
				for(j=1;j<=colb;++j)
					{	
						retMat(i,j)=0;
						for(k=1;k<=rowb;++k){
							retMat(i,j)+=mata(i,k)*matb(k,j);
						}
					}
			}
			return retMat;
	}
	Matrix operator*(float C){
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		Matrix newMat(row,col);
		int i,j;
		for(i=1;i<=row;++i)
			for(j=1;j<=col;++j)
			{
				newMat(i,j)=mat(i,j)*C;
			}
		return newMat;
	}
	Matrix operator*=(float C){
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		int i,j;
		for(i=1;i<=row;++i)
			for(j=1;j<=col;++j)
			{
				mat(i,j)*=C;
			}
		return mat;
	}
	Matrix operator*(int C){
		Matrix mat=*this;
		float Cf=float(C);
		return mat*Cf;
	}
	Matrix operator*=(int C){
		Matrix mat=*this;
		float Cf=float(C);
		return mat*=Cf;
	}