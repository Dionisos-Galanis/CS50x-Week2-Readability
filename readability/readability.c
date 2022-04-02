#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Getting text
    string Text;
    Text = get_string("Text: ");

    // Analizing text
    int nLetters, nWords, nSentences;

    nLetters = count_letters(Text);
    nWords = count_words(Text);
    nSentences = count_sentences(Text);

    printf("nLetters = %d\nnWords = %d\nnSentences = %d\n", nLetters, nWords, nSentences);


    // Applying the Coleman-Liau index algorithm
    float L, S;

    L =  nLetters * 100.0 / nWords;
    S =  100.0 / nWords * nSentences;

    printf("L = %f\nS = %f\n", L, S);

    double GradeF = 0.0588 * L - 0.296 * S - 15.8;
    // Rounding and converting into int
    int Grade = (int) round(GradeF);

    // Printing the calculated grade
    if (Grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", Grade);
    }
}


// Counts letters (alfbetical) in the text
int count_letters(string text)
{
    int nLetters = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (isalpha(text[k])) // Checking if it is a letter
        {
            nLetters++;
        }
    }

    return nLetters;
}


// Counts words in the texts (uses space as the only valid delimiter!!!)
int count_words(string text)
{
    int nWords = 0;

    if (count_letters(text) != 0)
    {
        nWords = 1;
        for (int k = 0; k < strlen(text); k++)
        {
            if (isspace(text[k])) // Looking for spaces
            {
                nWords++;
            }
        }
    }

    return nWords;
}


// Counts sentences
int count_sentences(string text)
{
    int nSentences = 0;

    if (count_letters(text) != 0)
    {
        // nSentences = 1;
        for (int k = 0; k < strlen(text); k++)
        {
            if ((text[k] == '.') | (text[k] == '!') | (text[k] == '?')) // Looking for the ends of the sentences
            {
                nSentences++;
            }
        }
    }

    return nSentences;
}
