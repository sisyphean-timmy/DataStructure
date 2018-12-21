#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxsize 16
int bsta[maxsize];


void cbst(int len,int* data);
void pbst(void);
int LevelNodes(int level,int type); // type=0(total) means get 1~Level sum nodes ; type=1(single) means get the Level's nodes

main(void) {

    for(int i =0;i<maxsize;i++){bsta[i]=-1;} // inital the BST array

    int data[10]={0,5,6,4,8,2,3,7,1,9};

    cbst(10,data);
    pbst();

    system("pause");

}

void cbst(int len,int* data){
    bsta[1]=data[1]; // set root: node 1
    int cnt=2;// after root : node 2
    
    while(cnt<len){
        int index=1; // compare bsta[1(index)] == root
        
        while(bsta[index]!=-1){
            if(data[cnt]>bsta[index]){//right childe
                index = index*2+1;
            }else{//left childe
                index = index*2;
            }
        }
        bsta[index]=data[cnt];
        cnt++;
    }
    
}
void pbst(void){
    int cLevel=1; //from level 1
    int maxlevel = ceil(log(maxsize)/log(2));

    printf("BST:\n\n");

    while(cLevel<=maxlevel){

        printf("\n");

        int needSpace = (LevelNodes(maxlevel,1)-LevelNodes(cLevel,1))/2*3+1;
        int addSpace=0;
        for(addSpace;addSpace<needSpace;addSpace++){
            printf(" ");
        }

        int LevelStartIndex=LevelNodes(cLevel-1,0)+1;
        int LevelEndIndex=LevelNodes(cLevel,0);
        
        for(LevelStartIndex;LevelStartIndex<=LevelEndIndex;LevelStartIndex++){
            if(bsta[LevelStartIndex]==-1){
                printf(" x ");
            }else{
                printf(" %d ",bsta[LevelStartIndex]);
            }
        }
        cLevel++;
    }
    printf("\n\n");
}

int LevelNodes(int level,int type){
    int cnt=1;
    int amount=2;
    if(level==0){
        return 0;
    }else if(level==1){
        return 1;
    }else{
        if(type==0){
            while(cnt < level){ amount*=2; cnt++; }
            return amount-1;
        }else if(type==1){
            while(cnt < level-1){ amount*=2; cnt++; }
            return amount;
        }
    }
    
}