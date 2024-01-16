using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    internal class Polling
    {
        static bool myFlag = false;
        static void Main()
        {
            Thread MyThread = new Thread(Func);
            MyThread.Start();
            for(int i = 0; i < 3; i++)
            {
                Console.WriteLine(i + 1);
                Thread.Sleep(100);
            }
            myFlag = true;
            Console.WriteLine("MainThread end...");
        }
        private static void Func()
        {
            while(true)
            {
                if(myFlag)
                {
                    Console.WriteLine("Polling Success!");
                }
                Thread.Sleep(100);
            }
        }
    }
}
