/*
Description : Diffie Hellman Encryption Technique
Author : Anuj BHai Mehta
Date: Friday, 5th January, 2018 @ 02:56 AM
*/

#include <bits/stdc++.h>
using namespace std;

long int calculate(long int g, long int p, long int key)
{
	return ((long long int)pow(g, key))%p;
}
int main()
{
	cout<<"Choose a generator and a prime modulus"<<endl;
	long int g, p;
	cin>>g>>p;
	long int private_A, private_B;
	long int public_A, public_B;
	long int secret_A, secret_B;

	cout<<"Person A : Select a private key"<<endl;
	cin>>private_A;
	public_A = calculate(g, p, private_A);
	cout<<"Person A : Your Public key : "<<public_A<<endl;

	cout<<"Person B : Select a private key"<<endl;
	cin>>private_B;
	public_B = calculate(g, p, private_B);
	cout<<"Person B : Your Public key : "<<public_B<<endl;

	secret_A = calculate(public_B, p, private_A);
	secret_B = calculate(public_A, p, private_B);

	cout<<"Person A : Your secret message : "<<secret_A<<endl;
	cout<<"Person B : Your secret message : "<<secret_B<<endl;
	return 0;
}