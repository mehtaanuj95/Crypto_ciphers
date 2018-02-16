#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long m;
	cout<<"Person B : Choose a message"<<endl;
	cin>>m;

	long long int p1, p2;
	//cout<<"Person A : Choose two prime numbers"<<endl;
	//cin>>p1>>p2;
	p1 = 53; p2 = 59;
	long long int n = p1*p2;
	long long int phi_n = (p1-1)*(p2-1);

	long long int e;
	cout<<"Person A : Choose a odd small public exponent e"<<endl;
	cin>>e;

	//Choose a random number k
	long long int k = 2;
	//Private exponent of A
	long long int d;
	d = (k*phi_n+1)/e;
	cout<<"d is : "<<d<<endl;

	//'n' and 'e' are A's public keys
	//B's encrypted message
	long long int c;
	c = ((long long int)pow(m, e))%n;
	cout<<"c is : "<<c<<endl;

	//A's calculation to decrypt c;
	long long int msg_received;
	//msg_received = ((long long int)pow(c, d))%n;
    msg_received = c;
    for(int t = 2; t <= d; t++)
    {
    	msg_received = (msg_received * c)%n; 
    }

	cout<<"Msg received by A is : "<<msg_received<<endl;
	return 0;
}