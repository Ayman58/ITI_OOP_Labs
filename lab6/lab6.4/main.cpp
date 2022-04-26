#include <iostream>
#include <graphics.h>
using namespace std;
class Point{
    int x,y;
public:

    Point(){x=y=0;}
    Point(int a){x=y=a;}
    Point(int a,int b){x=a; y=b;}

    int getPointX() {return x;}
    int getPointY(){return y;}
    void setPointX(int a){x=a;}
    void setPointY(int a){y=a;}

    ~Point() {cout<<"Point destructor"<<endl;}
};
class Line{
    Point s,e;
public:
    Line()
    {
        s.setPointX(0);
        s.setPointY(0);
        e.setPointX(0);
        e.setPointY(0);
    }
    Line(Point p1):s(p1){}
    Line(int x1,int y1,int x2,int y2):s(x1,y1),e(x2,y2){}
    Line(Point p1,Point p2):s(p1),e(p2){}

    void setPointStart(Point a){s=a;}
    void setPointEnd(Point a){e=a;}
    Point getPointStart(){return s;}
    Point getPointEnd(){return e;}

    void Draw(){
        setcolor(RED);
        line(s.getPointX(),s.getPointY(),e.getPointX(),e.getPointY());
    }
};
class Rect{
    Point ul,lr;
public:
    Rect()
    {
        ul.setPointX(0);
        ul.setPointY(0);

        lr.setPointX(0);
        lr.setPointY(0);
    }
    Rect(int x1,int y1,int x2,int y2):ul(x1,y1),lr(x2,y2){}
    Rect(Point p1,Point p2):ul(p1),lr(p2){}

    void setPointUl(Point a){ul=a;}
    void setPointLr(Point a){lr=a;}
    Point getPointUl(){return ul;}
    Point getPointlr(){return lr;}
    void Draw(){
        setcolor(YELLOW);
        rectangle(ul.getPointX(),ul.getPointY(),lr.getPointX(),lr.getPointY());
    }
};
class Circle{
    Point center;
    int rad;
public:

    Circle()
    {
        center.setPointX(0);
        center.setPointY(0);
        rad=0;
    }
    Circle(int a){rad=a;}
    Circle(int x,int y,int a):center(x,y){rad=a;}
    Circle(Point p,int a):center(p){rad=a;}

    void setPoint(Point a){center=a;}
    void setRad(int a){rad=a;}
    Point getPoint(){return center;}
    Point getRad(){return rad;}

    void Draw(){
        setcolor(GREEN);
        circle(center.getPointX(),center.getPointY(),rad);
    }
};

class Picture{
    Rect* prect;
    int rectNum;
    Line* pline;
    int lineNum;
    Circle* pcircle;
    int circleNum;
public:
    Picture(){
        prect=NULL;
        pline=NULL;
        pcircle=NULL;
        rectNum=lineNum=circleNum=0;
    }

    Picture(Rect* rptr,int rnum,Line* lptr,int lnum,Circle* cptr,int cnum){
        prect=rptr;
        rectNum=rnum;
        pline=lptr;
        lineNum=lnum;
        pcircle=cptr;
        circleNum=cnum;
    }

    void setRect(Rect* pr,int rn){
        prect=pr;
        rectNum=rn;
    }
    void setLine(Line* pl,int ln){
        pline=pl;
        lineNum=ln;
    }
    void setCircle(Circle* pc,int cn){
        pcircle=pc;
        circleNum=cn;
    }
    void Paint()
    {
        for(int i=0;i<rectNum;i++) {prect[i].Draw();}
        for(int i=0;i<lineNum;i++) {pline[i].Draw();}
        for(int i=0;i<circleNum;i++) {pcircle[i].Draw();}
    }
};

int main()
{
    initwindow(400,400);

    //Rect r(50,50,100,100);
    //r.Draw();

    //Line l(110,120,220,230);
   // l.Draw();

    //Circle c(200,200,50);
    //c.Draw();

    Rect rarr [2]={Rect(10,20,30,40),Rect(50,60,70,80)};
    Circle carr [3]={Circle(10,20,10),Circle(20,30,30),Circle(40,50,20)};
    Line larr [1]={Line(20,20,30,30)};

    Picture p(rarr,2,larr,1,carr,3);
    p.Paint();

    getch();
    closegraph();
}
