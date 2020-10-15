#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int isRowBased(int arr[2][3]);
int isColumnBased(int arr[2][3]);

int main() {
    int arr[2][3] = {{0, 1, 2},{3, 4, 5}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("&arr[%d][%d]: %d\n", i, j, &arr[i][j]);
        }
        
    }
    
    if (isRowBased(arr))
    {
        printf("Array satir bazli olarak memoryde tutuluyor.\n");
    }
    else
    {
        printf("Array satir bazli olarak memoryde tutulmuyor.\n");
    }
    if (isColumnBased(arr))
    {
        printf("Array sutun bazli olarak memoryde tutuluyor.\n");
    }
    else
    {
        printf("Array sutun bazli olarak memoryde tutulmuyor.\n");
    }
    
    return 0;
}

int isRowBased(int arr[2][3]) {
    if (abs((uintptr_t) &arr[0][1] - (uintptr_t) &arr[0][0]) == sizeof(int)) //ayni satirdaki ardisik elemanların adresleri arasındaki fark array tipinin boyutuna esitse dizi satir bazli olarak saklanmaktadir
    {
        return 1;
    }
    return 0;
}

int isColumnBased(int arr[2][3]) {
    if (abs((uintptr_t) &arr[1][0] - (uintptr_t) &arr[0][0]) == sizeof(int)) //ayni sutundaki ardisik elemanların adresleri arasındaki fark array tipinin boyutuna esitse dizi sutun bazli olarak saklanmaktadir
    {
        return 1;
    }
    return 0;
}
