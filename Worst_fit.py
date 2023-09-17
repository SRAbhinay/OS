def worst_fit(blockSize, processSize):
    m = len(blockSize)
    n = len(processSize)
    allocation = [-1] * n

    for i in range(n):
        worst_idx = -1
        for j in range(m):
            if blockSize[j] >= processSize[i]:
                if worst_idx == -1 or blockSize[j] > blockSize[worst_idx]:
                    worst_idx = j

        if worst_idx != -1:
            allocation[i] = worst_idx
            blockSize[worst_idx] -= processSize[i]

    print("\nProcess No.\tProcess Size\tBlock no.")
    for i in range(n):
        print(f" {i + 1}\t\t\t", end="")
        print(f"{processSize[i]}\t\t\t\t", end="")
        if allocation[i] != -1:
            print(f"{allocation[i] + 1}", end="")
        else:
            print("Not Allocated", end="")
        print("\n")

blockSize = [100, 500, 200, 300, 600]
processSize = [212, 417, 112, 426]

worst_fit(blockSize, processSize)
