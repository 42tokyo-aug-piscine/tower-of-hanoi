
#include <stdio.h>

void hanoi(int , int , int* , int* , int*);

int fin = 0,count = 0;

int main(void)
{
    int n , t , i=0 , tower[3][17] ,a=0,b=0,c=0;
    char ans[3][40];

    scanf("%d %d",&n,&t);


      while(i<n){
        tower[0][i]=1;
        tower[1][i]=0;
        tower[2][i]=0;
        i++;
      }
      
    hanoi(n,t,tower[0],tower[1],tower[2]);

    i=n-1;
    while(i>=0){
      if(tower[0][i]==1){
        if(a==0) sprintf(ans[0], "%d", i);
        else sprintf(ans[0], "%s %d",ans[0] , i);
        a++;
      }
      if(tower[1][i]==1){
        if(b==0) sprintf(ans[1], "%d", i);
        else sprintf(ans[1], "%s %d",ans[1] , i);
        b++;
      }
      if(tower[2][i]==1){
        if(c==0) sprintf(ans[2], "%d", i);
        else sprintf(ans[2], "%s %d",ans[2] , i);
        c++;
      }
    }

    printf("%s\n%s\n%s\n",ans[0],ans[1],ans[2]);

    return 0;
}

void hanoi( int n , int t , int* a ,int* b ,int* c)
{
    if(n>=2)hanoi(n-1,t,a,c,b);

    int i = 0 ;

    if(fin == 0){
        while( i < 17 ){
            if(a[i] != 0)
            {
                c[i]=1;
                a[i]=0;
                break;
            }
            i++;
        }
    }

    count++;

    if( t == count )fin = 1;

    if(n>=2)hanoi(n-1,t,b,a,c);
    return ;
}
