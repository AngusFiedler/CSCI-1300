#include <iostream>
using namespace std;

int check(int mydata[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum = sum + mydata[i];
  }
  return sum;
}
int main()
{
  int vdata[3];
  int rsum;
  for (int cnt = 0; cnt < 3; cnt++)
  {
    vdata[cnt] = cnt + 1;
  }
  rsum = check(vdata, 3);
  cout << rsum;
  return 0;
}
