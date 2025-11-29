
import java.io.*;
import java.util.*;

class CoinCollection {
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // Max Heap
    static int coins = 0;

    public static void main(String args[]) {
        CoinCollection ob = new CoinCollection();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char ch[][] = new char[n][n];

        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for (int j = 0; j < n; j++)
                ch[i][j] = s.charAt(j);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[i][j] == 'C') {
                    ob.DFS(i, j, ch, n);
                    pq.add(coins);
                    coins = 0;
                }
            }
        }

        int player1 = 0, player2 = 0;
        int c = 0;
        while (!pq.isEmpty()) {
            if (c % 2 == 0)
                player1 += pq.poll();
            else
                player2 += pq.poll();
            c++;
        }

        System.out.print(player1 + " " + player2);
    }

    void DFS(int i, int j, char ch[][], int n) {
        if (i < 0 || j < 0 || i >= n || j >= n || ch[i][j] == 'N')
            return;

        coins++;

        ch[i][j] = 'N';
        DFS(i + 1, j, ch, n);
        DFS(i - 1, j, ch, n);
        DFS(i, j + 1, ch, n);
        DFS(i, j - 1, ch, n);
    }
}