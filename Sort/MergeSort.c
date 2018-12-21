#include <stdio.h>
#include <stdlib.h>
/* merge sort ¦X¨Ö±Æ§Ç */

void merge(int* a,int i1,int j1,int i2,int j2){

    int temp[50];	// new run
    int k=0;	// index for new run
    int i,j;	// beginning of two runs , prevent to influence the orignal value
    i=i1;
    j=i2;
    
    while(i<=j1 && j<=j2){ //select min from two run put to new temp run
        if(a[i]<a[j]){ 
            //printf("1. temp[%d]=a[%d]=%d;\n",k,i,a[i]);
            temp[k]=a[i];
            k++,i++;
        }else{
            //printf("2. temp[%d]=a[%d]=%d;\n",k,j,a[j]);
			temp[k]=a[j];
            k++,j++;
		}
    }
    
    while(i<=j1){    //copy remaining  of the first run
        //printf("3. temp[%d]=a[%d]=%d;\n",k,i,a[i]);
        temp[k]=a[i];
        k++,i++;
    }
	
    while(j<=j2){   //copy remaining  of the second run
        //printf("4. temp[%d]=a[%d]=%d;\n",k,j,a[j]);
        temp[k]=a[j];
        k++,j++;
    }    
    
    for(i=i1,j=0;i<=j2;i++,j++){	//Transfer elements from temp[] back to a[]
        a[i]=temp[j];
        printf("New set :a[%d]=%d ,temp[%d]=%d;\n",i,a[i],j,temp[j]);
	}
}

void mergesort(int* a,int l,int r){
    int m;
    if(l<r){
        m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        printf("Call merge :l=%d,m=%d,m+1=%d,r=%d\n",l,m,m+1,r);
        merge(a,l,m,m+1,r);	//merging of two sub-arrays
        printf("\n");
    }
}

main(void){

    int i,n,a[30];
    
    printf("Merge sort\n");
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");

    for(i=0;i<n;i++){
        printf("%d th data: ",i+1);
        scanf("%d",&a[i]);
    }
    
    mergesort(a,0,n-1);

    printf("\nSorted list: \n\n");

    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    system("pause");
}