#include "matrix.hpp"
#include "InputArray.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
  using namespace sukacheva;

  if (argc != 4)
  {
    std::cerr << "Wrong number of elements.\n";
    return 1;
  }

  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Cannot parse a value.\n";
    return 3;
  }

  size_t rows = 0, cols = 0;

  if (num == 1)
  {
    {
      int staticMatrix[10000];
      std::ifstream input(argv[2]);
      input >> rows;
      input >> cols;
      if (!input)
      {
        std::cerr << "Cannot read an input.\n";
        return 2;
      }
      for (size_t i = 0; i < rows * cols; i++)
      {
        input >> staticMatrix[i];
      }
      size_t MaxDiagonal = MaxSideDiagonal(staticMatrix, cols, rows);
      {
        std::ofstream output(argv[3]);
        output << MaxDiagonal;
      }
    }
  }

  else if (num == 2)
  {
    std::ifstream input(argv[2]);
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read an input.\n";
      return 2;
    }
    int* dinamicMatrix = new int[rows * cols];
    {
      try
      {
        readMatrix::inputMatrix(input, dinamicMatrix, rows * cols, rows * cols);
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what();
        delete[] dinamicMatrix;
        return 2;
      }
    }
    {
      std::ofstream output(argv[3]);
      output << MaxSideDiagonal(dinamicMatrix, rows, cols);
    }
    delete[] dinamicMatrix;
  }
  else
  {
    std::cerr << "Argument is out of range. \n";
    return 1;
  }
  return 0;
}
