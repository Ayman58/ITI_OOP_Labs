#include <iostream>
using namespace std;
class Base
{
public:
    int x;

    Base(){x=0; }
    Base(int L){x=L;}

   virtual void mymethod()
    {
        cout <<"base class.. "<<endl;
    }

};
class drived:public Base
{
public:
    int y;

     drived(){y=0;}
     drived(int L, int M):Base(L)
        {y=M;}

    void mymethod()
    {
        cout <<"drived  class.. "<<endl;
    }
};
int main()
{
    drived* D;
    D=new drived (5,3);
    //D.mymethod();
    Base* B;
    B=D;
    B-> mymethod();
    D-> mymethod();
    return 0;
}
