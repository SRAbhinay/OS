#include <stdio.h>
int main()
{
int proc_no, resour_no, i, j, k;
proc_no = 5;
resour_no = 3;
int allocate[5][3] = { { 0, 1, 0 },
{ 2, 0, 0 },
{ 3, 0, 2 },
{ 2, 1, 1 },
{ 0, 0, 2 } };
int maximum[5][3] = { { 7, 5, 3 },
{ 3, 2, 2 },
{ 9, 0, 2 },
{ 2, 2, 2 },
{ 4, 3, 3 } };
int available[3] = { 3, 3, 2 };
int f[proc_no], ans[proc_no], ind = 0;
for (k = 0; k < proc_no; k++) {
f[k] = 0;
}
int need[proc_no][resour_no];
for (i = 0; i < proc_no; i++) {
for (j = 0; j < resour_no; j++)
need[i][j] = maximum[i][j] - allocate[i][j];
}
int y = 0;
for (k = 0; k < 5; k++) {
for (i = 0; i < proc_no; i++) {
if (f[i] == 0) {
int flag = 0;
for (j = 0; j < resour_no; j++) {
if (need[i][j] > available[j]){
flag = 1;
break;
}
}
if (flag == 0) {
ans[ind++] = i;
for (y = 0; y < resour_no; y++)
available[y] += allocate[i][y];
f[i] = 1;
}
}
}
}
int flag = 1;
for(int i=0;i<proc_no;i++)
{
if(f[i]==0)
{
flag=0;
printf("Not safe");
break;
}
}
if(flag==1)
{
printf("SAFE Sequence\n");
for (i = 0; i < proc_no - 1; i++)
printf("P%d ->", ans[i]);
printf(" P%d\n", ans[proc_no - 1]);
}
return (0);
}