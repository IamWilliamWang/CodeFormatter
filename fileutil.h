#ifndef FILEUTIL
#define FILEUTIL

#include <stdbool.h>
/**
 * @brief ReadAllText 读取文件内所有的文字
 * @param fileName 文件名称
 * @return 成功为文件的内容，失败为NULL
 */
char* ReadAllText(char* fileName)
{
    static char content[1500];
    FILE *readerFilePointer = fopen(fileName,"r");
    if(readerFilePointer==NULL)
    {
        return NULL;
    }
    int contentIndex=0;
    while(!feof(readerFilePointer))
    {
        content[contentIndex++] = (char)fgetc(readerFilePointer);
    }
    //content[contentIndex]='\0';
    fclose(readerFilePointer);
    return content;
}

/**
 * @brief WriteAllText 把content全部写入文件中
 * @param fileName 文件名
 * @param content 要写入的内容内容
 * @return 成功为true，失败为false
 */
bool WriteAllText(char* fileName,char content[])
{
    FILE *writeFilePointer = fopen(fileName,"w");
    if(writeFilePointer==NULL)
    {
        return false;
    }

    int contentIndex=0;
    while(content[contentIndex]!='\0')
    {
        fputc(content[contentIndex++],writeFilePointer);
    }

    fclose(writeFilePointer);
    return true;
}

#endif // FILEUTIL

