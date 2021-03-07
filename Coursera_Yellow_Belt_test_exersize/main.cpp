#include <iostream>
#include <fstream>
#include <stdexcept>
#include <exception>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{

    int rows;
    int columns;
    vector<vector<int>> mtx;
public:

    Matrix()
    {
//        конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
        this->columns = 0;
        this->rows = 0;
        mtx.assign(rows, vector<int>(columns));
    };
    
    Matrix(int num_rows, int num_columns)
    {

//            конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
        if (num_rows < 0 || num_columns < 0)
            throw out_of_range("Out of range");

            columns = num_columns;
            rows = num_rows;
            
            mtx.resize(rows, vector<int>(columns));
    };

    
   int At(const int& i, const int& j) const
    {
//        константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
        try
        {
            return mtx.at(i).at(j);
        }
        catch (out_of_range& ex)
        {
//            Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.
            throw out_of_range("Out of range");
        }
    }

    int& At(const int& i, const int& j)
    {
        try
        {
            return mtx.at(i).at(j);
        }
        catch (out_of_range& ex)
        {
//            Это же исключение должен бросать метод At, если переданная в него ячейка выходит за границы матрицы.
            throw out_of_range("Out of range");
        }
            //        неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
    }

    
    void Reset(const int new_rows, const int new_columns)
    {

        if (new_rows < 0 || new_columns < 0)
            throw out_of_range("Out of range");
        
        rows = new_rows;
        columns = new_columns;
        mtx.assign(rows, vector<int>(columns));
        

//        метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
    }
    
    int GetNumRows() const
    {
//        константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно
        return rows;
    }
    
    int GetNumColumns() const
    {
//        константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно
        return columns;
    }

};

 
istream& operator >> (istream& stream, Matrix& mtx)
{
//    оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов (именно в этом порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент первой строки и второго столбца и так далее
//    cout << "Enter rows and columns" << endl;
    
    int rows = 0, columns = 0; //строки - столбцы!

    try
    {
        stream >> rows >> columns;
        mtx = Matrix(rows, columns);
        
//        cout << endl;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                stream >> mtx.At(i, j);
            }
//            cout << endl;
        }
        
//        cout << "Num Rows: " << mtx.GetNumRows() << endl;
//        cout << "Num Columns: " << mtx.GetNumColumns() << endl;
//        cout << "Value at 0*0 matrix is: " << mtx.At(0, 0) << endl;
//
//        mtx.Reset(3, 3);
//        cout << "Reset mtx 3 * 3:" << endl;
        cout << endl;
    }
    catch (exception& ex)
    {
        throw;
    }
        
    return stream;
}

ostream& operator << (ostream& stream, const Matrix& mtx)
{
//    оператор вывода в поток ostream; он должен выводить матрицу в том же формате, в каком её читает оператор ввода, — в первой строке количество строк и столбцов, во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
    int num_rows = mtx.GetNumRows();
    int num_columns = mtx.GetNumColumns();
    
    stream << mtx.GetNumRows() << " " << mtx.GetNumColumns() << endl;
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            stream << mtx.At(i, j) << " ";
        }
        stream << endl;
    }
    
    return stream;
}

bool operator == (const Matrix& lhs, const Matrix& rhs)
{
//    оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы равны между собой, в противном случае он должен возвращать false.
    
    if ((!lhs.GetNumColumns() || !lhs.GetNumRows()) &&
        (!rhs.GetNumColumns() || !rhs.GetNumRows()))
        return true;
    
    if (lhs.GetNumRows() != rhs.GetNumRows() ||
        lhs.GetNumColumns() != rhs.GetNumColumns())
    {
        return false;
    }

    for (int i = 0; i < lhs.GetNumRows(); i++)
    {
        for (int j = 0; j < lhs.GetNumColumns(); j++)
        {
            if (lhs.At(i, j) != rhs.At(i, j))
                return false;
        }
    }
    
    return true;
}


Matrix operator + (const Matrix& lhs, const Matrix& rhs)
{
//    оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой; если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.
    
//    Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые матрицы равны. Сумма двух пустых матриц также является пустой матрицей.
    
    if ((!lhs.GetNumColumns() || !lhs.GetNumRows()) && (!rhs.GetNumColumns() || !rhs.GetNumRows()))
        return Matrix(0, 0);

    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns())
    {
        throw invalid_argument("Wrong matrix size.");
    }

    int lhs_rows = lhs.GetNumRows();
    int lhs_col = lhs.GetNumColumns();
            
    Matrix summ = Matrix(lhs_rows, lhs_col);
    
    for (int i = 0; i < lhs_rows; i++)
    {
        for (int j = 0; j < lhs_col; j++)
        {
            summ.At(i, j) = (lhs.At(i, j) + rhs.At(i, j));
        }
    }

    return summ;
}

int main()
{
//    Matrix one;
//    Matrix two;
//    Matrix summ;
//
//
//    cin >> one >> two;
//
//
////    cout << (one == two) << endl;
//    summ = one + two;
//    cout << summ << endl;
//    Matrix one(2,0);
//    Matrix two(0,3);
//
//    std::cout << (one + two) << std::endl;
//
    Matrix one(0,4);
    Matrix two(6,0);
    cout << boolalpha << (one == two) << '\n';
    
  return 0;
}
