#include <stdio.h>

int main()
{
    unsigned char x,y;// output variables
    unsigned char u=0x01, v=0x11;//input variables
    x= ((~u)&(~v))|((~u)&v)|(u&v);
    y=((~u)|v);
    if(x==y)
    {
        printf("u'+v=u'v'+u'v+uv");
    }
    else
    {
        printf("u'+v=!u'v'+u'v+uv");
    }

    return 0;
}
