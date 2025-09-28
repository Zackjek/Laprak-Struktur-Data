#include<iostream>
using namespace std;

int main(){
    float celcius, fahrenheit;
    cout<<"Tulis sedingin apa gebetan lu : ";
    cin>>celcius;
    fahrenheit = (9.0/5.0) * celcius + 32;
    cout<< "Kalau di fahrenheit itu " << fahrenheit << " derajat" << endl;
    cout<< "Itu dingin banget sih, buruan peluk biar hangat :v" << endl;
    return 0;
}