//Program Knapsack Fractional +tabel dengan greedy
#include <cstdlib>
#include <iostream>

//deklarasi berat, profit, kapasitas, dan jumlah barang
using namespace std;
int w[10],p[10],p_no[10],n,m;
float d[10],x[10];

template <class T>
void item(T *a,int i,int j)
{ T temp;
 temp=a[j];
 a[j]=a[i];
 a[i]=temp;
 return;
}

void display() //untuk menampilkan tabel
{
 cout<<"\nBarang\t\tW\t\tP\t\tPi/Wi\n";
 
 for(int i=0;i<n;i++)
  cout<<p_no[i]<<"\t\t"<<w[i]<<"\t\t"<<p[i]<<"\t\t"<<d[i]<<"\n";
  
}

//fungsi menghitung profit maksimal
void knapsack()
{
 int u,i; //variabel untuk kapasitas barang
 u=m;
 float x[10];
 for(i=0;i<n;i++)
  x[i]=0;
 for(i=0;i<n;i++)
 {
  if(w[i]>u)
   break;
  else
  {
   x[i]=1;
   u=u-w[i];
  }
  //perurangan untuk sorting greedy by density 
 }
 if(i<=n)
  x[i]=(float)u/w[i];
 for(i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
   if(p_no[i]>p_no[j])
   {
    item(p_no,i,j);
    item(x,i,j);
    item(p,i,j);
   }
  }
 }
 float opt_solution=0;
 for(i=0;i<n;i++)
 {
  //perhitungan profit maksimum
  opt_solution=opt_solution+(p[i]*x[i]);
 }
 
 cout<<"===========HASIL===========\n";
 cout<<"\nBarang\t\tDiambil\n";
 
 for(int i=0;i<n;i++)
 cout<<p_no[i]<<"\t\t"<<x[i]<<"\n";
 
 cout<<"\nJumlah profit maksimal yang didapat: "<<opt_solution;
}

//program utama
int main(int argc, char *argv[])
{
    int i;
cout<<"Metode Greedy untuk Knapsack";
 cout<<"\n\nKapasitas knapsack :  ";
 cin>>m;
 cout<<"Banyak Barang: ";
 cin>>n;
 
 for(i=0;i<n;i++)
 {
  p_no[i]=i+1;
  cout<<"\nBarang ke-"<<i+1<<"\nProfit:\t";
  cin>>p[i];
  cout<<"Berat:\t";
  cin>>w[i];
  d[i]=(float)p[i]/w[i];
 }
 display();
 for(i=0;i<n;i++)
 {
  for(int j=i+1;j<n;j++)
  {
   if(d[i]<d[j])
   {
    item(p_no,i,j);
    item(w,i,j);
    item(p,i,j);
    item(d,i,j);
   }
  }
 }
 display();
 knapsack();
 cout<<"\n\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
