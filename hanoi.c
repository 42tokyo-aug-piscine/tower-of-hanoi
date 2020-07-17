
#include <stdio.h>

void hanoi(int , int , int* , int* , int*);

int fin = 0,count = 0;

//動くには動きますが不要部分めちゃくちゃ多いです・・・多分半分くらいは短くできます笑
//とりあえずgithub使ってみたくてコード編集する前にあげちゃいましたので、時間あったら改訂版出します〜
//gitの使い方がむず過ぎて多分無理やけど・・・

int main(void)
{
    int n , t , i , a[17] , b[17] , c[17] ;

    scanf("%d %d",&n,&t);

    for(i = 0 ; i < n ; i++){
        a[i]=1;
        b[i]=0;
        c[i]=0;
    }

    hanoi(n,t,a,b,c);

    i = n-1 ;
    count=0;
    while( i >= 0 ){
        if( a[i] != 0 ) {
            printf("%d",i+1);
            break;
        }else count++;
        i--;
        if( count == n ) printf("-");
    }
     i--;
    while( i >= 0 ){
        if( a[i] != 0 ) printf(" %d",i+1);
        else count++;
        i--;
        if( count == n ) printf("-");
    }
    printf("\n");

    i = n-1 ;
    count=0;
    while( i >= 0 ){
        if( b[i] != 0 ) {
            printf("%d",i+1);
            break;
        }else count++;
         i--;
         if( count == n ) printf("-");
    }
     i--;
    while( i >= 0 ){
         if( b[i] != 0 ) printf(" %d",i+1);
         else count++;
         i--;
         if( count == n ) printf("-");
    }
    printf("\n");
    i = n-1 ;
    count=0;
    while( i >= 0 ){
        if( c[i] != 0 ){
            printf("%d",i+1);
            break;
        }
         else count++;
         i--;
         if( count == n ) printf("-");
    }
    i--;
    while( i >= 0 ){
         if( c[i] != 0 ) printf(" %d",i+1);
         else count++;
         i--;
         if( count == n ) printf("-");
    }
    printf("\n");
    return 0;
}

void hanoi( int n , int t , int* a ,int* b ,int* c)
{


    if(n>=2)hanoi(n-1,t,a,c,b);

    //a→c
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

    if( t == count ){
        fin = 1;
    }


    if(n>=2)hanoi(n-1,t,b,a,c);


    return ;
}
