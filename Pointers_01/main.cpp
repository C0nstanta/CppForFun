//Задание 2
//Написать программу, которая для введённой с клавиатуры строки (максимальная длина строки — 80 символов) сообщает, какая цифра в ней встречается чаще всего, либо сообщает, что цифры в строке совсем отсутствуют. Если с одинаковой частотой в строке встретилось несколько цифр, то в качестве лидера вывести любую из подходящих цифр. Для обхода строк использовать указатели.

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {

    int number = 0;// Записываем текущую цифру
    int *ptrNumber = &number; // Берем на нее указатель
    
    int maxNumberCount = 0; //Переменная, в которую записываем макс значение повторений.
    int maxNumber = 0;
    
    
    int countNum = 0; // Делаем подсчет текущей цифры в строке
    int *ptrCountNum = &countNum; // Ее указатель
    
    int count = 0;
    const int MAXSIZE = 80; // Длинна строки
    
    char *block = new char[MAXSIZE];
    char *ptrBlock = block;
    
    cout << "Enter any string with max length 80 symbols" << endl;
    cin >> block;
    
    if (strlen(block) <= MAXSIZE){
        cout << "Block: " << block << " , SIZE: " << strlen(block) << endl;
        
        while (count < strlen(block)) {
            if (isdigit(*(ptrBlock++))){
                *ptrCountNum = 0;
                for (int i = 0; i <= strlen(block); i++){
                    if (*(ptrBlock - 1) == *(block + i)){
                        cout << "(*(ptrBlock - 1) == *(block - i)): " << *(ptrBlock - 1) << " == " << *(block + i) << endl;
                        *ptrCountNum += 1;
                    }
                    
                }
                
                *ptrNumber = (*(ptrBlock - 1) - 48);
                
                cout << "number: " << number << endl;
                cout << "*(ptrBlock - 1): " << *(ptrBlock - 1) << endl;
                cout << "*ptrCountNum: " << *ptrCountNum << endl;
                
                if (*ptrCountNum > maxNumberCount){
                    maxNumber = *(ptrBlock - 1) - 48;
                    maxNumberCount = *ptrCountNum;
                }
                
            }
            
            count++;
        }
        
        if (*ptrCountNum == 0){
            cout << "We have not numbers in this string" << endl;
        }
        else cout << "MaxCountNumber: " << maxNumberCount << " Number: " << maxNumber << endl;
    }
    else
    {
        cout << "String length > Max Size" << endl;
    }
    
    
    return 0;
}
