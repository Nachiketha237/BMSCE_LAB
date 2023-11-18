import java.util.*;

class Student {
	String usn;
	String name;

	private int[] credits;
	private int[] grades;

	Student(String usn, String name, int[] credits, int[] grades) {
		this.usn = usn;
		this.name = name;
		this.credits = credits;
		this.grades = grades;
	}

	double give_sgpa() {
		double total_grade_point = 0;
		double total_credits = 0;
		for(int i = 0; i < grades.length; i++){
			total_grade_point += grades[i] * credits[i];
			total_credits += credits[i];
		}

		return (total_grade_point/total_credits);
	}	
};

class Main {
	public static void main(String args[]) {
		Scanner sc0 = new Scanner(System.in);
		System.out.println("Enter the number of subjects");
		int num_credits = sc0.nextInt();

		int[] credits = new int[num_credits];
		System.out.println("Enter the credits of each subject");
		for(int i = 0; i < num_credits; i++){
			credits[i] = sc0.nextInt();
		}

		System.out.println("Enter the number of students");
		int num_students = sc0.nextInt();

		Scanner sc = new Scanner(System.in);
		Student[] students = new Student[num_students];
		for(int i = 0; i < num_students; i++){
			System.out.println("Enter the USN of student " + i+1);
			String temp_usn = sc.nextLine();
			System.out.println("Enter the name of student " + i+1);
			String temp_name = sc.nextLine();
			int[] temp_grades = new int[num_credits];

			System.out.println("Enter the grades of all the subjects of student " + i+1);
			for(int j = 0; j < num_credits; j++){
				temp_grades[j] = sc.nextInt();
			}

			students[i] = new Student(temp_usn, temp_name, credits, temp_grades);
		}

		for(int i = 0; i < students.length; i++){
			System.out.println("The SGPA of student " + i+1 + " is " + students[i].give_sgpa());
		}
	}
};
