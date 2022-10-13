import java.util.*;
class accounts
{
    int accno;
    int balance=1000;
    accounts(int acno)
    {
        accno=acno;
    }
    public void withdraw(int amt)
    {
        if(amt>=balance)
        {
            System.out.println("insufficient balance");
        }
        else
        {
            balance=balance-amt;
        }
    }
    public void deposite(int amt)
    {
        if(amt<=0)
        {
            System.out.println("the minimum amount that can be deposited should be greater than 0");
        }
        else
        {
            balance=balance+amt;
        }
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        int amt;
        System.out.println("enter the account number");
        int acno=sc.nextInt();
        accounts obj=new accounts(acno);
        System.out.println("initial amount = "+(obj.balance));
        System.out.println("Enter \n1 to deposite \n2 to make a withdraw");
        int c=sc.nextInt();
        switch(c)
        {
            case 1: System.out.println("enter the amount to be deposited");
                amt=sc.nextInt();
                obj.deposite(amt);
                System.out.println("Account number "+obj.accno);
                System.out.println("the final balance is "+obj.balance);
                break;
            case 2: System.out.println("enter the amount to be withdrawn");
                amt=sc.nextInt();
                obj.withdraw(amt);
                System.out.println("Account number "+obj.accno);
                System.out.println("the final balance is "+obj.balance);
                break;
            default: System.out.println("wrong input");
        }
    }
}
