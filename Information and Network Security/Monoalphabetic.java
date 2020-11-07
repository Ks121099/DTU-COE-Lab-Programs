import java.util.Scanner;
public class Monoalphabetic {

    private static final String alphabet = "abcdefghijklmnopqrstuvwxyz";
    private static final String Al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static String encrypt(String plaintext, String key) {
        String ciphertext = "";

        for (char chr : plaintext.toCharArray()) {
            if(Character.isUpperCase(chr))
            {
            byte position = (byte) Al.indexOf(chr);
            if (chr == ' ') {
                    ciphertext+=" ";
                } 
            else {
                    ciphertext+=Character.toUpperCase(key.charAt(position));
                    }
            }
            else
            {
                byte position = (byte) alphabet.indexOf(chr);
                if (chr == ' ') {
                        ciphertext+=" ";
                    } 
                else {
                        ciphertext+=key.charAt(position);
                     }
            }
        }
        return ciphertext;
    }
    
    public static String decrypt(String ciphertext, String key) {
        String plaintext ="";
        for (char chr : ciphertext.toCharArray()) {
            if(Character.isUpperCase(chr))
            {
            byte position = (byte) key.indexOf(Character.toLowerCase(chr));
            if (chr == ' ') {
                plaintext+=" ";
            } 
            else {
                plaintext+=Al.charAt(position);
                }
            }
            else
            {
                byte position = (byte) key.indexOf(chr);
                if (chr == ' ') {
                    plaintext+=" ";
                } 
                else {
                    plaintext+=alphabet.charAt(position);
                    }
            }
        }
        return plaintext;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        System.out.println("Enter the plain text:");
        String text = myObj.nextLine();
        String key="mnopqrstuvwxyzabcdefghijkl";
        System.out.println("\nKey                : "+key.toUpperCase()+"\nPlaintext          : "+text );
        String ciphertext=encrypt(text, key);
        System.out.println("Ciphertext message : "+ciphertext);
        System.out.println("Deciphered message : " +decrypt(ciphertext,key ));
    }
}