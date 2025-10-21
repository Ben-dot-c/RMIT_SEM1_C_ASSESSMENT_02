#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100 //MAXLEN defined to make changing all string lengths easier

//void does not return a value

void newstudent() //function to Write a new student
{
    int count = 1;
    char ID[MAXLEN];
    char NAME[MAXLEN];
    char AGE[MAXLEN];
    char CLASS[MAXLEN];
    char TEXT[5][20] = {"Student ID: ", "Student name: ", "Student age: ", "Class Group: "};
    char FILEPATH[MAXLEN] = {"STUDENTS/"};

    printf("To create new student enter student ID: ");
    if (fgets(ID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input"); //perror to return a more detailed error message 
        return;
    }
    ID[strcspn(ID, "\n")] = 0; //remove newline character

    strcat(ID, ".txt"); //add ".txt" and "STUDENTS/" to create full filepath
    strcat(FILEPATH, ID);

    FILE *fptr; //create file (fptr == file pointer)
    fptr = fopen(FILEPATH, "w");
    if (fptr == NULL) 
    {
        perror("Error creating file"); //print error using perror to give more information
    }

    printf("enter student ID: ");
    if (fgets(ID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    ID[strcspn(ID, "\n")] = 0; //removes newline character that comes from user input

    printf("enter student name: ");
    if (fgets(NAME, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    NAME[strcspn(NAME, "\n")] = 0;

    printf("enter student age: ");
    if (fgets(AGE, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    AGE[strcspn(AGE, "\n")] = 0;

    printf("enter student class: ");
    if (fgets(CLASS, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    CLASS[strcspn(CLASS, "\n")] = 0;

    char *arr[4] = {ID, NAME, AGE, CLASS}; //fill array

    for(int i = 0; i < 4; i++) //print all students informaiton to both screen and file
    {
        printf("%s%s\n",TEXT[i], arr[i]);
        fprintf(fptr,"%s\n", arr[i]);
    }

    fclose(fptr);//close file
}

void newclass() //function to create and fill a new class
{
    char GROUPNAME[MAXLEN];
    char FILENAME[MAXLEN];
    char TID[MAXLEN];
    char SID[MAXLEN];
    int classsize = 0;
    char FRST[MAXLEN][10] = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth", "Tenth"};
    int count = 0;
    char FILEPATH[MAXLEN] = {"CLASSES/"};

    printf("To create new class enter class group: ");
    if (fgets(GROUPNAME, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    GROUPNAME[strcspn(GROUPNAME, "\n")] = 0;

    strcat(GROUPNAME, ".txt");
    strcat(FILEPATH, GROUPNAME);

    FILE *fptr; //create file (fptr == file pointer)
    fptr = fopen(FILEPATH, "w");
    if (fptr == NULL) 
    {
        perror("Error creating file");
    }

    printf("Enter class group: ");
    if (fgets(GROUPNAME, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    GROUPNAME[strcspn(GROUPNAME, "\n")] = 0;
    fprintf(fptr, "%s\n", GROUPNAME);

    printf("Enter assigned tacher: ");
    if (fgets(TID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    TID[strcspn(TID, "\n")] = 0;
    fprintf(fptr, "%s\n", TID);

    printf("how many students will be in the class (MAX SIZE 10): ");
    scanf("%d", &classsize);
    if(classsize > 10) //make max class size 10
    {
        printf("ERROR CLASS SIZE EXCEEDS MAXIMUM");
    }

    getchar(); //clear input buffer
    for(count = 0; count < classsize; count++)//create loop to add students to the class file loop size determained by classsize
    {
        printf("Enter %s student ID: ", FRST[count]);
        if (fgets(SID, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        SID[strcspn(SID, "\n")] = 0;
        fprintf(fptr, "%s\n", SID);
    }
    fclose(fptr);
}

void newteacher() //function to create a new teacher and give them a class group
{
    char TID[MAXLEN];
    char TNAME[MAXLEN];
    char class[MAXLEN];
    char TEXT[5][20] = {"Teacher ID: ", "Teacher name: ", "Class Group: "};
    char FILEPATH[MAXLEN] = {"TEACHERS/"};

    printf("enter teacher ID to begin: ");
    if (fgets(TID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    TID[strcspn(TID, "\n")] = 0;

    strcat(TID, ".txt");
    strcat(FILEPATH, TID);

    FILE *fptr;
    fptr = fopen(FILEPATH, "w");
    if (fptr == NULL) 
    {
        perror("Error creating file");
    }

    printf("enter teacher ID: ");
    if (fgets(TID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    TID[strcspn(TID, "\n")] = 0;

    printf("enter teacher name: ");
    if (fgets(TNAME, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    TNAME[strcspn(TNAME, "\n")] = 0;

    printf("enter assigned class: ");
    if (fgets(class, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    class[strcspn(class, "\n")] = 0;

    char *arr[3] = {TID, TNAME, class}; //fill array

    for(int i = 0; i < 3; i++)
    {
        printf("%s%s\n",TEXT[i], arr[i]);
        fprintf(fptr,"%s\n", arr[i]);
    }

    fclose(fptr);
}

void newresults() //function to add results to a students through string comparrison
{
    int i = 0;
    char SID[MAXLEN];
    char subject[MAXLEN];
    char FILENAME[MAXLEN] = {"RESULTS FOR "};
    float TOTALMARKS, ACTUALSCORE, PERCENTAGE;
    float SMARR[10][10]; //PARRALEL ARRAY
    float PERCENTARR[10];
    float summarks, sumscore;
    char FILEPATH[MAXLEN] = {"RESULTS/"};

    printf("Which student would you like to grade: ");
    if (fgets(SID, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return;
    }
    SID[strcspn(SID, "\n")] = 0;

    strcat(FILENAME, SID);
    strcat(FILENAME, ".txt");
    strcat(FILEPATH, FILENAME);

    FILE *fptr;
    fptr = fopen(FILEPATH, "w");
    if (fptr == NULL) 
    {
        perror("Error creating file");
    }

    do
    {
        printf("enter subject(or done to quit): ");
        if (fgets(subject, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        subject[strcspn(subject, "\n")] = 0;

        if(strcmp(subject, "done") == 0)
        break;

        printf("enter total marks: ");
        scanf("%f", &TOTALMARKS);

        printf("enter score: ");
        scanf("%f", &ACTUALSCORE);
        getchar(); //eats newline character to stop loop from skiping "enter subject" on loop

        PERCENTAGE = ACTUALSCORE / TOTALMARKS * 100; //calcutale percentage of score 
        SMARR[2][i] = TOTALMARKS; //assigned ith array index from user input
        SMARR[1][i] = ACTUALSCORE;
        i++; //increment used for array indexing location

        fprintf(fptr, "for %s %s got %.2f out of %.2f questions right for a total of %.2f%%\n", subject, SID, ACTUALSCORE, TOTALMARKS, PERCENTAGE);

    } while(1);
 
    for(int count = 0; count < i; count++) //sums all of both arrays
    {
        summarks += SMARR[2][count];
        sumscore += SMARR[1][count];
    }

    float sumpercent = sumscore / summarks * 100; //calculate total percentage
    fprintf(fptr, "For a total percentage of %.2f%%\n", sumpercent);
    fclose(fptr);

}

void viewstudent() //function to allow user to view students
{
    char SID[MAXLEN];
    char check[MAXLEN];
    char printer;

    do
    {  
        char FILEPATH[MAXLEN] = {"STUDENTS/"};

        printf("which student would you like to view: ");
        if (fgets(SID, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        SID[strcspn(SID, "\n")] = 0;

        strcat(SID, ".txt");
        strcat(FILEPATH, SID);

        FILE *fptr;
        fptr = fopen(FILEPATH, "r");
        if (fptr == NULL) 
        {
            perror("Error opening file");
        }

        while ((printer = fgetc(fptr)) != EOF) // Read character by character
        putchar(printer); //prints from file to screen
        fclose(fptr);

        printf("would you like to view another student(y/n): ");
        if (fgets(check, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        check[strcspn(check, "\n")] = 0;

        if(strcmp(check, "no") == 0 || strcmp(check, "No") == 0 || strcmp(check, "n") == 0 || strcmp(check, "N") == 0) //checking for when user wishes to leave 
        break;
    } 
    while(1);
}

void viewclass() //function to allow user to view class groups
{
    char CLASS[MAXLEN];
    char check[MAXLEN];
    char printer;
    
    do
    {  
        char FILEPATH[MAXLEN] = {"CLASSES/"};

        printf("which class would you like to view: ");
        if (fgets(CLASS, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        CLASS[strcspn(CLASS, "\n")] = 0;

        strcat(CLASS, ".txt");
        strcat(FILEPATH, CLASS);

        FILE *fptr;
        fptr = fopen(FILEPATH, "r");
        if (fptr == NULL) 
        {
            perror("Error opening file");
        }

        while ((printer = fgetc(fptr)) != EOF) 
        putchar(printer);
        fclose(fptr);

        printf("would you like to view another class(y/n): ");
        if (fgets(check, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        check[strcspn(check, "\n")] = 0;

        if(strcmp(check, "no") == 0 || strcmp(check, "No") == 0|| strcmp(check, "n") == 0 || strcmp(check, "N") == 0)
        break;
    } 
    while(1);
}

void viewteacher() //function to allow user to view teachers
{
    char TID[MAXLEN];
    char check[MAXLEN];
    char printer;
    char FILEPATH[MAXLEN] = {"TEACHERS/"};
    
    do
    {  
        char FILEPATH[MAXLEN] = {"TEACHERS/"};

        printf("which teacher would you like to view: ");
        if (fgets(TID, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        TID[strcspn(TID, "\n")] = 0;

        strcat(TID, ".txt");
        strcat(FILEPATH, TID);

        FILE *fptr;
        fptr = fopen(FILEPATH, "r");
        if (fptr == NULL) 
        {
            perror("Error opening file");
        }

        while ((printer = fgetc(fptr)) != EOF)
        putchar(printer);
        fclose(fptr);

        printf("would you like to view another teacher(y/n): ");
        if (fgets(check, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        check[strcspn(check, "\n")] = 0;

        if(strcmp(check, "no") == 0 || strcmp(check, "No") == 0|| strcmp(check, "n") == 0 || strcmp(check, "N") == 0)
        break;
    } 
    while(1);
}

void viewresults() //function to allow user to view students results
{
    char RESULTS[MAXLEN];
    char check[MAXLEN];
    char printer;

    do
    { 
        char FILEPATH[MAXLEN] = {"RESULTS/RESULTS FOR "};

        printf("Which students results would you like to view: ");
        if (fgets(RESULTS, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        RESULTS[strcspn(RESULTS, "\n")] = 0;

        strcat(RESULTS, ".txt");
        strcat(FILEPATH, RESULTS);

        FILE *fptr;
        fptr = fopen(FILEPATH, "r");
        if (fptr == NULL) 
        {
            perror("Error opening file");
        }

        while ((printer = fgetc(fptr)) != EOF)
        putchar(printer);
        fclose(fptr);

        printf("\nwould you like to view another student's results(y/n): ");
        if (fgets(check, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        check[strcspn(check, "\n")] = 0;

        if(strcmp(check, "no") == 0 || strcmp(check, "No") == 0|| strcmp(check, "n") == 0 || strcmp(check, "N") == 0)
        break;
    } 
    while(1);
}

void delete() //function to allow user to delete any file
{
    char INPUT[MAXLEN];
    do
    {
        printf("which would you like to delete\n--Student--\n--Class--\n--Teacher--\n--Results--\n");
        if (fgets(INPUT, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        INPUT[strcspn(INPUT, "\n")] = 0;

        if (strcmp(INPUT, "student") == 0 || strcmp(INPUT, "Student") == 0) //check user input
        {
            char FILEPATH[MAXLEN] = {"STUDENTS/"};

            printf("which student would you like to delete: ");
            if (fgets(INPUT, MAXLEN, stdin) == NULL) 
            {
                perror("Error reading input");
                return;
            }
            INPUT[strcspn(INPUT, "\n")] = 0;

            strcat(INPUT, ".txt");
            strcat(FILEPATH, INPUT);

            char* fptr = FILEPATH;
            if (remove(fptr) == 0) //delete file
            {
                printf("File has been deleted: \n");
            }
            else 
            {
                perror("Error failed to delete file");
            }
        }
        else if (strcmp(INPUT, "class") == 0 || strcmp(INPUT, "Class") == 0)
        {
            char FILEPATH[MAXLEN] = {"CLASSES/"};

            printf("which class would you like to delete: ");
            if (fgets(INPUT, MAXLEN, stdin) == NULL) 
            {
                perror("Error reading input");
                return;
            }
            INPUT[strcspn(INPUT, "\n")] = 0;

            strcat(INPUT, ".txt");
            strcat(FILEPATH, INPUT);

            char* fptr = FILEPATH;
            if (remove(fptr) == 0)
            {
                printf("File has been deleted: \n");
            }
            else 
            {
                perror("Error failed to delete file");
            }
        }
        else if (strcmp(INPUT, "teacher") == 0 || strcmp(INPUT, "Teacher") == 0)
        {
            char FILEPATH[MAXLEN] = {"TEACHERS/"};

            printf("which teacher would you like to delete: ");
            if (fgets(INPUT, MAXLEN, stdin) == NULL) 
            {
                perror("Error reading input");
                return;
            }
            INPUT[strcspn(INPUT, "\n")] = 0;

            strcat(INPUT, ".txt");
            strcat(FILEPATH, INPUT);

            char* fptr = FILEPATH;
            if (remove(fptr) == 0)
            {
                printf("File has been deleted: \n");
            }
            else 
            {
                perror("Error failed to delete file");
            }
        }
        else if (strcmp(INPUT, "results") == 0 || strcmp(INPUT, "Results") == 0)
        {
            char FILEPATH[MAXLEN] = {"RESULTS/"};
            char FILENAME[MAXLEN] = {"RESULTS FOR "};

            printf("which students results would you like to delete: ");
            if (fgets(INPUT, MAXLEN, stdin) == NULL) 
            {
                perror("Error reading input");
                return;
            }
            INPUT[strcspn(INPUT, "\n")] = 0;

            strcat(FILENAME, INPUT);
            strcat(FILENAME, ".txt");
            strcat(FILEPATH, FILENAME);

            char* fptr = FILEPATH;
            if (remove(fptr) == 0)
            {
                printf("File has been deleted: \n");
            }
            else 
            {
                perror("Error failed to delete file");
            }
        }
        
        printf("would you like to delete another file(y/n): "); //prompt to see if user wants to delete another file
        if (fgets(INPUT, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return;
        }
        INPUT[strcspn(INPUT, "\n")] = 0;

        if(strcmp(INPUT, "no") == 0 || strcmp(INPUT, "No") == 0|| strcmp(INPUT, "n") == 0 || strcmp(INPUT, "N") == 0)
        break;
    } 
    while(1);
}

void ERROR() //ERROR MESSAGE FUNTION     thought I was going to use this more
{
    printf("ERROR please try again\n"); //print error
}

int main()
{
    char INPUT[MAXLEN];
    char welcomemessage[MAXLEN] = "Welcome to the school management system ";
    char name[MAXLEN];

    printf("Please enter your name: ");
    if (fgets(name, MAXLEN, stdin) == NULL) 
    {
        perror("Error reading input");
        return 1;
    }
    name[strcspn(name, "\n")] = 0;

    strcat(welcomemessage, name);

    printf("%s\n", welcomemessage);

    while (1)
    {
        printf("Would you like to view, create or delete data(or type exit to exit): ");
        if (fgets(INPUT, MAXLEN, stdin) == NULL) 
        {
            perror("Error reading input");
            return 1;
        }
        INPUT[strcspn(INPUT, "\n")] = 0; //remove newline character to ensure inputs stay clean

        if(strcmp(INPUT, "exit") == 0) //allow user to leave program
        break;

        do
        {
            if (strcmp(INPUT, "view") == 0 || strcmp(INPUT, "View") == 0)
            {
                printf("What would you like to view\n--Student--\n--Class--\n--Teacher--\n--Results--\n");
                if (fgets(INPUT, MAXLEN, stdin) == NULL) 
                {
                    perror("Error reading input");
                    return 1;
                }
                INPUT[strcspn(INPUT, "\n")] = 0;
                            
                if (strcmp(INPUT, "student") == 0 || strcmp(INPUT, "Student") == 0)
                {
                    viewstudent(); //call viewstudent function
                    break;
                }
                else if (strcmp(INPUT, "class") == 0 || strcmp(INPUT, "Class") == 0)
                {
                    viewclass();
                    break;
                }
                else if (strcmp(INPUT, "teacher") == 0 || strcmp(INPUT, "Teacher") == 0)
                {
                    viewteacher();
                    break;
                }
                else if (strcmp(INPUT, "results") == 0 || strcmp(INPUT, "Results") == 0)
                {
                    viewresults();
                    break;
                }
                else
                {
                    ERROR(); //call error function
                    break;
                }
            }
            else if (strcmp(INPUT, "create") == 0 || strcmp(INPUT, "Create") == 0)
            {
                printf("What would you like to create\n--Student--\n--Class--\n--Teacher--\n--Results--\n");
                if (fgets(INPUT, MAXLEN, stdin) == NULL) 
                {
                    perror("Error reading input");
                    return 1;
                }
                INPUT[strcspn(INPUT, "\n")] = 0;

                if (strcmp(INPUT, "student") == 0 || strcmp(INPUT, "Student") == 0)
                {
                    newstudent(); //call newstudent function
                    break;
                }
                else if (strcmp(INPUT, "class") == 0 || strcmp(INPUT, "Class") == 0)
                {
                    newclass();
                    break;
                }
                else if (strcmp(INPUT, "teacher") == 0 || strcmp(INPUT, "Teacher") == 0)
                {
                    newteacher();
                    break;
                }
                else if (strcmp(INPUT, "results") == 0 || strcmp(INPUT, "Results") == 0)
                {
                    newresults();
                    break;
                }
                else
                {
                    ERROR();
                    break;
                }
            }
            else if (strcmp(INPUT, "delete") == 0 || strcmp( INPUT, "Delete") == 0)
            {
                delete(); //call delete functino
                break;
            }
            else
            {
                ERROR();
                break;
            }
        } while(strcmp(INPUT, "menu") != 0 || strcmp(INPUT, "Menu") == 0);
    }
    return 0;
}