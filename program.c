
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// isVowel returns 1 if the character is a vowel
// otherwise it returns 0
int isVowel(char);
void hyphenate(char [], char []);

int main()
{
    //word variable is the variable for the user input
    //wordHyp is hyphenated version of word
    char word [50] = "", wordHyp [100] = "";
    printf("Enter a word for hyphenation:\n");
    scanf("%s", word);
	hyphenate(word, wordHyp);
    printf("%s\n", wordHyp);
    return 0;
}

int isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}

void hyphenate(char word [], char wordHyp[])
{
    int vowelcount = 0; //sesli harf sayisini saklamak icin kullaniliyor.

    for (int i = 0; i != strlen(word); i++) // sesli harfi saydirma islemi
    {
        if (isVowel(word[i]))
        {  
            vowelcount++;
        }
    }

    int index=0; // worldHype atama islemi icin indis
    int count=1; // ayni yere hata olmasini önlemek amaciyla belirlenen degisken

    for (int i = 0; i != strlen(word); i++) //yeni chara her sesli harften sonra '-' atama islemi
    {
        wordHyp[index] = word[i];
        if (isVowel(word[i])&&(count<vowelcount)) //hece sayisindan bir eksik olacak kadar '-' atama kosulu
        {
            wordHyp[index+1] ='-';
            index++;
            count++;
        }
        index++;
    }
    if ((vowelcount == 2) &&(isVowel(wordHyp[0]) == 1) && (strlen(wordHyp)-1 ==5)) 
    //2 heceli sesliyle baslayan ve 5 karakter uzunlugunda olan kelimeler icin
    {
        for (int i = strlen(wordHyp); i > 0 ; i--) //dongyule ileri doğru kaydırma işlemi
        //bir kere yapilmasini saglamak amaciyla dongu, dizinin sonundan basina dogrudur.
        {
            if (wordHyp[i]=='-')
            {
                char a = wordHyp[i]; //kaydirma icin tutulan yedek degiskeni
                wordHyp[i]= wordHyp[i+1];
                wordHyp[i+1]=a; 
            }
        }
    }

    if (vowelcount == 2 && ((strlen(wordHyp) - 1)>4) && (!isVowel(wordHyp[0])) && ((strlen(wordHyp) - 1)<7)&&(isVowel(wordHyp[strlen(wordHyp)-1])==1)) 
    //2 heceli ve 4-7 karakter uzunlugunda olan ve sesli harfle baslamayan kelimeler icin
    {
        for (int i = strlen(wordHyp); i > 0 ; i--) //dongyule ileri doğru kaydırma işlemi
        //bir kere yapilmasini saglamak amaciyla dongu, dizinin sonundan basina dogrudur.
        {
            if (wordHyp[i]=='-')
            {
                char a = wordHyp[i]; //kaydirma icin tutulan yedek degiskeni
                wordHyp[i]= wordHyp[i+1];
                wordHyp[i+1]=a; 
            }
        }
    }

    else if (vowelcount != 1 && !(vowelcount == 2 && strlen(wordHyp)-1 == 5)) // 1 hece ve 2 hece 4 harf harici calissin
    {
        int notvowel = 0; //sirali unsuz serisi

        for (int i = 0; i < strlen(wordHyp); i++)
        {
            if (isVowel(wordHyp[i]) || (wordHyp[i] == '-')) //sirali unsuz bozuldukca sifirlanan seri
            {
                notvowel = 0;
            }
            if ((!isVowel(wordHyp[i]) && (wordHyp[i] != '-'))) // '-' konumu duzeltme islemi
            {  
                notvowel++;
                if (notvowel == 2&&(isVowel(wordHyp[i+1]))) //2 unsuz arka arkaya gelirse yapilacak yer degistirme
                {  
                    char c; //yer degistirme icin tutulan temp degiskeni
                    c=wordHyp[i-2]; //tekli kaydırma
                    wordHyp[i-2]= wordHyp[i-1];
                    wordHyp[i-1]=c;
                }
                else if (notvowel == 3) //3 unsuz arka arkaya gelirse yapilacak islem.
                {   
                    char c; //yer degistirme icin tutulan temp degiskeni
                    c = wordHyp[i-3]; //2li kaydırma
                    wordHyp[i-3]=wordHyp[i-2];
                    wordHyp[i-2]=wordHyp[i-1];
                    wordHyp[i-1]=c;
                } 
            }
        }
    }  
}
