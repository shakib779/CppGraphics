#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;
const int INSIDE = 0;
const int LEFT   = 1;
const int RIGHT  = 2;
const int BOTTOM = 4;
const int TOP    = 8;

const int x_max = 10;
const int y_max = 10;
const int x_min = 0;
const int y_min = 0;

int encode(int x, int y){
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

string tob(int n){
    string s = "";
    while(n > 0){
        s += (n%2) + 48;
        n /= 2;
    }
    for(int i = s.size(); i < 4; i++){
        s += "0";
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){

    int x1, x2, y1, y2;
    x1 = -4; y1 = 8;
    x2 = 15; y2 = 21;

    cout << "Four bit region code for endpoint (" << x1 << ", " << y1 << ") = " << tob(encode(x1, y1)) << "\n";
    cout << "Four bit region code for endpoint (" << x2 << ", " << y2 << ") = " << tob(encode(x2, y2)) << "\n";

    return 0;
}
