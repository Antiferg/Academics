#include<stdio.h>
#include<stdlib.h>

int main()
{
FILE* reader;

reader= fopen("Database.xlsx", "a+");
if(reader == NULL) 
{
    printf("The file is not opened. The program will now exit.");
    exit(0);
}

while(!feof(reader))
{
    
}

}