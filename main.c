#include <stdio.h>
#include <stdlib.h>

char board_data[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char current_player = 'X';

void print_board()
{
	printf(
		"     |     |     \n"
		"  %c  |  %c  |  %c  \n"
		"-----|-----|-----\n"
		"  %c  |  %c  |  %c  \n"
		"-----|-----|-----\n"
		"  %c  |  %c  |  %c  \n"
		"     |     |     \n"
		"\n",
		board_data[0], board_data[1], board_data[2],
		board_data[3], board_data[4], board_data[5],
		board_data[6], board_data[7], board_data[8]
	      );
}

int check_won(char player)
{
	return ((board_data[0] & board_data[1] & board_data[2]) == player ||
		(board_data[3] & board_data[4] & board_data[5]) == player ||
		(board_data[6] & board_data[7] & board_data[8]) == player ||
		(board_data[0] & board_data[3] & board_data[6]) == player ||
		(board_data[1] & board_data[4] & board_data[7]) == player ||
		(board_data[2] & board_data[5] & board_data[8]) == player ||
		(board_data[0] & board_data[4] & board_data[8]) == player ||
		(board_data[2] & board_data[4] & board_data[6]) == player);
}

void ask_input()
{
	char input[80];
	int choice;

	while (1) {
		printf("Player %c: Input a number: ", current_player);

		fgets(input, 80, stdin);
		choice = atoi(input);

		if (choice < 1 || choice > 9 || board_data[choice-1] != ' ') continue;
		else {
			board_data[choice-1] = current_player;
			break;
		}
	}
}

void winning_message(char player)
{
	print_board();
	printf("%c has won this game! Congratulations!\n", player);
}

int main()
{
	int turn;
	for (turn = 0; turn < 9; turn++) {
		print_board();
		ask_input();
		if (check_won(current_player)) {
			winning_message(current_player);
			break;
		}
		current_player = current_player == 'X' ? 'O' : 'X';
	}
	return 0;
}
