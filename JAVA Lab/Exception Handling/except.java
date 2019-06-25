// ALSO STUDY CREATING YOUR OWN EXCEPTION

class Except {
    public static void main(String[] args) {
        int a = 0;
        try {
            // if(a == 0)
            //     throw new Exception("lol");
            int d[] = {2};
            d[3] = 10;
            System.out.println(d);
            int c = 5/a;
        } catch(ArithmeticException e) {
            System.out.println("AE: " + e);
        }
        catch(Exception e) {
            System.out.println(e);
        }
    }
}