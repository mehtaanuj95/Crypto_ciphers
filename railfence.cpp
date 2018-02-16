/*
Description : Rail Fence Cipher
Author : Anuj BHai Mehta
Date: Friday, 5th January, 2018 @ 01:35 AM
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"Enter the plain text"<<endl;
	char plainText[100];
	cin>>plainText;
	cout<<"Enter number of rails"<<endl;
	int rails;
	cin>>rails;
	
	//rail fence matrix
	char a[rails][100];

	//----------STEP - 1 : Fill railfence matrix---------//
	int direction = -1;
	int i = 0, j = 0;
	int k = 1;
	int length = strlen(plainText);

	//fill rail fence matrix by null values
	for(int p = 0; p < rails; p++) {
		for(int q = 0; q < 100; q++) {
			a[p][q] = '_';
		}
	}
	int dir = -1;
	a[0][0] = plainText[0];
	while(k < length) {
		if(direction < 0) {
			a[i+1][j+1] = plainText[k];
			i++;
			j++;
			k++;
		}
		else {
			a[i-1][j+1] = plainText[k];
			k++;
			i--;
			j++;
		}
		if(i == (rails - 1) && dir == -1) 
		{
			direction = -1*direction;
			dir = 1;
		}
		if(i == 0 && dir == 1)
		{
			direction = -1*direction;
			dir = -1;
		}
	}
	char ciphertext[length];
	k = 0;
	for(int p = 0; p < rails; p++) {
		for(int q = 0; q < 100; q++) {
			if(a[p][q] != '_') {
				ciphertext[k] = a[p][q];
				k++;
			}
			if(k == length ) 
				break;
		}
	}
	ciphertext[length] = '\0';
	cout<<"The cipher text is : ";
	cout<<ciphertext<<endl;
	//------------DECRYPTION-----------//
	char original[rails][strlen(plainText)];
	//fill original matrix with positions
	direction = -1;
	i = 0, j = 0;
	k = 1;
	length = strlen(plainText);

	//fill rail fence matrix by null values
	for(int p = 0; p < rails; p++) {
		for(int q = 0; q < strlen(plainText); q++) {
			original[p][q] = '_';
		}
	}
	dir = -1;
	original[0][0] = '*';
	while(k < length) {
		if(direction < 0) {
			original[i+1][j+1] = '*';
			i++;
			j++;
			k++;
		}
		else {
			original[i-1][j+1] = '*';
			k++;
			i--;
			j++;
		}
		if(i == (rails - 1) && dir == -1) 
		{
			direction = -1*direction;
			dir = 1;
		}
		if(i == 0 && dir == 1)
		{
			direction = -1*direction;
			dir = -1;
		}
	}
	k = 0;
	//fill the ciphertext accordingly
	for(int p = 0; p < rails; p++) {
		for(int q = 0; q < strlen(ciphertext); q++) {
			if(original[p][q] != '_') {
				original[p][q] = ciphertext[k];
				k++;
			}
		}
	}
	/*
	for(int p = 0; p < rails; p++) {
		for(int q = 0; q < strlen(ciphertext); q++) {
			cout<<original[p][q];
		}
		cout<<endl;
	}
	*/
	cout<<"The original text is : ";
	for(int p = 0; p < strlen(ciphertext); p++)
	{
		for(int q = 0;q < rails; q++) {
			if(original[q][p] != '_')
				cout<<original[q][p];
		}
	}
	cout<<endl;
	return 0;
}