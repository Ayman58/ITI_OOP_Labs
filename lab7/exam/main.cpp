#include <iostream>

using namespace std;
class parent
{
public:
    int x;
    parent(int m){x=m;}
};
class child : protected parent
{
public:
    int y;
    child(int m, int n):parent(m){y=n;}
};
class grand:public child
{
    int z;
public:
    grand(int a,int b,int c): child(a,b){z=c;}
};
int main()
{
    grand c(3,5,7);
    cout<<"x="<<c.x;
    cout<<"x="<<c.y;
    cout<<"x="<<c.z;
    return 0;
}
