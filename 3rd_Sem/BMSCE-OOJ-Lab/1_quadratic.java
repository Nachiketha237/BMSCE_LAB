import java.util.*;
import java.lang.Math;
 
class Quadratic{
   public static void main(String args[]){
       Scanner sc = new Scanner(System.in);
 
       System.out.println("Enter the values of a, b, c for the quadratic equation:");
       double a = sc.nextDouble();
       double b = sc.nextDouble();
       double c = sc.nextDouble();
 
       double discriminent = b*b-4*a*c;
 
       if(discriminent > 0){
           double result1 = (-b+Math.sqrt(discriminent))/(2*a);
           double result2 = (-b-Math.sqrt(discriminent))/(2*a);
           System.out.println("The roots are real and distinct: " + result1 + " and " + result2);
       }
       else if(discriminent == 0){
           double result = (-b+discriminent)/(2*a);
           System.out.println("The roots are real and same: " + result);
       }
       else{
           double realPart = -b/(2*a);
           double imaginaryPart = Math.sqrt(Math.abs(discriminent))/(2*a);
 
           System.out.println("The roots are imaginary: " + realPart + "+i" + imaginaryPart + " " + realPart + "-i" + imaginaryPart);
       }
   }
}
