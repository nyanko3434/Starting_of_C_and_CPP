#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>

struct book
{
    char name[100], nikname[50], type[50], bmark[50], status[20], rating[5], upt[30], genre[50];
}bo, ok[100], tem;

FILE *f,*p;
float rate;
char comr[20]="Completed Reading",
     curr[20]="Currently Reading",
     plar[20]="Plan to Read",
     com[5],
     search[100];
int flag = 0, i, j, count = 0, choice, sn;
time_t t;

void add();
void list();
void look();
void update();
void del();
void clear();
void help();
void nn(char *n);
void mess(int);
void pribo (struct book, int);

void main()
{
    do
    {
      system("cls");
        printf("*****                    **********          **********                    *****\n");
        printf("*****                             My Book List                             *****\n");
        printf("*****                    **********          **********                    *****\n");
        printf("\tMain Menu\n");
        printf("\t[1] |Add a New book to the list      |\n");
        printf("\t[2] |View the list                   |\n");
        printf("\t[3] |Search a Specific Book          |\n");
        printf("\t[4] |Update/Change details of a book |\n");
        printf("\t[5] |Delete a book record from list  |\n");
        printf("\t[6] |Clear the Entire list           |\n");
        printf("\t[7] |Help                            |\n\n");
        printf("\t[0] |Exit                            |\n\n\n");

        printf("Enter the number of task you want to perform (1 - 7) : ");
        scanf("%d",&sn);

        switch(sn)
        {
        case 1:
            add();
            break;
        case 2:
            list();
            break;
        case 3:
            look();
            break;
        case 4:
            update();
            break;
        case 5:
            del();
            break;
        case 6:
            clear();
            break;
        case 7:
            help();
            break;
        }

    }while(sn!=0);

    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\t\t\t****  Enter any key to Exit  ****");
 getch();
 system("cls");

}

void add()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    system("cls");
    printf("\t\t****   Adding New Record To The List   ****\n\n");
    printf("[Note : If you don't want to enter a specific detail right now enter NN / nn]\n\n\n");

    f = fopen("book list.txt","a");

    printf("Enter the following details of the book\n");

    printf("\nName of the book      : ");
    scanf("%s",bo.name);

    printf("\nNickname for the book : ",bo.nikname);
    scanf("%s",bo.nikname);

    printf("\nType of book(Novel/Comic/Light Novel/....etc) : ");
    scanf("%s",bo.type);

    printf("\nGenre of book : ");
    scanf("%s",bo.genre);

    nn(&bo.type);
    nn(&bo.nikname);
    nn(&bo.genre);

    printf("\n 1) %s\t 2) %s\t 3)%s\n",comr,curr,plar);
    Sta:
    printf("Enter status(1 - 3) : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        strcpy(bo.status, comr);
        printf("Give your rating on book(0 - 10) : ");
        scanf("%s",bo.rating);
        rate = atof(bo.rating);
        if (!(rate>0 && rate<=10))
            strcpy(bo.rating,"----");
        strcpy(bo.bmark,"----");
        break;
    case 2:
        strcpy(bo.status,curr);
        printf("\nGive your rating on book(0 - 10) : ");
        scanf("%s",bo.rating);
        rate = atof(bo.rating);
        if (!(rate>0 && rate<=10))
            strcpy(bo.rating,"----");
        printf("\nSet a book mark :");
        scanf("%s",bo.bmark);
        nn(&bo.bmark);
        break;
    case 3:
        strcpy(bo.status, plar);
        strcpy(bo.rating,"----");
        strcpy(bo.bmark,"----");
        break;
    default:
        printf("Please Enter number form 1 to 3 only!!\n");
        goto Sta;
        break;
    }

    pribo(bo,0);
    printf("Do you want to add this record to the list? Press yes or no : ");
    scanf("%s", com);
    strlwr(com);
    if (strcmp(com,"yes")==0)
    {
        system("cls");
        t = time(NULL);
        strcpy(bo.upt,ctime(&t));
        fwrite(&bo, sizeof(bo),1,f);

        mess(1);
    }
    else
        mess(0);

    getch();
    fclose(f);

}

void list()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    i = 0;
    system("cls");
    f = fopen("book list.txt","r");
    while(!feof(f))
    {
         fread (&ok[i], sizeof (ok[i]) ,1,f);
        i++;
        count++;
    }
    fclose(f);
    for (i=0;i<count-1;i++)
        for(j=i+1;j<count-1;j++)
        if(strcmp(ok[i].name,ok[j].name)==1)
        {
            tem = ok[i];
            ok[i] = ok[j];
            ok[j] = tem;
        }
    list :
    system("cls");
    printf(" ****                    **********          **********                    ****\n\n");
    printf("                                  My Book List\n\n");
    printf(" ****                    **********          **********                    ****\n\n");

    for (i=0; i<count-1; i++)
        printf("[%d] %s\n",i+1,ok[i].name);
    printf("\n\n\nDo you want to see the details of a specific book? \nIf yes, enter the number of the book. Enter [ 0 ] to get back to main menu : ");
    scanf("%d",&j);
    j--;
    if (j>=0 && j<count)
    {
        pribo(ok[j],1);
        printf("\n\n\n\t\t Enter any key to get back to the list......");
        getch();
        goto list;
    }

}

void look()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    top :
    system("cls");
    printf("\t\t  ******     Search Specific Books     ******");
    printf("\n\n\n 1) Name\t 2) Nickname\t 3)Status\t 4) Score\t 5) Type\n\n[0] Exit\n\n");
    printf("Enter on what basis you want to search the books(1 - 5) : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        flag--;
        break;
    case 1:
        i=0; count=0;
        printf("\n\nEnter the Name of book : ");
        scanf("%s",search);
        f = fopen("book list.txt","r");
        while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
        {
            if (strcmp(bo.name,search)==0)
            {
                ok[i] = bo;
                i++;
                count++;

            }
        }
        fclose(f);
        break;
    case 2:
        i=0; count=0;
        printf("\n\nEnter the Nickname of book : ");
        scanf("%s",search);
        f = fopen("book list.txt","r");
        while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
        {
            if (strcmp(bo.nikname,search)==0)
            {
                ok[i] = bo;
                i++;
                count++;
            }
        }
        fclose(f);
        break;
    case 3:
        i=0; count=0;
        printf("\n\n 1) %s\t 2) %s\t 3)%s\n",comr,curr,plar);
        Sta:
        printf("Enter status(1 - 3) : ");
        scanf("%d",&sn);
        switch(sn)
        {
        case 1:
            strcpy(search, comr);
            break;
        case 2:
            strcpy(search,curr);
            break;
        case 3:
            strcpy(search, plar);
            break;
        default:
            printf("Please Enter number form 1 to 3 only!!\n");
            goto Sta;
            break;
        }
        f = fopen("book list.txt","r");
        while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
        {
            if (strcmp(bo.status,search)==0)
            {
                ok[i] = bo;
                i++;
                count++;
            }
        }
        fclose(f);
        break;
    case 4:
        i=0; count=0;
        printf("\n\nEnter the Score of book : ");
        scanf("%s",search);
        f = fopen("book list.txt","r");
        while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
        {
            if (strcmp(bo.rating,search)==0)
            {
                ok[i] = bo;
                i++;
                count++;
            }
        }
        fclose(f);
        break;
    case 5:
        i=0; count=0;
        printf("\n\nEnter the Type of book : ");
        scanf("%s",search);
        f = fopen("book list.txt","r");
        while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
        {
            if (strcmp(bo.type,search)==0)
            {
                ok[i] = bo;
                i++;
                count++;
            }
        }
        fclose(f);
        break;
    default:
        goto top;
        break;
    }

    if(!(flag<0))
    {
        result:
        system("cls");
        printf("\n Results : \n\n");
        if(count==0)
        {
            printf("\n\n\n\n\n\n\t\t\t******     NO MATCH FOUND     *****");
            getch();
        }
        else
        {
            for (i=0; i<count; i++)
                printf("[%d] %s\n",i+1,ok[i].name);
            printf("\n\n\nDo you want to see the details of a specific book? \nIf yes, enter the number of the book.Enter [ 0 ] to get back to menu : ");
            scanf("%d",&j);
            j--;
            if (j>=0 && j<count)
            {
                pribo(ok[j],1);
                printf("\n\n\n\t\t Enter any key to get back to the result......");
                getch();
                goto result;
            }
        }
        goto top;
    }
}

void update()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    system("cls");
    printf("\n\t\t*****    Update/Change details of a book    *****\n\n\n");
    printf("Enter Name of book you want to change details of : ");
    scanf("%s",search);
    p=fopen("copy.txt","w");
    f=fopen("book list.txt","r");
    while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
    {
            if (strcmp(bo.name,search)==0)
            {
                system("cls");
                flag = 1;
                pribo(bo,1);
                printf("Enter [ yes ] if you want to updated this record. Else [ no ] :");
                scanf("%s",com);
                if (strcmp(strlwr(com),"yes")!=0)
                    fwrite (&bo, sizeof (bo) ,1,p);
                else
                {
                    mid:
                    system("cls");
                    printf("\t\t  ******     Select the Field you want to change     ******");
                    printf("\n\n\n 1) Name    2) Nickname    3)Status    4) Score    5) Type   6) Bookmark\n\n");
                    printf("Select the Field you want to change(1 - 6) : ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                        printf("\nEnter New Name : ");
                        scanf("%s",bo.name);
                        break;
                    case 2:
                        printf("\nEnter New Nickname : ");
                        scanf("%s",bo.nikname);
                        break;
                    case 3:
                        printf("\n\n 1) %s\t 2) %s\t 3)%s\n",comr,curr,plar);
                        Sta:
                            printf("Enter status(1 - 3) : ");
                            scanf("%d",&sn);
                            switch(sn)
                            {
                                case 1:
                                    strcpy(bo.status, comr);
                                    strcpy(bo.bmark,"----");
                                    break;
                                case 2:
                                    strcpy(bo.status,curr);
                                    break;
                                case 3:
                                    strcpy(bo.status, plar);
                                    break;
                                default:
                                    printf("Please Enter number form 1 to 3 only!!\n");
                                    goto Sta;
                                    break;
                            }
                        break;
                    case 4:
                        printf("\nEnter New Score : ");
                        scanf("%s",bo.rating);
                        break;
                    case 5:
                        printf("\nEnter New Type : ");
                        scanf("%s",bo.type);
                        break;
                    case 6:
                        printf("\nEnter New bookmark : ");
                        scanf("%s",bo.bmark);
                        break;
                    default:
                        goto mid;
                        break;
                    }
                    flag = 2;
                    printf("\nIf you want to change other details of this book, Enter [ yes ] : ");
                    scanf("%s",com);
                    strlwr(com);
                    if (strcmp(com,"yes") == 0)
                    goto mid;
                    t = time(NULL);
                    strcpy(bo.upt,ctime(&t));
                    fwrite (&bo, sizeof (bo) ,1,p);
                }
            }
           else
            {
                fwrite (&bo, sizeof (bo) ,1,p);
            }
    }
    fclose(p);
    fclose(f);
    remove("book list.txt");
    rename("copy.txt","book list.txt");

    system("cls");

    if(flag == 0)
        printf("\n\n\n\n\n\n\n\n\t   *****    There exists no record of such name    *****");
    else if(flag == 2)
        mess(1);
    else
        mess(0);
    getch();
}

void del()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    system("cls");
    printf("\n\t\t*****    Delete a book record from list    *****\n\n\n");
    printf("Enter Name of book you want to delete record of : ");
    scanf("%s",search);
    p=fopen("copy.txt","w");
    f=fopen("book list.txt","r");
    while((fread (&bo, sizeof (bo) ,1,f))!= NULL)
    {
            if (strcmp(bo.name,search)==0)
            {
                flag = 1;
                pribo(bo,1);
                printf("Enter [ yes ] if you want to delete this record. Else [ no ] :");
                scanf("%s",com);
                if (strcmp(strlwr(com),"yes")!=0)
                    fwrite (&bo, sizeof (bo) ,1,p);
                else
                    flag = 2;
            }
           else
            {
                fwrite (&bo, sizeof (bo) ,1,p);
            }
    }
    fclose(p);
    fclose(f);
    remove("book list.txt");
    rename("copy.txt","book list.txt");

    system("cls");

    if(flag == 0)
        printf("\n\n\n\n\n\n\n\n\t   *****    There exists no record of such name    *****");
    else if(flag == 2)
        mess(1);
    else
        mess(0);
    getch();
}
void clear()
{
    flag = 0; i = 0; j = 0; choice=0; count=0;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\nAre you sure you want to clear the entire list? Enter [ yes ] to conform. Enter any other keys/words to cancel this process. : ");
    scanf("%s",com);
    strlwr(com);
    if (strcmp(com,"yes") == 0)
    {
        f = fopen("book list.txt","w");
        fclose(f);
        mess(1);
    }
    else
        mess(0);

    getch();
}

void help()
{
    system("cls");
    printf("\n\t\t\t\t\tHelp\n\n");
    printf("[1] This program helps one to create and organize their own personal book list.\n\n");
    printf("[2] This programs helps user organize by allowing user to add details to each   book such as status(completed,reading,plan to read), rating, bookmark etc.\n\n");
    printf("[3] While adding a record to a list, if you don't want to fill any field right  at the moment you can enter [ nn ] which fill that place with [----]. And you   can fill that area later.\n\n");
    printf("[4] If a book has very long name or a name hard to remember, you can give that  book a nickname, which makes it easier to search later on. ");
    printf("\n\n\n\n\n\n\n\n\t\tPress any key to Exit......");
    getch();
}
void nn(char *n)
{
    char a[50];
    strcpy(a,n);
    if (strcmp(strlwr(a),"nn")==0)
    {
        strcpy(n,"----");
    }

}
void mess(int a)
{
    system("cls");
    if(a==0)
        printf("\n\n\n\n\n\n\n\n\n ****                    The Process has been Terminated                   ****\n\n");
    else
        printf("\n\n\n\n\n\n\n\n\n ****                      Task Completed Successfully                     ****\n\n");
    printf("\n\n\n\n\n\n\n\n\n\t\t\tPress any key to continue....");
}

void pribo (struct book oo, int a)
{
    system("cls");
    printf("\n\n Name        : %s\n Nickname    : %s\n Type        : %s\n Genre       : %s\n Status      : %s\n Rating      : %s\n Bookmark    : %s\n",
            oo.name,oo.nikname, oo.type, oo.genre, oo.status, oo.rating, oo.bmark);
    if(a == 1)
        printf(" Last Updated: %s\n",oo.upt);
}

