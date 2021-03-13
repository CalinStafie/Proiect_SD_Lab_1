#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");

unsigned int frecv[300000002];
void CountSort(unsigned int arr[], unsigned int n, unsigned int val_max)
{
    unsigned int i,contor;
    //am declarat vectorul de frecventa global deoarece creste viteza programului
    for(i=0;i<n;++i)
        ++frecv[arr[i]];
    unsigned int j = 0;
    for(i=0;i<val_max;++i)
        for(contor=1;contor<=frecv[i];++contor)
            arr[j++] = i;
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
        cout << "CountSort va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        CountSort(v, numar_numere, val_max);

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
/// Timpul algoritmului este influentat de Valoarea Maxima din array "val_max"
/// care crapa la 10^8 iar N-ul poate sa duca chiar pana la 10^8-10^9
/// daca Max este suficient de mic.

/// Dupa ce am declarat vectorul de frecventa global, Max se putea duce pana la 10^8 fara sa crape
    return 0;
}
