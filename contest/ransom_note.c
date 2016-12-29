#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct
{
    char* word;
    bool selected;
} magt;

int main()
{
    int m;
    int n;
    int magazine_i = 0;
    int ransom_i = 0;

    scanf("%d %d",&m,&n);

    if ((m < 0) || (n < 0) || (m > 30000) || (n > 30000))
        return 0;

    magt* magazine = malloc(sizeof(magt) * m);
    for(magazine_i = 0; magazine_i < m; magazine_i++){
        magazine[magazine_i].word = (char *)malloc(100 * sizeof(char));
        magazine[magazine_i].selected = false;
        scanf("%s",magazine[magazine_i].word);
        if (strlen(magazine[magazine_i].word) > 5)
            return 0;
    }

    char* *ransom = malloc(sizeof(char*) * n);
    for(ransom_i = 0; ransom_i < n; ransom_i++){
       ransom[ransom_i] = (char *)malloc(100 * sizeof(char));
       scanf("%s",ransom[ransom_i]);
       if (strlen(ransom[ransom_i]) > 5)
           return 0;
    }

    if (n > m)
    {
        printf("No");
        return 0;
    }

    int ri = 0;
    int mi = 0;

    //scan for ransom words
    for (ri = 0; ri < n; ri ++)
    {
        //Scan for magazine words
        for (mi = 0; mi < m; mi ++)
        {
            if ((strcmp(ransom[ri], magazine[mi].word) == 0) &&
                (strlen(ransom[ri]) == strlen(magazine[mi].word)) &&
                (magazine[mi].selected == false))
            {
                magazine[mi].selected = true;
                break;
            }
        }
        if (mi == m)
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");

    return 0;
}

