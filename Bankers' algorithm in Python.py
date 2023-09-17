if __name__ == "__main__":
    proc_no = 5
    resour_no = 3
    alloc = [[0, 1, 0],
             [2, 0, 0],
             [3, 0, 2],
             [2, 1, 1],
             [0, 0, 2]]
    max = [[7, 5, 3],
           [3, 2, 2],
           [9, 0, 2],
           [2, 2, 2],
           [4, 3, 3]]
    avail = [3, 3, 2]
    f = [0] * proc_no
    ans = [0] * proc_no
    ind = 0
    for k in range(proc_no):
        f[k] = 0
    need = [[0 for i in range(resour_no)] for i in range(proc_no)]
    for i in range(proc_no):
        for j in range(resour_no):
            need[i][j] = max[i][j] - alloc[i][j]
    y = 0
    for k in range(5):
        for i in range(proc_no):
            if f[i] == 0:
                flag = 0
                for j in range(resour_no):
                    if need[i][j] > avail[j]:
                        flag = 1
                        break
                if flag == 0:
                    ans[ind] = i
                    ind += 1
                    for y in range(resour_no):
                        avail[y] += alloc[i][y]
                    f[i] = 1
    print("A SAFE Sequence")
    for i in range(proc_no - 1):
        print("P", ans[i], " ->", sep="", end="")
    print(" P", ans[proc_no - 1], sep="")
