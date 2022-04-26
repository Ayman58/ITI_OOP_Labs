/*3- Class GeoShape:
class Geoshape
	- private members dim1, dim2
	- constrcutors & destructor
	- setters & getters
	- function CalcArea(return 0)

	- then we have to create 4 derived classes (Rectangle, Square, Circle, Triangle)
	in which they inherit from GeoShape base class.
	- override function CalcArea in these derived classes to claculate area according to each shape*/
#include <iostream>

using namespace std;

class Geoshape
{
protected:
    int dim1;
    int dim2;

public:
    getdim1(){return dim1;}
    getdim2(){return dim2;}
    setdim1(int d) {dim1=d;}
    setdim2(int d){dim2=d;}

    Geoshape(){dim1=dim2=0;}
    Geoshape(int d) {dim1=dim2=d;}
    Geoshape(int d,int d2){dim1=d; dim2=d2;}

    ~Geoshape()
    {
        cout<<" Geo distructor "<<endl;
    }


    float calcarea()
    {
        return 0;
    }

};
class Rectangle:public Geoshape
{
    int x,y;
public:

    Rectangle() {x=y=0;}

    Rectangle(int a,int b):Geoshape(a,b)
    {
        x=a;
        y=b;
    }

    float CalcArea(){
        return getdim1()*getdim2();
    }
};
class Square: protected Geoshape{
    int x,y;
    public:
        Square(){
        x=y=0;
    }
    Square(int a):Geoshape(a){
        x=y=a;
    }

    float CalcArea()
    {
        return getdim1()*getdim2();
    }
};

class Circle: public Geoshape{
    int x,y;
    public:
    Circle(int a):Geoshape(a){
        x=y=a;
    }

    float CalcArea(){
        return (int) 3.14*getdim1()^2;
    }
};
class Triangle: public Geoshape{
    int x,y;
public:
    Triangle(int a,int b):Geoshape(a,b){
        x=a;
        y=b;
    }

    float CalcArea(){
        return (0.5*getdim1())*getdim2();
    }
};

int main()
{
    Circle c(5);
    cout<<"Circle area= "<<c.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Rectangle r(5,2);
    cout<<"Rectangle area= "<<r.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Square s(5);
    cout<<"Square area= "<<s.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Triangle t(5,8);
    cout<<"Triangle area= "<<t.CalcArea()<<endl;

    return 0;
}
