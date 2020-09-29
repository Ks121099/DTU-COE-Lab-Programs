import java.util.*;
import java.util.Scanner;
public class polyalpha
{ 
static String generateKey(String str, String key) 
{ 
    int x = str.length();  
    for (int i = 0; ; i++) 
    { 
        if (x == i) 
            i = 0; 
        if (key.length() == str.length()) 
            break; 
        key+=(key.charAt(i)); 
    } 
    return key; 
} 
  
static String cipherText(String str, String key) 
{ 
    String cipher_text=""; 
  
    for (int i = 0; i < str.length(); i++) 
    { 
        int x = (str.charAt(i) + key.charAt(i)) %26; 
        x += 'A';   
        cipher_text+=(char)(x); 
    } 
    return cipher_text; 
} 

static String Decrypt(String cipher_text, String key) 
{ 
    String orig_text=""; 
    for (int i = 0 ; i < cipher_text.length() && i < key.length(); i++) 
    { 
        int x = (cipher_text.charAt(i) - key.charAt(i) + 26) %26;  
        x += 'A'; 
        orig_text+=(char)(x); 
    } 
    return orig_text; 
} 
  
public static void main(String[] args)  
    { 
    final Scanner sc = new Scanner(System.in);
    System.out.println("Enter plaintext");
    final String str = sc.nextLine();
    System.out.println("Enter keyword");
    final String keyword = sc.nextLine();
    
    String key = generateKey(str, keyword); 
    String cipher_text = cipherText(str, key);
    System.out.println("Plain Text     : " + str); 
    System.out.println("Keyword        : " + keyword);
    System.out.println("Key            : " + key + "\n");  
    System.out.println("Ciphered  Text : " + cipher_text + "\n"); 
    System.out.println("Decrypted Text : " + Decrypt(cipher_text, key)); 
    sc.close();
    } 
} 
