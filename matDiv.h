	//除法
        Matrix operator/(double C){
                Matrix mat=*this;
                int row=mat.row(),col=mat.col();
                Matrix newMat(row,col);
                int i,j;
                for(i=1;i<=row;++i)
                        for(j=1;j<=col;++j)
                        {
                                newMat(i,j)=mat(i,j)/C;
                        }
                return newMat;
        }
        Matrix operator/=(double C){
                Matrix mat=*this;
                int row=mat.row(),col=mat.col();
                int i,j;
                for(i=1;i<=row;++i)
                        for(j=1;j<=col;++j)
                        {
                                mat(i,j)/=C;
                        }
                return mat;
        }
        Matrix operator/(int C){
                Matrix mat=*this;
                double Cf=double(C);
                return mat/Cf;
        }
        Matrix operator/=(int C){
                Matrix mat=*this;
                double Cf=double(C);
                return mat/=Cf;
        }