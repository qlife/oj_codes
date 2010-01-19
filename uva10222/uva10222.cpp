#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
    int dic[256];
    int c = 0;
    memset(dic,'\0',sizeof(dic));

    dic['e'] = 'q';
    dic['d'] = 'a';
    dic['c'] = 'z';
    dic['r'] = 'w';
    dic['f'] = 's';
    dic['v'] = 'x';
    dic['t'] = 'e';
    dic['g'] = 'd';
    dic['b'] = 'c';
    dic['y'] = 'r';
    dic['h'] = 'f';
    dic['n'] = 'v';
    dic['u'] = 't';
    dic['j'] = 'g';
    dic['m'] = 'b';
    dic['i'] = 'y';
    dic['k'] = 'h';
    dic[','] = 'n';
    dic['o'] = 'u';
    dic['l'] = 'j';
    dic['.'] = 'm';
    dic['p'] = 'i';
    dic[';'] = 'k';
    dic['/'] = ',';
    dic['['] = 'o';
    dic['\''] = 'l';
    dic[']'] = 'p';
    dic['\\'] = '[';
    dic[' '] = ' ';

    dic['E'] = 'q';
    dic['D'] = 'a';
    dic['C'] = 'z';
    dic['R'] = 'w';
    dic['F'] = 's';
    dic['V'] = 'x';
    dic['T'] = 'e';
    dic['G'] = 'd';
    dic['B'] = 'c';
    dic['Y'] = 'r';
    dic['H'] = 'f';
    dic['N'] = 'v';
    dic['U'] = 't';
    dic['J'] = 'g';
    dic['M'] = 'b';
    dic['I'] = 'y';
    dic['K'] = 'h';
    dic['O'] = 'u';
    dic['L'] = 'j';
    dic['P'] = 'i';

    dic['\n'] = '\n';

    do {
        c = fgetc(stdin);
        if (EOF == c) break;
        fputc(dic[c],stdout);
    } while (true) ;

    return 0;
}
