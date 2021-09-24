//
#include<bits/stdc++.h>
using namespace std;
 
int knapsack_dp(int n, int M, int w[], int p[])
{
    int i,j;
 
    //membuat matrix dynamic programming
    int knapsack[n+1][M+1];
 
    //knapsack[i][j] menunjukkan nilai maksimum item yang dapat dicapai dalam knpasack dengan i tersedia 
    //item dan kapasitas knapsack menjadi j
    for(j=0;j<=M;j++)
        knapsack[0][j]=0; //karena jika tidak ada item, tidak ada nilai yang dapat dicapai
 
    //inisialisasi knapsack[i][0]=0 for 0<=i<=n,
    for(i=0;i<=n;i++)
        knapsack[i][0]=0; 
 
    //mengisi matrix
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=M;j++)
        {
            //mengecek apakah berat barang i saat ini kurang dari atau sama dengan kapasitas knapsack
            //lalu mengambil nilai maksimal dari item
            if(w[i-1]<=j)
            {
                knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
            }
 
            //jika tidak dapat menyertakan item saat ini dalam kasus ini, maka:
            else
            {
                knapsack[i][j]=knapsack[i-1][j];
            }
        }
    }
 
 
    return knapsack[n][M];
 
 
}
 
int main()
{
    int i,j;
    int n;  //banyak item
    int M;  //kapasitas knapsack
 
    cout<<"Masukkan banyak barang : ";
    cin>>n;
 
    int w[n];  //weight dari item
    int p[n];  //value dari item
 
    cout<<"Masukkan weight dan profit dari semua item"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
 
    cout<<"Masukkan kapasitas knapsack  ";
    cin>>M;
 
 
    int result=knapsack_dp(n,M,w,p);
 
    //nilai maksimum akan diberikan oleh knasack[n][M], yaitu menggunakan n item dengan kapasitas M
    cout<<"Hasil profit maksimal dengan dynamic programming: "<<result;
    return 0;
}
