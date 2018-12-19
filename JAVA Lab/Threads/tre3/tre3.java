class Callme {
    void func(String message) {
        System.out.print("[");
        try {
            Thread.sleep(500);
            System.out.print(message);
        } catch(InterruptedException e) {
            System.out.println(e);
        }
        System.out.print("]\n");
    }
}

class Caller implements Runnable {
    Thread t;
    Callme target;
    String msg;
    Caller(Callme obj, String s) {
        t = new Thread(this);
        target = obj;
        msg = s;
        t.start();
    }

    public void run() {
        target.func(msg);
    }
}

class Tre3 {
    public static void main(String args[]) {
        Callme target = new Callme();
        Caller obj1 = new Caller(target, "one");
        Caller obj2 = new Caller(target, "two");
        Caller obj3 = new Caller(target, "three");


    }
}