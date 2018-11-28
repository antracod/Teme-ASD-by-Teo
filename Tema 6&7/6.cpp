#include <iostream>
using namespace std;

const int NMAX = 1000;
int v[NMAX];
int n;
/// HEAPSORT
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

void solheap(int v[], int n, int i) 
{ 
	int largest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	if (l < n && v[l] > v[largest]) 
		largest = l; 

	if (r < n && v[r] > v[largest]) 
		largest = r; 
	if (largest != i) 
	{ 
		swap(v[i], v[largest]);  
		solheap(v, n, largest); 
	} 
} 

void sorteaza() 
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		solheap(v, n, i); 

	for (int i=n-1; i>=0; i--) 
	{ 
		swap(v[0], v[i]); 

		solheap(v, i, 0); 
	} 
} 

int main() 
{ 
	citeste();
    sorteaza();
    afis();
} 
