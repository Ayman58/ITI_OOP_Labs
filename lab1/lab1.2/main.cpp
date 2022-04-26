#include <iostream>
using namespace std;
struct comp
{
    private:
        int real;
        int img;
public:
    void setreal(int R) ///setters
       {real=R;}
    void setimg(int i)
       {img=i;}
    int getreal()      ///getters
        {return real;}
    int getimg()
       {return img;}
};
comp add (comp c1,comp c2)
{
    comp result;
    result.setreal(c1.getreal()+c2.getreal());
    result.setimg(c1.getimg()+c2.getimg());
    return result;
}
comp sub (comp c1,comp c2)
{
    comp result;
    result.setreal(c1.getreal()-c2.getreal());
    result.setimg(c1.getimg()-c2.getimg());
    return result;
}
 comp print(comp cc3)
{
   if(cc3.getimg()<0)
      cout << "cc3=" <<cc3.getreal() << cc3.getimg()<<"i" << endl;
   else if (cc3.getimg()==0)
        cout << "cc3=" <<cc3.getreal() << endl;
    else if (cc3.getreal()==0)
        cout << "cc3=" << cc3.getimg()<<"i" << endl;
    else if(cc3.getreal()==0&&cc3.getimg()==0)
        cout << "cc3=" << 0 << endl;
        else
       cout << "cc3=" <<cc3.getreal()<<"+" << cc3.getimg()<<"i" << endl;
}
int main()
{
    comp cc1,cc2,cc3;
    int R,i;
    cout <<"enter complex num ="<< endl;
    cin >> R>>i ;
    cc1.setreal(R);
    cc1.setimg(i);
    print(cc1);
    /*cc2.setreal(3);
    cc2.setimg(2);
    cc3=sub(cc1,cc2);
*/
    return 0;
}
