#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int n1, n2, i, j, key = 0, total;
    char str1[100000], str2[100000], hasil[10000];
    char *pch, *ptr;
    //cin >> n1;
    char a[100][100];
    fgets(str1, sizeof(str1), stdin);
    //cin >> n2;
    char b[100][100];
    fgets(str2, sizeof(str2), stdin);
    //str tok
    pch = strtok (str1, " \n");
    i = 0;
    while (pch != NULL){
       strcpy(a[i], pch);
       ++i;
       pch = strtok (NULL, " \n"); 
    }

    ptr = strtok (str2, " \n");
    i = 0;
    while (ptr != NULL){
       strcpy(b[i], ptr);
       ++i;
       ptr = strtok (NULL, " \n"); 
    }
    n1 = atoi(a[0]);
    n2 = atoi(b[0]);
    //cout << n1 << endl;
    //cout << n2 << endl;

    /*for (i=1; i<=n2 ;i++)
      cout << b[i] << endl;
      */
    //compare
    for (i=1; i<=n1; i++){
      for (j=1; j<=n2; j++){
        if (strcmp(a[i], b[j]) == 0){
          key = 1;
          strcat(hasil, a[i]);
          strcat(hasil, " ");
        }
        
      }
    }
    
    if (key == 0)
      cout << "tidak ada kesamaan" << endl;
    else {
      total = strlen(hasil);
      for (i=0; i<total-1; i++){
        cout << hasil[i];
      }
      cout << endl;
    }
    return 0;
}
