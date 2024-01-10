using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    interface IRectangle
    {
        void Area(int width, int height);
    }
    interface ITriangle
    {
        void Area(int width, int height);
    }
    class Shape : IRectangle, ITriangle
    {
        void IRectangle.Area(int width, int height)
        {
            Console.WriteLine("Rectangle Area : " + width * height);
        }
        void ITriangle.Area(int width, int height)
        {
            Console.WriteLine("Triangle Area : " + width * height / 2);
        }
    }
    internal class Interface
    {
        public static void Main()
        {
            Shape s = new Shape();
            // s.IRectangle.Area(10, 10); -> error
            // s.ITriangle.Area(10, 10); -> error
            ((IRectangle)s).Area(20, 20); // Casting-Up
            ((ITriangle)s).Area(20, 20); // Casting-Up
            IRectangle r = s; // Casting-Up on interface
            ITriangle t = s; // Casting-Up on interface
            r.Area(30, 30);
            t.Area(30, 30);
        }
    }
}
