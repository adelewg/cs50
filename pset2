#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*The purpose of this program is to compute the approximate US Grade level required to comprehend some text that is input by the user, using the
Coleman-Liau index which is a simple formula computed from the number of letters, words and sentences: index = 0.0588 * L - 0.296 * S - 15.8
Grades fall between 1 and 16+
L is the average number of letters per 100 words
S is the average number of sentences per 100 words in the text
*/

int main(void)
{
    string text = get_string("Text: ");

    int length = strlen(text);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    //Here we count the number of letters in the text by going through each character to check if it is either a lower case letter or an upper case letter
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

    }

    /*Here we count the number of words - the word count starts of at 1 and not zero this is because the logic here always gives one less word. The program
    checks for a letter or the following chars that normally are found in text (? ! " , ' .) each time one of these is followed by a space that counts as a word*/

    for (int i = 0; i < length; i++)
    {
        if ((isalpha(text[i]) || text[i] == 33 || text[i] == 34 || text[i] == 39 || text[i] == 46 || text[i] == 63 || text[i] == 44)
            && isspace(text[i + 1]))
        {
            words++;
        }

    }

    /* Here we are counting the number of sentences in the text. A sentence ends with either a full-stop, question mark or exclamation point*/

    for (int i = 0; i < length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences ++;
        }
    }

    /* In the C programming language if you divide and int by an int the result will also be an int ie it will be truncated and you will lose the decimal part
    thus rendering it inaccurate hence below the integers are type cast into floats so that the ans is a float. Probably its not necessary to type case all to
    floats?*/

    float l = (float)letters * 100 / (float)words;
    float s = (float)sentences * 100 / (float)words;

    int index = round(0.0588 * l - 0.296 * s - 15.8);
    double test = 0.0588 * l - 0.296 * s - 15.8;

    /* depending on the value of index print the grade level - grade 1 is an index of 1 or less and grade 16+ is an index of 16 and above */

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }

    else
    {
        printf("Grade 16+\n");
    }

    /*
    printf("Letters: %i Words: %i Sentences: %i\n Index: %i \n Test: %f\n" , letters, words, sentences, index, test);*/

}



