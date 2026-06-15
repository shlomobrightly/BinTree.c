//practicing forks in linux

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//aplying a recursive approach

void build_tree(int curr_depth, int max_depth, int is_left) {
	if (curr_depth == 1) {
		printf("Parent PID: %d\n", getpid());
	}
	else {
		if (is_left) {
			printf("Left child: Procccess PID: %d, Parent PID: %d\n", getpid(), getppid());
		}
		else {
			printf("Right child: Procccess PID: %d, Parent PID: %d\n", getpid(), getppid());
		}
	}

	if (curr_depth >= max_depth) {
		return;
	}

	int left_pid = fork();

	if (left_pid < 0) {
		printf("left fork error\n");
		exit(1);
	}
	else if (left_pid == 0) {
		build_tree(curr_depth +1, max_depth, 1);
		exit(0);
	}

	int right_pid = fork();

	if (right_pid < 0) {
		printf("right fork error\n");
		exit(1);
	}
	else if (right_pid == 0) {
		build_tree(curr_depth + 1, max_depth, 0);
		exit(0);
	}

	wait(NULL);
	wait(NULL);
}


int main(int argc, char *argv[]) {
	//program name + number
	if (argc != 2) {
		printf("argument error\n");
		return 1;
	}

	int mDepth = atoi(argv[1]);

	if (mDepth < 1) {
		printf("depth must be at least 1\n");
		return 1;
	}

	biuld_tree(1, mDepth, 0);

	return 0;
}

