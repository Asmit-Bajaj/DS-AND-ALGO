/*Experiment : 46
 * This is a simulator game of snake and ladder
 */

using namespace std;

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>

class game	//The game class
{
	int pos,dice;
	int stats[100],N;
public:
	game (){pos= 1;N=0;}
	void take_turn(string);
	void update_score(string);	//member function
	int show();
	int display();
	//void stat(string s);
};

void game :: take_turn(string c)	//takes the turn
{
	dice = (rand()%10)+1;
                if(dice>4)
                    dice = dice-4;
	cout<<"     ! "<<c<<" got :  "<<dice<<endl<<endl;
}

void game :: update_score(string c)	//updates the current score
{
	if(dice+pos>100)
	{
		cout<<"Sorry "<<c<<" can't move in this turn"<<endl<<endl;
	}
	else
	{
		pos = pos + dice;
	}

	switch(pos)
	{
		case 32 : cout<<"** oops : "<<c<<"! got bitten by the snake down to 6 **"<<endl<<endl;
			  pos  = 6;
			 break;
		case 74 : cout<<"** oops : "<<c<<"! got bitten by the snake down to 22 **"<<endl<<endl;
                          pos  = 22;
                         break;
		case 86 : cout<<"** oops : "<<c<<"! got bitten by the snake down to 51 **"<<endl<<endl;
                          pos  = 51;
                         break;
		case 99 : cout<<"** oops : "<<c<<"! got bitten by the snake down to 2 **"<<endl<<endl;
                          pos  = 2;
                         break;
		case 18 : cout<<"** ooh : "<<c<<"! got a ladder up to 64 **"<<endl<<endl;
                          pos  = 64;
                         break;
		case 16 : cout<<"** ooh : "<<c<<"! got a ladder up  to 45 **"<<endl<<endl;
                          pos  = 45;
                         break;
		case 48 : cout<<"** ooh : "<<c<<"! got a ladder up to 66 **"<<endl<<endl;
                          pos  = 66;
                         break;
		case 9 : cout<<"** ooh : "<<c<<"! got a ladder up to 31 **"<<endl<<endl;
                          pos  = 31;
                         break;
		case 50 : cout<<"** ooh : "<<c<<"! got a ladder up to 93 **"<<endl<<endl;
                          pos  = 93;
                         break;
		case 63 : cout<<"** ooh : "<<c<<"! got a ladder up to 81 **"<<endl<<endl;
                          pos  = 81;
                         break;

	}
	//stats[N] = pos;
	//N++;
	
}

int game :: display()	//displays the position
{
	return pos;
}
int game :: show()	//check for game completion
{
	if(pos == 100)
		return 1;
	else 
		return 0;
}
	
/*void game :: stat(string s)
{
cout<<endl<<endl<<"The stats position of winning player ( "<<s<<" ) are as follows : "<<endl<<endl;
for(int i=0;i<N;i++)
{
	cout<<"Position : "<<stats[i]<<endl;
}
cout<<endl<<endl;
}*/

int main()
{
	game s1,s2;
	//srand(time(NULL));
	int u=0,c=0;
	int a = 0;
	//int seed = 1;

while(a<200)
{
	//srand(seed);
	cout<<endl<<"**** Welcome to the snake-ladder game! ****"<<endl;
	cout<<"**** Instruction : It is similar to that as played in real world *****"<<endl<<endl;
	//cout<<"*Enter your name : ";
	string user = "asmit";
	//getline(cin,user);	//takes the name

	cout<<endl<<user<<"!Welcome to the game.Your are playing againts the computer!"<<endl;
	cout<<"**** Both players are at position 1 and 1 currently ****"<<endl;
	cout<<"**** Here the game starts ****";

	while(1)
	{
		cout<<endl<<endl<<"Your turn : Press 'R' to roll the dice ";
		char ch;
		int x;
		//cin>>ch;
		s1.take_turn(user);	//takes the turn
		s1.update_score(user);	//updates the score
		 x = s1.show();		//check for game completion
	
		if(x == 1)
		{
			cout<<"congrats "<<user<<"! You won"<<endl<<endl;
			//s1.stat(user);
			u++;
			break;
		}
		cout<<"Computer's turn : computer rolling dice"<<endl;
		s2.take_turn("Computer");
		s2.update_score("Computer");
		x = s2.show();
		if(x == 1)
                {
                        cout<<"oh "<<user<<"! You lose the game"<<endl<<endl;
			//s2.stat("Computer");
			c++;
                        break;
                }
		cout<<"** Current position : ** "<<endl<<"* "<<user<<" at : "<<s1.display()<<endl;
		cout<<"* Computer at : "<<s2.display();

 	}
	//cout<<endl<<"user : "<<u<<endl<<"computer : "<<c;
	//cout<<endl<<endl<<endl;
	a++;
	//seed++;
}
	 cout<<endl<<"user : "<<u<<endl<<"computer : "<<c;
	cout<<endl<<endl<<endl;
 
	return 0;
}