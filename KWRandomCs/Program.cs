using System;
using System.Security.Cryptography;

namespace KWRandomCs
{
    class Program
    {
        const int RANGE_MAX = 100;

        static void Main(string[] args)
        {
            var rnd = new Random(Environment.TickCount);
            
            Console.WriteLine("{0}, {1}", rnd.Next(0, RANGE_MAX), rnd.NextDouble());

            var cryp = new RNGCryptoServiceProvider();
            var buff = new Byte[25];

            cryp.GetBytes(buff);
            Array.ForEach<Byte>(buff, b => Console.Write(b + ","));
            Console.WriteLine();
        }
    }
}
