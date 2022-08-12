using System;

/*
namespace EventTest
{
    delegate void EventHandler(string message);

    class Mynotifier
    {
        public event EventHandler SomethingHappened;
        public void DoSomething(int number)
        {
            int temp = number % 10;

            if (temp != 0 && temp % 3 == 0) ;
            {
                SomethingHappened(String.Format($"{number} : 짝"));
            }
        }
    }

    class MainApp
    {
        static public void Myhandler(string message)
        {
            Console.WriteLine(message);
        }

        static void Main(string[] args)
        {
            Mynotifier notifier = new Mynotifier();
            notifier.SomethingHappened += new EventHandler(Myhandler);

            for (int i = 0; i < 30; ++i)
            {
                notifier.DoSomething(i);
            }
        }
    }
}
*/

namespace StatementLambda
{
    class MainaApp
    {
        delegate string Concatenate(string[] args);

        static void Main(string[] args)
        {
            Concatenate concat =
                (arr) =>
                {
                    string result = "";
                    foreach (string s in arr)
                        result += s;

                    return result;
                };

            Console.WriteLine(concat(args));
        }
    }
}
