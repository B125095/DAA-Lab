#include<stdio.h>
typedef struct{
   int id;
   double v,w,lamda;
   double q,density,fraction;
}iteam;
void swap(iteam *a,iteam *b){
    iteam t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n;
    double W,total=0;
    printf("enter how many number of iteam:\n");
    scanf("%d",&n);
    printf("Enter the maximum weight that can taken :\n");
    scanf("%lf",&W);
    iteam a[n];
    for(int i=0;i<n;i++){
        a[i].id=i+1;
        printf("Enter the %dth iteam(v,w,lamda):\n",i+1);
        scanf("%lf %lf %lf",&a[i].v,&a[i].w,&a[i].lamda);
        a[i].q=a[i].w*a[i].lamda;
        a[i].fraction=0;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].q<a[j].q)swap(&a[i],&a[j]);
        }
    }
    for(int i=0;i<n;i++){
        a[i].density=a[i].v/a[i].w - a[i].lamda*(i+1);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].density<a[j].density)swap(&a[i],&a[j]);
        }
    }
    for(int i=0;i<n && W>0;i++){
        if(a[i].density<=0)break;

        if(a[i].w<=W){
            a[i].fraction=1;
           W-=a[i].w;

        }
        else{
            a[i].fraction=W/a[i].w;
            W=0;
        }
        total+=a[i].fraction*a[i].w*a[i].density;
        printf("iteam %d : fraction =%,2lf,density=%.2lf\n",a[i].id,a[i].fraction,a[i].density);

    }
    printf("\n Maximum value= %.2lf\n",total);


    return 0;
}