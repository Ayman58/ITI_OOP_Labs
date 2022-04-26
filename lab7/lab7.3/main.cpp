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
class shape
{
protected:

    int color;
public:
    shape(){color=0;}
    shape(int c){color=c;}
    void setmycolor(int c){color=c;}
    virtual void Draw ()=0; //pure virtual function

};
class Line:public shape
{
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
    Line(int x1,int y1,int x2,int y2, int c):shape(c), s(x1,y1),e(x2,y2){}
    Line(Point p1,Point p2, int c):s(p1),e(p2){setmycolor(c);}

    void setPointStart(Point a){s=a;}
    void setPointEnd(Point a){e=a;}
    Point getPointStart(){return s;}
    Point getPointEnd(){return e;}

    void Draw(){
        setcolor(color);
        line(s.getPointX(),s.getPointY(),e.getPointX(),e.getPointY());
    }
};
class Rect:public shape
{
    Point ul,lr;
public:
    Rect()
    {
        ul.setPointX(0);
        ul.setPointY(0);

        lr.setPointX(0);
        lr.setPointY(0);
    }
    Rect(int x1,int y1,int x2,int y2,int c):shape(c), ul(x1,y1),lr(x2,y2){}
    Rect(Point p1,Point p2,int c):shape(c),ul(p1),lr(p2){}

    void setPointUl(Point a){ul=a;}
    void setPointLr(Point a){lr=a;}
    Point getPointUl(){return ul;}
    Point getPointlr(){return lr;}
    void Draw(){
        setcolor(color);
        rectangle(ul.getPointX(),ul.getPointY(),lr.getPointX(),lr.getPointY());
    }
};
class Circle:public shape
{
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
    Circle(int x,int y,int a,int c):shape(c),center(x,y){rad=a;}
    Circle(Point p,int a,int c):shape(c),center(p){rad=a;}

    void setPoint(Point a){center=a;}
    void setRad(int a){rad=a;}
    Point getPoint(){return center;}
    Point getRad(){return rad;}

    void Draw(){
        setcolor(color);
        circle(center.getPointX(),center.getPointY(),rad);
    }
};

class Picture{
    int shnum;
    shape** pshape;// shape* pshape[];
    //Rect* prect;
    //int rectNum;
   // Line* pline;
   // int lineNum;
   // Circle* pcircle;
   // int circleNum;
public:
    Picture(){
        shnum=0;
        pshape=NULL;
       // prect=NULL;
        //pline=NULL;
        //pcircle=NULL;
       // rectNum=lineNum=circleNum=0;
    }

    Picture(shape** sharr,int N ){
        shnum=N;
        pshape=sharr;


       /* prect=rptr;
        rectNum=rnum;
        pline=lptr;
        lineNum=lnum;
        pcircle=cptr;
        circleNum=cnum;*/
    }
//void setshape(int , shape**);
void setshape(int n, shape** shptr)
{
    shnum= n;
    pshape= shptr;


 /*   void setRect(Rect* pr,int rn){
        prect=pr;
        rectNum=rn;
    }
    void setLine(Line* pl,int ln){
        pline=pl;
        lineNum=ln;
    }
    void setCircle(Circle* pc,int cn){
        pcircle=pc;
        circleNum=cn;*/
}
    void Paint()
    {
        for(int i=0;i<shnum;i++)
            {
                pshape[i]->Draw();}

       /* for(int i=0;i<rectNum;i++) {prect[i].Draw();}
        for(int i=0;i<lineNum;i++) {pline[i].Draw();}
        for(int i=0;i<circleNum;i++) {pcircle[i].Draw();}*/
    }
};

int main()
{
    initwindow(400,400);
    shape* shpArr[5];
    Picture p;

    /*Rect r(50,50,100,100,6); r.Draw();
    Line l(110,120,220,230,4); l.Draw();
    Circle c(200,200,50,7); c.Draw();

    Rect rarr [2]={Rect(10,20,30,40,2),Rect(50,60,70,80,9)};
    Circle carr [3]={Circle(10,20,10,3),Circle(20,30,30,5),Circle(40,50,20,8)};
    Line larr [1]={Line(20,20,30,30,6)};*/
    Circle c(70,100,50,3);
    Rect r(200,250,70,70,2);
    Line l(200,200,30,30,6);
    shpArr[0]=&c;
    shpArr[1]=&r;
    shpArr[2]=&l;


    p.setshape(3,shpArr);
    p.Paint();

    getch();
    closegraph();
}
