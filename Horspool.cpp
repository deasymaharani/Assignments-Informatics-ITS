//Deasy Maharani Putri 5111100035 - Horspool

#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#define MAX_LEN 255

using namespace std;

int Table[MAX_LEN];

int check(int len_pat, int i)   //fungsi untuk mengecek apakah isi pada tabel masih bernilai 6 atau tidak
{
    //for(int idx=0;idx<MAX_LEN;idx++)
        //{
            if(Table[i]!=len_pat)
            return 1;
        //}
            else return 0;
}

//fungsi untuk memasukkan nilai karakter pada shift table
void ShiftTable(string pattern)
{
    int len_pat, cek;

    len_pat = pattern.length();

    for(int i=0;i<MAX_LEN;i++)  //menginisialisasi semua nilai karakter pada tabel dengan nilai 6
    Table[i] = len_pat;

    for(int j=len_pat-2;j>=0;j--)   //fungsi memasukkan dengan loop dari belakang, sehingga harus di cek dahulu
    {
        cek = check(len_pat, pattern[j]);   //cek apakah nilai pada tabel masih 6 atau tidak,
        if(cek == 0)    //bila masih 6 maka di replace dengan jarak geser yg baru
            Table[pattern[j]] = len_pat-1-j;
    }
}
//fungsi hoorspool
int HoorspoolMatching(string pattern, string text)
{
    ShiftTable(pattern);    //generate shift table
    int len_pat = pattern.length();
    int len_text = text.length();
    int i = len_pat-1;
    while(i<=len_text-1)    //proses mencocokan antara teks dengan pattern
    {
         int match = 0;
         while(match<=len_pat-1 && pattern[len_pat-1-match]==text[i-match]) //apabila terdapat kecocokan antara teks dengan pattern
         {
                match = match + 1;  //maka counter kecocokan ditambah
         }
         if(match == len_pat)   //apabila jumlah kecocokan pada pattern sama dengan kecocokan pada teks, maka diambil indeksnya
             return i - len_pat + 1;
         else       //apabila tidak terdapat kecocokan maka digeser berdasarkan jarak yg terdapat pada tabel
         {
             i = i + Table[text[i]];
         }
    }
    return -1;
}

int main()
{
    string pattern;
    string text;
    int found;

    cout<<"masukkan text :"<<endl;
    getline(cin, text);

    cout<<"masukkan pattern :"<<endl;
    getline(cin, pattern);

    ShiftTable(pattern);
/*
    for(int a=0; a<=MAX_LEN; a++)
    {
        cout<<"%c"<<a;
    }
    cout<<endl;

    for(int a=0; a<=MAX_LEN; a++)
    {
        cout<<Table[a];
    }
*/
    //memanggil fungsi hoorspool
    found = HoorspoolMatching(pattern, text);

    if(found >= 0)  //apabila ketemu, print index nya
    {
             cout<<"substring is found at index "<<found<<endl;
             for(int i=0;i<text.length();i++)
             {
                     cout << text[i] << " " ;
             }
             cout << endl;
             for(int i=0;i<text.length();i++)
             {
                     cout << i << " " ;
             }
             cout << endl;
    }
    else
    cout<<"substring is not found over all of text"<<endl;

    system("pause");
}
