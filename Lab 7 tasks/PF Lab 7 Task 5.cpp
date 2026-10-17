#include <stdio.h>
int main(){
 int a[3][3][3];
 int i,j,k,y,same;
 printf("Enter 27 elements:\n");
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   for(k=0;k<3;k++){
    scanf("%d",&a[i][j][k]);
   }
  }
 }
 for(i=0;i<3;i++){
  printf("\nLayer %d:\n",i+1);
  for(j=0;j<3;j++){
   for(k=0;k<3;k++){
    printf("%d ",a[i][j][k]);
   }
   printf("\n");
  }
 }
 for(int i=0;i<3;i++){
  for(y=i+1;y<3;y++){
   same=1;
   for(j=0;j<3;j++){
    for(k=0;k<3;k++){
     if(a[i][j][k]!=a[y][j][k]){
      same=0;
     }
    }
   }
   if(same==1){
    printf("\nLayer %d and Layer %d are identical",i+1,y+1);
   }
   else{
    printf("\nLayer %d and Layer %d are different",i+1,y+1);
   }
  }
 }
 return 0;
}