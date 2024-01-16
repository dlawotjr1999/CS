using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ConstrainedExecution;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    public class car
    {
        public string company;
        public int year;
        public car(string company_, int year_)
        {
            this.company = company_;
            this.year = year_;
        }
    };
    // 다중 상속을 활용한 구현
    public class Cars : IEnumerator, IEnumerable
    {
        private car[] carlist;
        int position = -1;

        public Cars()
        {
            carlist = new car[6]
            {
                new car("Ford", 1992),
                new car("Fiat", 1988),
                new car("Buick", 1932),
                new car("Ford", 1932),
                new car("Dodge", 1999),
                new car("Honda", 1977)
            };
        }
        public IEnumerator GetEnumerator()
        {
            return (IEnumerator)this;
        }
        public bool MoveNext()
        {
            position++;
            return (position < carlist.Length);
        }
        public void Reset()
        {
            position = -1;
        }
        public object Current
        {
            get { return carlist[position]; }
        }
    }
    internal class IEnumeratorApp2
    {
        static void Main()
        {
            Cars cars = new Cars();
            foreach (car c in cars)
            {
                Console.WriteLine($"Company: {c.company}, Year: {c.year}");
            }
        }
    }
}
