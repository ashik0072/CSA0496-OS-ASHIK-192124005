#include<stdio.h>
int main()
{
char ch;
FILE *fp1,*fp2;
fp1=fopen("hi.txt","r");
fp2=fopen("hello.txt","w");
ch=fgetc(fp1);
while(ch!=EOF)
{
fputc(ch,fp2);
ch=fgetc(fp1);
}
fclose(fp2);
fclose(fp1);
return 0;
}
