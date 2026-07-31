#include <stdio.h>

int gcd(int a, int b){  //函数名小写，变量名和函数名不冲突
    if (a < 0)a = -a;
	if (b < 0)b = -b;
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
    return a;
}

struct rational{
    int numerator, denominator;
};

int numerator(struct rational z){
    return z.numerator;
}

int denominator(struct rational z){
    return z.denominator;
}

struct rational make_rational(int numerator, int denominator){
    if(denominator == 0){
        printf("Denominator must be not equal to zero.\n");
        return make_rational(0, 1);
    }
    if(denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }
    int gcd_value = gcd(numerator, denominator);
    struct rational z;
    z.numerator = numerator / gcd_value;
    z.denominator = denominator / gcd_value;
    return z;
}

struct rational add_rational(struct rational a, struct rational b){
    return make_rational(numerator(a) * denominator(b) + numerator(b) * denominator(a), denominator(a) * denominator(b));
}

struct rational sub_rational(struct rational a, struct rational b){
    return make_rational(numerator(a) * denominator(b) - numerator(b) * denominator(a), denominator(a) * denominator(b));
}

struct rational mul_rational(struct rational a, struct rational b){
    return make_rational(numerator(a) * numerator(b), denominator(a) * denominator(b));
}

struct rational div_rational(struct rational a, struct rational b){
    if(numerator(b) == 0){
        printf("Cannot divide by zero.\n");
        return make_rational(0, 1);
    }
    return make_rational(numerator(a) * denominator(b), denominator(a) * numerator(b));
}

void print_rational(struct rational z){
    if(numerator(z) != 0){
        printf("rational = %d/%d\n", numerator(z), denominator(z));
    }else{
        printf("rational = 0\n");
    }
}

int main(void){
    struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));
    struct rational c = make_rational(2,4);
    struct rational d = make_rational(3,6);
    print_rational(c);
    print_rational(d);
    make_rational(1, 0);
    struct rational e = make_rational(1,-2);
    struct rational f = make_rational(-6,8);
    struct rational g = make_rational(-6,-8);

    print_rational(e);
    print_rational(f);
    print_rational(g);
    
	return 0;
}