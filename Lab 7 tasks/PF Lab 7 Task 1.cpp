#include <stdio.h>
int main(){
 int a[3][3],b[2][2],co[3][3],adj[3][3];
 int i,j,r,c,x,y,det=0;
 float inv[3][3];
 printf("Enter 3x3 matrix:\n");
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   scanf("%d",&a[i][j]);
  }
 }
 printf("\nTranspose:\n");
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   printf("%d ",a[j][i]);
  }
  printf("\n");
 }
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   x=0;
   for(r=0;r<3;r++){
    if(r==i){
     continue;
    }
    y=0;
    for(c=0;c<3;c++){
     if(c==j){
      continue;
     }
     b[x][y]=a[r][c];
     y++;
    }
    x++;
   }
   if((i+j)%2==0){
    co[i][j]=b[0][0]*b[1][1]-b[0][1]*b[1][0];
   }
   else{
    co[i][j]=-(b[0][0]*b[1][1]-b[0][1]*b[1][0]);
   }
  }
 }
 printf("\nCofactor Matrix:\n");
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   printf("%d ",co[i][j]);
  }
  printf("\n");
 }
 for(j=0;j<3;j++){
  det=det+a[0][j]*co[0][j];
 }
 printf("\nDeterminant = %d\n",det);
 printf("\nAdjoint Matrix:\n");
 for(i=0;i<3;i++){
  for(j=0;j<3;j++){
   adj[i][j]=co[j][i];
   printf("%d ",adj[i][j]);
  }
  printf("\n");
 }
 if(det==0){
  printf("\nInverse does not exist.\n");
 }
 else{
  printf("\nInverse Matrix:\n");
  for(i=0;i<3;i++){
   for(j=0;j<3;j++){
    inv[i][j]=(float)adj[i][j]/det;
    printf("%.2f ",inv[i][j]);
   }
   printf("\n");
  }
 }
 return 0;
}
