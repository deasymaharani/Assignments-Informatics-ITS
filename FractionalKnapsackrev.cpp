/*deasy maharani putri - 5111100035 - PAAL D*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<double, pair<int, int> >VW[100];
vector<pair<int, double> >KnapsackValue;

void FractionalKnapsack(int capacity, int n)
{
     double load;
     int item;
     
     load = 0;
     item = n-1;
     
     while(item >= 0 && load < capacity)
     {
       //cout<<"masuk while knapsack";         
       double remain = capacity - load;
       double take;
       double val;
       if(remain > 0)
       {
          if(VW[item].second.second <= remain)
          {
          take = VW[item].second.second;
          val = VW[item].second.first;
          KnapsackValue.push_back(make_pair(item,val));
          }
          else
          {
           take = (double)remain/VW[item].second.second;
           val = (double)take * VW[item].second.first;
           KnapsackValue.push_back(make_pair(item,val));
           }
           load = load + take;                       
           item = item-1;   
       }
     }
}

int main()
{
    int capacity, n, value, weight, i; 
    double ratio;
    
    cout<<"masukkan kapasitas tas: "<<endl;
    cin>>capacity;
    
    cout<<"masukkan jumlah item: "<<endl;
    cin>>n;
    
    cout<<"masukkan nilai dan bobot "<<endl;
    
    for(i=0;i<n;i++)
    {
     cin>>value;
     cin>>weight;
     VW[i].second.first = value; 
     VW[i].second.second = weight;
     VW[i].first = (double)VW[i].second.first / VW[i].second.second;
    }
     
    sort(VW, VW+n);
    
    for(i=0;i<n;i++)
    {
       cout<<i<<" "<<VW[i].first<<" "<<VW[i].second.first<<" "<<VW[i].second.second<<endl;
    }
    
    
    FractionalKnapsack(capacity, n);
    
    cout<<endl;
    
    cout<<"Isi knapsack adalah: "<<endl;
    
    for(i=0;i<KnapsackValue.size();i++)
    {
      cout<<i+1<<". "<<"Barang ke "<<KnapsackValue[i].first+1<<" senilai"<<" $"<<KnapsackValue[i].second<<endl;
    }
    
    cout<<"Total value pada knapasack adalah: $";
    
    double total=0;
    
    for(i=0;i<KnapsackValue.size();i++)
    {
      total = total+KnapsackValue[i].second;
    }
    cout<<total<<endl;
  
    system("pause");
}
