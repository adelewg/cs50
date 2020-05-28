#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])

{
    //check to ensure that a key was provided in the command line argument. If it was than argc should be 2
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    //check to see that the key is valid - ie contains 26 chars, all chars are alphabetical and none of the chars appears more than once

    if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }


    //iterate through each character in the key and check that each character is an alphabetical character
    string key = argv[1];
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }

    //check that the key does not contain any repeated characters by comparing the string to itself in a nested for loop

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i != j)
            {
                if (tolower(key[i]) == tolower(key[j]))
                {
                    printf("the key must not contain repeated characters\n");
                    return 1;
                }
            }
            else
            {
                continue;
            }

        }
    }

    //now that everything is good ask the user to provide the plaintext to be ciphered
    string plain_text = get_string("Plaintext: ");

    //create a copy of the string that the user provided - this ensures that you create a string of the same length. This is the cipher string that will be changed character by character
    string cipher_text = plain_text;

    //iterate throught each character in the user provided string and substitute each alphabetical character according to the key that was provided in the command line argument
    for (int i = 0; i < strlen(plain_text); i++)
    {
        if (isalpha(plain_text[i]) && islower(plain_text[i]))
        {

            cipher_text[i] = tolower(key[plain_text[i] - 97]);
        }
        else if (isalpha(plain_text[i]) && isupper(plain_text[i]))
        {
            cipher_text[i] = toupper(key[plain_text[i] - 65]);
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }

    printf("ciphertext: %s\n", cipher_text);


}
