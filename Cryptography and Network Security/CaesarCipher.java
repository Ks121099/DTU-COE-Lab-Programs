import java.util.Scanner;
public class CaesarCipher 
{ 
    public static String encryption(String text, int k) 
    { 
        String result="";
        for (int i=0; i<text.length(); i++) 
        { 
            if (Character.isUpperCase(text.charAt(i))) 
            { 
                char ch = (char)(((int)text.charAt(i)+k-65)%26+65); 
                result+=ch; 
            } 
            else
            { 
                char ch = (char)(((int)text.charAt(i)+k-97)%26+97); 
                result+=ch; 
            } 
        } 
        return result; 
    } 
    public static String decryption(String text, int k) 
    { 
        String result=encryption(text, 26-k);
        return result; 
    }
    public static void main(String[] args) 
    { 
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter the input text:");
        String text = myObj.nextLine();
        System.out.println("Enter the key to shift:");
        int k= myObj.nextInt();
        String encrypt=encryption(text, k).toString();
        System.out.println("Text          : " + text); 
        System.out.println("Shift         : " + k); 
        System.out.println("Encrypted Text: " + encrypt);
        System.out.println("Decrypted Text: " + decryption(encrypt,k));
    } 
}