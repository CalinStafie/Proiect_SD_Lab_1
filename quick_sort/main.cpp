#include <bits/stdc++.h>
#include <chrono>

std::mt19937 gen(time(0));
using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");

unsigned int partitionare_Lomuto (unsigned int arr[],unsigned int low, unsigned int high)
{
    unsigned int pivot =arr[high];
    unsigned int i = low - 1;

    for (unsigned int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort_Lomuto(unsigned int arr[], int low, int high)
{
    if (low < high)
    {

        unsigned int pindex = partitionare_Lomuto(arr, low, high);


        quickSort_Lomuto(arr, low, pindex - 1);
        quickSort_Lomuto(arr, pindex+ 1, high);
    }
}






int partitionare_Hoare(unsigned int arr[], unsigned int low,unsigned int high)
{
    {
    unsigned int pivot = arr[low];
    unsigned int i = low - 1;
    unsigned int j = high + 1;

    while (true)
    {
        //cautam cel mai din stanga element mai mare sau egal cu pivotul
        do
        {
            i++;
        } while (arr[i] < pivot);

        //cautam cel mai din dreapta element mai mic sau egal cu pivotul
        do
        {
            j--;
        } while (arr[j] > pivot);

        //cei doi indecsi se incaleca(intalnesc)
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }

    }
}

void quickSort_Hoare(unsigned int arr[], int low, int high)
{
    if (low < high)
    {

        unsigned int pindex2 = partitionare_Hoare(arr, low, high);

        //sortam elementele inainte de partitionare si dupa
        quickSort_Hoare(arr, low, pindex2);
        quickSort_Hoare(arr, pindex2 + 1, high);
    }
}






//generam un pivot random intre low si high, interschimband acel pivot cu ultimul element si apeland functia
//partitionare_Lomuto
int partition_random(unsigned int arr[], int low, int high)
{
    srand(time(NULL));
    unsigned int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
    return partitionare_Lomuto(arr, low, high);
}


void quickSort_random(unsigned int arr[], int low, int high)
{
    if (low < high) {

        int pindex_random = partition_random(arr, low, high);

        quickSort_random(arr, low, pindex_random - 1);
        quickSort_random(arr, pindex_random + 1, high);
    }
}


/*
 //Am incercat si un alt algoritm de generare random a numerelor.
void generate_Randoms(unsigned int v[], unsigned int numar_numere, unsigned int val_max){
    std::uniform_int_distribution<unsigned int> u_unsigned_int(0, val_max);

    for (unsigned int i = 0; i < numar_numere; i++)
        v[i] = u_unsigned_int(gen);
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

unsigned int v[100000002], v_Hoare[100000002], v_random[100000002];
unsigned int T, numar_numere, val_max;

int main()
{
    fin>>T;
    for(int k=1;k<=T;k++)
    {
        fin>>numar_numere>>val_max;
        cout<< "N = " << numar_numere << "  " << "Max = "<< val_max << '\n';
        generate_Randoms(v, numar_numere, val_max);
        for (unsigned int i = 0 ; i < numar_numere ;++i)
            {
                v_Hoare[i] = v[i];
                v_random[i] = v[i];
            }

        cout << "QuickSort cu partitia 'Lomuto', pivotul ales fiind ULTIMUL element, va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        quickSort_Lomuto(v, 0, numar_numere-1);

        //stop
        auto stop = high_resolution_clock::now();

        //durata
        auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << " milisecunde." << '\n';

    if(test_sort(v, numar_numere))
        cout<<"Algoritmul a sortat bine."<<'\n';
    else
        cout<<"Algoritmul NU a sortat bine."<<'\n';



    cout << "QuickSort cu partitia 'Hoare', pivotul ales fiind PRIMUL element, va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start2 = high_resolution_clock::now();

        quickSort_Hoare(v_Hoare, 0, numar_numere-1);

        //stop
        auto stop2 = high_resolution_clock::now();

        //durata
        auto duration2 = duration_cast<milliseconds>(stop2 - start2);

    cout << duration2.count() << " milisecunde." << '\n';

    if(test_sort(v_Hoare, numar_numere))
        cout<<"Algoritmul a sortat bine."<<'\n';
    else
        cout<<"Algoritmul NU a sortat bine."<<'\n';



    cout << "QuickSort cu partitia 'Lomuto', cu pivot random ,va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start3 = high_resolution_clock::now();

        quickSort_random(v_random, 0, numar_numere-1);

        //stop
        auto stop3 = high_resolution_clock::now();

        //durata
        auto duration3 = duration_cast<milliseconds>(stop3 - start3);

    cout << duration3.count() << " milisecunde." << '\n';

    if(test_sort(v_random, numar_numere))
        cout<<"Algoritmul a sortat bine."<<'\n';
    else
        cout<<"Algoritmul NU a sortat bine."<<'\n';
    cout<<'\n';

    }

/*

    In acest algoritm am descris si comparat trei implementari diferite pentru quick sort, acelea fiind:
        1. Quick Sort cu partitionare de tip "Lomuto" si ca pivot ales fiind ultimul element avand o viteza destul de buna
      comparat cu restul variantelor de implementare (pentru 10^8 numere ia aprox 25-26 secunde)
        2. Quick Sort cu partitionare de tip "Hoare" si ca pivot ales fiind primul element. Aceasta implementare este cea
      mai optima implementare, avand o viteza de 24-25 secunde pentru 10^8 numere.
        3. Quick Sort cu partitionare de tip "Lomuto" si ca pivot ales fiind un element random generat intre low si high,
      fiind destul de lent in comparatie cu variantele prezentate mai sus (28-29 secunde pentru 10^8 numere)

*/
    return 0;
    }
