#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encrypt(FILE *inputfile,FILE *outputfile,char *key)
    {
        int keyindx=0;
        int keylength=strlen(key);
        int ch;
        while((ch=fgetc(inputfile))!=EOF)
        {
            fputc(ch^key[keyindx],outputfile);
            keyindx=(keyindx+1)%keylength;
        }
    }

int main()
{
    char inputfileName[256];
    char outputfileName[256];
    char key[16];
    printf("�����ļ�����");
    scanf("%s",inputfileName);
    printf("���ܺ���ļ���:");
    scanf("%s",outputfileName);
    printf("����");
    scanf("%s",key);
    FILE *inputfile=fopen(inputfileName,"rb");
    FILE *outputfile=fopen(outputfileName,"wb");
    if(inputfile==NULL||outputfile==NULL)
            return 1;
    encrypt(inputfile,outputfile,key);
    fclose(inputfile);
    fclose(outputfile);
    printf("���ܳɹ�!");
    return 0;
}
