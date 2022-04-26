/*3- Composition Example: Point, Rect, Circle, Line + drawing graphics.
	- each class should have: attributes, constructors, setters, Draw()*/
#include <iostream>
#include <Graphics.h>
using namespace std;
class point
{
protected:
    int x;
    int y;
public:
   void setx(int a){x= a;}
   void sety(int b){y= b;}
   int getx(){return x;}
   int gety(){return y;}

    point (){x=y=0;}
    point (int a){x=y=a;}
    point (int a,int b){x=a; y=b;}

   ~point(){ }
};
class rect
{
    point UL;
    point LR;
public:
void setUL(int a,int b)
{
    UL.setx(a);
    UL.sety(b);
}
void setLR(int a,int b)
{
    LR.setx(a);
    LR.sety(b);
}

point getUL()
{
    return UL;//getx(),gety();
}
point getLR()
{
    return getx(),gety();

}

    rect()
    {
    UL.setx(10);
    UL.sety(10);
    LR.setx(15);
    LR.sety(15);
    }

    rect (int x,int y,int x2,int y2):UL (x,y), LR(x2,y2)
    {
        ///UL.setx(x1);
        ///UL.sety(y1);
        /// LR.setx(x2);
        ///LR.sety(y2);
    }

     rect (point p1,point p2)//:UL (p1.x ,p1.y), LR(p2.x,p2.y)
    {
        UL.setx(p1.getx());
        UL.sety(p1.gety());
        UL.setx(p2.getx());
        UL.sety(p2.gety());


    }
    void draw()
    {
        setcolor(WHITE);
        rectangle(UL.getx(),UL.gety(),LR.getx(),LR.gety());
    }

};
class linee
{
    point start;
    point End;
 public:

    void setstart(int a,int b)
{
    start.setx(a);
    start.sety(b);
}
void setEnd(int a,int b)
{
    End.setx(a);
    End.sety(b);
}

point getstart()
{
    return start;
}
point getEnd()
{
    return End;
}

    linee()
    {
    start.setx(10);
    start.sety(10);
    End.setx(15);
    End.sety(15);
    }

    linee (int x,int y,int x2,int y2):start(x,y),End(x2,y2)
    {
        ///start.setx(x1);
        ///start.sety(y1);
        ///
        ///
    }

     linee (point p1,point p2)//:UL (p1.x ,p1.y), LR(p2.x,p2.y)
    {
        start.setx(p1.getx());
        start.sety(p1.gety());
        End.setx(p2.getx());
        End.sety(p2.gety());

    }
    void draw()
    {
        setcolor(WHITE);
        line(start.getx(),start.gety(),End.getx(),End.gety());
        //rectangle(UL.getx(),UL.gety(),LR.getx(),LR.gety());
    }
} ;

int main()
{
    initwindow(400,400);
    rect r;//(40,40,20,20);
    r.setUL(40,40);
    r.setLR(20,20);
    r.draw();

    linee l(12,12,30,30);//(12,12,30,30);
//    l.setUL(12,12);
 //   l.setLR(30,30);
    l.draw();
   // cout << "Hello world!" << endl;
   getch();
   closegraph();
    return 0;
}
