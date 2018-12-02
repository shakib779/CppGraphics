#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

struct Point{
    int x, y;
};

struct Line {
    int x1, y1, x2, y2;
};

string side(Line line, Point p){
    int val = (p.y - line.y1)*(line.x2 - line.x1) - (p.x - line.x1)*(line.y2 - line.y1);
    if(val > 0) return ("Right");
    else if(val < 0) return ("Left");
    else return ("Point is on the Line");
}

int main(){
    Line line = Line({-30, 10, 29, -15});

    Point p1 = Point({0, 0});
    Point p2 = Point({-9057, 3835});
    Point p3 = Point({15, 28});
    Point p4 = Point({45, 18});
    Point p5 = Point({-30, 10});
    Point p6 = Point({29, -15});

    cout << side(line, p1) << "\n";
    cout << side(line, p2) << "\n";
    cout << side(line, p3) << "\n";
    cout << side(line, p4) << "\n";
    cout << side(line, p5) << "\n";
    cout << side(line, p6) << "\n";

    return 0;
}

