#include <stdio.h>
int main(){
 int a[3][3],b[3][3],mul[3][3];
 int r1,c1,r2,c2,i,j,k;
 printf("Enter rows and columns of first matrix: ");
 scanf("%d%d",&r1,&c1);
 printf("Enter rows and columns of second matrix: ");
 scanf("%d%d",&r2,&c2);
 if(r1<1||r1>3||c1<1||c1>3||r2<1||r2>3||c2<1||c2>3){
  printf("Invalid dimensions");
  return 0;
 }
 if(c1!=r2){
  printf("Matrix multiplication not possible");
  return 0;
 }
 printf("Enter first matrix:\n");
 for(i=0;i<r1;i++){
  for(j=0;j<c1;j++){
   scanf("%d",&a[i][j]);
  }
 }
 printf("Enter second matrix:\n");
 for(i=0;i<r2;i++){
  for(j=0;j<c2;j++){
   scanf("%d",&b[i][j]);
  }
 }
 for(i=0;i<r1;i++){
  for(j=0;j<c2;j++){
   mul[i][j]=0;
   for(k=0;k<c1;k++){
    mul[i][j]+=a[i][k]*b[k][j];
   }
  }
 }
 printf("\nFirst Matrix:\n");
 for(i=0;i<r1;i++){
  for(j=0;j<c1;j++){
   printf("%d ",a[i][j]);
  }
  printf("\n");
 }
 printf("\nSecond Matrix:\n");
 for(i=0;i<r2;i++){
  for(j=0;j<c2;j++){
   printf("%d ",b[i][j]);
  }
  printf("\n");
 }
 printf("\nMultiplication Result:\n");
 for(i=0;i<r1;i++){
  for(j=0;j<c2;j++){
   printf("%d ",mul[i][j]);
  }
  printf("\n");
 }
 return 0;
}