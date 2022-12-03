#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

int countWords(char str[]){
    int count=1;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ' && str[i+1] != ' ' && str[i+1]!= '-' && str[i+1]!= '&'){
            count++;
        }    
    }
    
    if (isalnum(str[0])){}
    else{
        count = 0;
    }

    printf("Num words: %d\n", count);
    return count;
}

int countSent(char str[]){
    int count=0;
    for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] == '.' || str[i] == '!' || str[i] == '?')  && (str[i+1] != '.' || str[i+1] != '!' || str[i+1] != '?')){
            count++;
        }
    }

    printf("Num sent: %d\n", count);
    return count;
}

int countSyl(char str[]){
    int count = 0, diff = 0;
    int i=0, j=0;
    for (i = 0; str[i] != '\0'; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
            count++;
            j=i+1;
            while (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' || str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U'){
                j++;
            }
            diff=j-i-1;
        }
        i += diff; 
        diff = 0;   
    }
    printf("Num syll: %d\n", count);
    return count;
}

float fkgrade(char str[]){
    float numWords = (float) countWords(str);
    float numSent = (float) countSent(str);
    float numSyl = (float) countSyl(str);
    if (numSent == 0 || numWords == 0){
        return -1; 
    }
    else{
        float grade = 0.39*(numWords/numSent) + 11.8*(numSyl/numWords) - 15.59;
        return grade;
    }
};

int main() {
    char plato[] = "He who is the real tyrant, whatever men may think, is the real slave, and is obliged to practise the greatest adulation and servility, and to be the flatterer of the vilest of mankind.  He has desires which he is utterly unable to satisfy, and has more wants than any one, and is truly poor, if you know how to inspect the whole soul of him: all his life long he is beset with fear and is full of convulsions and distractions, even as the State which he resembles: and surely the resemblance holds?";

    char aurelius[] = "Nothing pertains to human beings except what defines us as human.  No other things can be demanded of us.  They aren't proper to human nature, nor is it incomplete without them.  It follows that they are not our goal, or what helps us reach it -- the good.  If any of them were proper to us, it would be improper to disdain or resist it.  If the things themselves were good, it could hardly be good to give them up.  But in reality, the more we deny ourselves such things (and things like them) -- or are deprived of them involuntarily, even -- the better we become.";

    char descartes[] = "I suppose, accordingly, that all the things which I see are false (fictitious); I believe that none of those objects which my fallacious memory represents ever existed; I suppose that I possess no senses; I believe that body, figure, extension, motion, and place are merely fictions of my mind.  What is there, then, that can be esteemed true?  Perhaps this only, that there is absolutely nothing certain.";
    
    char test[] = "";
    
    printf("Plato...\nexpected sentences = 2\n expected words = 94\n  expected syllables = 135\n");
    float out = fkgrade(plato);
    printf("> Reading Level = %f\n", out);
    printf("Marcus Aurelius...\n  expected sentences = 7\n   expected words = 104\n    expected syllables = 151\n");
    out = fkgrade(aurelius);
    printf("> Reading Level = %f\n", out);
    printf("Rene Descartes...\n  expected sentences = 3\n   expected words = 67\n    expected syllables = 111\n");
    out = fkgrade(descartes);
    printf("> Reading Level = %f\n", out);
    printf("Empty\n");
    out = fkgrade(test);
    printf("> Reading Level = %f\n", out);
}