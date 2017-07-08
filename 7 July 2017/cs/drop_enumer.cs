using System;
using System.Collections.Generic;
using System.Linq;

namespace CshConsoleApplication10
{
    static class Extensions
    {
        public static IEnumerable<T> Drop<T>(this IEnumerable<T> enumer, Int32 count)
        {
            if (count < 0) {
                throw new ArgumentOutOfRangeException("count cannot be negative");
            }
            
            return enumer.Reverse().Take(count).Reverse();
        }
    }

    sealed class Program
    {
        static void Main(String[] args)
        {
            var range    = Enumerable.Range(1, 9).ToArray();
            var subrange = range.Drop(5).ToArray();

            Console.WriteLine(String.Join(" ", subrange));
        }
    }
}

