#include <iostream>
using namespace std;

int main() {
    int date,month;
    cin >> date;
    month = date%100;
    if (month<6&&month>2)cout<<"spring ";
    else if (month<9&&month>5)cout<<"summer ";
    else if (month<12&&month>8)cout<<"autumn ";
    else cout<<"winter ";
//或者:
    switch(month%12/3)
    {
        case 0:cout<<"winter"<<endl;break;
        case 1:cout<<"spring"<<endl;break;
        case 2:cout<<"summer"<<endl;break;
        case 3:cout<<"autumn"<<endl;break;
        default:break;
    }
    return 0;
}
