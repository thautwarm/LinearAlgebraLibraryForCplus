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
	Matrix operator*(double C){
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
	Matrix operator*=(double C){
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
		double Cf=double(C);
		return mat*Cf;
	}
	Matrix operator*=(int C){
		Matrix mat=*this;
		double Cf=double(C);
		return mat*=Cf;
	}
	void getLinear(Matrix mata,Matrix matb,Matrix matc){
		int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col(),rowc=matc.row(),colc=matc.col();
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		if(rowb!=cola||row!=rowa||col!=colb||rowc!=row||colc!=col){printf("error_getLinear\n"); return;}
			int i,j,k;
			for(i=1;i<=row;++i){
				for(j=1;j<=col;++j)
					{	
						mat(i,j)=0;
						for(k=1;k<=rowb;++k){
							mat(i,j)+=mata(i,k)*matb(k,j);
						}
						mat(i,j)+=matc(i,j);
					}
				
			}

	}
	void getMul(Matrix mata,Matrix matb){
		int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		if(rowb!=cola||row!=rowa||col!=colb){printf("error_getMul\n"); return;}
			int i,j,k;
			for(i=1;i<=row;++i){
				for(j=1;j<=col;++j)
					{	
						mat(i,j)=0;
						for(k=1;k<=rowb;++k){
							mat(i,j)+=mata(i,k)*matb(k,j);
						}
					}
				
			}

	}
	
	void getAdd(Matrix mata,Matrix matb){
		int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		if(row!=rowa||row!=rowb||col!=cola||col!=colb) {printf("error_getAdd\n"); return;}
			int i,j;
			for(i=1;i<=row;++i)
				for(j=1;j<=col;++j)
					mat(i,j)=mata(i,j)+matb(i,j);
	}
	void getSub(Matrix mata,Matrix matb){
		int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
		Matrix mat=*this;
		int row=mat.row(),col=mat.col();
		if(row!=rowa||row!=rowb||col!=cola||col!=colb) {printf("error_getSub\n"); return;}
			int i,j;
			for(i=1;i<=row;++i)
				for(j=1;j<=col;++j)
					mat(i,j)=mata(i,j)-matb(i,j);
	}
	
	void Hadamard(Matrix mata,Matrix matb){
	int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
	Matrix mat=*this;
	int row=mat.row(),col=mat.col();
	if(row!=rowa||row!=rowb||col!=cola||col!=colb) {printf("error_Hadamard\n"); return;}
			int i,j;
			for(i=1;i<=row;++i)
				for(j=1;j<=col;++j)
					mat(i,j)=mata(i,j)*matb(i,j);
	}
	
	void randomShack(){
		double sum=0,v;
		Matrix mat=*this;
		int i,j,row=mat.row(),col=mat.col();
		for(i=1;i<=row;i++)
			for(j=1;j<=col;++j)
				sum+=fabs(mat(i,j));
		sum/=row*col/100;
		rand()/(1.0*RAND_MAX);
		for(i=1;i<=row;i++)
			for(j=1;j<=col;++j)
			{ v=rand()/(1.0*RAND_MAX)*sum;
				mat+=(rand()%2==0)?v:-v;
			}
	}
	
	