import java.io.*;
import java.net.*;
import java.util.*;
 class Client2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception
    {
        // TODO code application logic here
       
            Socket s=new Socket("localhost",12344);
        DataOutputStream dos=new DataOutputStream(s.getOutputStream());
        DataInputStream din=new DataInputStream(s.getInputStream());
        String str;
        Scanner sc=new Scanner(System.in);
        while(true)
        {
        str=din.readUTF();
        System.out.println(str);
        str=sc.nextLine();
        dos.writeUTF(str);
        }
       
        
    }
    
}
