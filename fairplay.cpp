#include <bits/stdc++.h>
using namespace std;
int check(char a[], int length, char data)
{
	for(int i = 0; i <= length; i++)
	{	
		if(a[i] == data)
			return 1;
	}
	return -1;
}
int findxpos(char a[5][5], char data) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(a[i][j] == data)
				return i;
		}
	}
}
int findypos(char a[5][5], char data) {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			if(a[i][j] == data)
				return j;
		}
	}
}
int samecolumn(char a[5][5], char b, char c) {
	int y1 = findypos(a, b);
	int y2 = findypos(a, c);
	if(y1 == y2) {
		return 1;
	}
	else
		return -1;
}
int samerow(char a[5][5], char b, char c) {
	int x1 = findxpos(a, b);
	int x2 = findxpos(a, c);
	if(x1 == x2) {
		return 1;
	}
	else
		return -1;
}
int main()
{
	char key[20];
	cout<<"Choose a key"<<endl;
	cin>>key;

	char keymatrix[5][5];
	char key_without_duplicate[20];
	int k = 1;
	int length = strlen(key);
	key_without_duplicate[0] = key[0];
	for(int i = 1; i < length; i++)
	{
		if(check(key, i-1, key[i]) != 1)
		{
			key_without_duplicate[k] = key[i];
			k++;
		}
	}
	key_without_duplicate[k] = '\0';
	cout<<key_without_duplicate<<endl;

	//filling up the keymatrix
	int freq[26];
	for(int i = 0; i < 26; i++)
	{
		freq[i] = 0;
	}
	for(int i = 0;i < strlen(key_without_duplicate);i++) {
		int p = key_without_duplicate[i] - 'a';
		freq[p] = 1;
	}
	for(int i = 0; i < 26; i++) {
		cout<<(char)(i+97);
	}
	cout<<endl;
	for(int i = 0; i < 26; i++) {
		cout<<freq[i];
	}
	cout<<endl;
	//also put the frequency of q as 1
	freq['q' - 'a'] = 1;
	char a[25];
	for(int i = 0; i < 25; i++) {
		a[i] = ' ';
	}
	for(int i = 0;i < strlen(key_without_duplicate); i++)
	{
		a[i] = key_without_duplicate[i];
	}
	k = strlen(key_without_duplicate);
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] == 0) {
			a[k] = (char)(i+'a');
			k++;
		}
	}
	cout<<a<<endl;
	k = 0;
	//filling the keymatrix
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			keymatrix[i][j] = a[k];
			k++;
		}	
	}
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cout<<keymatrix[i][j]<<" ";
		}	
		cout<<endl;
	}

	cout<<"Enter the message to be encrypted"<<endl;
	char msg_old[20];
	char msg[20];
	cin>>msg_old;
	if(strlen(msg_old)%2 == 0) {
		strcpy(msg, msg_old);
	}
	else
	{
		int i;
		for(i = 0; i < strlen(msg_old); i++) {
			msg[i] = msg_old[i];
		}
		msg[i] = 'z';
		msg[i+1] = '\0';
	}
	//cout<<"New msg is : "<<msg<<"     its length : "<<strlen(msg)<<endl;
	char s[20];
	k = 0;
	for(int i = 0; i < strlen(msg)-1; i+=2) {
		char first = msg[i];
		char second = msg[i+1];
		if(k == 12) {
			break;
		}
		//condition 1
		if(samecolumn(keymatrix, first, second) == 1){
			int x = findxpos(keymatrix, first);
			int y = findypos(keymatrix, first);
			if(x == 4) {
				x = -1;
			}
			s[k] = keymatrix[x+1][y];
			k++;

			x = findxpos(keymatrix, second);
			y = findypos(keymatrix, second);
			if(x == 4) {
				x = -1;
			}
			s[k] = keymatrix[x+1][y];
			k++;
		}
		else if(samerow(keymatrix, first, second) == 1) {
			int x = findxpos(keymatrix, first);
			int y = findypos(keymatrix, first);
			if(y == 4) {
				y = -1;
			}
			s[k] = keymatrix[x][y+1];
			k++;
			
			x = findxpos(keymatrix, second);
			y = findypos(keymatrix, second);
			if(y == 4) {
				y = -1;
			}
			s[k] = keymatrix[x][y+1];
			k++;
		}
		else {
			int x1 = findxpos(keymatrix, first);
			int y1 = findypos(keymatrix, first);

			int x2 = findxpos(keymatrix, second);
			int y2 = findypos(keymatrix, second);
			s[k] = keymatrix[x1][y2];
			k++;
			s[k] = keymatrix[x2][y1];
			k++;
			
		}	
	}
	for(int i = 0; i < k; i++) {
		cout<<s[i];
	}
	cout<<endl;
}