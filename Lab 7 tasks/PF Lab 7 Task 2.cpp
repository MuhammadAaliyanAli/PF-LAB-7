#include <stdio.h>
int main(){
 int a[5][5],b[5][5],mul[5][5]={0};
 int r,c,i,j,k,zero=1,identity=1,diagonal=1;
 int scalar=1,upper=1,lower=1,symmetric=1,skew=1;
 int equal=1,idempotent=1,nilpotent=1;
 int detZero=0,detNonZero=0;
 int n,p,q,sign,det;
 int temp[5][5],minor[5][5],x,y;
 int choice;

 printf("Enter rows and columns: ");
 scanf("%d%d",&r,&c);
 if(r<1||r>5||c<1||c>5){
  printf("Invalid size");
  return 0;
 }
 printf("Enter matrix:\n");
 for(i=0;i<r;i++){
  for(j=0;j<c;j++){
   scanf("%d",&a[i][j]);
  }
 }

 if(r==c){
  printf("Square Matrix\n");
 }
 else{
  printf("Rectangular Matrix\n");
 }
 if(r==1){
  printf("Row Matrix\n");
 }
 if(c==1){
  printf("Column Matrix\n");
 }

 for(i=0;i<r;i++){
  for(j=0;j<c;j++){
   if(a[i][j]!=0){
    zero=0;
   }
  }
 }
 if(zero==1){
  printf("Zero Matrix\n");
  printf("Null Matrix\n");
 }

 if(r==c){
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    if(i==j){
     if(a[i][j]!=1){
      identity=0;
     }
     if(a[i][j]!=a[0][0]){
      scalar=0;
     }
    }
    else{
     if(a[i][j]!=0){
      identity=0;
      diagonal=0;
      scalar=0;
     }
    }
    if(i>j&&a[i][j]!=0){
     upper=0;
    }
    if(i<j&&a[i][j]!=0){
     lower=0;
    }
    if(a[i][j]!=a[j][i]){
     symmetric=0;
    }
    if(a[i][j]!=-a[j][i]){
     skew=0;
    }
   }
  }

  if(identity==1){
   printf("Identity Matrix\n");
  }
  if(diagonal==1){
   printf("Diagonal Matrix\n");
  }
  if(scalar==1){
   printf("Scalar Matrix\n");
  }
  if(upper==1){
   printf("Upper Triangular Matrix\n");
  }
  if(lower==1){
   printf("Lower Triangular Matrix\n");
  }
  if(symmetric==1){
   printf("Symmetric Matrix\n");
  }
  if(skew==1){
   printf("Skew-Symmetric Matrix\n");
  }

  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    for(k=0;k<c;k++){
     mul[i][j]+=a[i][k]*a[k][j];
    }
   }
  }

  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    if(mul[i][j]!=a[i][j]){
     idempotent=0;
    }
    if(mul[i][j]!=0){
     nilpotent=0;
    }
   }
  }
  if(idempotent==1){
   printf("Idempotent Matrix\n");
  }

  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    temp[i][j]=a[i][j];
   }
  }
  nilpotent=0;
  for(n=1;n<=r;n++){
   int allZero=1;
   for(i=0;i<r;i++){
    for(j=0;j<c;j++){
     if(temp[i][j]!=0){
      allZero=0;
     }
    }
   }
   if(allZero==1){
    nilpotent=1;
    break;
   }
   for(i=0;i<r;i++){
    for(j=0;j<c;j++){
     mul[i][j]=0;
     for(k=0;k<c;k++){
      mul[i][j]+=temp[i][k]*a[k][j];
     }
    }
   }
   for(i=0;i<r;i++){
    for(j=0;j<c;j++){
     temp[i][j]=mul[i][j];
    }
   }
  }
  if(nilpotent==1){
   printf("Nilpotent Matrix\n");
  }

  det=0;
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    temp[i][j]=a[i][j];
   }
  }
  
  double d[5][5],factor,swap;
  int swaps=0;
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    d[i][j]=a[i][j];
   }
  }
  for(i=0;i<r;i++){
   p=i;
   for(j=i+1;j<r;j++){
    if(d[p][i]==0&&d[j][i]!=0){
     p=j;
    }
   }
   if(d[p][i]==0){
    detZero=1;
    break;
   }
   if(p!=i){
    for(j=0;j<r;j++){
     swap=d[i][j];
     d[i][j]=d[p][j];
     d[p][j]=swap;
    }
    swaps++;
   }
   for(j=i+1;j<r;j++){
    factor=d[j][i]/d[i][i];
    for(k=i;k<r;k++){
     d[j][k]-=factor*d[i][k];
    }
   }
  }
  if(detZero==1){
   printf("Singular Matrix\n");
  }
  else{
   printf("Non-Singular Matrix\n");
  }
 }
 printf("Compare with another matrix? (1=Yes, 0=No): ");
 scanf("%d",&choice);
 if(choice==1){
  printf("Enter second matrix:\n");
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    scanf("%d",&b[i][j]);
   }
  }
  for(i=0;i<r;i++){
   for(j=0;j<c;j++){
    if(a[i][j]!=b[i][j]){
     equal=0;
    }
   }
  }
  if(equal==1){
   printf("Equal Matrix\n");
  }
  else{
   printf("Matrices are not equal\n");
  }
 }
 return 0;
}
