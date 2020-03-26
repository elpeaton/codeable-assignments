#include <cs50.h>
#include <stdio.h>

void printHashes(int h);
void printSpaces(int h, int s);

int main(void)
{
    int height;
    //recibir solo enteros entre 1 y 8
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    //imprimir lineas
    for (int line = 0; line < height; line++)
    {
        printSpaces(height, line);
        printHashes(line);
        printf("  ");
        printHashes(line);
        printf("\n");
    }
}

void printHashes(int h)
{
    for (int hashes = 0; hashes < h + 1; hashes++)
    {
        printf("#");
    }
}

void printSpaces(int h, int s)
{
    for (int spaces = h - s; spaces > 1; spaces--)
    {
        printf(" ");
    }
}