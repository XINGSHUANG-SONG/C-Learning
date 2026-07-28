#include <stdio.h>

//int main(void) {
//	int a, b;
//	scanf("%d%d", &a, &b);
//	//printf("a = %d, b = %d.\n", a, b);
//	a = (a < 0 ? -a : a);
//	b = (b < 0 ? -b : b);
//	do {
//		if (a != 0 && b != 0 && a % b != 0) {
//			int temp = a % b;
//			a = b;
//			b = temp;
//			//printf("a = %d, b = %d.\n", a, b);
//		}
//	} while (a * b != 0 && a % b != 0);
//	if (a == 0 || b == 0)
//		b = (b == 0 ? a : b);
//	printf("GCD about a and b is %d.\n", b);
//	return 0;
//}
int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a == 0) {
		printf("GCD = %d\n", b);
		return 0;
	}
	if (b == 0) {
		printf("GCD = %d\n", a);
		return 0;
	}
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	printf("GCD = %d\n", a);
	return 0;
}