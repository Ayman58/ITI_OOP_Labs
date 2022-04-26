#include <iostream>
using namespace std;
class Complex {
private:
   int real;
   int imagen;
public:
Complex()
{
cout<<"the default constructor"<<endl;
}
Complex(const Complex& c)
{
   cout<<"the copy constructor"<<endl;
   real=c.real;
   imagen=c.imagen;
}
Complex(int r,int i){
real=r;
imagen=i;
}
void setReal(int r){
real = r;
}
int getReal(){
return real;
} void setImagen(int i){
imagen = i;
}
int getImagen(){
return imagen;
} /*Complex Add(Complex b){
int r=real+b.getReal();
int i=imagen+b.getImagen();
Complex result;
result.setReal(r);
result.setImagen(i);
return result;
}*/ Complex Addv2(const Complex& b){
int r=real+b.getReal();
int i=imagen+b.getImagen();
Complex result;
result.setReal(r);
result.setImagen(i);
return result;
} Complex Subtract(Complex b){
int r=real-b.getReal();
int i=imagen-b.getImagen();
Complex result;
result.setReal(r);
result.setImagen(i);
return result;
}
void print(){
if(real>0&&imagen>0){
cout << "the total is: " <<real<<"+"<<imagen<<"i"<< endl;
}else if(imagen<0){
cout << "the total is: " <<real<<imagen<<"i"<< endl;
}else if(imagen==0){
cout << "the total is: " <<real<< endl;
}else if(real==0){
cout << "the total is: " <<imagen<<"i"<< endl;
}else if(real==0&&imagen==0){
cout << "the total is: " <<"0"<< endl;
}else{
cout << "the total is: " <<real<<"+"<<imagen<<"i"<< endl;
}
} ~Complex(){
cout<<"destructor"<<endl;
}
};int main()
{
Complex c1(3,5),c2(9,6); c1.print(); //Complex cadd=c1.Add(c2);
Complex caddv2=c1.Addv2(c2);
//Complex csub=c1.Subtract(c2);
//cadd.print();
caddv2.print();
//csub.print();}
