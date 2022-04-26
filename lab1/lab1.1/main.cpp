#include <iostream>

using namespace std;

///pass by value
/*int swap (int x,int y)

{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

int main()
{
    int A=4,B=5;
    cout << "before swap:A="<<A<<",B="<<B << endl;
    swap(A,B);
    cout << "After swap:A="<<A<<",B="<<B << endl;
    return 0;
}*/
///pass by address
/*int swap (int* x,int* y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int A=4,B=5;
    cout << "before swap:A="<<A<<",B="<<B << endl;
    swap(&A,&B);
    cout << "After swap:A="<<A<<",B="<<B << endl;
    return 0;
}*/

///pass by refrence
int swap (int &x,int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main()
{
    int A=4,B=5;
    cout << "before swap:A="<<A<<",B="<<B << endl;
    swap(A,B);
    cout << "After swap:A="<<A<<",B="<<B << endl;
    return 0;
}

