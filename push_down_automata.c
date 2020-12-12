#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int stack[100];

struct trans{
    int input;
    int stack_sym;
    int operation;
    int state;
};

void main(){
    int acc_mode,i,temp,j;
    struct trans **state_matrix;
    int init_state;
    int states;
    struct trans ts;
    int final_state;
    int input_buffer[100];
    int curr_state;
    int *no_of_trans;
    stack[0] = -1;
    int flag;
    int ch = 1;
    int top = 0;
    
   
    printf("\nEnter The No. Of States : ");
    scanf("%d",&states);
    
    state_matrix = malloc(states * sizeof(struct trans *));
    no_of_trans = malloc(sizeof(int)*states);
    
    for(i=0;i<states;i++){
        printf("\nEnter The Number Of Transitions For State : %d ",(i+1));
        scanf("%d",&temp);
        no_of_trans[i] = temp;
        printf("Enter The Transitons as follows :- input symbol(0,1,2...) stack symbol(-1,0,1,...) operation(1 for pop and 2 for push and 3 for nothing) state : \n");
        state_matrix[i] = malloc(sizeof(struct trans)*temp);
        
        for(j=0;j<temp;j++){
            //ts = malloc(sizeof(struct trans));
            scanf("%d %d %d %d",&ts.input,&ts.stack_sym,&ts.operation,&ts.state);
            state_matrix[i][j] = ts;
        }
    }
    
    for(i=0;i<states;i++){
        for(j=0;j<no_of_trans[i];j++){
            printf("%d %d %d %d\n",state_matrix[i][j].input,state_matrix[i][j].stack_sym,state_matrix[i][j].operation,state_matrix[i][j].state);
        }
        printf("\n\n");
    }
    
    printf("\nEnter the initial state : ");
    scanf("%d",&init_state);
      

    while(ch == 1){
        printf("Enter The Size of Input String : ");
        scanf("%d",&temp);
        printf("\nEnter The String (0,1,2...) : ");
    
        curr_state = init_state;
    
        for(i=0;i<temp;i++){
        scanf("%d",&input_buffer[i]);
        }
    

    stack[0] = -1;
    top = 0;
    
    for(i=0;i<temp;i++){
        flag = 0;
        for(j=0;j<no_of_trans[curr_state];j++){
            if(state_matrix[curr_state][j].input == input_buffer[i] && state_matrix[curr_state][j].stack_sym == stack[top]){
                if(state_matrix[curr_state][j].operation == 2){
                    //printf("hello");
                    stack[++top] = state_matrix[curr_state][j].input;
                    flag = 1;
                    curr_state = state_matrix[curr_state][j].state;
                    break;
                }else if(state_matrix[curr_state][j].operation == 1){
                    top--;
                    flag =1;
                    curr_state = state_matrix[curr_state][j].state;
                    break;
                }else if(state_matrix[curr_state][j].operation == 3){
                    flag = 1;
                    curr_state = state_matrix[curr_state][j].state;
                }
                
            }
        }
        if(flag == 0)
            break;
    }
    
    if(flag == 0){
        printf("\nString Not Accepted");
    }else{
        if(stack[top] == -1){
            printf("\nString is accepted");
        }else{
            printf("\nString Not Accepted");
        }
    }

    printf("\nDo You want to continue : (1 for yes and 2 for no) : ");
    scanf("%d",&ch);
    }
   
}