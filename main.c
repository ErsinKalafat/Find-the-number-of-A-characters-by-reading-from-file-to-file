#include <stdio.h>
#include <stdlib.h>

void terminale_oku()
{
    FILE *dosya;
    char c;
    int i=0;

    if ((dosya = fopen("ornek.txt","r"))==NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }


    while((c=fgetc(dosya)) != EOF)
    {
        printf("%c",c);

        if (c==' ')
            printf("\n");
        if (c=='a')
            i++;

    }
    printf("\n\n %d",i);

    fclose(dosya);
}

void dosyadan_dosyaya_oku()
{
    FILE *dosya, *dosya2;
    char c;
    int i=0;

    if ((dosya = fopen("ornek.txt","r"))==NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }

    if ((dosya2 = fopen("sonuc.txt","w"))==NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }

    while((c=fgetc(dosya)) != EOF)
    {
        fprintf(dosya2, "%c",c);
        if (c=='a')
            i++;
        if (c==' ')
        {
            fprintf(dosya2,"\n");
            fprintf(dosya2,"%d adet \"a\" harfi var.\n\n ",i);
            i=0;
        }

    }

    fclose(dosya2);
}

int main()
{
    terminale_oku();
    dosyadan_dosyaya_oku();
    return 0;
}
