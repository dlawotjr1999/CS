using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class AnonymousType
    {
        static void Main()
        {
            var a = new { Name = "Valtan", Tribe = "DeivilBoss" };
            Console.WriteLine("Name: {0}, Tribe: {1}", a.Name, a.Tribe);

            var b = new { Type = "Esther", Members = new string[] { "Sillian", "Waye", "Baunturr" } };

            Console.Write("Esther: {0}. Members: ", b.Type);
            foreach (var member in b.Members)
                Console.Write("{0} ", member);
            Console.WriteLine();
        }
    }
}
