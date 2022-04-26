#include <iostream>

using namespace std;
template<class T> ///template<typename T>
class Stack
{
    T* Stk;
    int Tos;  //counter
    int Size;

public :
    Stack ()
    {
        //cout<<"\n non parameter  constructor"<<endl;
        Size = 5 ;
        Stk = new T [Size];
        Tos = 0 ;
    }

    Stack (const Stack &S)
    {
        cout<<"\nCopy constructor"<<endl;
        Size = S.Size;
        Tos = S.Tos;
        Stk = new T [Size];
        for(int i=0; i<Tos; i++)
        {
            Stk[i] = S.Stk[i];
        }
    }

    Stack (int L)
    {
        cout<<"\n parameter constructor with one value "<<endl;
        Size = L ;
        Stk = new T [Size];  //dynamic allocated
        Tos = 0 ;
    }

    ~Stack()
    {
       // cout<<"\n parameter destructor"<<endl;
        for(int i=0; i<Tos; i++)
            Stk[i] = -1;

        delete []Stk;
    }

    bool isFull()
    {
        return (Tos ==5);
    }

    bool isEmpty()
    {
        return (Tos ==0);
    }

    void push(T n)
    {
        if(isFull() == false)
            Stk[Tos++] = n;
        else
            cout<<"stack is full "<<endl;
    }

    T pop()
    {
        if (!isEmpty())
            return Stk[--Tos];
        else
        {
            cout<<"stack is Empty "<<endl;
            return -1 ;
        }
    }

    int Peak()
    {
        if (!isEmpty())
            return Stk[Tos];
        else
        {
            cout<<"stack is Empty "<<endl;
            return -1 ;
        }
    }

    Stack Reverse()
    //return new stack "with reversed internal array of original stack"
    {
        Stack stemp(Size);
        for(int i=Size-1; i>=0; i--)
        {
            stemp.push(Stk[i]);
        }
        return stemp;
    }
    void PrintStack()
    {
        for(int i=0; i<Tos; i++)
        {
            cout<<"cell number "<<i+1<<" :"<<Stk[i]<<endl;
        }
    }

    friend void viewcontent (Stack<T> S);

    operator = (Stack s)
    {
        Tos=s.Tos;
        Size=s.Size;
        for(int i=0; i<Tos; i++)
        {
            Stk[i] = s.Stk[i];
        }
    }

    Stack operator+(const Stack& s)
    {
        Stack result;
        result.Tos=Tos+s.Tos;
        result.Size=Size+s.Size;

        result.Stk=new T[Size+s.Size];
        int i;

        for(i=0; i<Tos; i++)
        {
            result.Stk[i] = Stk[i];
        }
        for(int i=0; i<s.Tos; i++)
        {
            result.Stk[i+Tos] = s.Stk[i];
        }
        delete [] Stk;


        return result;
    }
};

template<class T>
void viewcontent (Stack<T> S)
{
    cout<<"\n Stack Content :"<<endl;
    for(int i=0; i<S.Tos; i++)
    {
        cout<<S.Stk[i]<<endl;
    }
}

class comp
{
    int real;
    int img;
public:
    void setreal(int R)  {real = R;} ///setters
    void setimg(int I)  {img = I;}
    int getreal()  {return real;}  ///getters
    int getimg()  {return img;}
    ///construcors
    comp() {real=img=0;}
    comp(int n){real =img =n;}
    comp(int R,int I){real =R;img =I;}
    ~comp(){}
    comp(const comp& c){
        //cout<<"the copy constructor"<<endl;
        real=c.real;
        img=c.img;
    }

    void SetComp(int R, int I){real = R;img = I;}
    void SetComp(int N) {real = img = N;}

    comp PrintComplex ()
    {cout << "" <<real<<"+"<<img<<"i";}

friend istream & operator >> (istream &in,  comp &c);
};

int main()
{
    comp c1,c2;
    c1.setreal(3);
    c1.setimg(4);
    c2.setreal(5);
    c2.setimg(8);
   // c1.PrintComplex();
    Stack<comp> c3;
    c3.push(c1);
    c3.push(c2);
    c3.PrintStack();

    cout<<"\n_________________________________"<<endl;
    Stack<int> S1;
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.PrintStack();
    cout<<"\n________________________________"<<endl;

    Stack<char> S2;
    S2.push('A');
    S2.push('B');
    S2.push('c');
    S2.PrintStack();
    cout<<"\n_________________________________"<<endl;

}
ostream& operator<<(ostream& out,  comp& C)
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
