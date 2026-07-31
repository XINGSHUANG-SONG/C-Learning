#include <stdio.h>
#include <math.h>

struct complex_struct {
    double x, y;
};

double real_part(struct complex_struct z){
    return z.x;
}

double img_part(struct complex_struct z){
    return z.y;
}

double magnitude(struct complex_struct z){
    return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z){
    return atan2(z.y , z.x);
}

struct complex_struct make_from_real_img(double x, double y){
    struct complex_struct z;
    z.x = x;
    z.y = y;
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A){
    struct complex_struct z;
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2){
    return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) +img_part(z2));
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
    if(x != 0.0){
        if(y > 0.0){
            printf("z = %.1f+%.1fi", x, y);
        }else if(y < 0.0){
            printf("z = %.1f%.1fi", x, y);
        }else{
            printf("z = %.1f", x);
        }
    }else{
        if(y != 0.0){   //可以合并为!=0.0;
            printf("z = %.1fi", y);
        }else{
            printf("z = 0.0");
        }
    }
}

int main(void){
    struct complex_struct z[] = {
        { 1.0,  0.0},   // 只有实部
        {-1.0,  0.0},   // 只有负实部
        { 0.0,  2.0},   // 只有正虚部
        { 0.0, -2.0},   // 只有负虚部
        {-1.0,  2.0},   // 负实部、正虚部
        { 1.0, -2.0},   // 正实部、负虚部
        { 1.0,  2.0},   // 正实部、正虚部
        {-1.0, -2.0},   // 负实部、负虚部
        { 0.0,  0.0}    // 实部和虚部都是0
    };

    int count = sizeof(z) / sizeof(z[0]);

    for(int i = 0; i < count; i++){
        printf("test: %d\n", i + 1);
        print_complex(z[i]);
        printf("\n");
    }

    struct complex_struct z1 =
        make_from_real_img(3,4);

    struct complex_struct z2 =
        make_from_real_img(1,-2);


    printf("z1=");
    print_complex(z1);
    printf("\n");


    printf("real part=%.1f\n", real_part(z1));
    printf("imag part=%.1f\n", img_part(z1));
    printf("magnitude=%.1f\n", magnitude(z1));
    printf("angle=%f\n", angle(z1));


    printf("add:");
    print_complex(add_complex(z1,z2));
    printf("\n");


    printf("sub:");
    print_complex(sub_complex(z1,z2));
    printf("\n");


    printf("mul:");
    print_complex(mul_complex(z1,z2));
    printf("\n");


    printf("div:");
    print_complex(div_complex(z1,z2));
    printf("\n");

    return 0;
}