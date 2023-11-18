import java.lang.Math;
import java.util.*;

class Bank {
    Account accounts[];

    Bank(int num) {
        this.accounts = new Account[num];
    }

    static class Account {
        protected String name;
        protected UUID uuid;
        protected float balance;

        Account(String name, float balance) {
            this.balance = balance;

            this.uuid = UUID.randomUUID();
        }

        void displayStatus() {
            System.out.println("Account under: " + this.name);
            System.out.println("Account number: " + this.uuid);
            System.out.println("Current Balance: " + this.balance);
        }

        float balance() {
            return this.balance;
        }
    
        float deposit(float value) {
            this.balance += value;
            return this.balance;
        }

        float withdraw(float value) {
            this.balance -= value;
            return this.balance;
        }
    }

    static class SavingsAccount extends Account {
        private float interestR = 5;
        private float interestN = 2;

        SavingsAccount(String name, float balance) {
            super(name, balance);
        }

        void updateBalance(float time) {
            this.balance = (float)(this.balance*Math.pow(1 + (interestR/interestN), interestN*time));
        }

        @Override
        float withdraw(float value) {
            this.updateBalance(1);
            return super.withdraw(value);
        }

        @Override
        float deposit(float value) {
            this.updateBalance(1);
            return super.deposit(value);
        }

        float deposit(float time, float value) {
            this.updateBalance(time);
            return super.deposit(value);
        }

        float withdraw(float time, float value) {
            this.updateBalance(time);
            return super.withdraw(value);
        }
    }

    static class CurrentAccount extends Account {
        private float minBalance = 10000;
        private float serviceCharge = 1000;

        CurrentAccount(String name, float balance) {
            super(name, balance);
        }

        protected void updateBalance() {
            if(this.balance >= minBalance) return;

            this.balance = this.balance - serviceCharge;
        }

        @Override
        float withdraw(float value) {
            this.updateBalance();
            return super.withdraw(value);
        }

        @Override
        float deposit(float value) {
            this.updateBalance();
            return super.deposit(value);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Welcome to the bank");
        System.out.println("Enter the number of accounts do you want to make");
        int numAccounts = sc.nextInt();

        Bank bank = new Bank(numAccounts);

        for(int i = 0; i < numAccounts; i++) {
            System.out.println("Which account do you want to create?");
            System.out.println("1. Savings Account");
            System.out.println("2. Current Account");

            int choice = sc.nextInt();
            sc.nextLine();

            switch(choice) {
                case 1:
                    System.out.println("Enter your Name");
                    String tempName1 = sc.nextLine();
                    System.out.println("Enter the initial balance");
                    bank.accounts[i] = new Bank.SavingsAccount(tempName1, sc.nextFloat());
                    break;
                case 2:
                    System.out.println("Enter your Name");
                    String tempName2 = sc.nextLine();
                    System.out.println("Enter the initial balance");
                    bank.accounts[i] = new Bank.CurrentAccount(tempName2, sc.nextFloat());
                    break;
                default:
                    System.out.println("Please enter a valid choice");
            }
        }

        boolean isRunning = true;
        while(isRunning) {
            System.out.println("Enter the account that you want to access");
            int bankIndex = sc.nextInt();

            System.out.println("Enter the operation to be performed");
            System.out.println("1. Withdraw");
            System.out.println("2. Deposit");
            System.out.println("3. Display Status");
            System.out.println("4. Exit");

            int choice = sc.nextInt();

            switch(choice) {
                case 1:
                    System.out.println("Enter the amount to withdraw");
                    bank.accounts[bankIndex].withdraw(sc.nextFloat());
                    break;
                case 2:
                    System.out.println("Enter the amount to deposit");
                    bank.accounts[bankIndex].deposit(sc.nextFloat());
                    break;
                case 3:
                    bank.accounts[bankIndex].displayStatus();
                    break;
                case 4:
                    isRunning = false;
                    break;
                default: 
                    System.out.println("Enter a valid choice");
            }
        }

        sc.close();
    }
}
