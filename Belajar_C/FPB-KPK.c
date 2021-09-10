#include <stdio.h>

int fpb(int a, int b) {
      if (b==0) return a;
      else return fpb(b, a%b);
   }
int kpk (int a, int b){
    int r;
    r=a*b/fpb(a,b);
    return r;
}
int main () {
    int n,i,j,q,urut;
    scanf("%d",&n);
    int a[n];
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        a[i+1]=a[i+1]+a[i];
        //printf("%d", a[i]);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d",&urut);
        for(j=1;i<=n;i++){
            if(urut <= a[j]){
                printf("%d\n",j);break;
            }
        }
    }


}
