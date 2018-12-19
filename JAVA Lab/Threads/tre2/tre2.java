class NewThread extends Thread {
    NewThread() {
        super("Demo Thread");
        System.out.println("Child Thread" + this);
        start();
    }

    public void run() {
        try {
            for(int i=5; i>0; i--) {
                System.out.println("Child Thread " + Thread.currentThread().getName() + " " + i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            System.out.println("Child Interrupted");
        }
        System.out.println("Exiting Child Thread");
    }
}

class ExtendThread {
    public static void main(String[] args) {
        new NewThread();

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