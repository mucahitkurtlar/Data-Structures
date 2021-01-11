#include <stdio.h>

unsigned int myabs(int t);
void getChars(int arr[15][15]);
void showTable(int arr[15][15]);
int len(char str[15]);
void left2r(int table[15][15], char query[15], int charvec[4]);
void right2l(int table[15][15], char query[15], int charvec[4]);
void top2b(int table[15][15], char query[15], int charvec[4]);
void bottom2t(int table[15][15], char query[15], int charvec[4]);
void tl2br(int table[15][15], char query[15], int charvec[4]);
void br2tl(int table[15][15], char query[15], int charvec[4]);
void bl2tr(int table[15][15], char query[15], int charvec[4]);
void tr2bl(int table[15][15], char query[15], int charvec[4]);
void findnmark(int table[15][15], char query[15], int charvec[4]);
int isonline(int charvec[4], int i, int j, int length);

int charvec[4] = {-1, -1, -1, -1};
int table[15][15];
char query[15];

int main() {
    getChars(table);
    scanf("%s", &query);
    findnmark(table, query, charvec);
    showTable(table);
    return 0;
}

unsigned int myabs(int t) {
    if (t < 0)
    {
        return -1 * t;
    }
    return t;
    
}

int isbetween(int s, int b, int e) {
    if (s > e)
    {
        if (s >= b && b >= e)
        {
            return 1;
        } else
        {
            return 0;
        }
        
        
    } else if (s < e)
    {
        if (s <= b && b <= e)
        {
            return 1;
        } else
        {
            return 0;
        }
        
        
    } else
    {
        if (s == b)
        {
            return 1;
        } else
        {
            return 0;
        }
    }
}

int isonline(int charvec[4], int i, int j, int length) {
    if (charvec[0] == charvec[2])
    {
        if ((myabs(charvec[1] - j) + myabs(charvec[3] - j) == length - 1) && i == charvec[0])
        {
            return 1;
        }
        return 0;
        
    } else if (charvec[1] == charvec[3])
    {
        if ((myabs(charvec[0] - i) + myabs(charvec[2] - i) == length - 1) && j == charvec[1])
        {
            return 1;
        }
        return 0;
        
    } else
    {
        if ((myabs(charvec[0] - i) + myabs(charvec[2] - i) == length - 1) && (myabs(charvec[1] - j) + myabs(charvec[3] - j) == length - 1) && myabs(charvec[0] - i) == myabs(charvec[1] - j))
        {
            return 1;
        }
        return 0;
        
    }
}

void getChars(int arr[15][15]) {
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            scanf("%s", &arr[i][j]);
        }
    }
    
}

void showTable(int arr[15][15]) {
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%s", &arr[i][j]);
        }
        puts("");
    }
}

int len(char str[15]) {
    int length = 0;
    for (int i = 0; str[i] != '\0' && i < 15; i++)
    {
        length = i;
    }
    return length + 1;
}

void left2r(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    int ok = 0;
    for (int i = 0; i < 15; i++)
    {
        
        for (int j = 0; j <= 15 - length && ok != length; j++)
        {
            ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i][j + k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i;
                charvec[3] = j + length - 1;
            }
        }
    }
}

void right2l(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 0; i < 15; i++)
    {
        
        for (int j = 14; j >= length - 1; j--)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i][j - k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i;
                charvec[3] = j - length + 1;
            }
        }
    }
}

void top2b(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 0; i <= 15 - length + 1; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i + k][j] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i + length - 1;
                charvec[3] = j;
            }
        }
        
    }
        
}

void bottom2t(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 14; i >= length - 1; i--)
    {
        
        for (int j = 0; j < 15; j++)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i - k][j] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                    
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i - length + 1;
                charvec[3] = j;
            }
        }
        
    }
        
}

void tl2br(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 0; i <= 15 - length + 1; i++)
    {
        
        for (int j = 0; j <= 15 - length; j++)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i + k][j + k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                    
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i + length - 1;
                charvec[3] = j + length - 1;
            }
        }
        
    }
        
}

void br2tl(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 14; i >= length - 1; i--)
    {
        
        for (int j = 14; j >= length - 1; j--)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i - k][j - k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                    
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i - length + 1;
                charvec[3] = j - length + 1;
            }
        }
        
    }
        
}

void bl2tr(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 14; i >= length - 1; i--)
    {
        
        for (int j = 0; j <= 15 - length; j++)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i - k][j + k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                    
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i - length + 1;
                charvec[3] = j + length - 1;
            }
        }
        
    }
        
}

void tr2bl(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    for (int i = 0; i <= 15 - length; i++)
    {
        
        for (int j = 14; j >= length - 1; j--)
        {
            int ok = 0;
            for (int k = 0; k < length; k++)
            {
                if ((char) table[i + k][j - k] == query[k])
                {
                    ok++;
                } else
                {
                    ok = 0;
                }
                    
            }
            if (ok == length)
            {
                charvec[0] = i;
                charvec[1] = j;
                charvec[2] = i + length - 1;
                charvec[3] = j - length + 1;
            }
        }
        
    }
        
}

void mark(int table[15][15], char query[15], int charvec[4]) {
    int length = len(query);
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                table[i][j] = '*';
            }
            
        }
        
    } else
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (!(isonline(charvec, i, j, length)))
                {
                    table[i][j] = '*';
                }
                
            }
            
        }
    }
    
    
}

void findnmark(int table[15][15], char query[15], int charvec[4]) {
    left2r(table, query, charvec);
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        right2l(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        top2b(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        bottom2t(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        tl2br(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        br2tl(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        bl2tr(table, query, charvec);
    }
    if (charvec[0] == -1 && charvec[1] == -1 && charvec[2] == -1 && charvec[3] == -1)
    {
        tr2bl(table, query, charvec);
    }
    mark(table, query, charvec);
}