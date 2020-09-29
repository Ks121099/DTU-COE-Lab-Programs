#include <iostream>
#include<math.h>

using namespace std;

long long int calc(long long int a, long long int b, long long int N)
{ 
    if (b == 1)
        return a;
 
    else
        return (((long long int)pow(a, b)) % N);
}
 
int main()
{
    long long int N, G, x, a, y, b, ka, kb; 
    cout<<"\nEnter the values for N and G\n";
    cin>>N>>G;
	cout<<"\nEnter the private key for A ";
    cin>>a; 
    cout<<"Enter the private key for B ";
	cin>>b;
   
    cout<<"\nThe private key of A: "<<a;
    cout<<"\nThe private key of B: "<<b;
    x = calc(G, a, N); 
    y = calc(G, b, N); 
    
    cout<<"\n\nAfter exchange of keys";
    cout<<"\nkey recieved by A is (y):"<<y;
    cout<<"\nkey recieved by B is (x):"<<x;

    ka = calc(y, a, N); 
    kb = calc(x, b, N); 
     
    cout<<"\n\nActual key for the A is : "<<ka;
    cout<<"\nActual Key for the B is : "<<kb;
    if(ka==kb) 
    cout<<"\n\nBoth users have matching keys, thus successful\n"; 
    else
    cout<<"Key Generation failed"; 
    
    return 0;
}