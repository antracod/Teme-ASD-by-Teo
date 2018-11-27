#include <iostream>
using namespace std;

const int NMAX = 1000;
int v[NMAX];

int n;
/// QUICKSORT
void citeste()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
}

void afis()
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}

int partition ( int st, int dr) 
{ 
    int pivot = v[dr];    
    int i = (st - 1); 
  
    for (int j = st; j <= dr- 1; j++) 
    { 
        if (v[j] <= pivot) 
        { 
            i++;  
            swap(v[i], v[j]); 
        } 
    } 
    swap(v[i + 1], v[dr]); 
    return (i + 1); 
} 

void sorteaza(int st, int dr)
{
     if (st < dr) 
    { 
        int m = partition(st, dr); 
        sorteaza( st, m - 1); 
        sorteaza(m + 1, dr); 
    } 
}

int main()
{
    citeste();
    sorteaza(0,n-1);
    afis();
}