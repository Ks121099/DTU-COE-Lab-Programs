import java.util.*;
import java.util.Scanner;
public class hillcipher { 
public static void getKeyMatrix(String key, int keyMatrix[][]) 
{ 
    int k = 0; 
    for (int i = 0; i < 3; i++)  
    { 
        for (int j = 0; j < 3; j++)  
        { 
            keyMatrix[i][j] = (key.charAt(k)) % 65; 
            k++; 
        } 
    } 
} 
public static void encrypt(int cipherMatrix[][],int keyMatrix[][], int messageVector[][]) 
{ 
    int x, i, j; 
    for (i = 0; i < 3; i++)  
    { for (j = 0; j < 1; j++) 
        {   
            cipherMatrix[i][j] = 0; 
            for (x = 0; x < 3; x++) 
            { 
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j]; 
            } 
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26; 
        } 
    } 
} 

public static String HillCipher(String message, String key) 
{ 
    int [][]keyMatrix = new int[3][3]; 
    getKeyMatrix(key, keyMatrix); 
    int [][]messageVector = new int[3][1]; 
    for (int i = 0; i < 3; i++) 
        messageVector[i][0] = (message.charAt(i)) % 65; 
    int [][]cipherMatrix = new int[3][1]; 
    encrypt(cipherMatrix, keyMatrix, messageVector); 
    String CipherText=""; 
    for (int i = 0; i < 3; i++) 
        CipherText += (char)(cipherMatrix[i][0] + 65); 
    return CipherText; 
} 
public static void main(String[] args)  
{ 
    final Scanner sc = new Scanner(System.in);
    System.out.println("Enter plaintext");
    final String message = sc.nextLine();
    System.out.println("Enter keyword");
    final String key = sc.nextLine();
    String c=HillCipher(message, key); 
    System.out.println("Plain Text   :"+ message);
    System.out.println("Key          :"+ key);
    System.out.println("Cipher Text  :"+ c);
    sc.close();
} 
} 