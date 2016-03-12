/*deasy maharani putri - 5111100035 - PAAL D*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> >FS;
vector<int>SelectedActivity;

void RecursiveActivitySelector(int k, int n)
{
  //FS[-1].first = 0;
  int m;
  m = k+1;

  while(m<=n && FS[m].second < FS[k].first)
     m = m+1;
  
  if(m<=n)
  {    
     SelectedActivity.push_back(m);
     RecursiveActivitySelector(m,n);
  }
  
}

int main()
{
    
    int n, i, finish, start;
    
    cout<<"masukkan jumlah aktivitas :"<<endl;
    cin>>n;
    FS.push_back(make_pair(0,0));
    cout<<"masukkan waktu finish dan start: "<<endl;
    for(i=0;i<n;i++)
      {
       cin>> finish; cin>> start;
       FS.push_back(make_pair(finish, start));    
      }
    
    sort(FS.begin(), FS.end(), less<pair<int, int> >());  
    
    RecursiveActivitySelector(0,n);
    /*
    for(i=0;i<FS.size();i++)
    {
      cout<< i <<FS[i].first << FS[i].second<<endl;
    }
    */
   cout<<endl;
   cout<<"Aktivitas yang terpilih adalah: "<<endl;
   for(i=0;i<SelectedActivity.size();i++)
    {
      cout<<i+1<<". "<<"Aktivitas "<<SelectedActivity[i]<<endl;
    }
    cout<<endl;
    system("pause");
}
