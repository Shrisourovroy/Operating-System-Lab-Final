import java.util.Scanner;

public class Q_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        int[] pro = new int[n];
        int[] at = new int[n];
        int[] bt = new int[n];
        int[] pr = new int[n];
        int[] ct = new int[n];
        int[] rt = new int[n];

        int complete = 0;
        int t = 0;
        int[] wt = new int[n];
        int[] tat = new int[n];

        double totalWT = 0;
        double totalTAT = 0;


        for (int i = 0; i < n; i++) {
            System.out.println("\nProcess P" + (i + 1) + ":");

            System.out.print("Arrival Time: ");
            at[i] = sc.nextInt();

            System.out.print("Burst Time: ");
            bt[i] = sc.nextInt();

            System.out.print("Priority (Lower number = Higher priority): ");
            pr[i] = sc.nextInt();

            pro[i] = i + 1;
            rt[i] = bt[i];
        }
        System.out.println("\nGantt Chart:");
        System.out.print("| ");

        int prev = -1;


        while (complete != n) {
            int highest = -1;

            for (int i = 0; i < n; i++) {
                if (at[i] <= t && rt[i] > 0) {
                    if (highest == -1 || pr[i] < pr[highest]) {
                        highest = i;
                    }
                }
            }

            if (highest == -1) {
                t++;
                continue;
            }
            if (prev != highest) {
                System.out.print("P" + pro[highest] + " | ");
                prev = highest;
            }

            rt[highest]--;
            t++;

            if (rt[highest] == 0) {
                complete++;

                int finishTime = t;
                tat[highest] = finishTime - at[highest];
                wt[highest] = tat[highest] - bt[highest];

                totalWT += wt[highest];
                totalTAT += tat[highest];

            }
        }

        System.out.println("\n\nProcess\tAT\tBT\tPR\tCT\tWT\tTAT");

        for (int i = 0; i < n; i++) {
            System.out.println("\tP" + pro[i] + "\t" + at[i] + "\t" + bt[i]+ "\t" + pr[i] + "\t" + ct[i] + "\t" +wt[i] + "\t" + tat[i]);
        }

        System.out.println("\nAverage Waiting Time: " + (totalWT / n));
        System.out.println("Average Turnaround Time: " + (totalTAT / n));

        sc.close();



    }
}
