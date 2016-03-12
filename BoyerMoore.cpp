//Deasy Maharani Putri 5111100035 - BoyerMoore

#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#define MAX_LEN 255

using namespace std;

int Table[MAX_LEN];
int GoodSuffix[MAX_LEN];

int check(int len_pat, int i)        //fungsi untuk mengecek apakah shift table masih bernilai 6 atau bukan, jika bukan maka tidak perlu diganti
{
    //for(int idx=0;idx<MAX_LEN;idx++)
        //{
            if(Table[i]!=len_pat)
            return 1;
        //}
            else return 0;
}

void ShiftTable(string pattern)     //fungsi untuk mengisi shift table
{
    int len_pat, cek;

    len_pat = pattern.length();

    for(int i=0;i<MAX_LEN;i++)
    Table[i] = len_pat;     //diinisialisasi 6 semua

    for(int j=len_pat-2;j>=0;j--)   //memasukkan nilai ke tabel, loop dari belakang.
    {
        cek = check(len_pat, pattern[j]);   //cek dulu, apabila masih bernilai 6 maka di replace dg jarak sesungghnya, bila bukan 6 maka tidak perlu replace
        if(cek == 0)
            Table[pattern[j]] = len_pat-1-j;
    }
}
//fungsi untuk ngeprin isi dari shift table (hanya untuk debugging)
void PrintShiftTable()
{
    for(int a=0; a<=MAX_LEN; a++)
    {
        cout<<(char)a;
    }
    cout<<endl;

    for(int a=0; a<=MAX_LEN; a++)
    {
        cout<<Table[a];
    }
}
//good suffix table
void GoodSuffixTable()
{
    GoodSuffix[0] = 0;
    GoodSuffix[1] = 2;
    for(int i = 2; i<=5; i++)
        GoodSuffix[i] = 5;
}

int BoyerMoore(string pattern, string text)
{
    ShiftTable(pattern); //generate shift table
    GoodSuffixTable();//generate goodsuffix table
    //PrintShiftTable();

    int len_pat = pattern.length();
    int len_text = text.length();
    int i = len_pat-1;
    while(i<=len_text-1)       //mulai proses boyermoore - proses menggeser menurut jarak yang ditentukan oleh d1 dan d2
    {
         int match = 0;
         while(match<=len_pat-1 && pattern[len_pat-1-match]==text[i-match])
             {
                match = match + 1;  //apabila karakter di teks sama dengan karakter di pattern, maka jumlah kecocokan ditambah
             }
         if(match == len_pat)   //apabila jumlah kecocokan pada teks sama dengan pattern, maka ambil indeks cocok pertama kali
             return i - len_pat + 1;
         else   //menggeser menurut indeks dan jarak d
         {  int d1, d2, d, shift;
            shift = Table[text[i-match]] - match;
            d1 = max(shift,1);      //menghitung d1 dengan mengurangkan nilai karakter pada tabel dengan banyaknya kecocokan yang telah didapat
            d2 = GoodSuffix[match]; //mengambil nilai d2 pada tabel goodsuffix
            d = max(d1,d2);         //menghitung d dengan maksimal dari d1 dan d2
            cout<<"Table Value: "<< Table[text[i-match]] << " d1: "<<d1 <<" d2: "<< d2 <<" d: "<< d <<" match: "<< match <<endl;
            i = i + d;  //geser pattern sebanyak posisi skrg ditambah nilai d
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

    //panggil fungsi boyermoore
    found = BoyerMoore(pattern, text);

    if(found >= 0)  //apabila ketemu, print teks beserta indeksnya
    {
             cout<<endl<<"substring is found at index "<<found<<endl;
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
