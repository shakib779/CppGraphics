/**


    ***   A C++ Graphics program for tangent curve  ***


    [[[[[[[[[[[[[[[      ]]]]]]]]]]]]]]]
    [::::::::::::::      ::::::::::::::]
    [::::::::::::::      ::::::::::::::]
    [::::::[[[[[[[:      :]]]]]]]::::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [:::::[   Shakib Chowdhury   ]:::::]
    [:::::[        CSE, CU       ]:::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [:::::[                      ]:::::]
    [::::::[[[[[[[:      :]]]]]]]::::::]
    [::::::::::::::      ::::::::::::::]
    [::::::::::::::      ::::::::::::::]
    [[[[[[[[[[[[[[[      ]]]]]]]]]]]]]]]

*/

#include <bits/stdc++.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
#include<stdlib.h>
#include <unistd.h>

using namespace std;

/*** data types ***/
#define vint             vector <int>
#define pint             pair <int, int>
#define vstring          vector <string>
#define vlonglong        vector <long long>
#define plonglong        pair <long long, long long>


/************** Others ***************/
#define mem(a, b)        memset(a, b, sizeof(a))
#define read(f)          freopen(f, "r", stdin)
#define write(f)         freopen(f, "w", stdout)
#define FAST             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqr(x)           ((x)*(x))
#define all(x)           x.begin(), x.end()

/****************** Output ****************/
#define yes              cout << "Yes" << "\n"
#define YES              cout << "YES" << "\n"
#define no               cout << "No" << "\n"
#define NO               cout << "NO" << "\n"
#define dbg(x)           cerr << #x << " = " << x << endl
#define space            " "
#define newl             "\n"


/***********************************      STL printing output stream overloading start     ***********************************************/

template <typename T1, typename T2> inline ostream& operator << ( ostream& os, const pair<T1, T2>& p ){
    return os << "(" << p.first << "," << p.second << ")";
}

template <typename T> inline ostream &operator << (ostream & os, const vector<T>& v){
    bool first = true;
    os << "{";
    for(unsigned int i = 0; i < v.size(); i++){
        if(!first) os << ",";
        os << v[i];
        first = false;
    }
    return os << "}";
}

template <typename T> inline ostream &operator << (  ostream & os, const set<T>& v ){
    bool first = true;
    os << "{";
    for ( typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii ) {
        if( !first ) os << ",";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template <typename T1, typename T2> inline ostream &operator << ( ostream & os, const map<T1, T2>& v ){
    bool first = true;
    os << "{";
    for ( typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii ) {
        if( !first ) os << ",";
        os << *ii ;
        first = false;
    }
    return os << "}";
}

/***********************************      Mathematical function     ***********************************************/

template <typename T> bool isPrime(T n){
    T i, lmt = sqrt(n);
    for(i = 2; i <= lmt; i++)
        if(n%i == 0) return false;
    return true;
}

template <typename T> T gcd(T a, T b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

template <typename T> T BigMod(T b, T p, T m){
    if(p == 0) return 1%m;
    else if(p&1) return ((b%m)*(BigMod(b, p - 1, m)%m))%m;
    else{
        T s = BigMod(b, p/2, m);
        return ((s%m)*(s%m))%m;
    }
}

template <typename T> T power(T b, T p){
    if(p == 0) return 1;
    else if(p&1) return b*power(b, p - 1);
    else {
        T ret = power(b, p/2);
        return ret*ret;
    }
}

template <typename T> T ModInv(T b, T m){
    if(isPrime(b)) return BigMod(b, m - 2, m)%m;
    else if(gcd(b, m) == 1)
        return BigMod(b, m - 1, m)%m;
}

template <typename T> T egcd(T a, T b, T &x, T &y){
    T d;
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    else{
        T x1, y1;
        d = egcd(b%a, a, x1, y1);
        x = y1 - (b/a)*x1;
        y = x1;
    }
    return d;
}

/***********************************      Other function     ***********************************************/

int toint(string s){
    int i, j, l;
    int num;
    l = s.size();
    for(i = l - 1, j = 0, num = 0; i >= 0; i--, j++){
        num += (s[i] - 48)*power(10, j);
    }
    return num;
}

/****************************************************** Constant values **********************************************************/

const double    pi  = acos(-1);
const int       inf = (1<<30);
const long long INF = (1LL<<62) - 1;
const int       mod = (int) 1e9 + 7;
const double    EPS = 1e-9;

const int dx8[] = {-1, 0, +1, -1, +1, -1, 0, +1};
const int dy8[] = {+1, +1, +1, 0, 0, -1, -1, -1};

const int dx4[] = { 0,-1,+1, 0};
const int dy4[] = {+1, 0, 0,-1};

const int dx2[] = {+1, 0};
const int dy2[] = { 0,+1};

const int dxkn[] = {1, -1, 1, -1, 2, -2, -2, 2};
const int dykn[] = {2, 2, -2, -2, 1, 1, -1, -1};


/*******************************************************************************************************************************************************/
/*******************************************************************************************************************************************************/
/***                                                                                                                                                   */
/***                                                                  MAIN CODE                                                                        */
/***                                                                                                                                                   */
/*******************************************************************************************************************************************************/
/*******************************************************************************************************************************************************/


/**

BLUE         1
GREEN        2
CYAN         3
RED          4
MAGENTA      5
BROWN        6
LIGHTGRAY    7
DARKGRAY     8
LIGHTBLUE    9
LIGHTGREEN   10
LIGHTCYAN    11
LIGHTRED     12
LIGHTMAGENTA 13
YELLOW 14

*/

double degtorad(double x){
    return (x*pi)/180.0;
}

int main(){
    initwindow(1597, 1000);
    //int gd = DETECT, gm = 1000;
    //initgraph(&gd, &gm, NULL);

    int i, angle, maxx, maxy, prevx, prevy;
    double x, y;

    maxx = getmaxx();     /// get window width
    maxy = getmaxy();     /// get window width

    line(0, maxy/2, maxx, maxy/2);    /// x axis
    line(maxx/2, 0, maxx/2, maxy);    /// y axis

    line(maxx/2 - 5, maxy/2 - 100*sin(degtorad(90)), maxx/2 + 5, maxy/2 - 100*sin(degtorad(90)));
    outtextxy(maxx/2 - 30, maxy/2 - 100*sin(degtorad(90)) - 10, "1");
    line(maxx/2 - 5, maxy/2 - 200*sin(degtorad(90)), maxx/2 + 5, maxy/2 - 200*sin(degtorad(90)));
    outtextxy(maxx/2 - 30, maxy/2 - 200*sin(degtorad(90)) - 10, "2");
    line(maxx/2 - 5, maxy/2 + 100*sin(degtorad(90)), maxx/2 + 5, maxy/2 + 100*sin(degtorad(90)));
    outtextxy(maxx/2 - 30, maxy/2 + 100*sin(degtorad(90)) - 10, "-1");
    line(maxx/2 - 5, maxy/2 + 200*sin(degtorad(90)), maxx/2 + 5, maxy/2 + 200*sin(degtorad(90)));
    outtextxy(maxx/2 - 30, maxy/2 + 200*sin(degtorad(90)) - 10, "-2");

    outtextxy(maxx/2 + 10, maxy/2 + 10, "0");
    for(i = 1, angle = 0; i*90 <= maxx; i++){
        char s1[5], s2[5];
        sprintf(s1, "%d", i*90);
        sprintf(s2, "%d", -i*90);
        outtextxy(maxx/2 + i*90 - 10, maxy/2 + 40, s1);
        line(maxx/2 + i*90, maxy/2 - 5, maxx/2 + i*90, maxy/2 + 5);
        outtextxy(maxx/2 - i*90 - 10, maxy/2 + 40, s2);
        line(maxx/2 - i*90, maxy/2 - 5, maxx/2 - i*90, maxy/2 + 5);
    }


    settextstyle(3, HORIZ_DIR, 3);
    setcolor(11);
    outtextxy(200, 300, "tangent curve,  y = tan(x)");


    setcolor(10);
    for(x = 0, prevx = maxx/2, prevy = maxy/2; x <= maxx/2; x++) {
        y = 100*tan(degtorad(angle));
        y = maxy/2 - y;
        putpixel(maxx/2 + x, y, 12);
        line(prevx, prevy, maxx/2 + x, y);
        prevx = maxx/2 + x;
        prevy = y;
        angle++;
        //delay(1);
    }

    for(x = -1, angle = -1,  prevx = maxx/2, prevy = maxy/2; x > -(maxx/2); x--) {
        y = 100*tan(degtorad(angle));
        y = maxy/2 - y;
        putpixel(maxx/2 + x, y, 12);
        line(prevx, prevy, maxx/2 + x, y);
        prevx = maxx/2 + x;
        prevy = y;
        angle--;
        //delay(1);
    }

    //main();

    getch();
    closegraph();

    return 0;
}
