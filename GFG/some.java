import java.io.*;
public class Sample {
    public Sample()
    {
        System.out.println ("Printing One");
        return;
    }

    public void Sample()
    {
        System.out.println ("Printing two");
        return;
    }

    public static void main(String[] args)
    {
        Sample sample = new Sample();
    }
}