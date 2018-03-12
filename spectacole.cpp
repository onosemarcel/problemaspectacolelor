#include<iostream>
#include<fstream>
using namespace std;
int n, k, ordi[100];
float O[100][2];
ifstream f("input_1.dat");
ofstream g("output_1.dat");
int read_data()
{
    /*cout<<"n=";cin>>n;
    for(int i=1;i<=n;i++)
{
    cout<<"trupa "<<i<<" incepe la ";cin>>O[i][1];
     cout<<"trupa "<<i<<" sfarseste la ";cin>>O[i][2];
    ordi[i]=i;
}
cout<<"pauza: ";
cin>>k;*/

f>>n;
for(int i=1;i<=n;i++)
{
    f>>O[i][1];
    f>>O[i][2];
    ordi[i]=i;
}
f>>k;
}


int sort_data()
{
int terminat=1;
do
{
    terminat=1;
    for(int i=1;i<n;i++)
    {
        if(O[ordi[i]][2]>O[ordi[i+1]][2])
         {
            swap(ordi[i],ordi[i+1]);
            terminat=0;
         }
    }
}while(!terminat);
}
float compute(float ora, int minute)
{
    ora*=100;
    ora+=minute;
    if((int)ora%100>=60)
        ora+=40;
    ora=(ora/100)+((int)ora%100)/100;
    return ora;
}
int main()
{
    read_data();
    sort_data();
    float x=O[ordi[1]][2];
    g<<ordi[1]<<" ";
    for(int i=2;i<=n;i++)
        if(compute(x, k)<O[ordi[i]][1])
            {
                g<<ordi[i]<<" ";
                x=O[ordi[i]][2];
            }
f.close();
g.close();
}
