#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };

struct complex_struct {
    enum coordinate_type t;
    double a, b;
};

double real_part(struct complex_struct z){
    switch(z.t){
        case RECTANGULAR:
            return z.a;
        case POLAR:
            return z.a * cos(z.b);
    }
}

double img_part(struct complex_struct z){
    switch(z.t){
        case RECTANGULAR:
            return z.b;
        case POLAR:
            return z.a * sin(z.b);
    }
}

double magnitude(struct complex_struct z){
    switch(z.t){
        case RECTANGULAR:
            return sqrt(z.a * z.a + z.b * z.b);
        case POLAR:
            return z.a;
    }
}

double angle(struct complex_struct z){
    switch(z.t){
        case RECTANGULAR:
            return atan2(z.b , z.a);
        case POLAR:
            return z.b;
    }
}

struct complex_struct make_from_real_img(double x, double y){
    struct complex_struct z;
    z.t = RECTANGULAR;
    z.a = x;
    z.b = y;
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A){
    struct complex_struct z;
    z.t = POLAR;
    z.a = r;
    z.b = A;
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_mag_ang(magnitude(z1) * magnitude(z2), angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_mag_ang(magnitude(z1) / magnitude(z2), angle(z1) - angle(z2));
}

void print_complex(struct complex_struct z){
    double x = real_part(z);//不用反复调用
    double y = img_part(z);
    if(fabs(x) > 1e-10){
        if(y > 0.0){
            printf("z = %.1f+%.1fi", x, y);
        }else if(y < 0.0){
            printf("z = %.1f%.1fi", x, y);
        }else{
            printf("z = %.1f", x);
        }
    }else{
        if(fabs(y) > 1e-10){   //可以合并为!=0.0;
            printf("z = %.1fi", y);
        }else{
            printf("z = 0.0");
        }
    }
}

int main(void){
    // 测试1：直角坐标创建
    struct complex_struct z1 = make_from_real_img(3, 4);

    printf("z1:\n");
    print_complex(z1);
    printf("\n");

    printf("real = %.1f\n", real_part(z1));
    printf("imag = %.1f\n", img_part(z1));
    printf("magnitude = %.1f\n", magnitude(z1));
    printf("angle = %.3f\n\n", angle(z1));


    // 测试2：极坐标创建
    struct complex_struct z2 = make_from_mag_ang(5, atan2(4,3));

    printf("z2:\n");
    print_complex(z2);
    printf("\n");

    printf("real = %.1f\n", real_part(z2));
    printf("imag = %.1f\n", img_part(z2));
    printf("magnitude = %.1f\n", magnitude(z2));
    printf("angle = %.3f\n\n", angle(z2));


    // 测试3：加法
    struct complex_struct add = add_complex(z1,z2);

    printf("z1 + z2 = ");
    print_complex(add);
    printf("\n");


    // 测试4：减法
    struct complex_struct sub = sub_complex(z1,z2);

    printf("z1 - z2 = ");
    print_complex(sub);
    printf("\n");


    // 测试5：乘法
    struct complex_struct mul = mul_complex(z1,z2);

    printf("z1 * z2 = ");
    print_complex(mul);
    printf("\n");


    // 测试6：除法
    struct complex_struct div = div_complex(z1,z2);

    printf("z1 / z2 = ");
    print_complex(div);
    printf("\n");


    return 0;
}