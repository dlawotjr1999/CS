using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    internal class ParamThread
    {
        static void Main()
        {
            // MainThread
            Thread MyThread = new Thread(Func);
            MyThread.Start(7);
            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
            Console.WriteLine("MainThread end..");
        }
        private static void Func(object obj)
        {
            //SubThread
            int num = (int)obj;
            for(int i = 0; i < num; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
        }
    }
}
