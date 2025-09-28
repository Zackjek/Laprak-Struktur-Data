#include<iostream>
using namespace std;

int main(){
    double total_pembelian, diskon;
    cout<<"Berapa Kamu Belanja : Rp.";
    cin>>total_pembelian;
    if(total_pembelian >= 30000){
        diskon = 0.1 * total_pembelian;
        cout<<"Kamu dapat diskon sebesar : "<<diskon<<" orang kaya lu tong";
    }else{
        cout<<"Kamu belanjanya masih dikit, Tambahin lah, biar gua kaya :v";
    
    }
    return 0;
}