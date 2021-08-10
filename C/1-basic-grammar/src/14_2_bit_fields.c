/* 位字段示例 */
#include <stdio.h>
#include <stdbool.h> //c99定义了bool、true、false


#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (GREEN|RED)
#define MAGENTA (BLUE|RED)
#define CYAN (BLUE|GREEN)
#define WHITE (BLUE|GREEN|RED)

const char * colors[] = {
     "black", "red", "green", "yellow","blue", "magenta", "cyan", "white" };

struct box_props {
    bool opaque :1;
    unsigned int fill_color :3;
    unsigned int :4;
    bool show_border :1;
    unsigned int border_color :3;
    unsigned int border_style :2;
    unsigned int :2;
};

void show_setting(const struct box_props *pb);

int main(void){
    struct box_props box={true,YELLOW,true,GREEN,DASHED};
    printf("==>Original box setting:\n");
    show_setting(&box);
    box.opaque=false;
    box.border_color=MAGENTA;
    box.border_style=SOLID;
    puts("\n==>after modify:");
    show_setting(&box);
    puts("==>over!");
    return 0;
}

char* getStyle(int style){
    switch(style){
        case SOLID: return "solid";
        case DOTTED: return "dotted";
        case DASHED: return "dashed";
        default:
            return "unknown type";
    }
}

void show_setting(const struct box_props *pb){
    printf("is opaque? [%s].\n",pb->opaque?"yes":"no");
    printf("The fill color is [%s].\n", colors[pb->fill_color]);
    printf("is show border? [%s].\n",pb->show_border?"yes":"no");
    printf("border color is [%s].\n", colors[pb->border_color]);
    printf("border style is [%s].\n",getStyle(pb->border_style));
}


