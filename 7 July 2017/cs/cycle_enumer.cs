using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace CshConsoleApplication10
{
    static class Extensions
    {
        public static IEnumerable<T> Cycle<T>(this IEnumerable<T> enumer)
        {
            if (enumer == null) {
                throw new ArgumentNullException("enumer");
            }

            while (true) {
                foreach (var item in enumer) {
                    yield return item;
                }
            }
        }
    }

    sealed class Program
    {
        static void Main(String[] args)
        {
            var values = new Int32[] { 0, 1, 2, 3, 0 };
            
            foreach (var value in values.Cycle()) {
                Console.Write(" {0}", value);
                Thread.Sleep(100);
            }
        }
    }
}

