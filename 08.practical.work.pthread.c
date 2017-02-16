//Nguyen Manh Tuan//
//ICT GEN 6//
//USTHBI6-144//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	}
item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	// do nothing -- nothing to consume
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void *threadFunction(void *param){
	item x1,x2,x3;
	x1.type = 0;
	x1.unit = 0;
	x1.amount = 10;
	x2.type = 1;
	x2.unit = 1;
	x2.amount = 200;
	x3.type = 0;
	x3.unit = 0;
	x3.amount = 20;
	printf("produce item 1: type = %c, unit = %c, amount = %d \n",x1.type,x1.unit,x1.amount);
	produce(&x1);
	printf("first = %d,last = %d\n", first,last);
	printf("produce item 2: type = %c, unit = %c, amount = %d \n",x2.type,x2.unit,x2.amount);
	produce(&x2);
	printf("first = %d,last = %d\n", first,last);
	printf("produce item 3: type = %c, unit = %c, amount = %d \n",x3.type,x3.unit,x3.amount);
	produce(&x3);
	printf("first = %d,last = %d\n", first,last);
}
void *consumethread(void *param){
	consume();
	printf("consume item: first = %d,last = %d \n", first ,last);
	consume();
	printf("continue consume : first = %d,last = %d \n", first, last);
	return 0;
}
int main(){
	pthread_t tid1,tid2;
	pthread_create(
	&tid1,
	NULL,
	threadFunction,
	NULL);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,NULL,consumethread,NULL);
	pthread_join(tid2,NULL);
	return 0;	
}
