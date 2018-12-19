class Tre1 implements Runnable {
    Thread t1;

    Tre1() {
        t1 = new Thread(this, "New Thread");
        System.out.println("Child Thread" + t1);
        t1.start();
    }

    public void run() {
        try {
            for (int i = 5; i > 0; i--) {
                System.out.println("Child Thread " + Thread.currentThread().getName() + " " + i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            System.out.println("Child Interrupted");
        }
    }
}

class ThreadDemo {
    public static void main(String[] args) {
        new Tre1();

        try {
            for (int i = 5; i > 0; i--) {
                System.out.println("Main Thread " + Thread.currentThread().getName() + " " + i);
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            System.out.println("Main Interrupted");
        }
        System.out.println("Exiting Main");
    }
}