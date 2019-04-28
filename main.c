#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>
#include<wchar.h>

void caesarCipher(char* m, int key); //encrypt with Caesar cipher
void caesardecrypt(char* m, int key); //decryt with Caesar cipher
int find_index(char code[], char char_to_find); // find index for substitution cipher
char* encrypt(char *m, char code[]); // encrypt using substitution cipher
char* decrypt(char *m, char code[]); // decrypt using substitution cipher

int main()
{
	while (1)
	{
		int Option = 0;
		int Key = 0;
		char str[256];
		char code[26] = { 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' }; // for substitution cipher

		printf("*********************************\n Please Input an Option:\n1-Encrypt Caesar Chiper\n2-Decrypt Caesar\n3Encrypt Substitution\n4 Decrypt Substitution\n0 - Exit Program\n");
		scanf("%d", &Option); // user chooses option and int option is given a value
		if (Option == 0)
		{
			printf("Goodbye");
			break;
		}
		switch (Option)
		{
		case 1:// encrypt with Caesar cipher
			printf("I am on 1 : enter message to encrypt: ");
			scanf("%s" , str); // stores message in string
			printf("enter key: "); // user chooses how much the alphabet chifts by
			scanf("%d", &Key); 
			printf("The ciphered text is ");
			caesarCipher(str, Key); // function
			break;
		case 2: //decrypt with caesar cipher
			printf("I am on 2: enter message to decrypt: ");
			scanf("%s", str);
			printf("enter key: ");
			scanf("%d", &Key);
			printf("The ciphered text is ");
			caesardecrypt(str, Key); // function
			break;
		case 3: // encrypt with substitution cipher
			printf("I am on 3: message to encrypt: ");
			scanf("%s", str);
			char *encryptedmessage_ = encrypt(str, code);
			printf("Original message: %s\nEncrypted message: %s\n", str, encryptedmessage_);
			break;
		case 4: // decrypt with substitution cipher
			printf("I am on 4: message to decrypt: ");
			scanf("%s", str);
			char *encryptedmessage = encrypt(str, code);
			char *decryptedmessage = decrypt(str, code); // both functions needed
			printf("Decrypted message: %s\n", decryptedmessage);
		default:
			printf("Invalid Option. \n");
			break;
		}

	}

}

void caesarCipher(char* m, int key)
{
	int i = 0;
	
	int caesarvalue;
	char caesar;
	for (i = 0; i < strlen(m); i++)
	{
		caesarvalue = ((int)m[i] - 65 + key) % 26 + 65; // implementation of algorithm
		caesar = (char)(caesarvalue);
		printf("%c", caesar);
	}
}

void caesardecrypt(char* m, int key)
{
	int i = 0;
	int ch;
	int caesarvalue;
	char caesar;

	for (i = 0; i < strlen(m); i++)
	{
		caesarvalue = ((int)m[i] - 65 - key + 26) % 26 + 65; // implementation of algorithm
		caesar = (char)(caesarvalue);
		printf("%c", caesar);
	}

}

int find_index(char code[], char char_to_find) // function to find  value of code (used for substitution cipher)
{
	for (int i = 0; i < 26; i++)
	{
		if (code[i] == char_to_find)
		{
			return i;
		}
	}
	return -1;
}



char* encrypt(char *m, char code[])
{
	char *encryptedmessage = (char *)malloc(sizeof(char)*strlen(m));

	for (int i = 0; i < strlen(m); i++)
	{
		int encryptionvalue = toupper(m[i]) - 'A'; // encrypts messages in capital letters
		if (encryptionvalue >= 0 && encryptionvalue < 26)
		{
			encryptedmessage[i] = code[encryptionvalue];
		}
		else
		{
			encryptedmessage[i] = m[i];
		}
	}
	return encryptedmessage;
}

char *decrypt(char *m, char code[])
{	
	char *decryptedmessage = (char*)malloc(sizeof(char)*strlen(m));

	for (int i = 0; i <= strlen(m); i++)
	{
		int decryptionindex = toupper(m[i]) - 'A'; // decrypts in capital letters
		if (decryptionindex >= 0 && decryptionindex < 26)
		{
			int codeindex = find_index(code, toupper(m[i]));
			decryptedmessage[i] = 'A' + codeindex;
		}
	}
	return decryptedmessage;
}
