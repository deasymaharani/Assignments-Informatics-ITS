/*deasy - 5111100035 - paal d*/

#include<iostream>
#include<math.h>
#define MAX_N 10
#define MAX_W 10

using namespace std;

int F[MAX_N][MAX_W];
int Weights[MAX_N];
int Values[MAX_N];

//inisialisasi tabel F
void InitTable(int n, int w)
{
     int i, j;
     for(i=0;i<=n;i++)
     {
        for(j=0;j<=w;j++)
        {
          if(i == 0 || j == 0)
             F[i][j] = 0;
          else
             F[i][j] = -1;
        }
     }     
}
//fungsi knapsack
int MFKnapsack(int i, int j)
{
    int value;
    
         if(F[i][j] < 0)
         {
            if(j<Weights[i])//bila kapasitas sudah penuh
              value = MFKnapsack(i-1,j);
            else//bila kapasitas masih cukup
              value = max(MFKnapsack(i-1,j),Values[i]+MFKnapsack(i-1,j-Weights[i]));
            
            F[i][j] = value;   
         }
         return F[i][j];
}

int main()
{
   int n,w,x,y,a,i,j;
   int sack[10];
       
   cout<<"masukkan kapasitas knapsack"<<endl;
   cin>>w; 
   cout<<"masukkan jumlah item"<<endl;
   cin>>n;
   
   cout<<"masukkan bobot item"<<endl;
   for(i=0;i<=n;i++)
      cin>>Weights[i];
   
   cout<<"masukkan nilai item"<<endl;
   for(i=0;i<=n;i++)
      cin>>Values[i];
   
   InitTable(n,w);
   MFKnapsack(n,w);   

   cout<<"jumlah total values pada knapsack adalah "<<F[n][w]<<endl;
   
   x=n;          //backtracking
   y=w;
   a=0;
   int count=0;
   while(x!=0 && y!=0)
   {
      if(F[x][y] > F[x-1][y])
      {
         sack[a] = x;
         y = w - Weights[x];
         x--;
         a++;
         count++;
      }
      else 
          x--;
   }
   cout<<endl;
   cout<<"item pada knapsack sejumlah "<<count <<" yang terdiri dari :" <<endl;
   for(int b=0;b<count;b++)
   cout<<"item ke: "<<sack[b]<<endl;

   system("pause");
}
