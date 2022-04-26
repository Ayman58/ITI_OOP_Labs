
///-fno-elide-constructors
#include <iostream>
using namespace std;
class Stack
{
       int* Stk;
       int Tos;
       int Size;

public :
    Stack ()
     {
       cout<<"\nparameter constructor"<<endl;
       Size = 5 ;
       Stk = new int [Size];
       Tos = 0 ;
     }
      Stack (const Stack& S)
     {
       cout<<"\nCopy constructor"<<endl;
       Size = S.Size ;
       Tos = S.Tos ;
       Stk = new int [Size];
       for(int i=0;i<Tos;i++)
         {Stk[i] = S.Stk[i];}
     }

      Stack (int L)
     {cout<<"\nparameter constructor with one value "<<endl;
       Size = L ;
       Stk = new int [Size];
       Tos = 0 ;
       }

     ~Stack ()
     {
      cout<<"\nparameter destructor"<<endl;
      for(int i=0;i<Tos;i++)
        Stk[i] = -1;

       delete [] Stk ;
     }
       bool isFull(){return (Tos ==Size);}

       bool isEmpty(){return (Tos ==0);}

       void Push(int n )
       {if (isFull() == false)
        Stk[Tos++] = n ;
        else
         cout<<"\nstack is full "<<endl;
      }

      int Pop( )
      {if (!isEmpty() )
          return Stk[--Tos]  ;
        else   {
         cout<<"\nstack is Empty "<<endl;
            return -1 ;
               }
        }
    Stack Reverse() ///stack reversed
	 {
        Stack Reversed (this->Size);
	     Reversed.Tos = this ->Tos;
         for ( int i=0;i<Reversed.Tos;i++)
              {
              Reversed.Stk[i] = Stk[Tos-i-1] ;
              }
 	       return Reversed;
	  }

	     void PrintStack()
	     {
          for (int i=0;i<Size;i++)
	       {cout<<"Num = "<<Stk[i]<<endl;}
	     }

	friend void viewcontent (Stack S );///
};

  void viewcontent ( Stack S ) ///view content
 {
     cout<<"\n Stack Content :"<<endl;
     for(int i=0;i<S.Tos;i++)
     {cout<<S.Stk[i]<<endl;}
 }
  int main()
{
Stack S1;     /// parameterless
S1.Push(10);
S1.Push(20);
S1.Push(30);
viewcontent(S1); /// pass by value
cout<<"\n___________________"<<endl;
Stack ss = S1.Reverse();
cout<<"\nNum = "<<ss.Pop();
   return 0 ;

}
