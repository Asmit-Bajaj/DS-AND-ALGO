#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void main(){
	int noStates,noInput,temp1,temp2,i,j;
	int bufferSize,noFinalStates;
	int **mat;
	int *inputBuffer;
	int *finalState;
	int curr_state,startState;
	int flag = 1;
	int recog = 0;

	clrscr();
	printf("Enter the Number of States This Dfa have : ");
	scanf("%d",&noStates);

	printf("\nEnter the number of Input Symbols : ");
	scanf("%d",&noInput);

	mat = malloc(sizeof(int)*noStates);

	for(i=0;i<noStates;i++){
	  mat[i] = malloc(sizeof(int)*noInput);
	}

	for(i=0;i<noStates;i++){
		for(j=0;j<noInput;j++){
			mat[i][j] = -1;
		}
	}



	printf("\n\nEnter the transitions for each state as (inputSymbol(int only) transitionState) : ");

	for(i=0;i<noStates;i++){
		printf("\n\nEnter the transition for State - %d\n",i);
		for(j=0;j<noInput;j++){
			scanf("%d %d",&temp1,&temp2);
			mat[i][temp1] = temp2;
		}
	}

	printf("\n\n");
	for(i=0;i<noStates;i++){
		for(j=0;j<noInput;j++){
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}

	printf("\nHow many final states are there : ");
	scanf("%d",&noFinalStates);

	printf("\nEnter the final states : ");

	finalState = malloc(sizeof(int)*noFinalStates);

	for(i=0;i<noFinalStates;i++){
	      scanf("%d",&finalState[i]);
	}

	printf("\nEnter the starting state : ");
	scanf("%d",&startState);

	while(flag == 1){
		printf("\nEnter the size of Input Buffer : ");
		scanf("%d",&bufferSize);

		printf("Now Enter the input buffer as integer only (0,1,2,3,...)\n");

		inputBuffer = malloc(sizeof(int)*bufferSize);
		recog = 0;

		for(i=0;i<bufferSize;i++){
			scanf("%d",&inputBuffer[i]);
		}

		curr_state = startState;

		for(i=0;i<bufferSize;i++){
			curr_state = mat[curr_state][inputBuffer[i]];
		}

		for(i=0;i<noFinalStates;i++){
			if(finalState[i] == curr_state){
				recog = 1;
				break;
			}
		}
		printf("\n The current state : %d\n",curr_state);
		if(recog == 1)
			printf("\nString is Recognized\n");
		else
			printf("\nString is not recognized\n");

		printf("Do you Want to check more input buffers? (0/1) : ");
		scanf("%d",&flag);

	}

	getch();
}