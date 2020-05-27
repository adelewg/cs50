#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{


// first check to ensure that the user enters one command line argument. If this is not the case, an error message will be printed

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Now check that all the characters in the command line argument are decimal digits - iterate through each character in the string

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        string key = argv[1];

        if (isdigit(key[i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// convert the command line argument which is a string into an integer - which is the key that we are using in the encryption
    int encrypt_key = atoi(argv[1]);

// request user to input the text that they want to encrypt

    string plain_text = get_string("Plaintext: ");
    string cipher_text = plain_text;

//iterate over each character in the plaintext and cipher it with the key ensuring to preserve case and ignoring any character that is not a letter of the alphabet
    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
        {
            cipher_text[i] = (((plain_text[i] - 65) + encrypt_key) % 26) + 65;

        }

        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
        {
            cipher_text[i] = (((plain_text[i] - 97) + encrypt_key) % 26) + 97;
        }

        else
        {
            cipher_text[i] = plain_text[i];
        }

    }

    printf("ciphertext: %s\n", cipher_text);

}
