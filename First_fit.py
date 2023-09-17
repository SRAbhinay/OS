def first_fit(blockSize, processSize):
    m = len(blockSize)
    n = len(processSize)
    allocation = [-1] * n

    for i in range(n):
        for j in range(m):
            if blockSize[j] >= processSize[i]:
                allocation[i] = j
                blockSize[j] -= processSize[i]
                break

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

first_fit(blockSize, processSize)
