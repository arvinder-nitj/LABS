#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float> &arr, int n)
{
  // Create n empty buckets
  vector<float> b[n];

  //  Put array elements in different

  for (int i=0; i<n; i++)
  {
    int bi = n*arr[i]; // Index in bucket
    b[bi].push_back(arr[i]);
  }

  // Sort individual buckets
  for (int i=0; i<n; i++)
    sort(b[i].begin(), b[i].end());

  // Concatenate all buckets into arr[]
  int index = 0;
  arr.clear();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < b[i].size(); j++)
      arr.push_back(b[i][j]);
}

void bucketSortMixed(float arr[], int n)
{
  vector<float>Neg ;
  vector<float>Pos;

  for (int i=0; i<n; i++)
  {
    if (arr[i] < 0)

      // store -Ve elements by
      // converting into +ve element
      Neg.push_back (-1 * arr[i]) ;
    else
      // store +ve elements
      Pos.push_back (arr[i]) ;
  }

  bucketSort(Neg, (int)Neg.size());
  bucketSort(Pos, (int)Pos.size());


  for (int i=0; i < Neg.size(); i++)
    arr[i] = -1 * Neg[ Neg.size() -1 - i];

  for(int j=Neg.size(); j < n; j++)
    arr[j] = Pos[j - Neg.size()];
}

int main()
{
  float arr[] = {-0.897, 0.565, 0.656,
        -0.1234, 0, 0.3434};
  int n = sizeof(arr)/sizeof(arr[0]);
  bucketSortMixed(arr, n);

  cout << "Sorted array is \n";
  for (int i=0; i<n; i++)
    cout << arr[i] << " -> ";
  return 0;
}
