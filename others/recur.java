public class recur
{
    static int rec(int n)
    {
        if(n==0)
            return 1;
        else 
            return (rec(n-1)*n);
    }
    public static void main(String arg[])
    {
        int n=0;
        int result=rec(n);
        System.out.println(result);
    }
}