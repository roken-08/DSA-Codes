#include <stdio.h>


int min_element(int stack[],int n){
    int top = n-1;
    int ans = stack[top];
    for(int i = top; i>= 0; i--){
        if(stack[i] < ans){
            ans = stack[i];
        }
        
    }
    return ans;
}

int main(){
    int n = 0;
    printf("Enter Stack size: ");
    scanf("%d",&n);
    int stack[n];
    printf("Enter Stack Elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&stack[i]);
    }
    printf("Minimum Element in Stack is : %d",min_element(stack,n));
}