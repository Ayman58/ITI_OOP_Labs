#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;

public:
    Complex()
    {
       // cout<<"the default constructor"<<endl;
    }

    Complex(const Complex& c){
        //cout<<"the copy constructor"<<endl;
        real=c.real;
        img=c.img;
    }

    Complex(int r,int i){
        real=r;
        img=i;
    }

    void setreal(int r) {real = r;}
    void setimg(int i)  {img = i;}
    int getreal()  {return real;}
    int getimg()  {return img;}

        /// - operator
    Complex operator-(Complex &c){
        Complex result(real-c.real,img-c.img);
        return result;
    }
///- operator overloading
    Complex operator-(const int &n){
        Complex result(real-n,img-n);
        return result;
    }

    Complex operator-=(Complex &c){
        Complex result(real-c.real,img-c.img);
        return result;
    }

    Complex operator--(){
        real--;
        return *this;
    }
    Complex operator--(int){
        Complex temp(*this);
        real--;
        return temp;
    }
    bool operator==(Complex c){
        return (real==c.real&&img==c.img);
    }
    bool operator!=(Complex c){
        return (real!=c.real&&img!=c.img);
    }
    bool operator>(Complex c){
        return (real>c.real&&img>c.img);
    }

    bool operator<(Complex c){
        return (real<c.real&&img<c.img);
    }

    bool operator>=(Complex c){
        return (real>=c.real&&img>=c.img);
    }

    bool operator<=(Complex c){
        return (real<=c.real&&img<=c.img);
    }

    operator int(){
        return (real+img);
    }

    Complex Add(Complex b);
    Complex Addv2(Complex &b);
    Complex Subtract(Complex b);
    void print();

    ~Complex(){//  cout<<"destructor"<<endl;

        }
        friend  ostream& operator<<(ostream& out,   Complex& C);

friend istream & operator >> (istream &in,  Complex &c);
};
ostream& operator<<(ostream& out,  Complex& C)
{
    int R=0,I=0;
    if (C.getreal()!=0&&C.getimg()>0)
    {
        R=C.getreal();
        I=C.getimg();
        out << R ;
        out<<"+" ;
        out <<I<<"i"<<endl;
        return out ;

    }
    else if (C.getreal()!=0&&C.getimg()<0)
    {

        R=C.getreal();
        I=C.getimg();
        out << R <<I<<"i"<<endl;
        return out ;
    }
    else if (C.getreal()!=0&&C.getimg()==0)
    {
        R=C.getreal();
        out<< R<<endl;
        return out ;
    }
    else if (C.getreal()==0&&C.getimg()!=0)
    {

        I=C.getimg();
        out<<I<<"i "<<endl;
        return out ;
    }
    else if (C.getreal()==0&&C.getimg()==0)
    {
        R=0;
        out<< R << endl;
        return out ;
    }
    else if (C.getreal()!=0&&C.getimg()==1)
    {
    out << R<<"+i"<<endl ;
    return out ;
}
    else if (C.getreal()==0&&C.getimg()==1)
    {
    out <<"i" <<endl;
    return out ;
    }

}
istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.img;
    return in;
}


int main()
{
    Complex c1(3,5),c2;
    Complex c3;
   cout <<c1;
   cout<<"enter comp num:";
    cin>>c2;
    cout <<c2;
}

Complex operator-(int n,Complex &c){

        Complex result(n-c.getreal(),c.getimg());
        return result;
    }

Complex Complex::Add(Complex b){
        int r=real+b.getreal();
        int i=img+b.getimg();
        Complex result;
        result.setreal(r);
        result.setimg(i);

        return result;
    }

Complex Complex ::Addv2(Complex& b){
        int r=real+b.getreal();
        int i=img+b.getimg();
        Complex result;
        result.setreal(r);
        result.setimg(i);
        return result;
    }


Complex Complex::Subtract(Complex b){
        int r=real-b.getreal();
        int i=img-b.getimg();
        Complex result;
        result.setreal(r);
        result.setimg(i);
        return result;
    }

void Complex::print(){
        if(real>0&&img>0){
            cout << "the result = " <<real<<"+"<<img<<"i"<< endl;
        }else if(img<0){
            cout << "the result =  " <<real<<img<<"i"<< endl;
        }else if(img==0){
            cout << "the result =  " <<real<< endl;
        }else if(real==0){
            cout << "the result =  " <<img<<"i"<< endl;
        }else if(real==0&&img==0){
            cout << "the result =  " <<"0"<< endl;
        }else{
            cout << "the result =  " <<real<<"+"<<img<<"i"<< endl;
        }
    }
