//this code has benn written by GDM and he reserves all rights over this code.

#include <iostream>
#include<string>
using namespace std;

class CaesarEncry  //this class has the function that is used to encry the plaintext using caesar cipher and returns the ciphertext
{
public:
	int key;
	string plaintext,ciphertext;
	CaesarEncry()
	{
		cout << "Enter the plaintext"<<endl;
		cin >> plaintext;
		cout << "Enter the key for caesar encryption"<<endl;
		cin>>key;
	}
	string Cencry()
	{
		for (int i = 0; i < plaintext.length(); i++)
		{
			ciphertext[i] = char(int(plaintext[i]) + key);
		}
		cout << ciphertext;
		return "";
	}
};

class CaesarDecry  //this class contains the function that is used to decrypt the ciphertext to plaintext and returns plaintext as value 
{
public:
	int key;
	string plaintext, ciphertext;
	CaesarDecry()
	{
		cout << "Enter the ciphertext"<<endl;
		cin >> ciphertext;
		cout << "Enter key for Decryption"<<endl;
		cin >> key;
	}
	string Cdecry()
	{
		for (int i = 0; i < ciphertext.length(); i++)
		{
			plaintext[i] = char(int(ciphertext[i]) - key);
		}
		cout << plaintext;
		return "";
	}
};

class VignereEncry  //this class contains the function that is used to encrypt a given plaintext to ciphertext and returns the ciphertext
{
public:
	string key, plaintext,ciphertext;

	VignereEncry()
	{
		cout << "Please enter the plaintext to be encrypted"<<endl;
		cin >> plaintext;
		cout << "Please enter the key for encrypting the plaintext" << endl;
		cin >> key;
	}
	
	string Vencry()
	{
		int n = key.length();
		int a, b, c, d;
		string newkey;
		for (int i = n; i < plaintext.length(); i++)
		{
			key = key + key[i - n];
		}
		for (int j = 0; j < plaintext.length(); j++)
		{
			c = plaintext[j];
			b = key[j];
			a = 'a';
			d = (c - a) + (b - a);
			ciphertext = ciphertext + char(d);
		}
		cout << ciphertext;
		return "";
	}
};

class VignereDecry //this class contains the function that is used to decrypt a given ciphertext and returns the plaintext
{
public:
	string key, plaintext, ciphertext;
	VignereDecry()
	{
		cout << "Enter the encrypted ciphertext to be decrypted" << endl;
		cin >> ciphertext;
		cout << "Enter the key text";
		cin >> key;
	}
	string Vdecry()
	{
		int n = key.length();
		int a, b, c, d;
		for (int i = n; i < ciphertext.length(); i++)
		{
			key = key + key[i - n];
		}
		for (int j = 0; j < ciphertext.length(); j++)
		{
			c = ciphertext[j];
			b = key[j];
			a = 'a';
			d = (c - a) - (b - a);
			plaintext = plaintext + char(d);
		}
		cout << plaintext;
		return "";
	}
};

class XORencry  //this class has the function that is used to encrypt a given plaintext to ciphertext
{
public:
	string plaintext, ciphertext, key;

	XORencry()
	{
		cout << "Enter the plaintext for XOR encryption";
		cin >> plaintext;
		cout << "Enter the key for Encryption";
		cin >> key;
	}
	string Encry()
	{
		int n = key.length();
		for (int i = n; i < plaintext.length(); i++)
		{
			key = key + key[i - n];
		}
		for (int i = 0; i < plaintext.length(); i++)
		{
			ciphertext[i] = plaintext[i] ^ key[i];
		}
		cout << ciphertext;
		return "";
	}
};

class XORdecry //this class has the function that is used to decrypt a given ciphertext to plaintext using appropriate key
{
public:
	string plaintext, ciphertext, key;
	XORdecry()
	{
		cout << "Enter the ciphertext for XOR decryption";
		cin >> ciphertext;
		cout << "Enter the key for Encryption";
		cin >> key;
	}
	string Decry()
	{
		int n = key.length();
		for (int i = n; i < ciphertext.length(); i++)
		{
			key = key + key[i - n];
		}
		for (int i = 0; i < ciphertext.length(); i++)
		{
			plaintext[i] = ciphertext[i] ^ key[i];
		}
		cout << plaintext;
		return "";
	}
};


int main()
{
	int func;
	cout << "__________**********__________" << "WELCOME TO ENCRYDECRY" << "__________**********__________" << endl;
	cout << endl;
	cout << "What do you want this system to process?" << endl << "1.Caesar Encryption" << endl << "2.Caesar Decryption" << endl << "3.Vignere Encryption" << endl << "4.Vignere Decryption" << endl << "5.XOR encyption" << endl << "6.XOR decryption" << endl;
	cout << "Enter the number corresponding to the function to perform it\t";
	cin >> func;
	cout << endl;
	if (func == 1)
	{
		CaesarEncry c;
		c.Cencry();
	}
	else if (func == 2)
	{
		CaesarDecry d;
		d.Cdecry();
	}
	else if (func == 3)
	{
		VignereEncry v;
		v.Vencry();
	}

	else if (func == 4)
	{
		VignereDecry w;
		w.Vdecry();
	}

	else if (func == 5)
	{
		XORencry x;
		x.Encry();
	}

	else if (func == 6)
	{
		XORdecry y;
		y.Decry();
	}
	else
	{
		cout << "INVALID INPUT";
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


