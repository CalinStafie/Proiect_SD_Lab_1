#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");

void bubbleSort(unsigned int arr[], unsigned int n)
{
    bool ok;
    do
    {
        ok = 0;
        for(unsigned int i=0;i<n-1;++i)
            if(arr[i]>arr[i+1])
                {
                    swap(arr[i], arr[i+1]);
                    ok = 1;
                }
        --n;
    }while(ok);
}

std::mt19937 randomgen(time(NULL));
void generate_Randoms(unsigned int a[],unsigned int numar_numere, unsigned int val_max)
{
    //generam aleator "numar_numere" numere intre 0 si "val_max";
    for(unsigned int x=0; x<numar_numere; x++)
        a[x] = randomgen()%(val_max+1);
}

bool test_sort(unsigned int a[], unsigned int n)
{
    unsigned int i;
    for(i=0;i<n-1;++i)
        if(a[i]>a[i+1])
            return false;
    return true;
}

unsigned int v[190000002];
unsigned int T, numar_numere, val_max;

int main()
{
    fin>>T;
    for(int k=1;k<=T;k++)
    {
        fin>>numar_numere>>val_max;
        cout<< "N = " << numar_numere << "  " << "Max = "<< val_max << '\n';
        generate_Randoms(v, numar_numere, val_max);
        cout << "BubbleSort va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        bubbleSort(v, numar_numere);

        //stop
        auto stop = high_resolution_clock::now();

        //durata
        auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << " milisecunde." << '\n';

    if(test_sort(v, numar_numere))
        cout<<"Algoritmul a sortat bine."<<'\n';
    else
        cout<<"Algoritmul NU a sortat bine."<<'\n';
    cout<<'\n';
    }

/// Algoritmul crapa in jur de 10^6 numere.
/// Average time pentru 10^5 numere este de 30-35 secunde.
    return 0;
}
