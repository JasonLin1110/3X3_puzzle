#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int num=0;
    scanf("%d",&num);
    int i=0,j=0,k=0,p1[3][3]={0},p2[3][3]={0},element=0,line=0;
    for(i=0;i<num;i++){
        for(j=0;j<3;j++){
            scanf("%d",&line);
            for(k=0;k<3;k++){
                if(k==0){
                    element=line/100;
                }
                if(k==1){
                    element=(line%100)/10;
                }
                if(k==2){
                    element=line%10;
                }
                p1[j][k]=element;
            }
        }
        for(j=0;j<3;j++){
            scanf("%d",&line);
            for(k=0;k<3;k++){
                if(k==0){
                    element=line/100;
                }
                if(k==1){
                    element=(line/10)%10;
                }
                if(k==2){
                    element=line%10;
                }
                p2[j][k]=element;
            }
        }
        int p=0,tmp=0,key=0,puzzle1[9][2]={0},puzzle2[9][2]={0},l=0,m=0,n=0,a=0,b=0;
        for(p=0;p<3;p++){
            key=1;
            m=0;
            n=0;
            for(j=0;j<4;j++){
                for(k=0;k<3;k++){
                    if(p1[j][k]==0){
                        puzzle1[m][0]=j;
                        puzzle1[m][1]=k;
                        m++;
                    }
                    if(p2[j][k]==2){
                        puzzle2[n][0]=j;
                        puzzle2[n][1]=k;
                        n++;
                    }
                }
            }
            if(m==n){
                a=puzzle2[0][0]-puzzle1[0][0];
                b=puzzle2[0][1]-puzzle1[0][1];
                for(l=0;l<m;l++){
                    if((puzzle2[l][0]-puzzle1[l][0])!=a || (puzzle2[l][1]-puzzle1[l][1])!=b){
                        key=0;
                        break;
                    }
                }
            }
            else{
                key=0;
                break;
            }
            if(key==1){
                break;
            }
            else{
                tmp=p2[0][1];
                p2[0][1]=p2[1][0];
                p2[1][0]=p2[2][1];
                p2[2][1]=p2[1][2];
                p2[1][2]=tmp;
                tmp=p2[0][0];
                p2[0][0]=p2[2][0];
                p2[2][0]=p2[2][2];
                p2[2][2]=p2[0][2];
                p2[0][2]=tmp;
            }
        }
        if(key==1){
            printf("YES\n");
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    if(p1[j][k]==1){
                        printf("1");
                    }
                    else{
                        printf("2");
                    }
                }
                if(j!=2){
                    printf("\n");
                }
            }
        }
        else{
            printf("NO");
        }
        if(i!=num-1){
            printf("\n");
        }
        j=0;
        k=0;
    }
    return 0;
}
