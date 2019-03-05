#include <stdio.h>
#include <string.h>
#include <math.h>

int Counter(int num) {
    // счётчик единиц в двоичной записи числа
    int counter = 0;
    for (int i = 32768; i > 0; i /= 2)
    {
            if (num / i == 1)
            {
                num -= i;
                counter ++;
            }
    }
    return counter;
}

void Number( int num, int count)
{
    if (count == Counter(num))
    {
     printf("\nЧисло с максимальным кол-вом единиц в двоичном коде:  ");
     printf("%d\n" , num);
     printf("Его запись в двоичной системе исчисления:  ");
        for (int i = 32768; i > 0; i /= 2)
        {
            if (num / i == 1)
            {
                printf("1");
                num -= i;
            }
            else printf("0");
            
        }
    }
    printf("\n");
}

int main() {
    int max = 0;
    int start, end, temp;
    
    printf(" Введите интервал (максимальное число 32768). От ") ; // 2^15 = 32768
    scanf("%d", &start);
    printf(" до ") ;
    scanf("%d", &end);
    if (end < 0 || end > 32768)
    {
        printf(" Ошибка ввода !") ;
        return 0;
    }
    for (int i = start; i <= end; i++)
    {
       temp  = Counter(i);
        if (temp > max ) max = temp;
    }
    for (int i = start; i <= end; i++)
        Number(i, max);
    printf("\n");
    
    return 0;
}
