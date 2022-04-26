#include <iostream>
using namespace std;
class comp
{
private:
    int real;
    int img;
public:
    void setReal(int R)  {real = R;} ///setters
    void setImg(int I)  {img = I;}
    int getReal()  {return real;}  ///getters
    int getImg()  {return img;}
    ///construcor
    comp();
    comp(int n);
    comp(int R,int I);

    comp(const comp& c){
        cout<<"the copy constructor"<<endl;
        real=c.real;
        img=c.img;
    }

    ~comp();   ///construcor


    comp sum(comp& c) ///
    {
        int r=real+c.getReal();
        int i=img+c.getImg();
        comp result;
        result.setReal(r);
        result.setImg(i);
        return result;
    }
    comp sum2(comp c)///
    {
        int r=real+c.getReal();
        int i=img+c.getImg();
        comp result;
        result.setReal(r);
        result.setImg(i);
        return result;
    }
    void SetComp(int R, int I);
    void SetComp(int N);

    comp Addcomplex(comp C);
    comp subComplex(comp c);
    comp PrintComplex ();
};

 comp::comp(int R,int I)
    {real =R;img =I;}

  comp::comp(int n)
    {real =img =n;}

  comp::comp()
    {real=img=0;}

  comp::~comp()
     {
         //cout<<"\nparameter destructor"<<endl;
     }

  void comp::SetComp(int R, int I)
      {
        real = R;img = I;
       //cout<<"\nparameter costructor"<<endl;
      }

  void comp::SetComp(int N)
     {real = img = N;}

   comp comp::Addcomplex(comp C)
    {
    comp Res;
    Res.real= this -> real +C.real;
    Res.setImg(img + C.img);
    return Res;
    }

    comp comp::subComplex(comp c)
    {
    comp Res;
    Res.setReal(getReal()-c.getReal());
    Res.setImg(getImg()-c.getImg());
    return Res;
    }

    comp comp::PrintComplex ()
    {
     if(real>0&&img>0){
            cout << "the total is: " <<real<<"+"<<img<<"i"<< endl;
        }else if(img<0){
            cout << "the total is: " <<real<<img<<"i"<< endl;
        }else if(img==0){
            cout << "the total is: " <<real<< endl;
        }else if(real==0){
            cout << "the total is: " <<img<<"i"<< endl;
        }else if(real==0&&img==0){
            cout << "the total is: " <<"0"<< endl;
        }else{
            cout << "the total is: " <<real<<"+"<<img<<"i"<< endl;
        }
    }

int main()
{
    comp c1(3,4),c2(1,2);
    //c1.PrintComplex();
   comp c3=c1.sum2(c2);
    c3.PrintComplex();
    //comp cadd=c1.summ(c2);
    //comp caddv2=c1.summ2(c2);
    //comp csub=c1.subComplex(c2);
    //cadd.PrintComplex();
    //caddv2.PrintComplex();
    //csub.PrintComplex();

}
