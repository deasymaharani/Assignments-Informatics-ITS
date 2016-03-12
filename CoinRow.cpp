/*Deasy - 5111100035*/

#include <iostream>
#include <math.h>
#define MAX_LENGTH 10

using namespace std;

int Final[MAX_LENGTH];
int Maxim[MAX_LENGTH];

void CoinRow(int n, int Coin[MAX_LENGTH])
{
    Final[0] = 0;
    Final[1] = Coin[1];
    
    int Temp1, Temp2;
    
    for(int i=2;i<=n;i++)
    {
        Temp1 = Final[i-1];
        Temp2 = Coin[i] + Final[i-2];
        
        if(Temp1 > Temp2)
        {
           Final[i] =  Temp1;
           Maxim[i] = i-1;
        }
        else
        {   
            Final[i] =  Temp2;
            Maxim[i] = i-2;
        }
    }
    
}

int main()
{
    int Coin[MAX_LENGTH];
    int n, varBT;
    
    cout<<"masukkan jumlah koin"<<endl;
    cin>>n;
    cout<<"masukkan koin"<<endl;
    for(int i=1;i<=n; i++)
        cin>>Coin[i];

    CoinRow(n, Coin);
    
    cout<<"Maximum Amount is"<<endl;
    cout<<Final[n]<<endl;
    
     varBT = n;
     
    cout<<"Denomination of the coins are"<<endl;
    while(varBT!=0 && varBT!=1)
    {
      if(varBT - 2 == Maxim[varBT])
        
        cout<<"index "<<varBT<<". "<<Coin[varBT]<<endl;
      varBT = Maxim[varBT];
    }
    if(varBT == 1)
      cout<<"index "<<varBT<<". "<<Coin[varBT]<<endl;
    
    system("pause");
}
