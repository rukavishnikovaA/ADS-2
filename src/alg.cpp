// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
 int n = 0;
  for( int i = 0; i < len-1; i++)
  {
    for( int j = i + 1; j < len; j++)
    {
    if (arr[i] + arr[j] == value)
    n++;
    }
  }
return n;
}
int countPairs2(int *arr, int len, int value) {
 unsigned int n = 0, i = 0, l = 0, r = len - 1;
    while (l<r) {
        i = 1;
        while (true) {
            if (arr[r] > value || arr[l] + arr[r] > value) {
                r--;
            } else {
                break;
            }
        }
        while (l+ i <= r) {
            if (arr[l] + arr[l + i] == value) n++;
            i++;
        }
        l++;
    }
    return n;
}
int countPairs3(int *arr, int len, int value) {
int n = 0;
  for( int i = 0; i < len - 1; i++)
  {
  int left = i, right = len;
    while (left < right-1)
    {
    int midle = (left + right) / 2;
      if (arr[i] + arr[midle] == value)
      {
      n++;
      int j = midle+1;
        while (arr[i] + arr[j] == value && j <right)
        {
        n++;
        j++;
        }
      j = midle - 1;
          while (arr[i] + arr[j] == value && j>left)
          {
          n++;
          j--;
          }
       break;
       }
          if (arr[i] + arr[midle] > value)
          right = midle;
          else
          left = midle;
     }
  }
return n;
}
