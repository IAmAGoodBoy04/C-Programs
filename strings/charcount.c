#include <stdio.h>

int main()

{
    int vowels = 0, words = 1, consonants = 0, characters = 0;
    char str[9999];
    printf("Enter the sentence:\n");
    gets(str);
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] == 32){words++;}
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122){
            if (str[i] == 97 || str[i] == 101 || str[i] == 105 || str[i] == 111 || str[i] == 117 || str[i] == 65 || str[i] == 69 || str[i] == 73 || str[i] == 79 || str[i] == 85)
            {  vowels++;}
            else
            {consonants++;}
        }
        if (str[i] > 32 && str[i] <= 47 || str[i] >= 58 && str[i] <= 64 || str[i] >= 91 && str[i] <= 96 || str[i] >= 123 && str[i] <= 126)
        {characters++;}
    }
    printf("Number of vowels : %d\nNumber of words : %d\nNumber of consonants : %d\nNumber of special characters : %d\n", vowels, words, consonants, characters);
    return 0;
}