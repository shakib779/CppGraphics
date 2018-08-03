/**


    ***   A C++ Graphics program code to wish happy birthday with happy birthday tone using beep  ***


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

char *s[]= {"H", "A", "P", "P", "Y"};
char *ss[]= {"B", "I", "R", "T", "H", "D", "A", "Y"};
char *sss[]= {" ", " ", "N", "A", "M", "E", " "};                     /// change the name here to wish

int a[] = {9, 10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8};
int p = 0;

int main(){
    int gd = DETECT, gm = 1000, x = 250, y = 25, font = 0;

    initwindow(1597, 1000);

    setcolor(a[p%14]), p++;

    for (int i = 1; i <= 3; i++){
        settextstyle(4, HORIZ_DIR, 1);
        if(i == 1){
            outtextxy(x + 100, y, "                                    Yo :D        ");
            delay(2000);
        }
        if(i == 3){
            outtextxy(x + 100, y, "__________________________________________________");
            delay(2000);
        }
        y = y + 25;
    }

    setcolor(a[p%14]), p++;

    y += 50;
    settextstyle(7, HORIZ_DIR, 10);
    for(int i = 1, x = 450; i <= 5; i++){
        outtextxy(x, y, s[i - 1]);
        if(i == 1) Beep(264, 125);
    if(i == 2) Beep(264, 125);
    if(i == 3) Beep(297, 500);
    if(i == 4) Beep(264, 500);
    if(i == 5) Beep(352, 500);
        x += 125;
    }

    setcolor(a[p%14]), p++;

    y += 150;

    for(int i = 1, x = 300; i <= 8; i++){
        outtextxy(x, y, ss[i - 1]);
        if(i == 1) Beep(330, 1000);
        if(i == 2) Beep(264, 125);
        if(i == 3) Beep(264, 125);
        if(i == 4) Beep(297, 500);
        if(i == 5) Beep(264, 500);
        if(i == 6) Beep(396, 500);
        if(i == 7) Beep(352, 1000);
        if(i == 8) Beep(264, 125);
        if(i == 2) x += 75;
        else x += 125;
    }

    setcolor(9);

    y += 150;

    for(int i = 1, x = 350; i <= 7; i++){
        outtextxy(x, y, sss[i - 1]);

        if(i == 1 || i == 4) x += 160;
        else x += 120;

        if(i == 1) Beep(264, 125);
        if(i == 2) Beep(264, 500);
        if(i == 3) Beep(440, 500);
        if(i == 4) Beep(352, 250);
        if(i == 5) {Beep(352, 125);

        Beep(330, 500);
        Beep(297, 1000);}
    }

    setcolor(a[p%14]), p++;

    settextstyle(4, HORIZ_DIR, 1);
    for(int i = 1, x = 120, y = 500, v = 1150; i <= 10; i++){
        if(i == 1 || i == 2){
            outtextxy(x, y, "    i  i  i  i  i  ");
            outtextxy(x + v, y, "    i  i  i  i  i  ");
        }
        if(i == 3){
            outtextxy(x, y, "__i_i_i_i_i__");
            outtextxy(x + v, y, "__i_i_i_i_i__");
        }
        if(i == 4){
            outtextxy(x - 5, y, "|                    |");
            outtextxy(x - 5 + v, y, "|                    |");
        }
        if(i == 5){
            outtextxy(x - 37, y, "__|                    |__");
            outtextxy(x - 37 + v, y, "__|                    |__");
        }
        if(i == 6){
            outtextxy(x - 40, y, "|                             |");
            outtextxy(x - 40 + v, y, "|                             |");
        }
        if(i == 7){
            outtextxy(x - 72, y, "__|                             |__");
            outtextxy(x - 72 + v, y, "__|                             |__");
        }
        if(i == 8 || i == 9){
            outtextxy(x - 75, y, "|                                      |");
            outtextxy(x - 75 + v, y, "|                                      |");
        }
        if(i == 10){
            outtextxy(x - 75, y, "|___________________|");
            outtextxy(x - 75 + v, y, "|___________________|");

        }
        if(i == 1) Beep(466, 125);
        if(i == 2) Beep(466, 125);
        if(i == 3) Beep(440, 500);
        if(i == 4) Beep(352, 500);
        if(i == 5) Beep(396, 500);
        if(i == 6) Beep(352, 1000);
        if(i == 7) Beep(264, 125);
        if(i == 8) Beep(264, 125);
        if(i == 9) Beep(297, 500);
        if(i == 10) Beep(264, 500);
        y += 25;
    }

    Beep(352, 500);
    Beep(330, 1000);
    Beep(264, 125);
    Beep(264, 125);
    Beep(297, 500);
    Beep(264, 500);
    Beep(396, 500);
    Beep(352, 1000);
    Beep(264, 125);
    Beep(264, 125);
    Beep(264, 500);
    Beep(440, 500);
    Beep(352, 250);
    Beep(352, 125);
    Beep(330, 500);
    Beep(297, 1000);
    Beep(466, 125);
    delay(100);
    Beep(466, 125);
    delay(100);
    Beep(440, 500);
    delay(100);
    Beep(352, 500);
    delay(100);
    Beep(396, 500);
    delay(100);
    Beep(352, 1000);

    main();

    getch();
    closegraph();

    return 0;
}
