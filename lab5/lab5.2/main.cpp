/*2- Base/Drived classes:
class Base
	- private members x
	- protected member y
	- constrcutors & destructor
	- setters & getters
	- function sum (return summation of x and y)
class Drived
	- private members z
	- constrcutors & destructor
	- setters & getters
	- override function sum in derived to add functionality to the base sum function:
	(return summation of x and y and z)*/
#include <iostream>

using namespace std;

class Base
{
private:
    int x;
protected:
    int y;
public:
   void setx(int x){x= x;}
   void sety(int x){y= x;}
   int getx(){return x;}
   int gety(){return y;}

    Base()
    {
        x=0;
        y=0;
    cout<<"\n constructor"<<endl;
    }
    Base(int _x)
    {
        x=y=_x;
    cout<<"\n constructor"<<endl;
    }
     Base(int _x,int _y)
    {
        x=_x;
        y=_y;
    cout<<"\n constructor"<<endl;
    }
  ~Base()
  {
    cout<<"\n destructor"<<endl;
  }

  int sum()
  {
      return x+y;
  }
 void  print1()
  {
      cout<<"x+y="<<sum()<<endl;
  }
};
class drived:public Base
{
private:
    int z;
public:
    void setz(int x){z= x;}
   int getz(){return z;}

     drived()
    {
        z=0;
    cout<<"\n drived constructor"<<endl;
    }
    drived(int x):Base(x)
    {
        z=x;
    cout<<"\ndrived  constructor"<<endl;

    }
    drived(int _x, int _y, int _z):Base(_x,_y)
    {
        z=_z;
    cout<<"\ndrived  constructor"<<endl;

    }

  ~drived()
  {
    cout<<"\n drived destructor"<<endl;
  }
  int sum2()
  {
      return Base::sum()+z;
      //return getx()+gety()+z;
  }
   void  print2()
  {
      cout<<"x+y+z ="<<sum2()<<endl;
  }
};

int main()
{
    Base B(1,2) ;

    B.print1();
    drived D(4, 2, 3);
    D.print2();
    //cout << "Hello world!" << endl;
    return 0;
}
