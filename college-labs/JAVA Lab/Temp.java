import java.util.Arrays;

interface B {
    void prin3();
}

interface A extends B {
    void prin2();
}

public class Temp {
    static void prin() {
        System.out.println("lol");
    }
    public static void main(String args[]) {
        int arr[] = {2, 1, 3};
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        prin();
    }
}

class Another implements A{
    static void prin() {
        System.out.println("slick");
    }
    public void prin2() {
        int a = 20;
    }
    public void prin3() {
        System.out.println(2);
    }
}