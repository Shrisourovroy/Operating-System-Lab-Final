import java.util.Scanner;

public class Q_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter number of processes: ");
        n = sc.nextInt();

        int[] pro = new int[n];
        int[] at = new int[n];
        int[] bt = new int[n];
        int[] ct = new int[n];
        int[] wt = new int[n];
        int[] tat = new int[n];


        for (int i = 0; i < n; i++) {
            pro[i] = i + 1;
            System.out.print("Enter Arrival Time and Burst Time for Process " + pro[i] + ": ");
            at[i] = sc.nextInt();
            bt[i] = sc.nextInt();
        }


        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (at[j] > at[j + 1]) {
                    int temp = at[j];at[j] = at[j + 1];at[j + 1] = temp;

                    temp = bt[j];bt[j] = bt[j + 1];bt[j + 1] = temp;

                    temp = pro[j];pro[j] = pro[j + 1];pro[j + 1] = temp;
                }
            }
        }

        int time = 0;
        double totalWT = 0;
        double totalTat = 0;

        System.out.print("\nGantt Chart: ");

        for (int i = 0; i < n; i++) {
            if (time < at[i]) {
                time = at[i];
            }

            wt[i] = time - at[i];
            tat[i] = wt[i] + bt[i];
            ct[i] =
            time += bt[i];
            totalWT += wt[i];
            totalTat += tat[i];

            System.out.print("| P" + pro[i] + " ");
        }

        System.out.println("|");
        System.out.println("\nProcess\tAT\tBT\tCT\tWT\tTAT");

        for (int i = 0; i < n; i++) {
            System.out.println("\tP" + pro[i] + "\t" + at[i] + "\t" + bt[i]+ "\t" + ct[i] + "\t" +wt[i] + "\t" + tat[i]);
        }

        System.out.println("Average Waiting Time = " + (totalWT / n));
        System.out.println("Average Turnaround Time = " + (totalTat / n));

        sc.close();
    }
}
