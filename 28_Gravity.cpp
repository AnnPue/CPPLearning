#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    const float g = 9.81; // Acceleration due to gravity in m/s^2
    double posi = 0, velocity = 0;
    for(int i = 0; i < n; i++)
    {
        velocity += 0.5 * g;
        posi += velocity;
        cout << "v: " << velocity << '\t';
        cout << "y: " << posi << endl;
    }
    return 0;
}
