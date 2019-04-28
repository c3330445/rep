#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<stdlib.h>
#include<wchar.h>

void caesarCipher(char* m, int key);
void caesardecrypt(char* m, int key);
int find_index(char code[], char char_to_find);
char* encrypt(char *m, char code[]);
char* decrypt(char *m, char code[]);

int main()
{
	while (1)
	{
		int Option = 0;
		int Key = 0;
		char str[256];
		char code[26] = { 'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };

		printf("*********************************\n Please Input an Option:\n1-Encrypt Caesar Chiper\n2-Decrypt Caesar\n3Encrypt Substitution\n4 Decrypt Substitution\n0 - Exit Program\n");
		scanf("%d", &Option);
		if (Option == 0)
		{
			printf("Goodbye");
			break;
		}
		switch (Option)
		{
		case 1:// encrypt with Caesar cipher
			printf("I am on 1 : enter message to encrypt: ");
			scanf("%s", str);
			printf("enter key: ");
			scanf("%d", &Key);
			printf("The ciphered text is ");
			caesarCipher(str, Key);
			break;
		case 2:
			printf("I am on 2: enter message to decrypt: ");
			scanf("%s", str);
			printf("enter key: ");
			scanf("%d", &Key);
			printf("The ciphered text is ");
			caesardecrypt(str, Key);
			break;
		case 3:
			printf("I am on 3: message to encrypt: ");
			scanf("%s", str);
			char *encryptedmessage_ = encrypt(str, code);
			printf("Original message: %s\nEncrypted message: %s\n", str, encryptedmessage_);
			break;
		case 4:
			printf("I am on 4: message to decrypt: ");
			scanf("%s", str);
			char *encryptedmessage = encrypt(str, code);
			char *decryptedmessage = decrypt(str, code);
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
		caesarvalue = ((int)m[i] - 65 + key) % 26 + 65;
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
		caesarvalue = ((int)m[i] - 65 - key + 26) % 26 + 65;
		caesar = (char)(caesarvalue);
		printf("%c", caesar);
	}

}

int find_index(char code[], char char_to_find)
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
		int encryptionvalue = toupper(m[i]) - 'A';
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
		int decryptionindex = toupper(m[i]) - 'A';
		if (decryptionindex >= 0 && decryptionindex < 26)
		{
			int codeindex = find_index(code, toupper(m[i]));
			decryptedmessage[i] = 'A' + codeindex;
		}
	}
	return decryptedmessage;
}
