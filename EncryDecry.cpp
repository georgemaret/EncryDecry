//this code has benn written by GDM and he reserves all rights over this code.

#include <iostream>
#include<string>
using namespace std;
static int base = 'a';
class CaesarEncry  //this class has the function that is used to encry the plaintext using caesar cipher and returns the ciphertext
{
public:
	int key;
	string plaintext,ciphertext;
	CaesarEncry()
	{
		cout << "Enter the plaintext:  ";
		cin >> plaintext;
		cout << "Enter the key for caesar encryption:  ";
		cin>>key;
	}
	string Cencry()
	{
		for (int i = 0; i < plaintext.length(); i++)
		{
			if (isupper(plaintext[i]))
				ciphertext += char(int(plaintext[i] + key - 65) % 26 + 65);

			// Encrypt Lowercase letters
			else
				ciphertext += char(int(plaintext[i] + key- 97) % 26 + 97);
		}
		cout <<"Ciphertext: " << ciphertext << endl;
		return "";
	}
};

class CaesarDecry  //this class contains the function that is used to decrypt the ciphertext to plaintext and returns plaintext as value 
{
	int key;
	string plaintext, ciphertext;
public:
	CaesarDecry()
	{
		cout << "Enter the ciphertext: ";
		cin >> ciphertext;
		cout << "Enter key for Decryption: ";
		cin >> key;
	}
	string Cdecry()
	{
		for (int i = 0; i < ciphertext.length(); i++)
		{
			if (isupper(ciphertext[i]))
				plaintext += char(int(ciphertext[i] - key - 65) % 26 + 65);

			// Encrypt Lowercase letters
			else
				plaintext += char(int(ciphertext[i] - key - 97) % 26 + 97);
		}
		cout <<"Plaintext: " << plaintext << endl;
		return "";
	}
};

class VignereEncry  //this class contains the function that is used to encrypt a given plaintext to ciphertext and returns the ciphertext
{
	string key, plaintext, ciphertext;
public:

	VignereEncry()
	{
		cout << "Please enter the plaintext to be encrypted(Uppercase only)"<<endl;
		cin >> plaintext;
		cout << "Please enter the key for encrypting the plaintext(Uppercase only)" << endl;
		cin >> key;
	}
	
	string Vencry()
	{
		int n = key.length();
		string newkey=key;
		while (key.length() < plaintext.length())
		{
			key = key + newkey;
		}
		cout << key<<endl;
		for (int j = 0; j < plaintext.length(); j++)
		{
			char x = (plaintext[j] + key[j]) % 26;

			// convert into alphabets(ASCII)
			x += 'A';

			ciphertext.push_back(x);
		}
		cout << ciphertext<<endl;
		return "";
	}
};

class VignereDecry //this class contains the function that is used to decrypt a given ciphertext and returns the plaintext
{
	string key, plaintext, ciphertext;
public:
	
	VignereDecry()
	{
		cout << "Enter the encrypted ciphertext to be decrypted(Uppercase only)" << endl;
		cin >> ciphertext;
		cout << "Enter the key text(Uppercase only)"<<endl;
		cin >> key;
	}
	string Vdecry()
	{
		int n = key.length();
		string newkey = key;
		while (key.length() < ciphertext.length())
		{
			key = key + newkey;
		}
		for (int j = 0; j < ciphertext.length(); j++)
		{
			char x = ((ciphertext[j] - key[j])+ 26 ) % 26;

			// convert into alphabets(ASCII)
			x += 'A';
			plaintext.push_back(x);
		}
		cout << plaintext<<endl;
		return "";
	}
};

class XORencry  //this class has the function that is used to encrypt a given plaintext to ciphertext
{
	string plaintext, ciphertext, key;
public:
	
	XORencry()
	{
		cout << "Enter the plaintext for XOR encryption"<<endl;
		cin >> plaintext;
		cout << "Enter the key for Encryption"<<endl;
		cin >> key;
	}
	string Encry()
	{
		int n = key.length();
		string newkey = key;
		while (key.length() < plaintext.length())
		{
			key = key + newkey;
		}
		for (int i = 0; i < plaintext.length(); i++)
		{
			ciphertext[i] = plaintext[i] ^ key[i];
		}
		cout << ciphertext<<endl;
		return "";
	}
};

class XORdecry //this class has the function that is used to decrypt a given ciphertext to plaintext using appropriate key
{
	string plaintext, ciphertext, key;
public:
	
	XORdecry()
	{
		cout << "Enter the ciphertext for XOR decryption" << endl;
		cin >> ciphertext;
		cout << "Enter the key for Encryption"<<endl;
		cin >> key;
	}
	string Decry()
	{
		int n = key.length();
		string newkey = key;
		while (key.length() < ciphertext.length())
		{
			key = key + newkey;
		}
		for (int i = 0; i < ciphertext.length(); i++)
		{
			plaintext[i] = ciphertext[i] ^ key[i];
		}
		cout << plaintext<<endl;
		return "";
	}
};


int main()
{
	int func=0, exit=0;
	cout << "__________**********__________" << "WELCOME TO ENCRYDECRY" << "__________**********__________" << endl;
	cout << endl;
	while (exit == 0)
	{
		cout << "What do you want this system to process?" << endl << "1.Caesar Encryption" << endl << "2.Caesar Decryption" << endl << "3.Vignere Encryption" << endl << "4.Vignere Decryption" << endl << "5.XOR encyption" << endl << "6.XOR decryption" << endl << "7.Exit"<<endl;
		cout << "Enter the number corresponding to the function to perform it\t"<<endl;
		cin >> func;
		cout << endl;
		if (func == 1)
		{
			CaesarEncry c;
			c.Cencry();
			cout << endl;
		}
		else if (func == 2)
		{
			CaesarDecry d;
			d.Cdecry();
			cout << endl;
		}
		else if (func == 3)
		{
			VignereEncry v;
			v.Vencry();
			cout << endl;
		}

		else if (func == 4)
		{
			VignereDecry w;
			w.Vdecry();
			cout << endl;
		}

		else if (func == 5)
		{
			XORencry x;
			x.Encry();
			cout << endl;
		}

		else if (func == 6)
		{
			XORdecry y;
			y.Decry();
			cout << endl;
		}
		else if (func == 7)
		{
			exit = 1;
			cout << endl<<"Goodbye! ";
			break;
		}
		else
		{
			cout << "INVALID INPUT"<<endl;
		}
		cout << "Ok, now ";
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


