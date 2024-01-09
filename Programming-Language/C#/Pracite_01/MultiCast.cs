using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    delegate void MultiCastDelegate();
    class Schedule
    {
        public void Now()
        {
            Console.WriteLine("Time : " + DateTime.Now.ToString());
        }
       public static void Today()
        {
            Console.WriteLine("Date : " + DateTime.Today.ToString());
        }
    }
    internal class MultiCast
    {
        public static void Main()
        {
            Schedule obj = new Schedule();
            MultiCastDelegate mcd = new MultiCastDelegate(obj.Now);
            mcd += new MultiCastDelegate(Schedule.Today);
            mcd();
        }
    }
}
