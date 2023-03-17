#include <stdio.h>
 
int main() {
    int xm, ym, xr, yr;
    scanf("%d %d %d %d", &xm, &ym, &xr, &yr);
    
    if(xr>=xm && yr>=ym)
        printf("%d\n", (xr-xm)+(yr-ym));
    else if(xr>=xm)
        printf("%d\n", (xr-xm)+(ym-yr));
    else if(yr>=ym)
        printf("%d\n", (xm-xr)+(yr-ym));
    else
        printf("%d\n", (xm-xr)+(ym-yr));
 
    return 0;
}