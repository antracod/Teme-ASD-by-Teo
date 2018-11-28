#include <iostream>
#include <cstring>
using namespace std;
struct stiva
{
   int info;
   stiva *next;
}*prim,*ultim;
void afisare()
{
    if(prim==NULL)
       cout<<"stiva vida";
    else
    {
      cout<<"varf ";
      for(stiva *f=prim;f;f=f->next)
         cout<<f->info<<" ";
      cout<<" baza";
    }
cout<<'\n';
}
void push(int x)
{
   if(prim==NULL)
   {
      prim=new stiva;
      prim->info=x;
      prim->next=NULL;
      ultim=prim;
   }
   else
   {
      stiva *f=new stiva;
      f->info=x;
      f->next=prim;
      prim=f;
   }
}
int search(int x)
{
    for(stiva *f=prim;f;f=f->next)
      if(f->info==x)
        return 1;
    return -1;

}
int empty()
{
   if(prim==NULL)
     return 1;
   else
     return 0;
}
int pop()
{
    if(prim==NULL)
      return -1;
    else
    {
       int x=prim->info;
       stiva *f=prim->next;
       delete prim;
       prim=f;
       if(f==ultim or f==NULL)
       ultim=f;
       return x;
    }

}
int peek()
{
   if(prim==NULL)
     return -1;
   else
     return prim->info;
}
int main()
{
    prim=ultim=NULL;
    char s[250];
    cin>>s;
    int n=strlen(s);
    bool ok=1;
    for(int i=0;i<n && ok==1;i++)
    {
        if(s[i]=='(')
          push(1);
        else
        {
          if(empty()==0)
            ok=0;
          pop();

        }
    }
    if(empty()==0)
      cout<<"1";
    else
      cout<<"0";
}