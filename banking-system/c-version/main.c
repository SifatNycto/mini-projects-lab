#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <unistd.h>


//First account id
int account_no=1101;

//Structures

typedef struct
{
    char filename[100];
    char username[100];
    int pin;
    float balance;
} user_account;
user_account user;

//=============================================
// All the functions is being used are below
void loading_dots()
{    // This loop prints 3 dots "..." each second and then loop ends
    for (int i=0;i<3;i++)
    {
        printf(".");
        sleep(1);
    }
}
void head_title()
{
    printf("========== MINI_BANKING_SYSTEM ==========\n\n");
}
void login_page()
{
    printf("1.Log in\n2.Sign up\n3.Exit system\n");
}
void main_menu()
{
    printf("1.Check Balance\n2.Deposit Amount\n3.Withdraw Amount\n4.log out\n");
}

// saving login information in a json file
void login_info_save()
{
    sprintf(user.filename,"account_no_%d.json",account_no);
    FILE *file2p = fopen(user.filename, "w");   // Creating a json file for each separate accounts signed in
    if (file2p == NULL)
    {
        perror("Error Creating File!\n");
        return;
    }
    fprintf(file2p,"{\"username\": \"%s\", \"pin\": %d, \"balance\": %f}",user.username,user.pin,user.balance);
    fclose(file2p);
}
   
void overwrite_id()
{
    FILE *filep = fopen("account_no_data.json", "w");
    if (filep == NULL)
    {
        perror("Error opening file\n");
        return;
    }
    fprintf(filep,"{\"account_no\": %d}",account_no);
    fclose(filep);
}

void load_account_id()
{
    FILE *filep = fopen("account_no_data.json", "r");
    if (filep == NULL)
    {
        perror("Error opening file\n");
        return;
    }
    char buffer[200];
    while(fgets(buffer,sizeof(buffer),filep))
    {
        if (sscanf(buffer,"{\"account_no\": %d}",&account_no)==1) break;
    }
    fclose(filep);
}
void press_any_key() {
    getchar(); getchar();
}

//=================================================================================
// Main Progam begins here

int main() {
    // Creating a json file, which is to store the of account id has been used
    FILE *filep = fopen("account_no_data.json", "a");
    if (filep == NULL)
    {
        perror("Error opening file\n");
        return 1;
    }
    fclose(filep);

    // Main Homepage
    while(1)
    {
        int login_option;
        system("cls");
        head_title();
        login_page();
        printf("\nEnter the option: ");
        scanf("%d",&login_option);
        
        if(login_option==1)
        {   // 1.Log in - To login account already created option
            system("cls");
            head_title();
            int account_no_temp;
            int user_pin_temp;

            printf("Enter your account no: ");  // Enter account number
            scanf("%d", &account_no_temp);

            sprintf(user.filename,"account_no_%d.json",account_no_temp);  // This is to check if account exist or was created of this id or not
            FILE *file2p = fopen(user.filename, "r");
            if (file2p == NULL)
            {
                printf("Account id not found! Please sign up\n");
                loading_dots();
                continue;
            }
            char buffer2[200];
            while(fgets(buffer2,sizeof(buffer2),file2p))
            {
                if (sscanf(buffer2,"{\"username\": \"%[^\"]\", \"pin\": %d, \"balance\": %f}",&user.username,&user.pin,&user.balance)==1) break;
            }
            fclose(file2p);
            
            //**This supposed to be password but couldn't add due to me delaying
            printf("Enter your pin: "); // Pin of your account number
            scanf("%d", &user_pin_temp);

            if (user_pin_temp==user.pin)
            {
                loading_dots();
                while(1) {
                    system("cls");
                    head_title();
                    main_menu();
                    int select_option;
                    printf("\nEnter the option: ");
                    scanf("%d",&select_option);
                    
                    if (select_option==1)
                    {  // Check balance option
                        system("cls");
                        head_title();
                        printf("Your account no: %d\n",account_no_temp);
                        printf("Your username: %s\n",user.username);
                        printf("Your Current Balance: %.2f\n",user.balance);
                        printf("\nPress any key to return...");
                        press_any_key();

                    }
                    else if (select_option==2)
                    {  // Deposit option
                        system("cls");
                        head_title();
                        float user_current_balance=user.balance,deposit_amount;
                        printf("Enter the amount to deposit: $");
                        scanf("%f",&deposit_amount);
                        float total_amount=user_current_balance+deposit_amount;   //Adddition
                        user.balance=total_amount;  //Assigining to the struct variable

                        sprintf(user.filename,"account_no_%d.json",account_no_temp);
                        FILE *file2p = fopen(user.filename, "w");   // Overwriting deposit amount
                        if (file2p == NULL)
                        {
                            perror("Error Creating File!\n");
                            return 1;
                        }
                        fprintf(file2p,"{\"username\": \"%s\", \"pin\": %d, \"balance\": %f}",user.username,user.pin,user.balance);
                        fclose(file2p);
                    
                        loading_dots();
                        printf("\nDeposited Successfully!.");
                        printf("\nPress any key to return...");
                        press_any_key();
                        
                        
                    }
                    else if (select_option==3)
                    {
                        system("cls");
                        head_title();
                        float user_current_balance=user.balance,withdraw_amount;
                        printf("Enter the amount to deposit: $");
                        scanf("%f",&withdraw_amount);
                        float total_amount=user_current_balance-withdraw_amount;
                        user.balance=total_amount;

                        sprintf(user.filename,"account_no_%d.json",account_no_temp);
                        FILE *file2p = fopen(user.filename, "w");   // Overwriting Withdrawn ammount
                        if (file2p == NULL) {
                            perror("Error Creating File!\n");
                            return 1;
                        }
                        fprintf(file2p,"{\"username\": \"%s\", \"pin\": %d, \"balance\": %f}",user.username,user.pin,user.balance);
                        fclose(file2p);
                    
                        loading_dots();
                        printf("\nWithdrawn Successfully!.");
                        printf("\nPress any key to return...");
                        press_any_key();
                        
                    }
                    else if (select_option==4)
                    {
                        system("cls");
                        head_title();
                        printf("wait a minute");
                        loading_dots();
                        printf("\nYou Logged out Successfully.");
                        break;
                    }
                    else
                    {
                        system("cls");
                        head_title();
                        printf("Invalid input! Please enter any from (1,2,3,4).\n");
                        press_any_key();                        
                    }
                }
            }
            else
            {
                printf("Incorrect pin!");
                press_any_key();
            }
        }
        else if(login_option==2)
        {   // 2.Sign up - To create a new account option
            system("cls");
            head_title();
            load_account_id();
            printf("==Create a new account==\n");
            printf("Enter username: ");
            scanf(" %s", &user.username);
            printf("Enter pin: ");
            scanf(" %d", &user.pin);
            printf("Deposit at least $50 to activate the account.\nDeposit amount: $");
            scanf(" %f", &user.balance);
            
            if (user.balance>=50)
            {
                login_info_save();
                system("cls");
                head_title();
                printf("Your Account Created Successfully!\n");
                printf("Your account no: %d\n",account_no);
                printf("Your username: %s\n",user.username);
                printf("\nPress any key to return...");
                press_any_key();
                account_no++;
                overwrite_id();
            }
            else
            {
                printf("Insufficient amount! Please at least 50 needed.");
                press_any_key();
            }
        }
        else if(login_option==3)
        {
            system("cls");
            head_title();
            printf("Progam Exiting");
            loading_dots();
            printf("\nThank you for using our Bank system.");
            press_any_key();                      
            break;
        }
        else
        {
            system("cls");
            head_title();
            printf("Invalid input! Please enter between 1 or 2.\n");
            press_any_key();                      
        }
    }
    return 0;
}
