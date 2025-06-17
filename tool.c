#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// function using 
void encryptFile(const char *input_fileName, const char *output_fileName, const char *pass);
void decryptFile(const char *input_fileName, const char *output_fileName, const char *pass);
int validateFile(const char *fileName);

int main()
{
    int choice, algo;
    char input_file[100], output_file[100], pass[50];

    printf("\n=========================================\n");
    printf("  File Encryption and Decryption Tool\n");
    printf("=========================================\n\n");

    printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n");
    printf("PRESS :- \n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n\n");
    printf("Enter your choice : \n");
    scanf("%d", &choice);

    // handling error - for invalid choice by user.
    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice! Exiting...\n");
        return 1;
    }

    printf("Enter the name of the input file: \n");
    scanf("%s", input_file);

    // validatefile function main jakr check krega ki file exist kr rhi hai ki nahi jiska naam provide kiya hai
    if (!validateFile(input_file))
    {
        printf("Error: File not found or inaccessible.\n");
        return 1;
    }

    printf("Enter the name of the output file: \n");
    scanf("%s", output_file);

    printf("Enter a password for encryption/decryption (key) : \n");
    scanf("%s", pass);
    printf("\nx-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n\n");


    switch (choice)
    {
    case 1:
        encryptFile(input_file, output_file, pass);
        break;
    case 2:
        decryptFile(input_file, output_file, pass);
        break;
    }

    return 0;
}

//function for Encryption 
void encryptFile(const char *input_fileName, const char *output_fileName, const char *pass)
{
    //opening files in reading and writing mode
    FILE *input_file = fopen(input_fileName, "r");
    FILE *output_file = fopen(output_fileName, "w");
    
    //checking file exist or not.
    if (!input_file || !output_file)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    char ch;
    int key = 0;

    // Generate a key based on the pass - by summing all the values provided in pass
    for (int i = 0; pass[i] != '\0'; i++)
    {
        key += pass[i];
    }

    // printf("Encrypting using %s...\n", (algo == XOR_ALGO) ? "XOR Encryption" : "Caesar Cipher");
    printf("Encrypting.......\n");

    while ((ch = fgetc(input_file)) != EOF)
        {
            printf("$%d? ",ch);
            //performing XOR operation with each character of the file
            fputc(ch ^ key, output_file);
            Sleep(10);
        }

    Sleep(2000); // Pause for 2000 milliseconds (2 seconds) in (window.h)

    printf("\n\nFile encrypted successfully and saved to %s\n", output_fileName);

    fclose(input_file);
    fclose(output_file);
}

//funtion for Decryption
void decryptFile(const char *input_fileName, const char *output_fileName, const char *pass)
{
    FILE *input_file = fopen(input_fileName, "r");
    FILE *output_file = fopen(output_fileName, "w");

    if (!input_file || !output_file)
    {
        printf("Error: Unable to open file.\n");
        return;
    }

    char ch;
    int key = 0;

    // Generate a key based on the pass
    for (int i = 0; pass[i] != '\0'; i++)
    {
        key += pass[i];
    }

    // printf("Decrypting using %s...\n", (algo == XOR_ALGO) ? "XOR Encryption" : "Caesar Cipher");
    printf("Decrypting.......\n");
    while ((ch = fgetc(input_file)) != EOF)
    {
        printf(" $%d? ",ch);
        //performing XOR operation with each character of the file
        fputc(ch ^ key, output_file);
        Sleep(10);
    }

    Sleep(2000); // Pause for 2000 milliseconds (2 seconds) in (window.h)

    printf("\nFile decrypted successfully and saved to %s\n", output_fileName);

    fclose(input_file);
    fclose(output_file);
}

//funtion for validating file 
int validateFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    return 0;
}
