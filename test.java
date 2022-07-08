import java.util.Scanner;
import java.util.Stack;



class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int queries = scanner.nextInt();

        Stack<Integer>stack = new Stack<>();
        Stack<Integer>maxElements = new Stack<>();
        
        for(int i = 0; i<queries; i++) {
            int type = scanner.nextInt();
            if(type == 1) {
                int x = scanner.nextInt();
                stack.push(x);
                if(maxElements.empty() || maxElements.peek() <= x) {
                    maxElements.push(x);
                }

            } else if(type == 2) {
                if(maxElements.peek() == stack.pop()) {
                    maxElements.pop();
                }
            } else {
                System.out.println(maxElements.peek());
            }
        }

        scanner.close();

    }
}