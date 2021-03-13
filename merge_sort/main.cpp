#include <bits/stdc++.h>
#include <chrono>

//std::mt19937 gen(time(0));
using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");

unsigned int L[150000009], R[150000009];
void InteClasare(unsigned int arr[], unsigned int stanga, unsigned mijloc, unsigned dreapta)
{
    unsigned int nr_elemente_1 = mijloc - stanga + 1;
    unsigned int nr_elemente_2 = dreapta - mijloc;


    for (unsigned int i = 0; i < nr_elemente_1; i++)
        L[i] = arr[stanga + i];
    for (unsigned int j = 0; j < nr_elemente_2; j++)
        R[j] = arr[mijloc + 1 + j];

    unsigned int i = 0;

    unsigned int j = 0;

    unsigned int k = stanga;

    while (i < nr_elemente_1 && j < nr_elemente_2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nr_elemente_1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nr_elemente_2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
    ///merge(L, L + nr_elemente_1, R, R + nr_elemente_2, arr);
//}
void MergeSort(unsigned int arr[], unsigned int stanga, unsigned int dreapta)
{
    if(stanga >= dreapta)
        return;
    // am facut in loc de (stanga+dreapta)/2 deoarece am incercat sa evit overflow-ul pentru numere prea mari
    unsigned int mijloc = stanga + (dreapta - stanga) / 2;
    MergeSort(arr, stanga, mijloc);
    MergeSort(arr, mijloc + 1, dreapta);
    InteClasare(arr, stanga, mijloc, dreapta);
}

/* Am incercat si un alt algoritm de generare random a numerelor.
void generate_Randoms(unsigned int v[], unsigned int numar_numere, unsigned int val_max){
    std::uniform_int_distribution<unsigned int> u_int(0, val_max);

    for (int i = 0; i < numar_numere; i++)
        v[i] = u_int(gen);
}
*/

std::mt19937 randomgen(time(NULL));
//std::uniform_int_distribution<unsigned int>;
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
        cout << "MergeSort va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        MergeSort(v, 0, numar_numere - 1);

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

/// Algoritmul MergeSort sorteaza numere pana la 10^6 numere intr-un timp relativ scurt (0.2 secunde)
/// Pentru 10^7 numere dureaza in jur de 2 secunde sa le sorteze, pentru orice caz random
/// Pentru 10^8 numere MergeSort sorteaza cam in maxim 25 de secunde numerele
/// La 10^9 algoritmul de sortare crapa.
    return 0;
    }
