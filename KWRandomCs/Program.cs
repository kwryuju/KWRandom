using System;

namespace KWRandomCs
{
    class Program
    {
        const int RANGE_MAX = 100;

        static void Main(string[] args)
        {
            Random rnd = new Random(Environment.TickCount);
            
            Console.WriteLine("{0}, {1}", rnd.Next(0, RANGE_MAX), rnd.NextDouble());
        }
    }
}
