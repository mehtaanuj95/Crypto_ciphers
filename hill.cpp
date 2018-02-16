#include <bits/stdc++.h>
using namespace std;

int main()
{

	//--------STEP - 1 : CREATE KEYWORD MATRIX-----------//
	char keywordValue[20];
	int keywordOrder;
	cout<<"Choose a keyword order"<<endl;
	cin>>keywordOrder;
	int keyword[keywordOrder][keywordOrder];
	cout<<"Enter the keyword"<<endl;
	cin>>keywordValue;
	int length_keywordValue = strlen(keywordValue);

	if(length_keywordValue > keywordOrder*keywordOrder) {
		int count = 0;
		for(int i = 0; i < keywordOrder; i++) {
			for(int j = 0; j < keywordOrder; j++) {
				keyword[i][j] = keywordValue[count] - 'a';
				count++; 
			}
		}
	}
	else {
		int count = 0;
		int countPadding = 0;
		int countkeywordvalue = 0;
		for(int i = 0; i < keywordOrder; i++) {
			for(int j = 0; j < keywordOrder; j++) {
				count++;
				if(count <= length_keywordValue) {
					keyword[i][j] = keywordValue[countkeywordvalue] - 'a'; 
					countkeywordvalue++;
				}
				else {
					keyword[i][j] = countPadding;
					countPadding++; 		
				}
			}
		}
	}
	for(int i = 0; i < keywordOrder; i++) {
		for(int j = 0; j < keywordOrder; j++) {
			cout<<keyword[i][j]<<" ";
		}
		cout<<endl;
	}

	//-------------STEP - 2 : CREATE TEXT MATRICES----------//
	cout<<"ENter the text"<<endl;
	char textValue[100];
	cin>>textValue;
	int length_textValue = strlen(textValue);

	int width = length_textValue / keywordOrder;
	if(length_textValue % keywordOrder != 0)  
		width++;	
	//width+= 1; //to account for padding
	int text[keywordOrder][width];
	int count = 0;
	for(int i = 0; i < width; i++) {
		for(int j = 0; j < keywordOrder; j++) {
			if(count < length_textValue) {
				text[j][i] = textValue[count] - 'a';
				count++;
			}
			else {
				text[j][i] = 23;
			}
		}
	}
	for(int i = 0; i < width; i++) {
		cout<<text[0][i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i < width; i++) {
		cout<<text[1][i]<<" ";
	}

	//--------------STEP - 3 : Matrix MULTIPLICATION----------------//
	int temp1, temp2; 
	for(int k = 0; k < width; k++) {		
			temp1 = (keyword[0][0]*text[0][k] + keyword[0][1]*text[1][k])%26;
			temp2 = (keyword[1][0]*text[0][k] + keyword[1][1]*text[1][k])%26;
			text[0][k] = temp1;
			text[1][k] = temp2;
	}
	cout<<endl;
	for(int i = 0; i < width; i++) {
		cout<<(char)(text[0][i] + 'a')<<" ";
	}
	cout<<endl;
	for(int i = 0; i < width; i++) {
		cout<<(char)(text[1][i] + 'a')<<" ";
	}

	return 0;
}