using System;
using System.Linq;
using System.Collections.Generic;

namespace CshConsoleApplication5
{
    sealed class Program
    {
        private static Boolean IsPrime(Int32 value)
        {
            const Int32 kSmallestPrime = 2;
            
            if (value < kSmallestPrime) return false;
            if (value % 2 == 0)         return value == kSmallestPrime;
            
            var upperBound = (Int32)Math.Ceiling(Math.Sqrt(value));
        
            for (var div = kSmallestPrime | 1; div <= upperBound; div += 2) {
                if (value % div == 0) {
                    return false;
                }
            }

            return true;
        }

        static void Main(String[] args)
        {
            var minVal = -1;
            var maxVal = 100;
            var primes = Enumerable.Range(minVal, maxVal).Where(IsPrime);
            var result = String.Join(" ", primes);

            Console.WriteLine(result);
        }
    }
}
