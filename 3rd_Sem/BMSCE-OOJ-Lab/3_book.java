import java.util.*;

class Book{
	Book(int book_num) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the title of the book " + book_num+1 + ":");
		title = sc.nextLine();
		System.out.println("Enter the author of the book " + book_num+1 + ":");
		author = sc.nextLine();
		System.out.println("Enter the price of the book " + book_num+1 + ":");
		price = sc.nextInt();
		System.out.println("Enter the number of pages of the book " + book_num+1 + ":");
		num_pages = sc.nextInt();
	}

	void print_details() {
		System.out.println("Title: " + title);
		System.out.println("Author: " + author);
		System.out.println("Price: " + price);
		System.out.println("Number of Pages: " + num_pages + "\n");
	}

	void set_price(int newPrice) {
		price = newPrice;
	}

	private String title;
	private String author;
	private int price;
	private int num_pages;
}

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		boolean bLoop = true;

		System.out.println("Welcome to the book store!");
		System.out.println("Enter the number of books to enter: ");
		int num_books = sc.nextInt();
		Book[] books = new Book[num_books];

		for(int i = 0; i < num_books; i++) {
			books[i] = new Book(i);
		}

		while(bLoop) {
			System.out.println("\nEnter the Operation to perform: ");
			System.out.println("1.Exit\n2.Display Details\n3.Change the price");
			int choice = sc.nextInt();
			int book_choice = -1;
			if(choice != 1){
				System.out.println("Enter the book_num: ");
				book_choice = sc.nextInt();
			}

			switch(choice){
				case 1:
					bLoop = false;
					break;
				case 2:
					books[book_choice-1].print_details();
					break;
				case 3:
					System.out.println("Enter the new price of the book: ");
					int newPrice = sc.nextInt();
					books[book_choice-1].set_price(newPrice);
					break;
				default:
					System.out.println("Enter a valid choice");
			}
		}
	}
}
