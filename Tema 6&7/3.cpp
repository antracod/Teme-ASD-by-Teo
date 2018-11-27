#include <bits/stdc++.h> 
using namespace std; 

int n;
const int NMAX = 1000;
int v[NMAX];
int k;
void citeste()
{
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
}

int partition(int l, int r) 
{ 
    int x = v[r], i = l; 
    for (int j = l; j <= r - 1; j++) { 
        if (v[j] <= x) { 
            swap(v[i], v[j]); 
            i++; 
        } 
    } 
    swap(v[i], v[r]); 
    return i; 
} 
  
int quickselect( int l, int r) 
{ 

    if (k > 0 && k <= r - l + 1) { 
 
        int index = partition( l, r); 

        if (index - l == k - 1) 
            return v[index]; 

        if (index - l > k - 1)  
            return quickselect(l, index - 1); 

        return quickselect(index + 1, r); 
    } 

    return -1;
} 
  
int main() 
{ 
    citeste();
    cout << quickselect(0, n - 1); 
    return 0; 
} 