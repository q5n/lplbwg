//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>

//屏幕尺寸常量
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    //将要渲染的窗口结构指针
    SDL_Window* window = NULL;
    
    //窗口包含的表面(surface)指针
    SDL_Surface* screenSurface = NULL;

    //初始化 SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    } else {
        //创建窗口
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
        if( window == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        } else {
            //获取表面指针
            screenSurface = SDL_GetWindowSurface( window );

            //表面填充颜色-白色RGB(0xff,0xff,0xff)
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //更新表面
            SDL_UpdateWindowSurface( window );

            SDL_Delay( 2000 );//等待2秒
        }
    }

    //销毁窗口
    SDL_DestroyWindow( window );

    //退出SDL子系统
    SDL_Quit();

    return 0;
}