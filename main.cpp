#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
// afisare

void afis(long int v[], long int n)
{
    int i;
    for (i=0;i<n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



///radixsort

long int getmaxi( long int v[], long int n)
{
    long int i, maxi=v[0];
    for (i=1; i<n;i++)
    {
        if(v[i]>maxi)
            maxi=v[i];
    }
    return maxi;
}

void countingSort(long int v[], long int n, long int exp )
{
    long int output[n], i, nr[10];

    for(i=0;i<10;i++)
    {
        nr[i]=0;
    }

    for(i=0;i<n;i++)
    {
        nr[(v[i]/exp)%10]++;
    }

    for(i=1;i<10;i++)
    {
        nr[i]=nr[i]+nr[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[nr[(v[i]/exp)%10]-1]=v[i];
        nr[(v[i]/exp)%10]--;
    }

    for(i=0;i<n; i++)
    {
        v[i]=output[i];
    }
}

void radixSort( long int v[], long int n)
{
    long int exp, maxi=getmaxi(v,n);
    for(exp=1; maxi/exp>0; exp=exp*10)
    {
        countingSort(v, n, exp);
    }
}

///shellsort

void shellSort( long int v[], long int n)
{
    long int i,j, gap, aux;
    for( gap=n/2; gap>0; gap=gap/2)
    {
        for(i=gap; i< n; i++)
        {
            aux=v[i];
            for(j=i;j>=gap&&v[j-gap]>aux; j=j-gap)
            {
                v[j]=v[j-gap];
            }
            v[j]=aux;
        }
    }
}

///gnomesort

void gnomeSort( long int v[], long int n)
{
    int aux, i=0;
    while(i<n)
    {
        if(i==0)
            i++;
        if(v[i]>=v[i-1])
            i++;
        else
        {
            aux=v[i];
            v[i]=v[i-1];
            v[i-1]=aux;
            i--;
        }
    }

}

///mergeSort

void inter( long int st, long int dr, long int m, long int v[])
{
    long int w[dr+1], i,j,k;
    i=st;
    j=m+1;
    k=st;
    while(i<=m && j<=dr)
    {
        if(v[i]<v[j])
        {
            w[k]=v[i];
            k++;
            i++;
        }
        else
        {
            w[k]=v[j];
            k++;
            j++;
        }
    }

    while( i<=m)
    {
        w[k]=v[i];
        k++;
        i++;
    }
    while( j<=dr)
    {
        w[k]=v[j];
        k++;
        j++;
    }
    for(i=st;i<k;i++)
    {
        v[i]=w[i];
    }
}

void mergeSort(long int st, long int dr,  long int v[])
{
    if(st<dr)
    {
    long int m=(st+dr)/2;
    mergeSort(st, m, v);
    mergeSort(m+1, dr, v);
    inter(st, dr, m,v);
    }
}

/// quicksort


long int pivot( long int st, long int dr, long int v[])
{
    long int aux, i, piv= v[dr], poz=st;
    for(i = st; i < dr; i++)
        if(v[i] <= piv)
        {
            aux= v[i];
            v[i]=v[poz];
            v[poz]=aux;
            poz++;
        }

    aux=v[poz];
    v[poz]=v[dr];
    v[dr]=aux;
    return poz;
}

void quickSort( long int st, long int dr, long int v[])
{
    if(st<dr)
    {
        long int p = pivot(st, dr, v);
        quickSort(st, p-1, v);
        quickSort(p+1, dr, v);
        }
}


// Verificare
int verify(long int v[], long int n )
{
    long int i;
    for (i=1;i<n;i++)
    {
        if(v[i-1]>v[i])
        return 0;
    }
    return 1;
}


int main()
{
    ifstream fin("test1.txt");

    long int n;
    fin >> n;

    long int nrMax;
    fin >> nrMax;

    long int v[n], i;

    for( i = 0; i < n; i++)
        v[i] = rand()%nrMax;


    auto start = chrono::high_resolution_clock::now();

    ios_base::sync_with_stdio(false);

    ///radixSort(v,n);

    ///shellSort(v,n);

    ///gnomeSort(v,n);

    ///mergeSort(0,n-1, v);

    ///quickSort(0,n-1,v);

    auto end = chrono::high_resolution_clock::now();

    double time_taken =
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    afis(v,n);

    cout << "N = " << n << endl;
    cout << "Max = " << nrMax << endl;
    cout << "Timp sortare : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

    fin.close();
}

