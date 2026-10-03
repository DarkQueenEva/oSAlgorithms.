#include <stdio.h>

int main()
{
    int n, bt[20], rt[20], tq, time = 0, remain, i;
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    printf("Enter burst times\n");
    for(i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    i = 0;

    printf("\nProcess\tBurst\tTurnaround\tWaiting\n");

    while(remain > 0)
    {
        if(rt[i] > 0)
        {
            if(rt[i] <= tq)
            {
                time += rt[i];
                rt[i] = 0;

                printf("P[%d]\t%d\t%d\t\t%d\n",
                       i + 1, bt[i], time, time - bt[i]);

                tat += time;
                wt += time - bt[i];
                remain--;
            }
            else
            {
                rt[i] -= tq;
                time += tq;
            }
        }

        i = (i + 1) % n;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)tat / n);

    return 0;
}