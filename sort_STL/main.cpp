#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

ifstream fin("../date.in");

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

int main()
{
    fin>>T;
    for(int k=1;k<=T;k++)
    {
        fin>>numar_numere>>val_max;
        cout<< "N = " << numar_numere << "  " << "Max = "<< val_max << '\n';
        generate_Randoms(v, numar_numere, val_max);
        cout << "Sort_STL va sorta array-ul cu "  << numar_numere << " numere, cu o valoare maxima in vector de "
                << val_max << " in: ";
        //start
        auto start = high_resolution_clock::now();

        sort(v.begin(), v.end());

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
