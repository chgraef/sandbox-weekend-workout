using System;
using System.Linq;
using System.Collections.Generic;

namespace CshConsoleApplication10
{
    static class Extensions
    {
        public static IEnumerable<T> DropWhile<T>(this IEnumerable<T> enumer, Func<T, Boolean> condition)
        {
            if (enumer == null) {
                throw new ArgumentNullException("enumer");
            }
            
            if (condition == null) {
                throw new ArgumentNullException("condition");
            }
            
            Boolean willDrop = true;

            foreach (var item in enumer) 
            {
                if (!condition(item)) willDrop = false;
                if (!willDrop)        yield return item;
            }
        }
    }

    sealed class Program
    {
        static void Main(String[] args)
        {
            var lyrics = new String[] {
                "I wake up", 
                "Find myself unstable",
                "I'm hoping that",
                "this world",
                "is just a fable",
                "You realize",
                "It's too late",
                "To fight it",
            };

            var verse = lyrics.DropWhile((line) => !line.Contains("fable"));

            Console.WriteLine(String.Join("\n", verse));
        }
    }
}

