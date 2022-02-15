#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
//�����ַ�
#define ROW 10    //�ı���������ֵ�ɸı����̴�С
#define COL 10
 
//��ʼ����������
void InitBoard(char(*Board)[COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Board[i][j] = ' ';
		}
	}
}
 
//��ӡ���̼���������
void Display_Board(char Board[ROW][COL]) {
	system("cls");
	int i = 0, j = 0;
	printf("   ");
	for (i = 0; i < COL; i++) {
		if (i < COL - 1)
			printf(" %d |", i + 1);
		else
			printf(" %d ", i + 1);
	}
	printf("\n\n");
	for (i = 0; i < ROW; i++) {
		
		 if (i < ROW - 1) {
			for (j = 0; j < COL; j++) {
				if (j == 0)
					printf("%d   %c |", i + 1, Board[i][j]);
				else if (j < COL - 1) {
					printf(" %c |", Board[i][j]);
				}
				else
					printf(" %c \n", Board[i][j]);
			}
		}
		else {
			for (j = 0; j < COL; j++) {
				if (j == 0&&ROW<10)
					printf("%d   %c |", i + 1, Board[i][j]);
				else if(j==0)
					printf("%d  %c |", i + 1, Board[i][j]);
				else if (j < COL - 1) {
					printf(" %c |", Board[i][j]);
				}
				else
					printf(" %c \n", Board[i][j]);
			}
		}
		
 
		 if (i < ROW - 1)
			 printf("- ");
		 else
			 printf("  ");
		if (i < ROW - 1) {
			for (j = 0; j < COL; j++) {
				if(j==0){
					printf(" ---|");
				}else if (j < COL - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
		
	}
}
 
//���һ����
void Player_one(char Board[ROW][COL]) {
	printf("Please player1 to enter the numbers of rows and columns:");
	int x, y;
	while (1) {
		scanf_s("%d%d", &x, &y);
		
		//�ж�����Ϸ���
		if (x <= ROW && y <= COL && x >= 1 && y >= 1) {
			//�ж������Ƿ�ռ��
			if (Board[x - 1][y - 1] == ' ') {
				Board[x - 1][y - 1] = 'X';
				printf("���һ����\n\n");
				Display_Board(Board);
				break;
			}
			else {
				printf("��λ���Ѿ�������Ŷ�����������壺");
			}
		}
		else {
			printf("You have entered an invalid symbol! Please re-enter:");
		}
	}
	
}
 
//��Ҷ�����
void Player_two(char Board[ROW][COL]) {
	printf("Please player2 to enter the numbers of rows and columns:");
	int x, y;
	while (1) {
		scanf_s("%d%d", &x, &y);
 
		//�ж�����Ϸ���
		if (x <= ROW && y <= COL && x >= 1 && y >= 1) {
			//�ж������Ƿ�ռ��
			if (Board[x - 1][y - 1] == ' ') {
				Board[x - 1][y - 1] = 'O';
				printf("��Ҷ�����\n");
				Display_Board(Board);
				break;
			}
			else {
				printf("��λ���Ѿ�������Ŷ�����������壺");
			}
		}
		else {
			printf("You have entered an invalid symbol! Please re-enter:");
		}
	}
 
}
 
//��������
void Computer(char Board[ROW][COL]) {
 
	while (1) {
		int x = rand() % ROW;
		int y = rand() % COL;
		//�ж��Ƿ�ռ��
		if (Board[x][y] == ' ') {
			Board[x][y] = 'O';
			printf("��������\n\n");
			Display_Board(Board);
			break;
		}
	}
}
 
//�ж���Ϸ״̬
char check_win(char Board[ROW][COL]) {
	
 
	//�ж���
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Board[i][j] == Board[i][j + 1] && Board[i][j] == Board[i][j + 2] 
				&& Board[i][j] == Board[i][j + 3]
				&& Board[i][j] == Board[i][j + 4]
				&& Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//�ж���
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL; j++) {
			if (Board[i][j] == Board[i+1][j] && Board[i][j] == Board[i+2][j]
				&& Board[i][j] == Board[i + 3][j] 
				&& Board[i][j] == Board[i + 4][j] 
				&& Board[i][j] != ' ') {
 
				return Board[i][j];
			}
		}
	}
	//�ж���Խ���
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Board[i][j] == Board[i+1][j+1] && Board[i][j] == Board[i+2][j+2]
				&& Board[i][j] == Board[i + 3][j + 3] 
				&& Board[i][j] == Board[i + 4][j + 4]
				&& Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//�ж��ҶԽ���
	for (int i = 0; i < ROW-4 ; i++) {
		for (int j = 4; j < COL; j++) {
			if (Board[i][j] == Board[i - 1][j - 1] && Board[i][j] == Board[i - 2][j - 2]
				&& Board[i][j] == Board[i - 3][j - 3] 
				&& Board[i][j] == Board[i - 4][j - 4] && Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//�ж������Ƿ�����
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (Board[i][j] == ' ')
				return 'g';
		}
	}
 
	return 'p';
}
 
void menu() {
	system("cls");
	printf("********************\n");
	printf("***** 1.play one ***\n");
	printf("***** 2.play two ***\n");
	printf("***** 3.exit *******\n");
	printf("********************\n");
}
 
 
void game() {
 
	//�洢��������-��ά����   
	char Board[ROW][COL];  //����ֻ���������ݣ�����������û�б�Ҫ����д�������ͺ�����һ����
 
	//��ʼ����������
	InitBoard(Board, ROW, COL);
 
	//��ӡ���̺���������
	Display_Board(Board);
	
	
	char sign;
	while (1) {
		
		//���һ ���� ���ж���Ϸ�Ƿ����
		Player_one(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
	    
		//�������� ���ж���Ϸ�Ƿ����
		Computer(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
	}
	
	
		//�ж�ʤ����
	if (sign == 'X')
		printf("Player_one is a winer!\n");
	else if (sign == 'O')
		printf("Computer is a winer!\n");
	else
		printf("There are no losers here!\n");
	printf("��������ص����˵�");
	getch();
}
 
void game_two() {
 
	//�洢��������-��ά����   
	char Board[ROW][COL];  //����ֻ���������ݣ�����������û�б�Ҫ����д�������ͺ�����һ����
 
	//��ʼ����������
	InitBoard(Board, ROW, COL);
 
	//��ӡ���̺���������
	Display_Board(Board);
 
 
	char sign;
	while (1) {
 
		//���һ ���� ���ж���Ϸ�Ƿ����
		Player_one(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
		//��Ҷ����� ���ж���Ϸ�Ƿ����
		Player_two(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
	}
 
 
	//�ж�ʤ����
	if (sign == 'X')
		printf("Player_one is a winer!\n");
	else if (sign == 'O')
		printf("Computer is a winer!\n");
	else
		printf("There are no losers here!\n");
	printf("��������ص����˵�");
	getch();
}
 
int main(void) {
	srand((unsigned int)time(NULL));
 
	
	int chose_menu;
	do {
		//��ӡĿ¼
		menu();
		printf("���������Ҫ��");
 
 
		//�����û�ѡ��������
		
		scanf_s("%d", &chose_menu);
		switch (chose_menu) {
		case 1:
			printf("The game is loading,please wait patiently\n");
			game();
			break;
		case 2:
			game_two();
			break;
		case 3:
			printf("The game is exiting!\n");
			break;
		default:
			printf("You have entered an invalid symbol! Please re-enter:\n");
			break;
		}
	} while (chose_menu != 3);
	
	return 0;
 
	
	
}
