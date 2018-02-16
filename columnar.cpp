#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout<<"CHoose a key"<<endl;
	char key[20];
	cin>>key;
	int length_key = strlen(key);

	int f[26];
	for(int i = 0; i < 26; i++) {
		f[i] = 0;
	}
	for(int i = 0; i < length_key; i++) {
		int pos = key[i] - 'a';
		f[pos]++;
	}
	for(int i = 0; i < 26; i++) {
		cout<<(char)(i+'a');
	}
	cout<<endl;
	for(int i = 0; i < 26; i++) {
		cout<<f[i];
	}
	cout<<endl;

	int pos[26];
	for(int i = 0; i < 26; i++) {
		pos[i] = 0;
	}
	int count = 1;
	for(int i = 0; i < 26; i++) {
		if(f[i] == 1) {
			pos[i] = count;
			count++;
		}
	}
	for(int i = 0; i < 26; i++) {
		cout<<pos[i];
	}
	cout<<endl;
	//find permutation of key elements
	int per[length_key];
	for(int i = 0; i < length_key; i++) {
		int index = pos[ key[i] - 'a'];
		per[i] = index;	
	}
	for(int i = 0; i < length_key; i++) {
		cout<<per[i];
	}
	cout<<endl;

	char msg[100];
	cout<<"Enter your msg to be encrypted"<<endl;
	cin>>msg;
	int length_msg = strlen(msg);

	int rows = (length_msg / length_key)+1;
	char a[rows][length_key];
	int k = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < length_key; j++) {
			if(k < length_msg) {
				a[i][j] = msg[k];
				k++;
			}
			else {
				a[i][j] = '_';
			}
		}
	}
	for(int i = 0;i < rows; i++) {
		for(int j = 0; j < length_key; j++) {
			cout<<a[i][j];
		}
		cout<<endl;
	}
	cout<<"The encrypted message is : ";
	for(int i = 0;i < rows; i++) {
		for(int j = 0; j < length_key; j++) {
			cout<<a[j][i];
		}
	}
	cout<<endl;
	return 0;
}