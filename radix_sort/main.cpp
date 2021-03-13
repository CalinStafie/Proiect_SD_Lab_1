#include <bits/stdc++.h>
#include <chrono>

//std::mt19937 gen(time(0));
using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");


void CountSort(unsigned int arr[], unsigned int n, unsigned int exp, unsigned int baza)
{
    unsigned int i,contor;
    vector<vector<unsigned int>> frecv(baza, vector<unsigned int>());
    for(i=0;i<n;++i)
            frecv[(arr[i] / exp) % baza].push_back(arr[i]);

    unsigned int j = 0;
    for(i=0;i<=baza-1;++i)
            for(contor=0;contor<frecv[i].size();++contor)
                arr[j++] = frecv[i][contor];

}
void radixSort(unsigned int arr[], unsigned int n, unsigned int baza)
{
    unsigned int maxim_array = *max_element(arr, arr + n);
    short int numar_cifre_maxim = 0;
    do
    {
        ++numar_cifre_maxim;
        maxim_array/=baza;
    }while(maxim_array);
    unsigned int exp = 1;
    for(short int l=1; l<=numar_cifre_maxim; ++l)
    {
        CountSort(arr, n, exp, baza);
        exp *= baza;
    }
}
/* //Am incercat si un alt algoritm de generare random a numerelor.
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
unsigned int baza;

int main()
{
    fin>>T;
    cout<< "Introduceti numarul de bucketuri in care sa se lucreze (baza): ";
    cin>> baza;
    for(int k=1;k<=T;k++)
    {
        fin>>numar_numere>>val_max;
        cout<< "N = " << numar_numere << "  " << "Max = "<< val_max << '\n';
        generate_Randoms(v, numar_numere, val_max);
        cout << "RadixSort va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();


        radixSort(v, numar_numere, baza);

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


    return 0;
    }

/*
    Varianta cu memorie statica e mult mai rapida ca timp decat varianta cu alocare dinamica cu vreo 6 secunde pentru 10^8
    numere si cu vreo 2 secunde pentru 10^7 nr.

*/



/*
#include <bits/stdc++.h>
#include <chrono>

//std::mt19937 gen(time(0));
using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");


void CountSort(vector <unsigned int> &arr, unsigned int n, unsigned int exp, unsigned int baza)
{
    unsigned int i,contor;
    vector<vector<unsigned int>> frecv(baza, vector<unsigned int>());
    for(i=0;i<n;++i)
            frecv[(arr[i] / exp) % baza].push_back(arr[i]);

    unsigned int j = 0;
    for(i=0;i<=baza-1;++i)
            for(contor=0;contor<frecv[i].size();++contor)
                arr[j++] = frecv[i][contor];

}
void radixSort(vector <unsigned int> &arr, unsigned int n, unsigned int baza)
{
    unsigned int maxim_array = *max_element(arr.begin(), arr.end());
    short int numar_cifre_maxim = 0;
    do
    {
        ++numar_cifre_maxim;
        maxim_array/=baza;
    }while(maxim_array);
    unsigned int exp = 1;
    for(short int l=1; l<=numar_cifre_maxim; ++l)
    {
        CountSort(arr, n, exp, baza);
        exp *= baza;
    }
}
/* //Am incercat si un alt algoritm de generare random a numerelor.
void generate_Randoms(unsigned int v[], unsigned int numar_numere, unsigned int val_max){
    std::uniform_int_distribution<unsigned int> u_int(0, val_max);

    for (int i = 0; i < numar_numere; i++)
        v[i] = u_int(gen);
}
*/
/*
std::mt19937 randomgen(time(NULL));
//std::uniform_int_distribution<unsigned int>;
void generate_Randoms(vector <unsigned int> &a,unsigned int numar_numere, unsigned int val_max)
{
    //generam aleator "numar_numere" numere intre 0 si "val_max";
    for(unsigned int x=0; x<numar_numere; x++)
        {
            unsigned int t = randomgen()%(val_max+1);
            a.push_back(t);
        }
}

bool test_sort(vector <unsigned int> &a, unsigned int n)
{
    unsigned int i;
    for(i=0;i<n-1;++i)
        if(a[i]>a[i+1])
            return false;
    return true;
}

vector <unsigned int> v;
unsigned int T, numar_numere, val_max;
unsigned int baza;

int main()
{
    fin>>T;
    cout<< "Introduceti numarul de bucketuri in care sa se lucreze (baza): ";
    cin>> baza;
    for(int k=1;k<=T;k++)
    {
        fin>>numar_numere>>val_max;
        cout<< "N = " << numar_numere << "  " << "Max = "<< val_max << '\n';
        generate_Randoms(v, numar_numere, val_max);
        cout << "RadixSort va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        radixSort(v, numar_numere, baza);

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


    return 0;
    }
*/
