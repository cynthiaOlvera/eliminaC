#include <stdio.h>
#include <stdlib.h>
#define chunk 1024


int main()
{

    FILE *fr;
    char ch;
    int diagonal = 0;
    int comentarioL = 0;
    int comentarioE = 0;
    int asterisco = 0;

    fr= fopen("bubbleSort.txt", "r"); //archivo guardado en la carpeta del programa
    if( fr == NULL )
    {
        perror("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }

    while( ( ch = fgetc(fr) ) != EOF )
    {
        //Caso que no es comentario
        if(comentarioL == 0 && comentarioE==0)
        {
            if(ch == '/')
            {
                diagonal++;
                if(diagonal==2)
                {
                comentarioL = 1;
                diagonal=0;
                }
            }
            else if(ch=='*')
            {
                if(diagonal==1)
                {
                    comentarioE = 1;
                    diagonal=0;
                }
                else
                    printf("%c",ch);
            }

            else
            {
                if(diagonal==1)
                {
                    printf("/");
                    diagonal=0;
                }
                printf("%c",ch);
            }
        }

        //Es comentario
        else
        {
            if(ch == '/')
            {
                if(comentarioE==1)
                {
                    if(asterisco==1)
                    {
                        comentarioE = 0;
                        asterisco = 0;
                    }
                }
            }
            else if(ch=='*')
            {
                if(comentarioE==1)
                {
                    asterisco=1;
                }
            }

             else if(ch=='\n')
             {

                if(comentarioL==1)
                {
                   comentarioL =0;
                   asterisco = 0;
                }
             }
        }

    }

    fclose(fr);
    return 0;
}
