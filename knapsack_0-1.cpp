#include <stdio.h>
#include <conio.h>
#include <string.h>
void urutkanbyprofit(int no[],int weight[],int profit[]);
void urutkanbyweight(int no[],int weight[],int profit[]);
void urutkanbydensity(int no[],int weight[],int profit[],int density[]);
int knapsack; 
typedef struct{ 
int w; 
int p; 
int d; 
char s[15]; 
int i; 
}tabel; 
tabel tabel1[7],tabel2[7],tabel3[7],tabel4[7]; 
int main() 
{ 
int j,k[7],l[7],m[7],n[7]; 
int acc=0; 
for(j=0;j<7;j++) 
{ 
printf("Masukkan nilai w%d =",j+1);scanf("%d",&tabel1[j].w); 
printf("Masukkan nilai p%d =",j+1);scanf("%d",&tabel1[j].p); 
tabel1[j].d=tabel1[j].p/tabel1[j].w; 
tabel1[j].i=j+1; 
} printf("Kapasitas Knapsack W:");scanf("%d",&knapsack); 
printf("i       wi        pi        pi/wi       status\n"); 
for(j=0;j<7;j++) 
{ 
printf("%d        ",tabel1[j].i); 
printf("%d        ",tabel1[j].w); 
printf("%d        ",tabel1[j].p); tabel1[j].d=tabel1[j].p/tabel1[j].w; 
printf("%d\n",tabel1[j].d); 
}
/*Greedybyprofit*/ 
acc=0; 
printf("\nGreedy By Profit"); 
for(j=0;j<7;j++) 
{ 
k[j]=tabel1[j].i; 
l[j]=tabel1[j].w; 
m[j]=tabel1[j].p; 
} 
urutkanbyprofit(k,l,m); 
for(j=0;j<7;j++) 
{ 
tabel2[j].i=k[j]; 
tabel2[j].w=l[j]; 
tabel2[j].p=m[j]; 
} 
for(j=0;j<7;j++) 
{ 
acc=acc+tabel2[j].w; 
if(acc<=knapsack) 
strcpy(tabel2[j].s,"Diambil"); 
else 
strcpy(tabel2[j].s,"Tidak diambil"); 
}
/*Hasil*/ 
printf("\ni       wi        pi        pi/wi       status\n"); 
for(j=0;j<7;j++) 
{ 
printf("%d        ",tabel2[j].i); 
printf("%d        ",tabel2[j].w); 
printf("%d        ",tabel2[j].p); 
tabel2[j].d=tabel2[j].p/tabel2[j].w; 
printf("%d        ",tabel2[j].d); 
printf("%s\n",tabel2[j].s); } 
/*end Greedybyprofit*/

/*Greedybyweight*/ 
acc=0; printf("\nGreedy By weight\n"); 
for(j=0;j<7;j++) 
{ 
k[j]=tabel1[j].i; 
l[j]=tabel1[j].w; 
m[j]=tabel1[j].p;
} 
urutkanbyweight(k,l,m); 
for(j=0;j<7;j++) 
{ 
tabel3[j].i=k[j]; 
tabel3[j].w=l[j]; 
tabel3[j].p=m[j]; 
} 
for(j=0;j<7;j++) 
{ 
acc=acc+tabel3[j].w; 
if(acc<=knapsack) strcpy(tabel3[j].s,"Diambil"); 
else 
strcpy(tabel3[j].s,"Tidak diambil"); 
}
/*Hasil*/ 
printf("\ni       wi        pi        pi/wi       status\n"); 
for(j=0;j<3;j++) 
{ 
printf("%d        ",tabel3[j].i); 
printf("%d        ",tabel3[j].w); 
printf("%d        ",tabel3[j].p); 
tabel3[j].d=tabel3[j].p/tabel3[j].w; 
printf("%d        ",tabel3[j].d); 
printf("%s\n",tabel3[j].s); 
} 
/*end Greedybyweight*/

/*Greedybydensity*/ 
acc=0; 
printf("\nGreedy By density\n"); 
for(j=0;j<7;j++) 
{ 
k[j]=tabel1[j].i; 
l[j]=tabel1[j].w; 
m[j]=tabel1[j].p; 
n[j]=tabel1[j].d; 
} 
urutkanbydensity(k,l,m,n); 
for(j=0;j<7;j++) 
{ 
tabel4[j].i=k[j]; 
tabel4[j].w=l[j]; 
tabel4[j].p=m[j]; 
tabel4[j].d=n[j]; 
} 
for(j=0;j<7;j++) 
{ 
acc=acc+tabel4[j].w; 
if(acc<=knapsack) 
strcpy(tabel4[j].s,"Diambil"); 
else 
strcpy(tabel4[j].s,"Tidak diambil"); 
}
/*Hasil*/ 
printf("\ni       wi        pi        pi/wi       status\n"); 
for(j=0;j<3;j++) 
{ 
printf("%d        ",tabel4[j].i); 
printf("%d        ",tabel4[j].w); 
printf("%d        ",tabel4[j].p); 
printf("%d        ",tabel4[j].d); 
printf("%s\n",tabel4[j].s); 
} 
/*end Greedybydensity*/
getche(); 
} 
void urutkanbyprofit(int no[],int weight[],int profit[]) 
{ 
int i,j,temp; 
for(i=0;i<7;i++) 
for(j=0;j<7;j++) 
if(profit[i]>profit[j]) 
{ 
temp=no[i]; 
no[i]=no[j]; 
no[j]=temp; 
temp=weight[i]; 
weight[i]=weight[j]; 
weight[j]=temp; 
temp=profit[i]; 
profit[i]=profit[j]; 
profit[j]=temp; 
} 
} 
void urutkanbyweight(int no[],int weight[],int profit[]) 
{ 
int i,j,temp; 
for(i=0;i<7;i++) 
for(j=0;j<7;j++) 
if(weight[i]<weight[j]) 
{ 
temp=no[i]; 
no[i]=no[j]; 
no[j]=temp; 
temp=weight[i]; 
weight[i]=weight[j]; 
weight[j]=temp; 
temp=profit[i]; 
profit[i]=profit[j]; 
profit[j]=temp; 
} 
} 
void urutkanbydensity(int no[],int weight[],int profit[],int density[]) 
{ 
int i,j,temp; 
for(i=0;i<7;i++) 
for(j=0;j<7;j++) 
if(density[i]>=density[j]) 
{ 
temp=no[i]; 
no[i]=no[j]; 
no[j]=temp; 
temp=weight[i]; 
weight[i]=weight[j]; 
weight[j]=temp; 
temp=profit[i]; 
profit[i]=profit[j]; 
profit[j]=temp; 
temp=density[i]; 
density[i]=density[j]; 
density[j]=temp; 
}}


