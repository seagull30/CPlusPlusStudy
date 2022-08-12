using System;
#region 13.1
/*
namespace Delegate
{
    delegate int MyDelegate(int a, int b);

    class Calculator
    {
        public int Plus(int a,int b)
            { return a + b; }

        public static int Minus(int a, int b)
            { return a - b; }
    }

    class MainApp
    {
        static void Main(string[] args)
        {
            Calculator calc = new Calculator();
            MyDelegate Callback;

            Callback = new MyDelegate(calc.Plus);
            Console.WriteLine(Callback(3, 4));


            Callback = new MyDelegate(Calculator.Minus);
            Console.WriteLine(Callback(7, 5));
        }
    }
}
*/
#endregion
#region 13.2
/*
using System;

namespace UsingCallback
{
    delegate int Compare(int a, int b);

    class MainApp
    {
        static int AscendCompare(int a, int b)
        {
            if (a > b)
                return 1;
            else if (a == b)
                return 0;
            else
                return -1;
        }

        static int DescendCompare(int a, int b)
        {
            if (a < b)
                return 1;
            else if (a == b)
                return 0;
            else
                return -1;
        }

        static void BubbleSort(int[] DataSet, Compare comparer)
        {
            int i = 0;
            int j = 0;
            int temp = 0;
            for (i = 0; i < DataSet.Length; ++i)
            {
                for (j = 0; j < DataSet.Length - (i + 1); ++j)
                {
                    if (comparer(DataSet[j], DataSet[j + 1]) > 0)
                    {
                        temp = DataSet[j + 1];
                        DataSet[j + 1] = DataSet[j];
                        DataSet[j] = temp;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            int[] array = { 3, 7, 4, 2, 10 };

            Console.WriteLine("Sorting ascending...");
            BubbleSort(array, new Compare(AscendCompare));

            for (int i = 0; i < array.Length; ++i)
            {
                Console.Write($"{array[i]} ");
            }

            int[] array2 = { 7, 2, 8, 10, 11 };
            Console.WriteLine("\nSorting descending...");
            BubbleSort(array2, new Compare(DescendCompare));

            for (int i = 0; i < array2.Length; ++i)
            {
                Console.Write($"{array2[i]} ");
            }

            Console.WriteLine();
        }
    }
}
*/

#endregion
#region 13.3
namespace GenercDelegate
{
    delegate int Compare<T>(T a, T b);

    class MainApp
    {
        static int AscendCompare<T>(T a, T b) where T : IComparable<T>
        {
            return a.CompareTo(b);
        }

        static int DescendCompare<T>(T a, T b) where T : IComparable<T>
        {
            return a.CompareTo(b) * -1;
        }

        static void BubbleSort<T>(T[] DataSet, Compare<T> comparer)
        {
            int i;
            int j;
            T temp;
            for (i = 0; i < DataSet.Length; ++i)
            {
                for (j = 0; j < DataSet.Length - (i + 1); ++j)
                {
                    if (comparer(DataSet[j], DataSet[j + 1]) > 0)
                    {
                        temp = DataSet[j + 1];
                        DataSet[j + 1] = DataSet[j];
                        DataSet[j] = temp;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            int[] array = { 3, 7, 4, 2, 10 };

            Console.WriteLine("Sorting ascending...");
            BubbleSort(array, new Compare<int>(AscendCompare));

            for (int i = 0; i < array.Length; ++i)
            {
                Console.Write($"{array[i]} ");
            }

            string[] array2 = { "abc","def","ghi","jkl","mno" };
            Console.WriteLine("\nSorting descending...");
            BubbleSort(array2, new Compare<string>(DescendCompare));

            for (int i = 0; i < array2.Length; ++i)
            {
                Console.Write($"{array2[i]} ");
            }

            Console.WriteLine();
        }
    }
}
#endregion