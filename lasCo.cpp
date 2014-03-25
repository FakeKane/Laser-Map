y#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#include "EasyBMP.h"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        cout << "usage: ./lasCo imagefile\n";
        return 1;
    }
    
    BMP Image;
    Image.ReadFromFile(argv[1]);
    int height = Image.TellHeight();
    int width = Image.TellWidth();
    int maxBright = 0, maxBrightX = 0, maxBrightY = 0;
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int brightness = Image(x, y)->Red + Image(x, y)->Green + Image(x, y)->Blue;
            if(brightness > maxBright)
            {
                maxBright = brightness;
                maxBrightX = x;
                maxBrightY = y;                
            }
        }
    }
    
    cout << "height: " << height << "width: " << width << endl;
    cout << "The brightest spot is at (" << maxBrightX << ", " << maxBrightY << ").\n"; 
cout << "The distance from this point to the center is " << sqrt((maxBrightX - width/2) * (maxBrightX - width/2) + (maxBrightY - height/2) * (maxBrightY - height/2)) << endl;
    return 0;
}
