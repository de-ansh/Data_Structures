/*#include <iostream>
#include <climits>
using namespace std;
int knapSack(int v[], int w[], int n, int W) {
   if (W < 0)
      return INT_MIN;
   if (n < 0 || W == 0)
      return 0;
   int in = v[n] + knapSack(v, w, n - 1, W - w[n]);
   int ex = knapSack(v, w, n - 1, W);
   return max (in, ex);
}
int main() {
   int v[] = { 10, 6, 5, 1 };
   int w[] = { 9, 6, 7,3 };
   int W = 16;
   int n = sizeof(v) / sizeof(v[0]);
   cout << "Knapsack value is " << knapSack(v, w, n - 1, W);
   return 0;
}*/
#include <bits/stdc++.h>
int max(int a, int b) { return (a > b) ? a : b; }
// Prints the items which are put in a knapsack of capacity W
void printknapSack(int W, int wt[], int val[], int n) {
   int i, w;
   int K[n + 1][W + 1];
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++) {
      for (w = 0; w <= W; w++) {
         if (i == 0 || w == 0)
            K[i][w] = 0;
         else if (wt[i - 1] <= w)
            K[i][w] = max(val[i - 1] +
            K[i - 1][w - wt[i - 1]], K[i - 1][w]);
         else
            K[i][w] = K[i - 1][w];
      }
   }
   // stores the result of Knapsack
   int res = K[n][W];
   printf("maximum value=%d\n", res);
   w = W;
   printf("weights included\n");
   for (i = n; i > 0 && res > 0; i--) {
      if (res == K[i - 1][w])
         continue;
      else {
         printf("%d ", wt[i - 1]);
         res = res - val[i - 1];
         w = w - wt[i - 1];
      }
   }
}
// main code
int main() {
   int val[] = { 10, 6, 5,1 };
   int wt[] = { 9, 6, 7,3 };
   int W = 16;
   int n = sizeof(val) / sizeof(val[0]);
   printknapSack(W, wt, val, n);
   return 0;
}