/*#include<iostream>
using namespace std;
int main(){
    int m;
    cin>>m;
    int n ;
    cin>>n;
    int sum=m+n;
    cout<<"m "<<sum-m<<endl;
    cout<<"n "<<sum-n<<endl;
}
    */
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 3;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";

    return 0;
}