// 减法
        Matrix operator-(Matrix matb){
                Matrix mata=*this;
                int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
                if( (rowa!=rowb)||(cola!=colb))
                {
                        return NULL;
                }
                Matrix newMat(rowa,cola);
                int i,j;
                for(i=1;i<=rowa;++i)
                        for(j=1;j<=cola;++j)
                        {
                                newMat(i,j)=mata(i,j)-matb(i,j);
                        }
                return newMat;
        }
		Matrix operator-(){
                Matrix mat=*this;
				int row=mat.row(),col=mat.col();
                Matrix newMat(row,col);
                int i,j;
                for(i=1;i<=row;++i)
                        for(j=1;j<=col;++j)
                        {
                                newMat(i,j)=-mat(i,j);
                        }
                return newMat;
        }
		
		
        Matrix operator-=(Matrix matb){
                Matrix mata=*this;
                int rowa=mata.row(),rowb=matb.row(),cola=mata.col(),colb=matb.col();
                if( (rowa!=rowb)||(cola!=colb))
                {
                        return NULL;
                }
                int i,j;
                for(i=1;i<=rowa;++i)
                        for(j=1;j<=cola;++j)
                        {
                                mata(i,j)-=matb(i,j);
                        }
                return mata;
        }
        
        Matrix operator-(float C){
                Matrix mat=*this;
                int row=mat.row(),col=mat.col();
                Matrix newMat(row,col);
                int i,j;
                for(i=1;i<=row;++i)
                        for(j=1;j<=col;++j)
                        {
                                newMat(i,j)=mat(i,j)-C;
                        }
                return newMat;
        }
        Matrix operator-=(float C){
                Matrix mat=*this;
                int row=mat.row(),col=mat.col();
                int i,j;
                for(i=1;i<=row;++i)
                        for(j=1;j<=col;++j)
                        {
                                mat(i,j)-=C;
                        }
                return mat;
        }