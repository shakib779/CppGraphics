
/**[[[[[[[[[[[[[[[      ]]]]]]]]]]]]]]]
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
   [[[[[[[[[[[[[[[      ]]]]]]]]]]]]]]]**/


#include <bits/stdc++.h>
#include<graphics.h>
#include <termios.h>

using namespace std;

char get(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    //printf("%c\n",buf);
    return buf;
}

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

template <typename T1, typename T2> inline ostream& operator << ( ostream& os, const pair<T1, T2>& p )
{
    return os << "(" << p.first << "," << p.second << ")";
}

template <typename T> inline ostream &operator << (ostream & os, const vector<T>& v)
{
    bool first = true;
    os << "{";
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(!first) os << ",";
        os << v[i];
        first = false;
    }
    return os << "}";
}

template <typename T> inline ostream &operator << (  ostream & os, const set<T>& v )
{
    bool first = true;
    os << "{";
    for ( typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii )
    {
        if( !first ) os << ",";
        os << *ii;
        first = false;
    }
    return os << "}";
}
template <typename T1, typename T2> inline ostream &operator << ( ostream & os, const map<T1, T2>& v )
{
    bool first = true;
    os << "{";
    for ( typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii )
    {
        if( !first ) os << ",";
        os << *ii ;
        first = false;
    }
    return os << "}";
}

/***********************************      Mathematical function     ***********************************************/

template <typename T> bool isPrime(T n)
{
    T i, lmt = sqrt(n);
    for(i = 2; i <= lmt; i++)
        if(n%i == 0) return false;
    return true;
}

template <typename T> T gcd(T a, T b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

template <typename T> T BigMod(T b, T p, T m)
{
    if(p == 0) return 1%m;
    else if(p&1) return ((b%m)*(BigMod(b, p - 1, m)%m))%m;
    else
    {
        T s = BigMod(b, p/2, m);
        return ((s%m)*(s%m))%m;
    }
}

template <typename T> T power(T b, T p)
{
    if(p == 0) return 1;
    else if(p&1) return b*power(b, p - 1);
    else
    {
        T ret = power(b, p/2);
        return ret*ret;
    }
}

template <typename T> T ModInv(T b, T m)
{
    if(isPrime(b)) return BigMod(b, m - 2, m)%m;
    else if(gcd(b, m) == 1)
        return BigMod(b, m - 1, m)%m;
}

template <typename T> T egcd(T a, T b, T &x, T &y)
{
    T d;
    if(a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    else
    {
        T x1, y1;
        d = egcd(b%a, a, x1, y1);
        x = y1 - (b/a)*x1;
        y = x1;
    }
    return d;
}

/***********************************      Other function     ***********************************************/

int toint(string s)
{
    int i, j, l;
    int num;
    l = s.size();
    for(i = l - 1, j = 0, num = 0; i >= 0; i--, j++)
    {
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

#define KEY_UP         65
#define KEY_DOWN       66
#define KEY_LEFT       68
#define KEY_RIGHT      67
#define KEY_ESC        27

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    char c;
    int x = 300, y = 300, radius = 50;

    while(1){
        cleardevice();
        circle(x, y, radius);
        //setbkcolor(BLUE);
        setfontcolor(GREEN);
        outtextxy(100, 50, "Press ESC key two times to exit");
        setfill(RED);
        system("clear");
        c = get();
        cout << c << endl;
        if(c == '+'){
            radius += 10;
        }
        else if(c == '-'){
            radius -= 10;
        }
        else if(c == KEY_UP){
            y -= 10;
        }
        else if(c == KEY_DOWN){
            y += 10;
        }
        else if(c == KEY_LEFT){
            x -= 10;
        }
        else if(c == KEY_RIGHT){
            x += 10;
        }
        else if(c == KEY_ESC){
            c = get();
            if(c == KEY_ESC)
                exit(0);
        }
        else{
            radius += 0;
        }
    }

    getchar();
    closegraph();
    return 0;
}
