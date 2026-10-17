#include <stdio.h>
int main(){
 int a[3][3][3],sum[3]={0};
 int i,j,k,total=0,max,min;
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
    sum[i]+=a[i][j][k];
   }
   printf("\n");
  }
  printf("Layer Sum = %d\n",sum[i]);
  total+=sum[i];
 }
 max=0;
 min=0;
 for(i=1;i<3;i++){
  if(sum[i]>sum[max]){
   max=i;
  }
  if(sum[i]<sum[min]){
   min=i;
  }
 }
 printf("\nOverall Sum = %d\n",total);
 printf("Highest Sum: Layer %d = %d\n",max+1,sum[max]);
 printf("Lowest Sum: Layer %d = %d\n",min+1,sum[min]);
 return 0;
}