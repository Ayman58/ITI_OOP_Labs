#include <iostream>

using namespace std;

class Stack{
       int* Stk;
       int Tos;  //counter
       int Size;

    public :
      Stack (){
       cout<<"\n non parameter  constructor"<<endl;
       Size = 5 ;
       Stk = new int [Size];
       Tos = 0 ;
     }

     Stack (const Stack &S){
       cout<<"\nCopy constructor"<<endl;
       Size = S.Size;
       Tos = S.Tos;
       Stk = new int [Size];
       for(int i=0;i<Tos;i++){
            Stk[i] = S.Stk[i];
        }
     }

      Stack (int L){
      cout<<"\n parameter constructor with one value "<<endl;
       Size = L ;
       Stk = new int [Size];  //dynamic allocated
       Tos = 0 ;
     }

    ~Stack(){
       cout<<"\n parameter destructor"<<endl;
        for(int i=0;i<Tos;i++)
            Stk[i] = -1;

        delete []Stk;
    }

    bool isFull(){return (Tos ==5);}

    bool isEmpty(){return (Tos ==0);}

    void push(int n){
        if(isFull() == false)
            Stk[Tos++] = n;
        else
            cout<<"stack is full "<<endl;
    }

    int pop(){
        if (!isEmpty())
            return Stk[--Tos];
        else{
            cout<<"stack is Empty "<<endl;
            return -1 ;
        }
    }

	int Peak(){
	    if (!isEmpty())
            return Stk[Tos];
        else{
            cout<<"stack is Empty "<<endl;
            return -1 ;
        }
	}

	Stack Reverse();
	void PrintStack();

	friend void viewcontent (Stack S);

	operator = (Stack s)
	{
	    Tos=s.Tos;
	    Size=s.Size;
        for(int i=0;i<Tos;i++){
            Stk[i] = s.Stk[i];
        }
	}

	Stack operator+(const Stack& s){
	    Stack result;
	    result.Tos=Tos+s.Tos;
	    result.Size=Size+s.Size;

	    result.Stk=new int[Size+s.Size];
	    int i;

	    for(i=0;i<Tos;i++){
            result.Stk[i] = Stk[i];
        }
        for(int i=0;i<s.Tos;i++){
            result.Stk[i+Tos] = s.Stk[i];
        }
        delete [] Stk;


        return result;
	}
};


void viewcontent (Stack S){
     cout<<"\n Stack Content :"<<endl;
     for(int i=0;i<S.Tos;i++)
     {
         cout<<S.Stk[i]<<endl;
     }
}

int main(){

    Stack S1,S2;

	S1.push(10);
	S1.push(20);
	S1.push(30);
	S1.push(40);
	S1.push(50);

	S2.push(10);
	S2.push(20);

    viewcontent(S1);

    cout<<"\n___________________________________________________"<<endl;

    Stack s3=S1.Reverse();
   viewcontent(s3);
   // s3.PrintStack();
    cout<<"\n___________________________________________________"<<endl;
    S1=s3;
    viewcontent(S1);
    cout<<"\n___________________________________________________"<<endl;
    s3=S1+S2;
    viewcontent(s3);
    cout<<"\n___________________________________________________"<<endl;
}

Stack Stack::Reverse(){ //return new stack "with reversed internal array of original stack"
	    Stack stemp(Size);
	    for(int i=Size-1;i>=0;i--){
            stemp.push(Stk[i]);
	    }
	    return stemp;
    }


void Stack::PrintStack()
{
 for(int i=0;i<Size;i++)
    {
    cout<<"cell number "<<i+1<<" :"<<Stk[i]<<endl;
    }
}
