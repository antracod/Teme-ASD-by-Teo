#include <iostream>
using namespace std;

const int NMAX = 1000;
int v[NMAX];

int n;
/// RADIXSORT
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
int ia_max() 
{ 
	int mx = v[0]; 
	for (int i = 1; i < n; i++) 
		if (v[i] > mx) 
			mx = v[i]; 
	return mx; 
} 

void countSort(int exp) 
{ 
	int output[n]; 
	int i, count[10] = {0}; 

	for (i = 0; i < n; i++) 
		count[ (v[i]/exp)%10 ]++; 

	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (v[i]/exp)%10 ] - 1] = v[i]; 
		count[ (v[i]/exp)%10 ]--; 
	} 

	for (i = 0; i < n; i++) 
		v[i] = output[i]; 
} 

void sorteaza() 
{ 
	int m = ia_max(); 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(exp); 
} 


int main() 
{ 
	citeste();
    sorteaza();
    afis();
} 
