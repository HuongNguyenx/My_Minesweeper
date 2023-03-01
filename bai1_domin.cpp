#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int m, n, k;
int turn;
int choice1, choice2;
int myMap[100][100];
char mapShown[100][100];
int validChoice[100][100];
int x0[3] = {-1, 0, 1};
int y0[3] = {-1, 0, 1};
void bombLocation();
void updateMyMap();
void enterChoice();
bool checkChoice(int, int);
void buildMapShown();
void updateResult(int, int);
void printMapShown();
void printResult();

int main(){
	cin >> m >> n >> k;
	cout << "Please .... Waiting for playing!!!" << "\n";
	bombLocation();
	buildMapShown();
	do{
		enterChoice();
		system("cls");
		updateResult(choice1, choice2);
	} while (checkChoice(choice1, choice2) == true && turn < (m*n-k));
	
	if(checkChoice(choice1, choice2)) cout << "\n" << "You win!!" << "\n";
	else cout << "\n" << "You're dead!!!" << "\n";
	
	printResult();
	return 0;
}

void updateResult(int x, int y){
	if(myMap[x][y] == -1){
		mapShown[x][y] = '!';
	}
	else {
		mapShown[x][y] = char(myMap[x][y]+48);
		turn++;
	}
	printMapShown();
}

void printMapShown(){
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cout << mapShown[i][j] << " ";
		}
		cout << "\n";
	}
}

void buildMapShown(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			mapShown[i][j] = '*';
		}
	}
	printMapShown();
}

void enterChoice(){
	cout << "\n" << "Entering a grid you want to open: " << "\n";
	do{
		cin >> choice1 >> choice2;
	} while (validChoice[choice1][choice2] != 0 || choice1<1 || choice1>m || choice2<1 || choice2>n);
	
	validChoice[choice1][choice2] = 1;
}

bool checkChoice(int x, int y){
	if(myMap[x][y] == -1){
		return false;
	}
	return true;
}

void printResult(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(myMap[i][j] == -1){
				mapShown[i][j] = '!';
			}
			else{
				mapShown[i][j] = char(myMap[i][j]+48);
			}
		}
	}
	printMapShown();
}
void bombLocation(){
	int bombNum = 0;
	while(bombNum < k){
		srand(time(0));
		int x1 = rand()%m + 1;
		int y1 = rand()%n + 1;
		if(myMap[x1][y1] != -1){
			myMap[x1][y1] = -1;
			bombNum++;
		}
	}
	updateMyMap();
}
void updateMyMap(){
	int count;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			count = 0;
			if(myMap[i][j] != -1){
				for(int t=0; t<3; t++){
					for(int k=0; k<3; k++){
						if(myMap[i+x0[t]][j+y0[k]] == -1){
							count++;
						}
					}
				}
				myMap[i][j] = count;
			}
		}
	}
}
