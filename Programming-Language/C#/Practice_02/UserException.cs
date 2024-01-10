using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class UserErrException : ApplicationException
    {
        public UserErrException(string s) : base(s) { }
    }
    internal class UserException
    {
        static void Main()
        {
            try
            {
                throw new UserErrException("throw a exception with a message");
            }
            catch(UserErrException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
