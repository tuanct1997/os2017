//Nguyen Manh Tuan//
//USTHBI6-144//
//ICT-GEN6//

#include <unistd.h>
#include <stdio.h>

int main() {
	printf("Main before fork()\n");
	int pid = fork();
	if (pid == 0) {
		printf(" I am a child after fork()\n");
		char *args[]= { "/bin/ps","-ef" ,NULL};
		execvp("/bin/ps",args);
		printf("Finished launching ps -ef\n");
}
	else {
		printf("I am parent after fork(), child is %d\n",pid);
}
	int pid1 = fork();
	if (pid1 == 0) {
		printf("I am a child after fork()\n");
		char*args[]= { "free","-h",NULL};
		execvp("free",args);
		printf("Finished launching free -h\n");
}
	else {
		printf("I am parent after fork(), child is %d\n",pid1);
}
	return 0;
}
