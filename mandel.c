#include <SDL2/SDL.h>
#include <math.h>

long double map(long double value, long double in_min, long double in_max, long double out_min, long double out_max);
int width = 900;
int height = 900;
int max_iteration = 200;
int bright;
long double min = -2.84;
long double max = 1.0;
long double factor = 1;

int main(int argc, char **argv)
{
    int x;
    int y;
    int n;
    int i;
    int red;
    int green;
    int blue;
    int count;
    long double a;
    long double b;
    long double last_a;
    long double last_b;
    long double a1;
    long double b1;
    SDL_Window *window;
    SDL_Renderer *rend;
    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(1440, 900, 0, &window, &rend);
    SDL_RenderSetLogicalSize(rend, width, height);

    while (1)
    {
        count = 0;
        max -= 0.1 * factor;
        min += 0.15 * factor;
        factor *= 0.9349;
        max_iteration += 5;
        SDL_RenderPresent(rend);

        x = 0;
        while (x < width)
        {
            if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                return 0;

            y = 0;
            while (y < height)
            {
                a = map(x, 0, width, min, max);
                b = map(y, 0, height, min, max);
                last_a = a;
                last_b = b;
                y++;
                n = 0;
                i = 0;
                while (i < max_iteration)
                {
                    a1 = a * a - b * b;
                    b1 = 2 * a * b;
                    a = a1 + last_a;
                    b = b1 + last_b;
                    if((a+b) > 2)
                        break;
                    n++; 
                    i++;
                }

                bright = map(n, 0, max_iteration, 0, 255);

                if (n == max_iteration || bright < 20)
                    bright = 0;

                red = map(bright * bright, 0, 255 * 255, 0, 255);
                green = bright;
                blue = map(bright, 0, sqrt(255), 0, 255);
                SDL_SetRenderDrawColor(rend, red, green, blue, 255);
                SDL_RenderDrawPoint(rend, x, y);
                
            }
            x++;
        }
        count++;
    }
}

long double map(long double value, long double in_min, long double in_max, long double out_min, long double out_max)
{
    return (value - in_min ) * (out_max - out_min) / (in_max - in_min) + out_min; 
}
