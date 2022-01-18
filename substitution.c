#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    int count = 0;
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26-alphabet key to reference plain text
    string str1 = argv[1];//converts argv to string
    string cipher = "";
    int count1;
    
     
            
      
   
      
    
    if (argc == 1 || argc > 2)//checks whether any characters are repeated
    {
        printf("Invalid Entry\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++) 
    {  
        count1 = 1;  
        for (int j = i + 1; j < strlen(argv[1]); j++) 
        {  
            if (argv[1][i] == argv[1][j] && argv[1][i] != ' ')//loop for checking repeated characters
            {  
                count1++;  
               
                argv[1][j] = '0';  
            }  
        }  
     
        if ((count1 > 1) && (argv[1][i] != '0'))  
        {
            printf("Invalid Key\n");
            return 1;
        }
    }
    for (int i = 0; i < strlen(argv[1]); i++)//checks if any non-alphanumeric characters are present in the key
    {
        if ((argv[1][i] < 'A' || argv[1][i] > 'Z') && (argv[1][i] < 'a' || argv[1][i] > 'z'))
        {
            printf("Invalid Key\n");
            return 1;
        }
    }

    for (int i = 0; argv[1][i] != '\0'; i++)//checks the number of characters in key
    {

      
        count++;

    }
    
    if (count != 26 && argc == 2)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else if (count == 26 && argc == 2)
    {

        string input = get_string("plaintext: ");//takes input
        int k = 0;
        for (int j = 0; j <= 25; j++)//changes each character to ciphered text
        {
        
            if ((input[k] == toupper(str[j])) || (input[k] == tolower(str[j])))
            {
                if (input[k] == toupper(str[j]))
                {
                    input[k] = toupper(str1[j]);
                }
                else
                {
                    input[k] = tolower(str1[j]); 
                }
             
                j = - 1;
                k++;
            }
       
        
            else if ((input[k] < 'A' || input[k] > 'Z') && (input[k] < 'a' || input[k] > 'z'))//checks for any special characters,spaces etc.
            {
                k++;
                continue;
            }
            else
            {
                continue;
            }
       
        }
        printf("ciphertext: %s\n", input);
    }



}
