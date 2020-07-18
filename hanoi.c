
#include <stdio.h>
#include <string.h>


void hanoi(int , int , int* , int* , int*);

int fin = 0,count = 0;

int main(void)
{
    int n , t , i=0 , tower[3][17] ,a=0,b=0,c=0;
    char ans[3][40] = { "" , "" , ""} , p[40];

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
        if(a==0) sprintf(ans[0], "%d", i+1);
        else {
            strcpy(p,ans[0]);
            sprintf(ans[0], "%s %d",p , i+1);
        }
        a++;
      }

      if(tower[1][i]==1){
        if(b==0) sprintf(ans[1], "%d", i+1);
        else {
            strcpy(p,ans[1]);
            sprintf(ans[1], "%s %d",p , i+1);
        }
        b++;
      }
      if(tower[2][i]==1){
        if(c==0) sprintf(ans[2], "%d", i+1);
        else {
            strcpy(p,ans[2]);
            sprintf(ans[2], "%s %d",p , i+1);
        }
        c++;
      }
        i--;
    }


    if(strcmp(ans[0],"")==0) strcpy(ans[0],"-");
    if(strcmp(ans[1],"")==0) strcpy(ans[1],"-");
    if(strcmp(ans[2],"")==0) strcpy(ans[2],"-");

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
