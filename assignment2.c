#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[25];
    int age;
} User;

void createData()
{
    FILE *fp = fopen("user.txt", "a+");
    if (fp == NULL)
    {
        puts("Error opening file.\n");
        return;
    }
    User user;

    int checkId = 0;
    while (!checkId)
    {
        checkId = 1;
        printf("\nEnter user ID: ");

        if (scanf("%d", &user.id) != 1 || user.age <= 0)
        {
            printf("Invalid input. Please enter a valid integer ID.\n");
            while (getchar() != '\n');
            checkId = 0;
            continue;
        }

        rewind(fp);
        User tempUser;
        while (fscanf(fp, "%d\t%29[^\t]\t%d\n", &tempUser.id, tempUser.name, &tempUser.age) != EOF)
        {
            if (tempUser.id == user.id)
            {
                checkId = 0;
                printf("Error: ID %d already exists. Please enter a unique ID.\n", user.id);
                break;
            }
        }
    }

    printf("Enter user name: ");
    scanf(" %[^\n]s", user.name);

    while (1)
    {
        printf("Enter user age: ");
        if (scanf("%d", &user.age) != 1 || user.age <= 0)
        {
            printf("Invalid input. Age must be a positive number.\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }

    fprintf(fp, "%d\t%s\t%d\n", user.id, user.name, user.age);
    printf("\nUser added successfully\n");

    fclose(fp);
}

void readData()
{

    FILE *fp = fopen("user.txt", "r");
    if (fp == NULL)
    {
        puts("Error opening file.\n");
        return;
    }

    printf("\n%s\t%s\t\t%s\n", "ID", "Name", "Age");
    printf("--------------------------------------\n");
    User user;
    while (fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        printf("%d\t%s\t\t%d", user.id, user.name, user.age);
        printf("\n");
    }
    printf("\n");
    fclose(fp);
}

void updateData()
{
    int Id;
    int flag = 0;
    FILE *tempf = fopen("temp.txt", "w");
    FILE *fp = fopen("user.txt", "r");
    if (tempf == NULL || fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter user id: ");
    scanf("%d", &Id);
    User user;
    while (fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == Id)
        {
            flag = 1;
            int checkId = 0;
            while (!checkId)
            {
                checkId = 1;
                printf("\nEnter user ID: ");
                scanf("%d", &user.id);

                FILE *fpTemp = fopen("user.txt", "r");
                User tempUser;
                while (fscanf(fpTemp, "%d\t%29[^\t]\t%d\n", &tempUser.id, tempUser.name, &tempUser.age) != EOF)
                {
                    if (tempUser.id == user.id)
                    {
                        checkId = 0;
                        printf("Error: ID %d already exists. Please enter a unique ID.\n", user.id);
                        break;
                    }
                }
                fclose(fpTemp);
            }
            printf("Enter updated name: ");
            scanf(" %[^\n]s", user.name);
            while (1)
            {
                printf("Enter updated age: ");
                if (scanf("%d", &user.age) != 1 || user.age <= 0)
                {
                    printf("Invalid input. Age must be a positive number.\n");
                    while (getchar() != '\n'); 
                }
                else
                {
                    break;
                }
            }
        }
        fprintf(tempf, "%d\t%s\t%d\n", user.id, user.name, user.age);
    }
    fclose(fp);
    fclose(tempf);
    if (flag)
    {
        remove("user.txt");
        rename("temp.txt", "user.txt");
        printf("User Details are Updated.\n");
    }
    else
    {
        printf("User with %d ID does not exist.\n", Id);
        remove("temp.txt");
    }
    printf("\n");
}

void deleteData()
{
    int Id;
    int flag = 0;
    FILE *tempf = fopen("temp.txt", "w");
    FILE *fp = fopen("user.txt", "r");
    if (tempf == NULL || fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter user id you want to delete: ");
    scanf("%d", &Id);
    User user;
    while (fscanf(fp, "%d\t%29[^\t]\t%d\n", &user.id, user.name, &user.age) != EOF)
    {
        if (user.id == Id)
        {
            flag = 1;
        }
        else
        {
            fprintf(tempf, "%d\t%s\t%d\n", user.id, user.name, user.age);
        }
    }
    fclose(fp);
    fclose(tempf);
    if (flag)
    {
        remove("user.txt");
        rename("temp.txt", "user.txt");
        printf("User is deleted.\n");
    }
    else
    {
        printf("User with %d ID does not exist.\n", Id);
        remove("temp.txt");
    }
    printf("\n");
}

int main()
{

    int choice;
    while (1)
    {

        printf("1.Add a new user.\n");
        printf("2.Display the Data of all Users.\n");
        printf("3.Update Data of User.\n");
        printf("4.Remove a user by their ID.\n");
        printf("5.Exit\n");

        printf("Choose operation to perform: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a valid integer.\n\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice)
        {
        case 1:
            createData();
            break;
        case 2:
            readData();
            break;
        case 3:
            updateData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}