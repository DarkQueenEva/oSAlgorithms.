int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20];
    int i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;

    // Input total number of processes
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    printf("\nEnter Burst Time and Priority for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("\nP[%d]: ", i + 1);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority(Lower number means higher priority): ");
        scanf("%d", &pr[i]);

        p[i] = i + 1; // Process number
    }

    // Sort by priority using selection sort
    for(i = 0; i < n; i++)
    {
        pos = i;

        for(j = i + 1; j < n; j++)
        {
            if(pr[j] < pr[pos])
            {
                pos = j;
            }
        }

        // Swap priority
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        // Swap burst time
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process number
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // First process has zero waiting time
    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++)
    {
        wt[i] = 0;

        for(j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }

        total += wt[i];
    }

    avg_wt = (float)total / n;
    total = 0;

    // Display table header
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");