#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[100], ch;
	int k;
	cout<<"Enter the string to be encrypted"<<endl;
	//cin>>s;
	gets(s);
	cout<<"Enter the shift"<<endl;
	int ok;
	cin>>k;
	ok = k;
	if(k > 0) {
		for(int i = 0; i < strlen(s); i++) {
			ch = s[i];
			if(ch == ' ')
			{
				s[i] = ' ';
				continue;
			}
			if(isupper(ch)) {
				
				if (k > 0) {
					ch = ch - 65;
					ch = (ch + (k%26))%26;
					ch = ch + 65;
					s[i] = ch;
				}
				else {
					ch = ch - 65;
					ch = (ch - (k%26))%26;
					ch = ch - 65;
					s[i] = ch;
				}
					
			}
			else {
				if(k > 0) {
					ch = ch - 97;
					ch = (ch + (k%26))%26;
					ch = ch + 97;
					s[i] = ch;	
				}
				else {
					ch = ch - 97;
					ch = (ch - (k%26))%26;
					ch = ch + 97;
					s[i] = ch;	
				}
				
			}
		}
	}
	/*
	else {
		k = k * -1;
		for(int i = 0; i < strlen(s); i++) {
			
			ch = s[i];
			if(ch == ' ') {
				s[i] = ' ';
				continue;
			}
			if(isupper(ch)) {
				k = k%26;
				ch = ch - 65;
				if(k > ch) {
					k - ch;
					ch = 26;
				}
				ch = ch - k;
				ch = ch + 65;
				s[i] = ch;	
			}
			else {
				k= k%26;
				ch = ch - 97;
				if(k > ch) {
					k - ch;
					ch = 26;
				}
				ch = ch - k;
				ch = ch + 97;
				s[i] = ch;	
			}
		}
	}
	cout<<s<<endl;
	cout<<"Encrypt successful"<<endl;
	//decrypt();
	if(ok > 0)
	{
		for(int i = 0; i < strlen(s); i++) {
			ch = s[i];
			if(ch == ' ') {
				s[i] = ' ';
				continue;
			}
			if(isupper(ch)) {
				ch = ch - 65;
				ch = (ch - (k%26))%26;
				ch = ch + 65;
				s[i] = ch;	
			}
			else {
				ch = ch - 97;
				ch = (ch - (k%26))%26;
				ch = ch + 97;
				s[i] = ch;	
			}
			

		}
	}
	else {
		for(int i = 0; i < strlen(s); i++) {
			k = ok;
			ch = s[i];
			if(ch == ' ') {
				s[i] = ' ';
				continue;
			}
			if(isupper(ch)) {
				ch = ch - 65;
				ch = (ch - (k%26))%26;
				ch = ch + 65;
				s[i] = ch;	
			}
			else {
				ch = ch - 97;
				ch = (ch - (k%26))%26;
				ch = ch + 97;
				s[i] = ch;	
			}
		}
	}
	*/
	cout<<s<<endl;
	cout<<pow(1,2)<<endl;
	//cout<<-1%26<<endl;
	return 0;
}