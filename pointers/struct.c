#include <stdio.h>
struct bike{
    char *name;
    float price;
    int speed;
};

int main(void){
    // struct bike a={.name="honda",.price=1000,.speed=200};
    struct bike b={.price=2000,.speed=250};
    printf("Name: %s\n", b.name);
    printf("Price: %f\n", b.price);
    printf("Speed: %d\n", b.speed);
    set_names(&b, "yamaha");
    printf("New_Name: %s\n", b.name);
}

void set_names(struct bike *b, char *new_name){
    // (*b).name=new_name;
    b->name=new_name;
}
