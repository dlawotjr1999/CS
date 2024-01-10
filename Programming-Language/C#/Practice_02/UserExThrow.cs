using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class UserException : ApplicationException { }
    internal class UserExThrow
    {
        static void Method()
        {
            throw new UserException();
        }
        static void Main()
        {
            try
            {
                Console.WriteLine("Here: 1");
                Method();
                Console.WriteLine("Here: 2");
            } catch (UserException) 
            {
                Console.WriteLine("User-defined Exception");
            }
        }
    }
}
