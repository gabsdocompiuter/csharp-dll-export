#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void ShowError(HINSTANCE hDLL, char* error){
    typedef void (*ShowError)(char *string);
    ((ShowError)GetProcAddress(hDLL, "ShowError"))(error);
}

int main(){
    HINSTANCE hDLL = LoadLibrary("exemplo.dll");

    if (hDLL != NULL)
    {
        typedef void (*AllocTwoNumbers)(int number1, int number2);
        typedef void (*GetSum)(int *result);

        AllocTwoNumbers allocTwoNumbers = (AllocTwoNumbers)GetProcAddress(hDLL, "AllocTwoNumbers");
        if(allocTwoNumbers){
            allocTwoNumbers(2, 3);
        }

        GetSum getSum = (GetSum)GetProcAddress(hDLL, "GetSum");
        if(getSum){
            int result;
            getSum(&result);
            printf("o resultado da soma eh %d\n\n", result);
        }

        typedef void (*ShowError)(char *string);
        ((ShowError)GetProcAddress(hDLL, "ShowError"))("Houve um erro ao executar o programa");

        FreeLibrary(hDLL);
    }   

    system("pause");
    return 0;
}
