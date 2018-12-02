#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

double degtorad(double x){
    return (x*3.14159)/180.0;
}

struct Matrix {
    int row;
    int col;
    vector < vector <double> > val;
    Matrix(){
        row = 0;
        col = 0;
    }
    Matrix(int row_sz, int col_sz, double a[]){
        row = row_sz;
        col = col_sz;
        vector <double> tmp;
        for(int i = 0, j = 0; i < row*col; i++, j++){
            if(j == col_sz){
                val.push_back(tmp);
                tmp.clear();
                j = 0;
            }
            tmp.push_back(a[i]);
        }
        val.push_back(tmp);
        tmp.clear();
    }
    void print(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cout << setw(10) << val[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void graphPolygonPrint(){
        int i, maxx, maxy;
        maxx = getmaxx();
        maxy = getmaxy();

        for(i = 0; i < col; i++){
            if(i == col - 1){
                line(val[0][i] + maxx/2, maxy/2 - val[1][i], val[0][0] + maxx/2, maxy/2 - val[1][0]);
            }
            else{
                line(val[0][i] + maxx/2, maxy/2 - val[1][i], val[0][i + 1] + maxx/2, maxy/2 - val[1][i + 1]);
            }
        }
    }
    Matrix operator * (const Matrix &p){
        int ii, jj, i, j;
        double mul[10][10], tmp[109];

        for(ii = 0; ii < row; ii++){
            for(jj = 0; jj < p.col; jj++){
                mul[ii][jj] = 0;
            }
        }

        for(ii = 0; ii < row; ii++){
            for(jj = 0; jj < p.col; jj++){
                for(i = 0, j = 0; i < col, j < p.row; i++, j++){
                    mul[ii][jj] += val[ii][i]*p.val[j][jj];
                }
            }
        }

        for(ii = 0, i = 0; ii < row; ii++){
            for(jj = 0; jj < p.col; jj++){
                tmp[i++] = mul[ii][jj];
            }
        }

        Matrix ret = Matrix(row, p.col, tmp);
        return ret;
    }
};

double conv(double n){
    double CONV = 35.0;
    return n*CONV;
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);


    int i, n = 3;
    double h = -3.0, k = -3.0, deg = 60.0;
    double Vx[] = {0, 1, 5};
    double Vy[] = {0, 1, 2};

    h = conv(h), k = conv(k);
    for(i = 0; i < n; i++){
        Vx[i] = conv(Vx[i]);
        Vy[i] = conv(Vy[i]);
    }

    double a[] = {1, 0, h, 0, 1, k, 0, 0, 1};
    double b[] = {cos(degtorad(deg)), -sin(degtorad(deg)), 0, sin(degtorad(deg)), cos(degtorad(deg)), 0, 0, 0, 1};
    double c[] = {1, 0, -h, 0, 1, -k, 0, 0, 1};
    double d[] = {Vx[0], Vx[1], Vx[2], Vy[0], Vy[1], Vy[2], 1, 1, 1};

    Matrix T = Matrix(3, 3, a);
    Matrix R = Matrix(3, 3, b);
    Matrix invT = Matrix(3, 3, c);
    Matrix polygon = Matrix(3, 3, d);

    setcolor(GREEN);
    polygon.graphPolygonPrint();

    Matrix rot = T*R*invT*polygon;

    setcolor(CYAN);
    rot.graphPolygonPrint();

    getch();
    getch();

}

