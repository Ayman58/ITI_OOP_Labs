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

    ~Geoshape() {cout<<" Geo distructor "<<endl;}
   virtual float CalcArea() =0;
    //{return 0;}
};
class Rectangle:public Geoshape
{   int x,y;
public:
    Rectangle() {x=y=0;}
    Rectangle(int a,int b):Geoshape(a,b)
     {x=a; y=b;}

    float CalcArea(){
        return getdim1()*getdim2();
    }
};
class Square: public Geoshape{
    int x,y;
    public:
    Square(){x=y=0;}
    Square(int a):Geoshape(a)
       {x=y=a;}

    float CalcArea()
    {
        return getdim1()*getdim2();
    }
};
class Circle: public Geoshape
{
    int x,y;
    public:
    Circle(int a):Geoshape(a)
    {x=y=a;}

    float CalcArea()
    {
        return (int) 3.14*getdim1()^2;
    }
};
class Triangle: public Geoshape{
    int x,y;
public:
    Triangle(int a,int b):Geoshape(a,b)
        {x=a; y=b;}

    float CalcArea(){
        return (0.5*getdim1())*getdim2();
    }
};
float sumofall(Geoshape* shArr[] , int Size )
{
   float sum = 0;
   for (int i=0; i<Size; i++)
    sum+=shArr[i]->CalcArea();
   return sum;
}
int main()
{
    Circle C(5);
    cout<<"Circle area= "<<C.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Rectangle R(5,2);
    cout<<"Rectangle area= "<<R.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Square S(5);
    cout<<"Square area= "<<S.CalcArea()<<endl;
    cout<<"\n___________________________________________________"<<endl;
    Triangle T(5,8);
    cout<<"Triangle area= "<<T.CalcArea()<<endl;

    Geoshape* Arr[4];
    Arr[0]=&R;
    Arr[1]=&S;
    Arr[2]=&C;
    Arr[3]=&T;
    cout<< "\n sum of all areas "<<sumofall(Arr,4);
    return 0;
}
