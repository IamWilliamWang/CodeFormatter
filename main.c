#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileutil.h"
#include "characterutil.h"
#define space ' '

/**
 * @brief SetNewLineAndSpaces 换行并输出空格
 * @param spaceCounter 目前要输出几个空格
 */
void SetNewLineAndSpaces(int spaceCounter)
{
    SetCharacter('\n');
    int i;
    for(i=0;i<spaceCounter;i++)
    {
        SetCharacter(space);
        SetCharacter(space);
        SetCharacter(space);
        SetCharacter(space);
    }
}

void ProvideHelp()
{
    puts("本程序可以输入三个参数（空格隔开），后两个参数可省略：");
    puts("参数1.要转换的文件名。如果只提供此参数，转换后将会覆盖原文件");
    puts("参数2.转换后的文件名");
    puts("参数3.排版代码方式。名称如下");
    puts("  1)Allman(默认)");
    puts("  2)KR");
    puts("详情见 https://en.wikipedia.org/wiki/Indent_style");
}

int main(int argn,char* args[])
{
    char inputFileName[50],outputFileName[50];
    bool defaultCodingMode=true;
    switch (argn)
    {
    case 1:
        ProvideHelp();
        exit(0);
    case 2:
        strcpy(inputFileName,args[1]);
        strcpy(outputFileName,args[1]);
        break;
    case 3:
        strcpy(inputFileName,args[1]);
        strcpy(outputFileName,args[2]);
        break;
    case 4:
        strcpy(inputFileName,args[1]);
        strcpy(outputFileName,args[2]);
        if(!strcmp(args[3],"KR"))
            defaultCodingMode=false;
        break;
    default:
        exit(0);
    }

    char ch;
    int spaceCounter=0;
    bool ignoreSpace=true;
    input=ReadAllText(inputFileName);
    while((ch=GetCharacter())!='\0')
    {
        switch(ch)
        {
        case '\n':
            ignoreSpace=true;
            break;
        case ' ':
            if(ignoreSpace==false)
                SetCharacter(' ');
            break;
        case '>':
            SetCharacter('>');
            SetNewLineAndSpaces(spaceCounter);
            ignoreSpace=true;
            break;
        case '{':
            SetCharacter('{');
            spaceCounter++;
            SetNewLineAndSpaces(spaceCounter);
            ignoreSpace=true;
            break;
        case '}':
            spaceCounter--;
            SetNewLineAndSpaces(spaceCounter);
            ignoreSpace=true;
            SetCharacter('}');
            SetNewLineAndSpaces(spaceCounter);
            break;
        case ')':
            SetCharacter(')');
            if(input[inputIndex]!=';')
            {
                if(defaultCodingMode)
                    SetNewLineAndSpaces(spaceCounter);
                else
                    SetCharacter(' ');
                ignoreSpace=true;
            }
            break;
        case ';':
            SetCharacter(';');
            SetNewLineAndSpaces(spaceCounter);
            ignoreSpace=true;
            break;
        default:
            ignoreSpace=false;
            SetCharacter(ch);
            break;
        }
    }
    output[outputIndex]='\0';
    printf("----以下是转换结果----\n");
    printf("%s",output);
    WriteAllText(outputFileName,output);
    printf("\n----以上是转换结果----\n文件保存成功");
    return 0;
}

