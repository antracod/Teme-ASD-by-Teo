#include <iostream>

using namespace std;
struct nod
{
   int info;
   nod *next;
}*prim,*ultim;
void afisare()
{
    if(prim==NULL)
       cout<<"coada vida";
    else
    {
     cout<<"out ";
    for(nod *f=prim;f;f=f->next)
      cout<<f->info<<" ";
    cout<<"in";
    }
    cout<<'\n';
}
void push(int x)
{
    if(prim==NULL)
    {
       prim=new nod;
       prim->info=x;
       prim->next=NULL;
       ultim=prim;
    }
    else
    {
        if(prim==ultim)
        {
           nod *f=new nod;
           f->info=x;
           f->next=NULL;
           ultim->next=f;
           ultim=f;
           prim->next=ultim;
        }
        else
        {
            nod *f=new nod;
            f->info=x;
            f->next=NULL;
            ultim->next=f;
            ultim=f;
        }
    }

}
int peek()
{
   if(prim==NULL)
     return -1;
   return prim->info;
}
int search(int x)
{
    int count=0;
    for(nod *f=prim;f;f=f->next)
    {
       count++;
       if(f->info==x)
         return count;
    }
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
    nod *f=prim->next;
    int x=prim->info;
    delete prim;
    prim=f;
    return x;
}
int main()
{
   prim=ultim=NULL;
   afisare();
   push(1);
   push(2);
   push(3);
   afisare();
   cout<<search(2)<<'\n';
   cout<<search(4)<<'\n';
   cout<<empty()<<'\n';
   cout<<pop()<<'\n';
   afisare();
   cout<<peek()<<'\n';
   afisare();
   pop();
   pop();
   afisare();
   cout<<pop()<<'\n';
   cout<<empty();
}