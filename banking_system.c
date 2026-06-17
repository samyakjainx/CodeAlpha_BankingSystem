#include<stdio.h>
#include<stdlib.h>

struct Acc
{
    int acc;
    char name[50];
    float bal;
};

void createAcc();
void deposit();
void withdraw();
void balance();
void showAll();

int main()
{
    int ch;

    while(1)
    {
        printf("\n====================================\n");
        printf("         MINI BANKING SYSTEM\n");
        printf("====================================\n");

        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Balance Enquiry\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                createAcc();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                balance();
                break;

            case 5:
                showAll();
                break;

            case 6:
                printf("\nThank You!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void createAcc()
{
    FILE *fp;

    struct Acc a,t;

    int f=0;

    fp=fopen("bank.txt","ab+");

    printf("\nAccount Number : ");
    scanf("%d",&a.acc);

    rewind(fp);

    while(fread(&t,sizeof(t),1,fp))
    {
        if(t.acc==a.acc)
        {
            f=1;
            break;
        }
    }

    if(f)
    {
        printf("\nAccount Already Exists!\n");
        fclose(fp);
        return;
    }

    printf("Name : ");
    scanf(" %[^\n]",a.name);

    printf("Opening Balance : ");
    scanf("%f",&a.bal);

    fseek(fp,0,SEEK_END);

    fwrite(&a,sizeof(a),1,fp);

    fclose(fp);

    printf("\nAccount Created Successfully!\n");
}

void deposit()
{
    FILE *fp,*tp;

    struct Acc a;

    int no,f=0;

    float amt;

    fp=fopen("bank.txt","rb");
    tp=fopen("temp.txt","wb");

    printf("\nAccount Number : ");
    scanf("%d",&no);

    printf("Deposit Amount : ");
    scanf("%f",&amt);

    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.acc==no)
        {
            a.bal+=amt;
            f=1;
        }

        fwrite(&a,sizeof(a),1,tp);
    }

    fclose(fp);
    fclose(tp);

    remove("bank.txt");
    rename("temp.txt","bank.txt");

    if(f)
        printf("\nMoney Deposited Successfully!\n");
    else
        printf("\nAccount Not Found!\n");
}

void withdraw()
{
    FILE *fp,*tp;

    struct Acc a;

    int no,f=0;

    float amt;

    fp=fopen("bank.txt","rb");
    tp=fopen("temp.txt","wb");

    printf("\nAccount Number : ");
    scanf("%d",&no);

    printf("Withdraw Amount : ");
    scanf("%f",&amt);

    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.acc==no)
        {
            if(a.bal>=amt)
            {
                a.bal-=amt;
                printf("\nTransaction Successful!\n");
            }
            else
            {
                printf("\nInsufficient Balance!\n");
            }

            f=1;
        }

        fwrite(&a,sizeof(a),1,tp);
    }

    fclose(fp);
    fclose(tp);

    remove("bank.txt");
    rename("temp.txt","bank.txt");

    if(f==0)
        printf("\nAccount Not Found!\n");
}

void balance()
{
    FILE *fp;

    struct Acc a;

    int no,f=0;

    fp=fopen("bank.txt","rb");

    printf("\nAccount Number : ");
    scanf("%d",&no);

    while(fread(&a,sizeof(a),1,fp))
    {
        if(a.acc==no)
        {
            printf("\nName : %s\n",a.name);
            printf("Balance : %.2f\n",a.bal);
            f=1;
        }
    }

    fclose(fp);

    if(f==0)
        printf("\nAccount Not Found!\n");
}

void showAll()
{
    FILE *fp;

    struct Acc a;

    fp=fopen("bank.txt","rb");

    if(fp==NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n-----------------------------------\n");

    while(fread(&a,sizeof(a),1,fp))
    {
        printf("\nAccount : %d\n",a.acc);
        printf("Name    : %s\n",a.name);
        printf("Balance : %.2f\n",a.bal);
    }

    fclose(fp);
}