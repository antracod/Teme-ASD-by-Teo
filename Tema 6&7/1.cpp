#include <iostream>
using namespace std;

const int NMAX = 1000;
int v[NMAX];

int n;
/// MERGESORT
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

void merge(int l,int m, int r)
{
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = v[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = v[m + 1+ j]; 
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            v[k] = L[i]; 
            i++; 
        } 
        else
        { 
            v[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void sorteaza(int l,int r)
{
    if (l<r) 
    { 
        int m = l+(r-l)/2; 
        sorteaza(l, m); 
        sorteaza(m+1, r); 
        merge(l, m, r); 
    } 
}

int main()
{
    citeste();
    sorteaza(0,n-1);
    afis();
}